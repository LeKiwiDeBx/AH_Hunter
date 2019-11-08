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
/**
 *  fonction principale
 */
bool enBoucle = true;

int 
main(int argv, char *argc[])
{
	viewDataObserver inputView;
	roomModel modelSubject;

	// lance le controlleur principal de lieux
	lieuxController lieux_controller(modelSubject, inputView);
	// boucle infernale :))) bootstrap
	/* code */
	lieux_controller.useCaseController();
	// zone test
}
