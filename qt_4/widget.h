#ifndef WIDGET_H
#define WIDGET_H

#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <QPainter>
#include <QLineF>
#include <QString>
#include <QWidget>
#include <QObject>
#include <QWidget>
#include <QMessageBox>
#include "json.hpp"
#include "json.h"

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget();
    ~Widget();
    void setData(std::vector<int>&);
    void setDataFromJson(std::string&);
public slots:
    void SlotSignalToGiveVector();
    void SlotToSaveFile(QString&);
    void SlotAddNum(int);
    void SlotEraseNum(int);
signals:
    void SignalGiveVector(std::vector<int>&);
protected:
    void paintEvent(QPaintEvent* event);
private:
    std::vector<int> data;
    QPen* pen;
    QColor color;
    QPoint* penPosition;
};

void ReadFile(std::vector<int>&,const std::string&);
#endif // WIDGET_H
