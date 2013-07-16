#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    vector <string> ola={"(","n0","-","n03",")"};
    SyntaxAnalizer ol("34*39+(5/67)-40");

    cout<<endl<<ol.parse()->get_value()<<endl;


    QApplication a(argc, argv);
    MainWindow w(100,100);
    w.show();

    return a.exec();
}
