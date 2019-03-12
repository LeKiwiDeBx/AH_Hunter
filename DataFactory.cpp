#include "main.h"

subjectDataObject *DataFactory::getSDO(dataType dt, int id)
{ // std::cout << "DataFactory::getSDO" << std::endl;

    //  patron de methode

    this->readJson();
    auto ind{1};
    //faire pour tous les sDO (ie: roomData)
    for (Json::Value::const_iterator it = valJson["Room"].begin(); it != valJson["Room"].end(); ++it, ind++)
    {
        // faire un pointeur sDO sur roomData (ie new roomData)
        sDO = doMakeSDO(id, dt);
        // renseigner le sDO
        this->doSetData(it, sDO);
        // ajouter dans un mapObj map
        this->mapSDO(ind, sDO);
    }
    // DEBUGDEBUGDEBUGDEBUGDEBUGDEBUG            //////////////////////////
    // devrait retourner le pointeur sur le premier du map , cad indice 1
    return mapObj.find(id)->second;
    //return sDO;
};

subjectDataObject *DataFactory::doMakeSDO(int key, dataType dt)
{ // std::cout << "DataFactory::doMakeSDO" << std::endl;
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

void DataFactory::doSetData(Json::ValueConstIterator it, subjectDataObject *data)
{ // data->setId(valJson["Room"][sId])
    data->setId(it.key().asString());
    std::string sId = data->getId();
    data->setName(valJson["Room"][sId]["Texte"].asString());
    std::string sName = data->getName();
    data->setAllData(valJson["Room"][sId]);

    // std::cout << "DataFactory::doSetData ==>setAllData: " << data->getAllData("Texte") << std::endl;
    // std::cout << "DataFactory::doSetData ==>setAllData: " << data->getAllData("Question") << std::endl;
    // std::cout << "DataFactory::doSetData Id: " << sId << std::endl;
    // std::cout << "DataFactory::doSetData Name: " << sName << std::endl;
    // std::cout << valJson["Room"][sId]["Texte"] << std::endl;
    // std::cout << valJson["Room"][sId].get("Reponse", "nuke") << std::endl;
    // std::cout << valJson["Room"][sId].getMemberNames()[0] << std::endl;
    // std::cout << valJson["Room"][sId].getMemberNames()[1] << std::endl;
    // std::cout << valJson["Room"][sId].getMemberNames()[2] << std::endl;
    // std::cout << valJson["Room"][sId].getMemberNames()[3] << std::endl;
    // std::cout << valJson["Room"][sId].getMemberNames()[5] << std::endl;
    //exit(0);
    // sDO->setId(valJson["Room"][sId].asString());
    //
    // for (Json::Value::const_iterator it = valJson["Room"].begin(); it != valJson["Room"].end(); ++it)
    // {
    //     std::cout << it.key().asString() << "--> " << '\n';
    //     std::string s = it.key().asString();
    //     for (Json::Value::const_iterator it = valJson["Room"][s].begin(); it != valJson["Room"][s].end(); ++it)
    //         if (it.key().asString().compare("Reponse") == 0)
    //         {
    //             std::cout << it.key().asString() << " " << std::endl;
    //             for (unsigned int k = 0; k < valJson["Room"][s]["Reponse"].size(); k++)
    //             {
    //                 std::cout << "-->" << valJson["Room"][s]["Reponse"][k] << '\n';
    //             }
    //         }
    // }
    // sDO->setName(valJson["Room"][sId]["Texte"].asString());
    // std::cout << sDO->getName() << std::endl;
};

void DataFactory::mapSDO(const int key, subjectDataObject *sDO)
{ // std::cout << "indice des objet mappés "
    //using std::make_pair;
    // mapObj.insert(std::make_pair<int, subjectDataObject &>(0, *sDO));
    mapObj.insert(std::make_pair(key, sDO));
    // debug voir ce qu'il ya dans mapObj
    // for (mapObjIterator it = mapObj.begin(); it != mapObj.end(); it++)
    // {
    //     std::cout << "indice des objet mappés " << it->first << "--Id: " << it->second->getId() << "-- Texte: " << it->second->getName() << std::endl;
    // }
};