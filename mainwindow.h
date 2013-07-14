#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(int row,int column,QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    void print();

    void open();

    void save();

    void showAbout();

    void on_spreadsheet_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    void on_spreadsheet_itemChanged(QTableWidgetItem *item);

    void on_button_print_clicked();



    void on_actionPrint_triggered();

    void on_actionAbout_C_S_Excel_triggered();

    void on_actionExit_triggered();

    void on_pushButton_clicked();

    void on_actionOpen_triggered();

    void on_button_save_clicked();

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
    QString current_file;
};

#endif // MAINWINDOW_H
