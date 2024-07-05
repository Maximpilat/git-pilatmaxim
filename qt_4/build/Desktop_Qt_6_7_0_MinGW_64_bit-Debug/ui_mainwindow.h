/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *openAction;
    QAction *saveHowAction;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *text_grid_layout;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *tools_layout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *addButton;
    QLineEdit *addLineEdit;
    QVBoxLayout *verticalLayout_2;
    QPushButton *eraseButton;
    QLineEdit *eraseLineEdit;
    QTextEdit *output_textEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        openAction = new QAction(MainWindow);
        openAction->setObjectName("openAction");
        saveHowAction = new QAction(MainWindow);
        saveHowAction->setObjectName("saveHowAction");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        text_grid_layout = new QHBoxLayout();
        text_grid_layout->setObjectName("text_grid_layout");

        gridLayout->addLayout(text_grid_layout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");

        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        tools_layout = new QHBoxLayout();
        tools_layout->setObjectName("tools_layout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(addButton);

        addLineEdit = new QLineEdit(centralwidget);
        addLineEdit->setObjectName("addLineEdit");
        sizePolicy.setHeightForWidth(addLineEdit->sizePolicy().hasHeightForWidth());
        addLineEdit->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(addLineEdit);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        eraseButton = new QPushButton(centralwidget);
        eraseButton->setObjectName("eraseButton");
        sizePolicy.setHeightForWidth(eraseButton->sizePolicy().hasHeightForWidth());
        eraseButton->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(eraseButton);

        eraseLineEdit = new QLineEdit(centralwidget);
        eraseLineEdit->setObjectName("eraseLineEdit");
        sizePolicy.setHeightForWidth(eraseLineEdit->sizePolicy().hasHeightForWidth());
        eraseLineEdit->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(eraseLineEdit);


        horizontalLayout_2->addLayout(verticalLayout_2);


        tools_layout->addLayout(horizontalLayout_2);

        output_textEdit = new QTextEdit(centralwidget);
        output_textEdit->setObjectName("output_textEdit");

        tools_layout->addWidget(output_textEdit);


        gridLayout->addLayout(tools_layout, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(openAction);
        menu->addAction(saveHowAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        openAction->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        saveHowAction->setText(QCoreApplication::translate("MainWindow", "Save How", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        addLineEdit->setText(QCoreApplication::translate("MainWindow", "number", nullptr));
        eraseButton->setText(QCoreApplication::translate("MainWindow", "Erase", nullptr));
        eraseLineEdit->setText(QCoreApplication::translate("MainWindow", "index", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
