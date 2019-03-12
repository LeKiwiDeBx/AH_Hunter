#include "main.h"

using namespace std;

lieuxController::lieuxController(View &v)
{
    static bool onLoad = true;
    // cout << "Appel constructeur lieuxController (attach a view)\n";
    if (onLoad)
    {
        view = v;
        // view.presentData();
    }
}

lieuxController::lieuxController(const roomModel &m, const View &v)
{
    static bool onLoad = true;
    // cout << "Appel constructeur lieuxController (attach a view)\n";
    if (onLoad)
    {
        setView(v);
        setModel(m);
        // model = m;
        // view = v;
    }
}

void lieuxController::setView(const View &v)
{
    view = v;
}

void lieuxController::setModel(const roomModel &m)
{
    // cout << "passage lieuxController::setModel\n";
    model = m;
}

void lieuxController::invocator()
{
    // cout << "Appel invocator (command's trigger)\n";
}

void lieuxController::useCaseController(const string action)
{ //dispatch des getdata de la vue au model adequate

    view.modifyModel();
}

void lieuxController::useCaseController()
{
    string roomName("Room");
    //int roomNumber(1);

    // debug
    typedef enum
    {
        UC_VISITED,
        UC_TEXTE,
        UC_QUESTION,
        UC_REPONSE,
        UC_CONSEQUENCE,
        UC_ROOMNEXT
    } interactionType;

    interactionType useCase(UC_TEXTE);
    //fin debug

    switch (useCase)
    {
    case UC_VISITED:
        /*
        champ visited
        */
        break;
    case UC_TEXTE:
        /* 
        champ Reponse 
        */
        break;
    case UC_QUESTION:
        /*
        champ Question 
        */
        break;
    case UC_REPONSE:
        /*
        champ Texte
        */
        break;
    case UC_CONSEQUENCE:
        /*
        champ Consequence
        */
        break;
    case UC_ROOMNEXT:
        /*
        champ RoomNext
        */
        break;
    default:
        break;
    }
    // cout << "Appel useCaseController (command's parameters client/action-objet)" << endl;

    /*
			algo d'appel des model/view
			*/

    /* attache une vue de saisie */
    model.attach(this->view);
    // cout << "attache une vue de saisie" << endl;

    //modelSubject.update();
    //myIntro.writeIntro();

    /* récupère les data de la vue qui a une reponse du client */
    // model.getdata(this->view);
    // cout << "récupère les data de la vue" << endl;

    /* voir la zone texte statique [vue du contexte]*/
    //view.presentData(roomName, roomNumber);
    view.presentData(model.getdata(this->view));

    // cout << "voir la zone texte statique [vue du contexte]" << endl;
    // appel des interactions avec la vue
    view.receptor();
    /*traitement des data */
    std::string rep{view.modifyModel()};
    // on fait rien sur rep mais il faudra vérifier que cela puisse être un nombre valide
    model.setdata(rep);
    // update du model
    model.update();

    /* lieux_controller::doSomething() | model::modify() */

    /* mise à jour de toutes les vues [pulling] */
    model.notify();
    // cout << "mise à jour de toutes les vues [pulling] " << endl;

    //retour à la nouvelle vue
    // il faut récupérer la nouvelle vue =>  void viewDataObserver::update(subjectDataObject *sDO)
    // setView(view);
}

void lieuxController::modifyModel()
{
    // cout << "Appel modifyModel (update data) \n";
    model.setdata(view.modifyModel());
}

void lieuxController::presentData()
{
    // cout << "Appel presentData   (update directly the view) \n";
    this->view.presentData();
}
