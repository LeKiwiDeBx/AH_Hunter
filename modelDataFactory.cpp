#include "main.h"

subjectDataObject *modelDataFactory::getSDO(dataType dt)
{
    int id = 0; // <--------||DEBUG !!!!  ///////////////
    std::string sId = std::to_string(id);
    subjectDataObject *sDO = doMakeSDO(id, dt);
    // ..... initialisation du sDO
    ifstream ifs("configAHH.json");
    reader.parse(ifs, valJson);
    sDO->setId(sId);
    // std::string objectType = valJson[]
    // ..... mise en liste
    mapObj.insert(std::make_pair<int, subjectDataObject &>(id sDO));
    return sDO;
}

subjectDataObject *modelDataFactory::doMakeSDO(int key, dataType dt) const
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
}