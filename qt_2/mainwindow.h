#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include <QLineF>
#include <QString>
#include <QFileDialog>
#include <vector>
#include <fstream>
#include "mystack.h"

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

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_PopButton_clicked();

    void on_PushButton_clicked();

    void on_InputData_clicked();

private:
    MyStack Stack;
    QPen *Pen;
    QPoint *PenPos;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
