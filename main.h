/**
 * -----------------------------------------------------------------------
 * Fichier: main.h
 * Projet: AH_Hunter
 * Fichier créé le:  03-02-2018 à 19:57:07
 * Version:
 * Auteur: jean ° LeKiwiDeBx °
 * -----------------------------------------------------------------------
 */
#include <iostream>
#include <list>

class viewDataObserver;
class View;

class Model
{
public:
  Model(); // subject du pattern observer
  virtual ~Model(){};
  virtual void setdata() = 0;
  virtual void modify() = 0;
  virtual void demand() = 0;
  virtual void update() = 0;
  virtual void getdata(View &) = 0;
  virtual void attach(viewDataObserver &) = 0;
  virtual void detach() = 0;
  virtual void notify() = 0;
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
  virtual void getdata(View &);
  virtual void getdata();
  virtual void attach(viewDataObserver &);
  virtual void detach();
  virtual void notify();

protected:
  std::list<viewDataObserver *> m_list;
  typedef std::list<viewDataObserver *>::iterator iterator;
  typedef std::list<viewDataObserver *>::const_iterator const_iterator;
};

class View
{
public:
  View();
  virtual ~View(){};
  virtual void client();
  virtual void receptor();
  virtual void modifyModel();
  virtual void presentData();
};

class viewDataObserver : public View
{
public:
  viewDataObserver();
  virtual ~viewDataObserver(){};
  virtual void update();

protected:
  bool stateObserver;
  /*
   */
};

class subjectDataObject
{
public:
  subjectDataObject();
  virtual ~subjectDataObject(){};
  virtual void attach();
  virtual void detach();
  virtual bool getStateSubject();
  virtual void notify();

protected:
  virtual void getdata();
  bool stateSubject;
};

class roomData : public subjectDataObject
{
public:
  roomData();
  virtual ~roomData(){};
  roomData(const roomData &){};
};

class objectData : public subjectDataObject
{
public:
  objectData();
  virtual ~objectData(){};
  objectData(const objectData &){};
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
  explicit lieuxController(const View &v);
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
