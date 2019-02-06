#include "main.h"

subjectDataObject *DataFactory::getSDO(dataType dt)
{
    // Draft patron de methode
    int id = 1; // <--------||DEBUG !!!!  ///////////////

    this->readJson();
    sDO = doMakeSDO(id, dt);
    this->doSetData();
    // this->mapSDO("test", sDO);
    return sDO;
};

subjectDataObject *DataFactory::doMakeSDO(int key, dataType dt)
{
    switch (dt)
    {
    case DT_roomData:
        /* code */
        sDO = new roomData();
        break;
    case DT_objectData:
        sDO = new objectData();
    default:
        return NULL;
        break;
        }
    return sDO;
};

bool DataFactory::readJson()
{
    std::ifstream ifs("configAHH.json");
    reader.parse(ifs, valJson);
    return true;
};

void DataFactory::doSetData()
{

    std::string sId = std::to_string(1);
    sDO->setId(sId);
    sDO->setName(valJson["Room"][sId]["Texte"].asString());
    // debug
    //std::cout << sDO->getdata << std::endl;
};

void DataFactory::mapSDO(const std::string s, subjectDataObject *sDO)
{
    mapObj.insert(std::make_pair<int, subjectDataObject &>(0, *sDO));
};