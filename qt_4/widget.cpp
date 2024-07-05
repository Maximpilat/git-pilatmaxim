#include "widget.h"

Widget::Widget()
{
    pen = new QPen();
    color = Qt::red;
    penPosition = new QPoint(0,0);
    pen->setColor(color);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

Widget::~Widget()
{
    delete pen;
    delete penPosition;
}

void ReadFile(std::vector<int>& data_,const std::string& fileName)
{
    std::ifstream fin(fileName);
    int tempNum;
    while(fin >> tempNum)
        data_.push_back(tempNum);
}

void Widget::paintEvent(QPaintEvent *)
{
    if(this->data.empty())
        return;

    double x;
    double y = (double)(this->width())/(*std::max_element(this->data.begin(),this->data.end()));
    int penWidth = 20;
    pen->setWidth(20);

    QPainter painter(this);
    painter.begin(this);
    painter.setPen(*pen);

    x = 20 / 2;
    for(int i = 0; i < this->data.size();++i){
        painter.drawLine(0,x,this->data[i]*y,x);
        x += 20;
    }

    painter.end();
}

void Widget::setData(std::vector<int>& data_)
{
    this->data = data_;
    this->update();
}

void Widget::setDataFromJson(std::string& file_name)
{
    nlohmann::json file = MakeJson(file_name);
    if(!file.empty())
    {
        this->data.clear();
        for (nlohmann::json::iterator it = file.begin(); it != file.end(); ++it)
        {
            this->data.push_back(*it);
        }
        this->update();
    }
    else{
        QMessageBox::information(nullptr, "mistake", "file is empty or have problems");
        qDebug() << "file is empty or have problems";
    }

}

void Widget::SlotSignalToGiveVector()
{
    emit SignalGiveVector(data);
}

void Widget::SlotToSaveFile(QString& file_name)
{
    std::ofstream out(file_name.toStdString());
    out << "[";
    for (int i = 0; i < this->data.size(); ++i){
        if(i != this->data.size() - 1){
            out << this->data[i] <<", ";
        }
        else{
            out << this->data[i];
        }
    }
    out << "]";
    out.close();
}

void Widget::SlotAddNum(int num)
{
    this->data.push_back(num);
    this->update();
    emit SignalGiveVector(this->data);
}

void Widget::SlotEraseNum(int index)
{
    if(index >= 0 and index < this->data.size()){
        this->data.erase(this->data.begin() + index);
        this->update();
        emit SignalGiveVector(this->data);
    }
    else{
        QMessageBox::information(nullptr, "mistake", "bad index");
        qDebug() << "bad index";
    }

}
