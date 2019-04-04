
/**
 * -----------------------------------------------------------------------
 * Fichier: main.h
 * Projet: AH_Hunter
 * Fichier créé le:  03-02-2018 à 19:57:07
 * Version:
 * Auteur: jean ° LeKiwiDeBx °
 * -----------------------------------------------------------------------
 */
#ifndef _MAIN_H
#define _MAIN_H

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <jsoncpp/json/json.h>

class viewDataObserver;
class View;
class subjectDataObject;
class DataFactory;
/**
 * @brief 
 * 
 */
enum dataType
{
  DT_roomData,
  DT_objectData
};
/**
 * @brief subject du pattern observer
 * 
 */
class Model
{
public:
  Model();
  virtual ~Model(){};
  virtual void setdata(const std::string) = 0;
  virtual void modify() = 0;
  virtual void demand() = 0;
  virtual void update() = 0;
  virtual subjectDataObject *getdata(const View &) = 0;
  virtual void attach(View &) = 0;
  virtual void detach() = 0;
  virtual void notify() = 0;

protected:
  subjectDataObject *sDO;
  static int n;
};
/**
 * @brief 
 * 
 */
class roomModel : public Model
{
  DataFactory *doRoomData;

public:
  roomModel();
  ~roomModel(){};
  roomModel(const roomModel &) { std::cout << "constructeur de copie roomModel **************" << std::endl; };
  virtual void setdata(const std::string);
  virtual void modify();
  virtual void demand();
  virtual void update();
  virtual subjectDataObject *getdata(const View &);
  virtual void getdata();
  virtual void attach(View &);
  virtual void detach();
  virtual void notify();

protected:
  std::list<View *> m_list;
  typedef std::list<View *>::iterator iterator;
  typedef std::list<View *>::const_iterator const_iterator;
};
/**
 * @brief pour les objets
 * 
 */
class objectModel : public Model
{
public:
  objectModel();
  ~objectModel(){};
  virtual void setdata(std::string);
  virtual void modify();
  virtual void demand();
  virtual void update();
  virtual void getdata();
  virtual void attach();
  virtual void detach();
  virtual void notify();

protected:
  std::list<View *> m_list;
  typedef std::list<View *>::iterator iterator;
  typedef std::list<View *>::const_iterator const_iterator;
};
/**
 * @brief modèle MVP
 * 
 */
class View
{
  std::string sReceptor;

public:
  View();
  virtual ~View(){};
  virtual void client();
  virtual void receptor();
  virtual std::string modifyModel();
  virtual void presentData();
  virtual void presentData(const std::string, const int);
  virtual void presentData(subjectDataObject *);
  virtual void update(subjectDataObject *);
};
/**
 * @brief a confirmer
 * 
 */
class viewDataObserver : public View
{
public:
  viewDataObserver();
  virtual ~viewDataObserver(){};
  virtual void update(subjectDataObject *);

protected:
  bool stateObserver;
};
/**
 * @brief 'deserialization' des data .json
 * 
 */
class subjectDataObject
{
public:
  subjectDataObject(){};
  virtual ~subjectDataObject(){};
  virtual void attach(){};
  virtual void detach(){};
  virtual bool getStateSubject() { return true; };
  virtual void notify(){};
  virtual void setName(const std::string);
  virtual void setId(const std::string);
  virtual std::string getId() { return ""; };
  virtual std::string getName() { return ""; };
  virtual void setAllData(const Json::Value){};
  virtual std::string getAllData(const std::string) { return ""; };

protected:
  bool stateSubject;
  virtual void getdata(){};
};
/**
 * @brief data pour les room
 * 
 */
class roomData : public subjectDataObject
{
public:
  roomData(){};
  virtual ~roomData(){};
  roomData(const roomData &){};
  virtual void setName(const std::string);
  virtual void setId(const std::string);
  virtual void setAllData(const Json::Value);
  virtual std::string getName();
  virtual std::string getId();
  virtual std::string getAllData(const std::string);
  virtual std::string getRoomNext(const std::string, const std::string);

private:
  std::string name, id;
  Json::Value jAllVal;
};
/**
 * @brief data pour les objets
 * 
 */
class objectData : public subjectDataObject
{
public:
  objectData(){};
  virtual ~objectData(){};
  objectData(const objectData &){};
  virtual void setName(const std::string){};
  virtual void setId(const std::string){};
  virtual std::string getName() { return "I'm DATA"; };
  virtual std::string getId() { return "1"; };

private:
  std::string name, id;
};
/**
 * @brief presenter du MVP
 * 
 */
class Controller
{
public:
  Controller();
  virtual ~Controller();
  virtual void invocator() = 0;
  virtual void useCaseController() = 0;
  virtual void modifyModel() = 0;
  virtual void presentData() = 0;
};
/**
 * @brief presenter pour les lieux
 * 
 */
class lieuxController : public Controller
{
public:
  lieuxController(View &v);
  lieuxController(const roomModel &m, const View &v);
  virtual ~lieuxController();
  virtual void invocator();
  virtual void useCaseController();
  virtual void useCaseController(const std::string action);
  virtual void modifyModel();
  virtual void presentData();
  virtual void setView(const View &v);
  virtual void setModel(const roomModel &m);

private:
  View view;
  roomModel model;
};
/**
 * @brief fabrique de sDO (roomData et ObjectData)
 *@pattern  Patron de methode : getSDO ci-dessous algorithme
                        Factory
 */
class DataFactory
{
  Json::Reader reader;
  Json::Value valJson;

private:
  subjectDataObject *sDO;

public:
  DataFactory(){};
  virtual ~DataFactory(){};
  virtual subjectDataObject *getSDO(dataType, int id = 1); //contient algo pour construire l'objet

protected:
  typedef std::map<int, subjectDataObject *> MapObj;
  MapObj mapObj;
  typedef std::map<int, subjectDataObject *>::const_iterator mapObjIterator;

  virtual bool readJson();
  virtual void doSetData(Json::ValueConstIterator, subjectDataObject *);
  virtual subjectDataObject *doMakeSDO(int, dataType); //factory
  virtual void mapSDO(const int /* keys*/, subjectDataObject *);
};
/**
 * @brief  akoissaservraimenttesserieux
 * 
 */
class intro
{
public:
  Json::Reader reader;
  Json::Value valJson;

  intro();
  virtual ~intro(){};
  virtual void writeIntro();
};
#endif // _MAIN_H