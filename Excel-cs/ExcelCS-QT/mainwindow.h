#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTableWidget>
#include "Save_Load.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(int row, int column,QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    void load_matrix();

    void on_SpreadSheet_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    void on_SpreadSheet_itemChanged(QTableWidgetItem *item);

    void on_Button_Print_clicked();

    void on_actionPrint_triggered();

    void on_Button_New_clicked();

    void on_actionNew_triggered();

    void on_actionQuit_triggered();

    void on_actionAbout_Excel_CS_v_3_14_16_triggered();

    void on_Button_Save_clicked();

    void on_actionSave_triggered();

    void on_Button_Open_clicked();

private:
    Ui::MainWindow *ui;
    matrix m_matrix;
    SyntaxAnalizer m_parse;
    Save_Load m_document;
};

#endif // MAINWINDOW_H
