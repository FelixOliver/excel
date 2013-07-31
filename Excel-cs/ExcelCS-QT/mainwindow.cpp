#ifndef QT_NO_PRINTER
#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#endif

#include <QMessageBox>
//#include <QFile>
#include <QFileDialog>
//#include <QApplication>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "PreviewPrint.h"

const char *about_Excel ="<HTML> <p><b>Este pequeño programa C.S. Excel V. 3.1416 esta realizado por:</b></p> <li>->Orlando Pérez Paredes.</li> <li>->Oliver Sumari Huayta</li> <li>->Eyner Pariguana Medina</li></p> <li>Esperamos que este lo suficientemente convencido que merecemos 20.</li></HTML>";
int edition_controlator=1;

MainWindow::MainWindow(int row, int column,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_matrix.set_row(row);
    m_matrix.set_column(column);
    m_parse.set_matrix(&m_matrix);
    m_document.set_matrix(&m_matrix);

    ui->SpreadSheet->setRowCount(row);
    ui->SpreadSheet->setColumnCount(column);
    ::thread thread1([column,this]{for (register int i = 0; i < column/2; ++i)
                                       {
                                            expr name=name_column_from_number(i);
                                            QString _name(name.c_str());
                                            ui->SpreadSheet->setHorizontalHeaderItem(i, new QTableWidgetItem(_name));
                                       }});
    ::thread thread2([column,this]{for (register int i = column/2; i < column; ++i)
                                       {
                                            expr name=name_column_from_number(i);
                                            QString _name(name.c_str());
                                            ui->SpreadSheet->setHorizontalHeaderItem(i, new QTableWidgetItem(_name));
                                       }});
        thread2.join();
        thread1.join();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::load_matrix()
{
    for (register unsigned i=0;i<m_matrix.get_row();++i)
    {
        for (register unsigned j=0;j<m_matrix.get_column();++j)
        {
            if(m_matrix.exist(i,j))
            {
                if(m_matrix.get_element(i,j).get_expression()[0]=='=')
                    m_parse.set_expression(m_matrix.get_element(i,j).get_expression().substr(1));
                else if(is_number(m_matrix.get_element(i,j).get_expression()))
                    m_parse.set_expression(m_matrix.get_element(i,j).get_expression());
                try
                {
                    m_matrix.get_element(i,j).set_result(m_parse.parse()->get_value());
                    QString result;
                    result.setNum(m_matrix.get_element(i,j).get_result());
                    ui->SpreadSheet->item(i,j)->setText(result);
                }
                catch(Lexical_Error& _error)
                {
                    ui->SpreadSheet->item(i,j)->setText(QString(_error.what()));
                }
                ui->SpreadSheet->item(i,j)->setText(QString(m_matrix.get_element(i,j).get_expression().c_str()));
            }
        }
    }
}

void MainWindow::on_SpreadSheet_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    QString temp1;
    temp1.setNum(currentRow+1);
    temp1=ui->SpreadSheet->horizontalHeaderItem(currentColumn)->text()+temp1;
    ui->actual_cell->setText("Cell: "+temp1);


    if(ui->SpreadSheet->item(currentRow,currentColumn))
        if (m_matrix.exist(currentRow,currentColumn))
            ui->Formule_Bar->setText(QString(m_matrix.get_element(currentRow,currentColumn).get_expression().c_str()));
        else
            ui->Formule_Bar->setText(ui->SpreadSheet->item(currentRow,currentColumn)->text());
    else
        ui->Formule_Bar->setText("");

}

void MainWindow::on_SpreadSheet_itemChanged(QTableWidgetItem *item)
{
    if(edition_controlator &&(item->text().toStdString()[0]=='=' || is_number(item->text().toStdString())))
    {
        --edition_controlator;
        try
        {
            Cell _new(item->text().toStdString(),item->row(),item->column());

            m_matrix.insert(item->row(),item->column(),_new);
            if(m_matrix.get_element(item->row(),item->column()).get_expression()[0]=='=')
                m_parse.set_expression(m_matrix.get_element(item->row(),item->column()).get_expression().substr(1));
            else
                m_parse.set_expression(m_matrix.get_element(item->row(),item->column()).get_expression());
            m_matrix.get_element(item->row(),item->column()).set_result(m_parse.parse()->get_value());
            QString result;
            result.setNum(m_matrix.get_element(item->row(),item->column()).get_result());
            item->setText(result);
        }
        catch(Lexical_Error& _error){
            item->setText(QString(_error.what()));
        }

        catch(Syntax_Error & _error){
            item->setText(QString(_error.what()));
        }
        catch(Valor_Text & _error){
            item->setText(QString(_error.get_text().c_str()));
        }

        ui->Formule_Bar->setText(QString(m_matrix.get_element(item->row(),item->column()).get_expression().c_str()));

        ++edition_controlator;

        }
    else if(item->text().toStdString()=="")
    {
       m_matrix.erase(item->row(),item->column());
       ui->Formule_Bar->setText("");
    }

    else if(edition_controlator)
    {
        if(m_matrix.exist(item->row(),item->column()))
            m_matrix.get_element(item->row(),item->column()).set_expression(item->text().toStdString());
        else
        {
            Cell _new(item->text().toStdString(),item->row(),item->column());
            m_matrix.insert(item->row(),item->column(),_new);
            --edition_controlator;
            item->setText(QString(m_matrix.get_element(item->row(),item->column()).get_expression().c_str()));
            ++edition_controlator;
        }
        ui->Formule_Bar->setText(QString(m_matrix.get_element(item->row(),item->column()).get_expression().c_str()));
    }

}

void MainWindow::on_Button_Print_clicked()
{
    #ifndef QT_NO_PRINTER
    QPrinter printer(QPrinter::ScreenResolution);
    QPrintPreviewDialog dlg(&printer);
    dlg.setWindowIcon(QIcon("://icono 3.png"));
    PreviewPrint view;
    view.setModel(ui->SpreadSheet->model());
    connect(&dlg, SIGNAL(paintRequested(QPrinter*)), &view, SLOT(print(QPrinter*)));
    dlg.exec();
    #endif
}

void MainWindow::on_actionPrint_triggered()
{
    #ifndef QT_NO_PRINTER
    QPrinter printer(QPrinter::ScreenResolution);
    QPrintPreviewDialog dlg(&printer);
    dlg.setWindowIcon(QIcon("://icono 3.png"));
    PreviewPrint view;
    view.setModel(ui->SpreadSheet->model());
    connect(&dlg, SIGNAL(paintRequested(QPrinter*)), &view, SLOT(print(QPrinter*)));
    dlg.exec();
    #endif

}

void MainWindow::on_Button_New_clicked()
{
    MainWindow* _new= new MainWindow(ui->SpreadSheet->rowCount(),ui->SpreadSheet->columnCount());
    _new->show();
}

void MainWindow::on_actionNew_triggered()
{
    MainWindow* _new= new MainWindow(ui->SpreadSheet->rowCount(),ui->SpreadSheet->columnCount());
    _new->show();
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::on_actionAbout_Excel_CS_v_3_14_16_triggered()
{
    QMessageBox::about(this, "About C.S. Excel",about_Excel);
}


void MainWindow::on_Button_Save_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if(fileName.toStdString()[0])
        m_document.save(fileName.toStdString());
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if(fileName.toStdString()[0])
        m_document.save(fileName.toStdString());
}

void MainWindow::on_Button_Open_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this);
    m_document.open(file_name.toStdString());
    load_matrix();
}
