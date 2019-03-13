#include "main.h"
/*********
 * 
 *               DRAFT  DRAFT  DRAFT  DRAFT  DRAFT  DRAFT  DRAFT  DRAFT  DRAFT  DRAFT  DRAFT  DRAFT  DRAFT  
 * 
 *               NOT YET IMPLEMENTED  NOT YET IMPLEMENTED  NOT YET IMPLEMENTED  NOT YET IMPLEMENTED
 * 
 *               DRAFT  DRAFT  DRAFT  DRAFT  DRAFT  DRAFT  DRAFT  DRAFT  DRAFT  DRAFT  DRAFT  DRAFT  DRAFT  
 * /
 

/**
 * @brief Construct a new object Model::object Model object
 *                 Creation d'une Factory pour des objectData (il appartiendront au roomData?)
 *                   
 * @todo unique_pointer<> sur new
 *               verifier le succes du new
 */
objectModel::objectModel()
{
    DataFactory *doObjectData = new DataFactory();
    doObjectData->getSDO(DT_objectData);
}
/**
 * @brief 
 * 
 */
void objectModel::modify(){};
/**
 * @brief 
 * 
 */
void objectModel::setdata()
{ // std::cout << "set des data suite appel model::setdata\n";
    notify();
};
/**
 * @brief 
 * 
 */
void objectModel::getdata(){};
/**
 * @brief 
 * 
 */
void objectModel::demand(){};
/**
 * @brief 
 * 
 */
void objectModel::update()
{ //std::cout << "update direct (manipulates) des data du model suite appel du presenter [qui a le role du controller]\n";
}
/**
 * @brief 
 * 
 */
void objectModel::attach()
{ //viewDataObserver *v;
}
/**
 * @brief 
 * 
 */
void objectModel::detach() {}
/**
 * @brief 
 * 
 */
void objectModel::notify()
{ //pour chaque observateur on demande de faire update option: PULL (tiré)
    iterator itb = m_list.begin();
    const_iterator ite = m_list.end();

    for (; itb != ite; ++itb)
    {
        (*itb)->update();
    }
}