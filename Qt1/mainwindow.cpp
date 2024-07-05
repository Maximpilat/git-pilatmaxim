#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pen = new QPen();
    color = Qt::red;
    penPosition = new QPoint(0,0);
    pen->setColor(color);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pen;
    delete penPosition;
}

void readfile(std::vector<int>& data_,const std::string& file_name)
{
    std::ifstream fin(file_name);
    int tmp;
    while(fin >> tmp){
        data_.push_back(tmp);
    }
}

void MainWindow::on_openButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(0,"Open dialog","","*.txt");
    readfile(this->data,file_name.toStdString());
    this->update();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    if(this->data.empty())
        return;

    double a;
    double b = (double)(this->width())/(*std::max_element(this->data.begin(),this->data.end()));
    int penWidth = (this->height())/(this->data.size());
    pen->setWidth(50);

    QPainter painter(this);
    painter.begin(this);

    painter.setPen(*pen);
    a = penWidth / 2;
    for(int i = 0; i < this->data.size();++i){
        painter.drawLine(0,a,this->data[i]*b,a);
        a += penWidth;
    }
    painter.end();
}
