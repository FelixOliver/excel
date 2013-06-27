#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spreadsheet_itemChanged(QTableWidgetItem *item)
{
    ui->Formule_Bar->setText(item->text().toStdString().c_str());
}

void MainWindow::on_Formule_Bar_textChanged(const QString &arg1)
{
    ui->Formule_bar_txt->setText(ui->Formule_Bar->text().toStdString().c_str());

}
