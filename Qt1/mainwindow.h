#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDialog>
#include <QString>
#include <QPainter>
#include <QFileDialog>
#include <fstream>

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

private slots:
    void on_openButton_clicked();

protected:
    void paintEvent(QPaintEvent*);
private:
    Ui::MainWindow *ui;
    std::vector<int> data;
    QPen* pen;
    QColor color;
    QPoint* penPosition;
};

void readfile(std::vector<int>&,const std::string&);
#endif // MAINWINDOW_H
