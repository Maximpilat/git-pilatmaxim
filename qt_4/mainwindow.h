#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <fstream>
#include <filesystem>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include "json.hpp"
#include "widget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ReadJson(std::string&);
    void ReadJson(QString&);

public slots:
    void SlotPrintVectorFromWidget(std::vector<int>&);
signals:
    void SignalForPrint();
    void SignalPushNum(int);
    void SignalErasehNum(int);
    void SignalFileNameToSave(QString&);
private slots:
    void on_openAction_triggered();

    void on_saveHowAction_triggered();

    void on_addButton_clicked();

    void on_eraseButton_clicked();

private:
    Ui::MainWindow *ui;
    Widget* widget;
};
#endif // MAINWINDOW_H
