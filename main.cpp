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

#include <fstream>
#include <map>
#include <string>
#include <vector>

#include <iterator>
#include <algorithm>
// lecture fichier json [model]
#include <jsoncpp/json/json.h>
#include <json.hpp>

using namespace std;

class intro
{ //"mais on"

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
//////////////////////////// View /////////////////////////////////////////////
View::View()
{
	cout << "Appel du constructeur View\n";
}

void View::client(){
	/*presente les data au client*/
};

void View::receptor() const
{
	/* getline()*/
	string str;
	cout << "getline : ";
	getline(cin, str);
};

void View::modifyModel(
	/* demande au Controller adéquat de modifier les data du model*/){};

void View::presentData()
{
	cout << "View des data jeu /*Bla Bla Bla de presentData de View*/\n";
};

void View::presentData(const string s, const int n)
{
	cout << "View des data jeu /*Bla Bla Bla*/avec param\n";
}

void View::update()
{
}
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

//////////////////////// Model ////////////////////////////////////////////////
Model::Model()
{
	cout << "Appel constructeur Model\n";
}

roomModel::roomModel()
{
	cout << "Appel constructeur de roomModel\n";
}

void roomModel::modify(){};

void roomModel::setdata()
{
	cout << "set des data suite appel model::setdata\n";
	notify();
};

void roomModel::getdata(const View &v)
{
	v.receptor();
};

void roomModel::getdata(){

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

int main(int argv, char *argc[])
{
	intro myIntro;
	viewDataObserver inputView;
	roomModel modelSubject;
	lieuxController lieux_controller(modelSubject, inputView);

	//myIntro.writeIntro();
	lieux_controller.useCaseController();

	/*
	up 04/01/2019
	LeKiwideBx
	*/
}
