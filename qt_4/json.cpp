#include "json.h"

bool isCorrectExtension(std::string &file_name)
{
    int dote = file_name.find_last_of(".");
    return file_name.substr(dote+1) == "json";
}

bool isEmpty(std::string& file_name)
{
    return file_name.empty();
}

bool isCorrectStructure(nlohmann::json& json_)
{
    if(json_.is_array())
    {
        if(!json_.empty())
        {
            for (nlohmann::json::iterator it = json_.begin(); it != json_.end(); ++it)
            {
                if(!it->is_number_integer()){
                    QMessageBox::information(nullptr, "mistake", ".json hasn't int elements");
                    qDebug() << ".json hasn't int elements";
                    return false;
                }
            }
        }
        else{
            QMessageBox::information(nullptr, "mistake", ".json is empty");
            qDebug() <<  ".json is empty";
            return false;
        }
    }
    else{
        QMessageBox::information(nullptr, "mistake", ".json isn't correct(it isn't array");
        qDebug() << ".json isn't correct(it isn't array)";
        return false;
    }
    return true;
}

nlohmann::json MakeJson(std::string& file_name)
{
    if(!isEmpty(file_name))
    {
        if(isCorrectExtension(file_name))
        {
            std::ifstream in(file_name);
            if(in.is_open())
            {
                nlohmann::json file = nlohmann::json::parse(in);
                in.close();
                if(isCorrectStructure(file))
                {
                    return file;
                }
                else{
                    QMessageBox::information(nullptr, "mistake", "problem structure");
                    qDebug() <<  "problem structure";
                }
            }
            else{
                QMessageBox::information(nullptr, "mistake", "cannot open");
                qDebug() <<  "cannot open";
            }
        }
        else{
            QMessageBox::information(nullptr, "Mistake", "it isn't .json file");
            qDebug() <<  "it isn't .json file";
        }
    }
    else{
        QMessageBox::information(nullptr, "mistake", "is empty file name");
        qDebug() << "is empty file name";
    }
    nlohmann::json Empty;
    return Empty;
}
