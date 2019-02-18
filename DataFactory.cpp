#include "main.h"

subjectDataObject *DataFactory::getSDO(dataType dt)
{
    // Draft patron de methode
    int id = 1; // <--------||DEBUG !!!!  /////////////////

    this->readJson();
    sDO = doMakeSDO(id, dt);
    this->doSetData();
    // this->mapSDO("test", sDO);
    return sDO;
};

subjectDataObject *DataFactory::doMakeSDO(int key, dataType dt)
{

    if (key)
    {
        ;
    }
    switch (dt)
    {
    case DT_roomData:
        return new roomData();
        break;
    case DT_objectData:
        return new objectData();
        break;
    default:
        return nullptr;
        break;
    }
};

bool DataFactory::readJson()
{
    std::ifstream ifs("configAHH.json");
    reader.parse(ifs, valJson);
    return true;
};

void DataFactory::doSetData()
{
    std::cout << "DataFactory::doSetData\n";
    std::string sId = "1"; //sDO->getId();

    sDO->setId(valJson["Room"][sId].asString());
    //
    for (Json::Value::const_iterator it = valJson["Room"].begin(); it != valJson["Room"].end(); ++it)
    {
        std::cout << it.key().asString() << "--> " << '\n';
        std::string s = it.key().asString();
        for (Json::Value::const_iterator it = valJson["Room"][s].begin(); it != valJson["Room"][s].end(); ++it)
            if (it.key().asString().compare("Reponse") == 0)
            {
                std::cout << it.key().asString() << " " << std::endl;
                for (unsigned int k = 0; k < valJson["Room"][s]["Reponse"].size(); k++)
                {
                    std::cout << "-->" << valJson["Room"][s]["Reponse"][k] << '\n';
                }
            }
    }
    /////////////////////////////
    sDO->setName(valJson["Room"][sId]["Texte"].asString());
    // debug
    std::cout << sDO->getName() << std::endl;
};

void DataFactory::mapSDO(const std::string s, subjectDataObject *sDO)
{
    mapObj.insert(std::make_pair<int, subjectDataObject &>(0, *sDO));
};