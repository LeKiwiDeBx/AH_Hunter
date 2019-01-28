#include "main.h"

subjectDataObject *DataFactory::getSDO(dataType dt)
{
    // Draft patron de methode
    int id = 0; // <--------||DEBUG !!!!  ///////////////

    this->readJson();
    this->doSetData();
    sDO = doMakeSDO(id, dt);
    this->mapSDO("test", sDO);
    return sDO;
};

subjectDataObject *DataFactory::doMakeSDO(int key, dataType dt) const
{
    switch (dt)
    {
    case DT_roomData:
        /* code */
        return new roomData();
        break;
    case DT_objectData:
        return new objectData();
    default:
        return NULL;
        break;
    }
};

bool DataFactory::readJson()
{
    std::ifstream ifs("configAHH.json");
    std::reader.parse(ifs, valJson);
};

void DataFactory::doSetData()
{

    std::string sId = std::to_string(id);
    sDO->setId(sId);
};

void DataFactory::mapSDO(const std::string s, subjectDataObject *sDO)
{
    mapObj.insert(std::make_pair<int, subjectDataObject &>(id sDO));
};