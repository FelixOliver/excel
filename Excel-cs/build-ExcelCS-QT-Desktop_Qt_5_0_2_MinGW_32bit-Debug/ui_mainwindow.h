/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionPrint;
    QAction *actionQuit;
    QAction *actionAbout_Excel_CS_v_3_14_16;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *Button_New;
    QPushButton *Button_Save;
    QPushButton *Button_Open;
    QPushButton *Button_Print;
    QSpacerItem *horizontalSpacer;
    QSplitter *splitter;
    QLabel *actual_cell;
    QLineEdit *Formule_Bar;
    QTableWidget *SpreadSheet;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(734, 517);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icono 3.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/nuevo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon1);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Abrir.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon2);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/guardar.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon3);
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/imprimir.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon4);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/salir.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon5);
        actionAbout_Excel_CS_v_3_14_16 = new QAction(MainWindow);
        actionAbout_Excel_CS_v_3_14_16->setObjectName(QStringLiteral("actionAbout_Excel_CS_v_3_14_16"));
        actionAbout_Excel_CS_v_3_14_16->setIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Button_New = new QPushButton(centralwidget);
        Button_New->setObjectName(QStringLiteral("Button_New"));
        Button_New->setCursor(QCursor(Qt::PointingHandCursor));
        Button_New->setIcon(icon1);

        horizontalLayout->addWidget(Button_New);

        Button_Save = new QPushButton(centralwidget);
        Button_Save->setObjectName(QStringLiteral("Button_Save"));
        Button_Save->setCursor(QCursor(Qt::PointingHandCursor));
        Button_Save->setIcon(icon3);

        horizontalLayout->addWidget(Button_Save);

        Button_Open = new QPushButton(centralwidget);
        Button_Open->setObjectName(QStringLiteral("Button_Open"));
        Button_Open->setCursor(QCursor(Qt::PointingHandCursor));
        Button_Open->setIcon(icon2);

        horizontalLayout->addWidget(Button_Open);

        Button_Print = new QPushButton(centralwidget);
        Button_Print->setObjectName(QStringLiteral("Button_Print"));
        Button_Print->setCursor(QCursor(Qt::PointingHandCursor));
        Button_Print->setIcon(icon4);

        horizontalLayout->addWidget(Button_Print);

        horizontalSpacer = new QSpacerItem(395, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        actual_cell = new QLabel(splitter);
        actual_cell->setObjectName(QStringLiteral("actual_cell"));
        actual_cell->setStyleSheet(QLatin1String("color: rgb(0, 0, 255);\n"
"font: 75 10pt \"Kozuka Gothic Pro B\";"));
        splitter->addWidget(actual_cell);
        Formule_Bar = new QLineEdit(splitter);
        Formule_Bar->setObjectName(QStringLiteral("Formule_Bar"));
        splitter->addWidget(Formule_Bar);

        verticalLayout->addWidget(splitter);


        verticalLayout_2->addLayout(verticalLayout);

        SpreadSheet = new QTableWidget(centralwidget);
        SpreadSheet->setObjectName(QStringLiteral("SpreadSheet"));
        SpreadSheet->horizontalHeader()->setDefaultSectionSize(80);
        SpreadSheet->verticalHeader()->setDefaultSectionSize(20);

        verticalLayout_2->addWidget(SpreadSheet);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 734, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionPrint);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionAbout_Excel_CS_v_3_14_16);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Excel CS v. 3.1416", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionPrint->setText(QApplication::translate("MainWindow", "Print", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionAbout_Excel_CS_v_3_14_16->setText(QApplication::translate("MainWindow", "About Excel CS v 3.14.16", 0));
        Button_New->setText(QApplication::translate("MainWindow", "New", 0));
        Button_Save->setText(QApplication::translate("MainWindow", "Save", 0));
        Button_Open->setText(QApplication::translate("MainWindow", "Open", 0));
        Button_Print->setText(QApplication::translate("MainWindow", "Print", 0));
        actual_cell->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
