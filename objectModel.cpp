#include "main.h"

using namespace std;

objectModel::objectModel()
{
    // cout << "Appel constructeur de objectModel\n";
    // ici on récupère les datas de configAHH.json
    // la objectModel doit être créée par une factory

    // la objectModel doit créée ObjectData correspondant
    DataFactory *doObjectData = new DataFactory();

    // la objectModel demande à laoObjectData de se peupler des data de configAHH.json
    doObjectData->getSDO(DT_objectData);
}

void objectModel::modify(){};

void objectModel::setdata()
{
    // cout << "set des data suite appel model::setdata\n";
    notify();
};

void objectModel::getdata(){

};

void objectModel::demand(){};

void objectModel::update()
{
    // cout << "update direct (manipulates) des data du model suite appel du presenter [qui a le role du controller]\n";
}

void objectModel::attach()
{
    //viewDataObserver *v;
}

void objectModel::detach() {}

void objectModel::notify()
{
    //pour chaque observateur on demande de faire update option: PULL (tiré)
    iterator itb = m_list.begin();
    const_iterator ite = m_list.end();

    for (; itb != ite; ++itb)
    {
        (*itb)->update();
    }
}