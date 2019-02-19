#include "main.h"

subjectDataObject *DataFactory::getSDO(dataType dt)
{
    // Draft patron de methode
    int id = 1; // <--------||DEBUG !!!!  /////////////////

    this->readJson();

    //faire pour tous les sDO (ie: roomData)
    for (Json::Value::const_iterator it = valJson["Room"].begin(); it != valJson["Room"].end(); ++it, id++)
    {
        // faire un pointeur sDO sur roomData (ie new roomData)
        sDO = doMakeSDO(id, dt);
        // renseigner le sDO
        this->doSetData(sDO); // <--- sert a QUOI (debuggage?)
        // ajouter dans un mapObj map
        this->mapSDO(id, sDO);
    }
    // devrait retourner le pointeur sur le premier du map , cad indice 1
    return mapObj.find(1)->second;
    //return sDO;
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

void DataFactory::doSetData(subjectDataObject *data)
{
    std::string sId = data->getId();
    std::string sName = data->getName();
    std::cout << "DataFactory::doSetData Id: " << sId << std::endl;
    std::cout << "DataFactory::doSetData Name: " << sName << std::endl;

    std::cout << valJson["Room"][sId]["Texte"] << std::endl;
    exit(0);
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
    /////////////////////////////
    // sDO->setName(valJson["Room"][sId]["Texte"].asString());
    // // debug
    // std::cout << sDO->getName() << std::endl;
};

void DataFactory::mapSDO(const int key, subjectDataObject *sDO)
{
    // mapObj.insert(std::make_pair<int, subjectDataObject &>(0, *sDO));
    mapObj.insert(std::make_pair<int, subjectDataObject *>(key, *sDO));
};