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
		cout << "Introduction: " << valJson["Introduction"].asString() << endl;
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

void View::receptor()
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
	cout << "View data Debut jeu /*presente les data static*/\n";
};

/////////////////////////////// Controller ////////////////////////////////////

Controller::Controller()
{
	cout << "Appel constructeur Controller (build FrontController singleton)\n";
}

lieuxController::lieuxController(const View &v)
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
		this->model.setdata();
		this->view.presentData();
	}
}

void lieuxController::invocator()
{
	cout << "Appel invocator (command's trigger)\n";
}

void lieuxController::useCaseController()
{
	cout << "Appel useCaseController (command's parameters client/action-objet) "
			"\n";
}

void lieuxController::modifyModel()
{
	cout << "Appel modifyModel (update data) \n";
}

void lieuxController::presentData()
{

	cout << "Appel presentData   (update directly the view) \n";
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

void roomModel::getdata(View &v)
{
	v.receptor();
};

void roomModel::getdata(){

};

void roomModel::demand(){};

void roomModel::update()
{
	cout << "update des data suite appel observer\n";
}

void roomModel::attach() {}

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
	View myView;
	roomModel modelSubject;
	lieuxController lieux_controller(modelSubject, myView);

	modelSubject.update();
	myIntro.writeIntro();

	modelSubject.getdata(myView);
	modelSubject.notify();
	/*
	up 04/01/2019
	*/
}
