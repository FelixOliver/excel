#ifndef QT_NO_PRINTER
#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#endif

#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "preview_print.h"

std::vector<std::string> letters={"A","B","C","D","E","F",
                                   "G","H","I","J","K",
                                   "L","M","N","O","P",
                                   "Q","R","S","T","U",
                                   "V","W","X","Y","Z"};
const int letters_total=26;


const char *about_Excel ="<HTML> <p><b>Este pequeño programa<c> C.S. Excel V. 3.1416</c> esta realizado por:</b></p> <li>->Orlando Pérez Paredes.</li> <li>->Oliver Sumari Huayta</li> <li>->Eyner Pariguana Medina</li></p> <li>Esperamos que este lo suficientemente convencido que merecemos 20.</li></HTML>";

MainWindow::MainWindow(int row,int column,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spreadsheet->setRowCount(row);
    ui->spreadsheet->setColumnCount(column);
    for (register int i = 0; i < column; ++i)
    {
        int _column = i;
        std::string name;
        auto residue = _column%letters_total; /**<------Convierte la columna en letra mayuscula-----*/
        name = letters[residue]; /**< name es el resultado final */
        _column /= letters_total; /**< le da un nuevo valor para ver si _column es mayor que 26*/
        if(_column!=0) /**< Si es TRUE indica que _column era mayor que 26, False era menor*/
        {
            while(_column>0) /**< El ciclo parara cuando ya no quede cantidad extraible*/
            {
                residue = _column%letters_total; /**< Saca el residuo para convertir en base 26*/
                if(residue==0) /**< CUIDADO si el residuo es 0 indica que se extrae la Letra Z,
                                 _column es multiplo de 26*/
                {
                    _column/=letters_total;
                    name=letters[letters_total-1]+name; /**<Si fuese letters[residue-1] era igual a:
                                                                letters[-1] y eso es un error*/
                    if(_column<letters_total) /**<Si _column es menor a 26 entonces ya no se extrae mas*/
                        _column=0; /**<Si fuese asi aqui corta el ciclo */
                }
                else /**< Si se llega aqui es porque _column NO es multiplo de 26*/
                {
                    name=letters[residue-1]+name;
                    _column/=letters_total;
                }
            }
       }
        QString _name(name.c_str());
       ui->spreadsheet->setHorizontalHeaderItem(i, new QTableWidgetItem(_name));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::save()
{
   // if (current_file.isEmpty()) {
   //     return saveAs();
 //   } else {
        QString fileName = QFileDialog::getSaveFileName(this);
  //  }
}
/*
bool MainWindow::save_file(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
}

    QTextStream out(&file);
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    out << textEdit->toPlainText();
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

bool MainWindow::maybeSave()
{
    if (ui->Formule_Bar->isModified())
    {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("Application"),
                     tr("The document has been modified.\n"
                        "Do you want to save your changes?"),
                     QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (ret == QMessageBox::Save)
            return save();
        else if (ret == QMessageBox::Cancel)
            return false;
    }
    return true;
}*/

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    //if (!fileName.isEmpty())
        //loadFile(fileName);
}
/*
void MainWindow::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    QTextStream in(&file);
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    textEdit->setPlainText(in.readAll());
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
}
*/
void MainWindow::print()
{
    #ifndef QT_NO_PRINTER
    QPrinter printer(QPrinter::ScreenResolution);
    QPrintPreviewDialog dlg(&printer);
    Preview_Print view;
    view.setModel(ui->spreadsheet->model());
    connect(&dlg, SIGNAL(paintRequested(QPrinter*)), &view, SLOT(print(QPrinter*)));
    dlg.exec();
    #endif
}

void MainWindow::showAbout()
{
    QMessageBox::about(this, "About C.S. Excel",about_Excel);
}


void MainWindow::on_spreadsheet_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    QString temp1;
    temp1.setNum(currentRow+1);
    ui->actual_cell->setText("Cell: "+ui->spreadsheet->horizontalHeaderItem(currentColumn)->text()+temp1);

    if(ui->spreadsheet->item(currentRow,currentColumn))
        ui->Formule_Bar->setText(ui->spreadsheet->item(currentRow,currentColumn)->text());
    else
        ui->Formule_Bar->setText("");

}

void MainWindow::on_spreadsheet_itemChanged(QTableWidgetItem *item)
{
    ui->Formule_Bar->setText(item->text());
}

void MainWindow::on_button_print_clicked()
{
   // printAction = new QAction(tr("&Print"), this);

    //connect(ui->button_print, SIGNAL(click()), this, SLOT(print()));
    print();
}

void MainWindow::on_actionPrint_triggered()
{
    print();
}

void MainWindow::on_actionAbout_C_S_Excel_triggered()
{
    showAbout();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_pushButton_clicked()
{
    open();
}

void MainWindow::on_actionOpen_triggered()
{
    open();
}

void MainWindow::on_button_save_clicked()
{
    save();
}

void MainWindow::on_actionSave_triggered()
{
    save();
}
