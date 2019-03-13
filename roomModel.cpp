#include "main.h"
/**
 * @brief Construct a new room Model::room Model object
 * ici on récupère les datas de configAHH.json
l * la roomModel doit être créée par une factory
* la roomModel demande à la roomData de se peupler des data de configAHH.json
* et obtient un pointeur sur la roomData
* @todo unique_pointer<> sur le new et verifier le succes du new
 */
roomModel::roomModel()
{
    doRoomData = new DataFactory();
    this->sDO = doRoomData->getSDO(DT_roomData);
}
/**
 * @brief 
 * 
 */
void roomModel::modify(){};
/**
 * @brief appel de la DataFactory pour le nouvel sDO roomData
 * FONCTION BUGGEE confusion id de la room numero de la reponse aux questions
 * @param vReceptor ici c'est le numero choix de reponse ??? 
 * YA DU BUG
 */
void roomModel::setdata(const std::string vReceptor)
{
    auto id{std::stoi(vReceptor)};
    this->sDO = doRoomData->getSDO(DT_roomData, id);
};
/**
 * @brief 
 * retourne le sDO en cours
 * @param v inutile????
 * @return subjectDataObject* 
 */
subjectDataObject *roomModel::getdata(const View &v)
{
    return sDO;
};
/**
 * @brief retourne le nom en cours
 * @todo utile?
 */
void roomModel::getdata()
{
    sDO->getName();
};
/**
 * @brief 
 * 
 */
void roomModel::demand(){};
/**
 * @brief update direct (manipulates) des data du model suite appel du presenter [qui a le role du controller]\n
 * 
 */
void roomModel::update()
{
}
/**
 * @brief s'attache comme sujet au DataObserver (list)
 * @todo faire le distinguo entre view et viewDataObserver?????
 * @param v la vuepour laquelle on s'enregistre
 */
void roomModel::attach(View &v)
{
    this->m_list.push_back(&v);
}
/**
 * @brief se detache de l'observer
 * 
 */
void roomModel::detach() {}
/**
 * @brief pour chaque observateur (view) on demande de faire update option: PULL (tiré)
 * 
 */
void roomModel::notify()
{
    iterator itb = m_list.begin();
    const_iterator ite = m_list.end();

    for (; itb != ite; ++itb)
    {
        (*itb)->update(sDO);
    }
}