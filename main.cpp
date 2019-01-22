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

/////////////////////////////// main //////////////////////////////////////////
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

	/* cout << data_1.name << " " << data_1.value << endl;
	cout << data_2.name << " " << data_2.value << endl;
	typedef std::map<int, dataObjet> MapObj;
	typedef map<int, dataObjet>::const_iterator mapObjIterator;
	MapObj mapObj;
	mapObj.insert(make_pair(1, data_1)); */

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
	/* for (mapObjIterator it = mapObj.begin(); it != mapObj.end(); it++)
	{
		cout << it->first << " " << it->second.name << " " << it->second.value << endl;
	} */
}
