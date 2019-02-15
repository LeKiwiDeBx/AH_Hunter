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
    //sDO->setId(valJson["Room"][sId].asString());
    sDO->setName(valJson["Room"][sId]["Texte"].asString());
    // debug
    std::cout << sDO->getName() << std::endl;
};

void DataFactory::mapSDO(const std::string s, subjectDataObject *sDO)
{
    mapObj.insert(std::make_pair<int, subjectDataObject &>(0, *sDO));
};