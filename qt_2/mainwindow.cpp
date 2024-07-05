#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Pen = new QPen();
    PenPos = new QPoint(0, 0);
    Pen->setColor(Qt::red);

    this->update();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete Pen;
    delete PenPos;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    if (Stack.isEmpty())
        return;
    std::vector<int> Data;
    Stack.toVector(Data);
    int MaxElement = INT_MIN;
    for (auto i : Data)
        if (i > MaxElement)
            MaxElement = i;
    double Step = double(this->width() / MaxElement);
    int Ofset = (this->height()) / (Data.size());
    double Y = Ofset / 2;
    Pen->setWidth(20);
    QPainter Painter(this);
    Painter.begin(this);
    Painter.setPen(*Pen);
    for(int i = 0; i < Data.size(); i++){
        Painter.drawLine(0, Y, Data[i] * Step, Y);
        Y += Ofset;
    }
    Painter.end();
}

void MainWindow::on_PopButton_clicked()
{
    Stack.Pop();
    this->update();
}


void MainWindow::on_PushButton_clicked()
{
    int Value = ui->spinBox->value();
    Stack.Push(Value);
    this->update();
}

void MainWindow::on_InputData_clicked()
{
    QString File = QFileDialog::getOpenFileName(0, "Open dialog", "", "*.txt");
    std::ifstream fin(File.toStdString());
    int Number;
    while (!Stack.isEmpty())
        Stack.Pop();
    while (fin >> Number)
        Stack.Push(Number);
    this->update();
}


