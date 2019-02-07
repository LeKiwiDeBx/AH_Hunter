
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
// lecture fichier json [model]
#include <jsoncpp/json/json.h>
//#include <json.hpp>

#endif // _MAIN_H

class viewDataObserver;
class View;
class subjectDataObject;

enum dataType
{
  DT_roomData,
  DT_objectData
};

class Model
{
public:
  Model(); // subject du pattern observer
  virtual ~Model(){};
  virtual void setdata() = 0;
  virtual void modify() = 0;
  virtual void demand() = 0;
  virtual void update() = 0;
  virtual void getdata(const View &) = 0;
  virtual void attach(View &) = 0;
  virtual void detach() = 0;
  virtual void notify() = 0;

protected:
  subjectDataObject *sDO;
};

class roomModel : public Model
{
public:
  roomModel();
  ~roomModel(){};
  virtual void setdata();
  virtual void modify();
  virtual void demand();
  virtual void update();
  virtual void getdata(const View &);
  virtual void getdata();
  virtual void attach(View &);
  virtual void detach();
  virtual void notify();

protected:
  std::list<View *> m_list;
  typedef std::list<View *>::iterator iterator;
  typedef std::list<View *>::const_iterator const_iterator;
};

class objectModel : public Model
{
public:
  objectModel();
  ~objectModel(){};
  virtual void setdata();
  virtual void modify();
  virtual void demand();
  virtual void update();
  virtual void getdata();
  virtual void detach();
  virtual void notify();

protected:
  std::list<View *> m_list;
  typedef std::list<View *>::iterator iterator;
  typedef std::list<View *>::const_iterator const_iterator;
};

class View
{
public:
  View();
  virtual ~View(){};
  virtual void client();
  virtual void receptor() const;
  virtual void modifyModel();
  virtual void presentData();
  virtual void presentData(const std::string, const int);
  virtual void update();
};

class viewDataObserver : public View
{
public:
  viewDataObserver();
  virtual ~viewDataObserver(){};
  virtual void update();

protected:
  bool stateObserver;
};

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

protected:
  virtual void getdata(){};
  bool stateSubject;
};

class roomData : public subjectDataObject
{
public:
  roomData(){};
  virtual ~roomData(){};
  roomData(const roomData &){};
  virtual void setName(const std::string){};
  virtual void setId(const std::string){};
  virtual std::string getName() { return ""; };
  virtual std::string getId() { return ""; };

private:
  std::string name, id;
};

class objectData : public subjectDataObject
{
public:
  objectData(){};
  virtual ~objectData(){};
  objectData(const objectData &){};
  virtual void setName(const std::string);
  virtual void setId(const std::string);
  virtual std::string getName() { return ""; };
  virtual std::string getId() { return ""; };

private:
  std::string name, id;
};

class Controller
{
public:
  Controller();
  virtual ~Controller(){};
  virtual void invocator() = 0;
  virtual void useCaseController() = 0;
  virtual void modifyModel() = 0;
  virtual void presentData() = 0;
};

class lieuxController : public Controller
{
public:
  explicit lieuxController(View &v);
  explicit lieuxController(const roomModel &m, const View &v);
  virtual ~lieuxController(){};
  virtual void invocator();
  virtual void useCaseController();
  virtual void modifyModel();
  virtual void presentData();

private:
  View view;
  roomModel model;
};

class DataFactory
{
  Json::Reader reader;
  Json::Value valJson;

private:
  subjectDataObject *sDO;

public:
  DataFactory(){};
  virtual ~DataFactory(){};
  virtual subjectDataObject *getSDO(dataType); //contient algo pour construire l'objet

protected:
  typedef std::map<int, subjectDataObject> MapObj;
  MapObj mapObj;
  typedef std::map<int, subjectDataObject>::const_iterator mapObjIterator;
  //Patron de methode : getDSO ci dessous algorithme
  virtual bool readJson();
  virtual void doSetData();
  virtual subjectDataObject *doMakeSDO(int, dataType); //factory
  virtual void mapSDO(const std::string /* keys*/, subjectDataObject *);
};

class intro
{
public:
  Json::Reader reader;
  Json::Value valJson;

  intro();
  virtual ~intro(){};
  virtual void writeIntro();
};