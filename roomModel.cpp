#include "main.h"

using namespace std;

roomModel::roomModel()
{
    cout << "Appel constructeur de roomModel\n";
    // ici on récupère les datas de configAHH.json
    // la roomModel doit être créée par une factory

    // la roomModel doit créée sa roomData correspondant appel la factory
    DataFactory *doRoomData = new DataFactory();

    // la roomModel demande à la roomData de se peupler des data de configAHH.json
    // et obtient un pointeur sur la roomData
    this->sDO = doRoomData->getSDO(DT_roomData);
}

void roomModel::modify(){};

void roomModel::setdata(const std::string vReceptor)
{
    cout << "set des data suite appel model::setdata\n";
    notify();
};

subjectDataObject *roomModel::getdata(const View &v)
{
    //v.receptor();
    return sDO;
};

void roomModel::getdata()
{
    // récupère les données du roomData
    sDO->getName();
};

void roomModel::demand(){};

void roomModel::update()
{
    cout << "update direct (manipulates) des data du model suite appel du presenter [qui a le role du controller]\n";
}

void roomModel::attach(View &v)
{
    //viewDataObserver *v;
    this->m_list.push_back(&v);
}

void roomModel::detach() {}

void roomModel::notify()
{
    //pour chaque observateur on demande de faire update option: PULL (tiré)
    iterator itb = m_list.begin();
    const_iterator ite = m_list.end();

    for (; itb != ite; ++itb)
    {
        (*itb)->update();
    }
    // o.update(this) ;
}