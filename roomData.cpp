#include "main.h"

void roomData::setName(const std::string s)
{
    if (!s.empty())
        name = s;
    else
        name = "unknown";
}

void roomData::setId(const std::string s)
{
    // for (Json::Value::const_iterator it = DataFactory::valJson["Room"].begin(); it != DataFactory::valJson["Room"].end(); ++it)
    // {
    //     cout << it.key().asString() << "--> " << '\n';
    //     std::string s = it.key().asString();
    //     for (Json::Value::const_iterator it = DataFactory::valJson["Room"][s].begin(); it != DataFactory::valJson["Room"][s].end(); ++it)
    //         if (it.key().asString().compare("Reponse") == 0)
    //         {
    //             cout << it.key().asString() << " " << endl;
    //             for (unsigned int k = 0; k < DataFactory::valJson["Room"][s]["Reponse"].size(); k++)
    //             {
    //                 cout << "-->" << DataFactory::valJson["Room"][s]["Reponse"][k] << '\n';
    //             }
    //         }
    // }
    this->id = s;
}

std::string roomData::getName()
{
    return (this->name);
}
std::string roomData::getId()
{
    return id;
}