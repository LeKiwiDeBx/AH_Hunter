#include "main.h"
/**
 * @brief  Lit la configuration des room et fabrique un pointeur sur un  subjectDataObject (qui est roomData)
 *  chaque subjectDataObject est renseigné 
 * et ajouté dans un map<key, sDO*> 
 * @pattern patron de methode
 * retourne un pointeur sur  subjectDataObject  sDO* (le premier par defaut)
 * @param type de data peut être roomData ou objectData
 * @return subjectDataObject *
 */
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
    // devrait retourner le pointeur sur le premier du map , cad indice 1
    return mapObj.find(id)->second;
};
/**
 * @brief  fabrique un pointeur sur objet roomData ou objectData
 * @pattern Factory
 * @param ! key: indice inutile ! 
 *                             dt type de data à créée
 * @todo unique pointeur sur new
 *               tester si échec de creation du pointeur
 * @return pointeur  subjectDataObject 
 */
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
/**
 * @brief  parser du json de configuration du jeu
 * ! le nom du fichier est codé en dur!
 * @todo  externaliser le nom du fichier .json
 *                tester si échec de lecture du fichier* 
 * @return true 
 * @return false 
 */
bool DataFactory::readJson()
{
    std::ifstream ifs("configAHH.json");
    reader.parse(ifs, valJson);
    return true;
};
/**
 * @brief renseigne en data le sDO
 * 
 * @param it  itérateur du Json::Value en cours 
 * @param data le sDO à renseigner
 */
void DataFactory::doSetData(Json::ValueConstIterator it, subjectDataObject *data)
{
    data->setId(it.key().asString());
    std::string sId = data->getId();
    data->setName(valJson["Room"][sId]["Texte"].asString());
    std::string sName = data->getName();
    data->setAllData(valJson["Room"][sId]);
};
/**
 * @brief fit le mappage des sDO
 * 
 * @param key indice du mappage (correspond à l'id roomData)
 * @param sDO le pointeur à mapper
 */
void DataFactory::mapSDO(const int key, subjectDataObject *sDO)
{ // std::cout << "indice des objet mappés "
    mapObj.insert(std::make_pair(key, sDO));
};