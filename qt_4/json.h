#ifndef JSON_H
#define JSON_H
#include <string>
#include <typeinfo>
#include <fstream>
#include <iostream>
#include <QDebug>
#include <QMessageBox>
#include "json.hpp"

nlohmann::json MakeJson(std::string&);
bool isCorrectExtension(std::string&);
bool isEmpty(std::string&);
bool isCorrectStructure(nlohmann::json&);
#endif // JSON_H
