/**
 * -----------------------------------------------------------------------
 * Fichier: main.cpp
 * Projet: AH_Hunter
 * Fichier créé le:  01-02-2018 à 19:19:31
 * Version:  0.01 \u03B1
 *                              
 * Auteur: jean °} LeKiwiDeBx 
 *                             
 * -----------------------------------------------------------------------
		    present an adventure text game
  ___                                                       
 -   -_, _-_-            ,,                  ,              
(  ~/||    /,            ||                 ||              
(  / ||    || __         ||/\\ \\ \\ \\/\\ =||=  _-_  ,._-_ 
 \/==||   ~||-  -        || || || || || ||  ||  || \\  ||   
 /_ _||    ||===||       || || || || || ||  ||  ||/    ||   
(  - \\,  ( \_, |        \\ |/ \\/\\ \\ \\  \\, \\,/   \\,  
		`          _/                               
  
 * ------------------------------------------------------------------------                                                            
 */

#include "main.h"

using namespace std;

class intro
{ // maistson

	Json::Reader reader;
	Json::Value valJson;

  public:
	intro()
	{
		//using namespace Json;
		ifstream ifs("configAHH.json");
		reader.parse(ifs, valJson);
		cout << "\nWelcome to fabulous hunting game Adolph Hitler and other    "
				"bastards\n\t=- version \u03B1 0.001 KiwiTroBien  -="

			 << endl;
	}

	~intro()
	{
	}
	void writeIntro()
	{
		cout << "Introduction: " << valJson["Main"]["Introduction"].asString() << endl;
	}
};
//////////////////////////// viewDataObserver /////////////////////////////////////////////

viewDataObserver::viewDataObserver()
{
	cout << "Appel du constructeur viewDataObserver\n";
}

void viewDataObserver::update()
{
	cout << "Appel Update de la liste des viewDataObserver";
}

/////////////////////////////// Controller ////////////////////////////////////

Controller::Controller()
{
	cout << "Appel constructeur Controller (build FrontController singleton)\n";
}

lieuxController::lieuxController(View &v)
{
	static bool onLoad = true;
	cout << "Appel constructeur lieuxController (attach a view)\n";
	if (onLoad)
	{
		this->view = v;
		this->view.presentData();
	}
}

lieuxController::lieuxController(const roomModel &m, const View &v)
{
	static bool onLoad = true;
	cout << "Appel constructeur lieuxController (attach a view)\n";
	if (onLoad)
	{
		this->model = m;
		this->view = v;
	}
}

void lieuxController::invocator()
{
	cout << "Appel invocator (command's trigger)\n";
}

void lieuxController::useCaseController()
{
	string roomName("Room");
	int roomNumber(1);

	cout << "Appel useCaseController (command's parameters client/action-objet) "
			"\n";
	/*
			algo d'appel des model/view
			*/
	/* attache une vue de saisie */
	model.attach(this->view);
	cout << "attache une vue de saisie" << endl;

	//modelSubject.update();
	//myIntro.writeIntro();
	/* voir la zone texte statique [vue du contexte]*/
	view.presentData(roomName, roomNumber);
	cout << "voir la zone texte statique [vue du contexte]" << endl;

	/* récupère les data de la vue */
	model.getdata(this->view);
	cout << "récupère les data de la vue" << endl;

	/*traitement des data */
	/* lieux_controller::doSomething() | model::modify() */

	/* mise à jour de toutes les vues [pulling] */
	model.notify();
	cout << "mise à jour de toutes les vues [pulling] " << endl;
}

void lieuxController::modifyModel()
{
	cout << "Appel modifyModel (update data) \n";
}

void lieuxController::presentData()
{
	cout << "Appel presentData   (update directly the view) \n";
	this->view.presentData();
}

///////////////////// Class mock test ///////////////////////////////
class dataObjet
{
  public:
	string name;
	int value;

  private:
	/* data */

  public:
	dataObjet(const string, const int v /* args */);
	~dataObjet();
};

dataObjet::dataObjet(const string s, const int n /* args */)
{
	this->name = s;
	this->value = n;
}

dataObjet::~dataObjet()
{
}
/////////////////////////////////////////////////////////////////////

int main(int argv, char *argc[])
{
	intro myIntro;
	viewDataObserver inputView;
	roomModel modelSubject;
	dataObjet data_1("room1", 100), data_2("room2", 200);
	lieuxController lieux_controller(modelSubject, inputView);

	//myIntro.writeIntro();
	lieux_controller.useCaseController();
	// zone test
	cout << data_1.name << " " << data_1.value << endl;
	cout << data_2.name << " " << data_2.value << endl;
	typedef std::map<int, dataObjet> MapObj;
	typedef map<int, dataObjet>::const_iterator mapObjIterator;
	MapObj mapObj;
	mapObj.insert(make_pair(1, data_1));
	/* mapObj.insert(pair<int, dataObjet &>(1, data_1));
	mapObj.insert(pair<int, dataObjet &>(2, data_2)); */

	//mapObj.insert(make_pair<int, dataObjet&>(2, data_2));
	//c++17
	/* 
	mapObj.insert({1, data_1}); 
	mapObj.insert({2, data_2}); */

	/* mapObj.insert(MapObj::value_type(1, data_1));
	mapObj.insert(MapObj::value_type(2, data_2));
 */
	for (mapObjIterator it = mapObj.begin(); it != mapObj.end(); it++)
	{
		cout << it->first << " " << it->second.name << " " << it->second.value << endl;
	}

	/*
	up 15/01/2019
	LeKiwideBx
	*/
}
