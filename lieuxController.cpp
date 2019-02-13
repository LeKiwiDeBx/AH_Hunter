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
    model = m;
}

void lieuxController::invocator()
{
    // cout << "Appel invocator (command's trigger)\n";
}

void lieuxController::useCaseController(const string action)
{
    ;
}

void lieuxController::useCaseController()
{
    string roomName("Room");
    int roomNumber(1);

    // cout << "Appel useCaseController (command's parameters client/action-objet)" << endl;

    /*
			algo d'appel des model/view
			*/
    /* attache une vue de saisie */
    model.attach(this->view);
    // cout << "attache une vue de saisie" << endl;

    //modelSubject.update();
    //myIntro.writeIntro();

    /* récupère les data de la vue */
    model.getdata(this->view);
    // cout << "récupère les data de la vue" << endl;

    /* voir la zone texte statique [vue du contexte]*/
    view.presentData(roomName, roomNumber);
    view.presentData(model.getdata(this->view));

    // cout << "voir la zone texte statique [vue du contexte]" << endl;

    /*traitement des data */
    /* lieux_controller::doSomething() | model::modify() */

    /* mise à jour de toutes les vues [pulling] */
    model.notify();
    // cout << "mise à jour de toutes les vues [pulling] " << endl;
}

void lieuxController::modifyModel()
{
    // cout << "Appel modifyModel (update data) \n";
}

void lieuxController::presentData()
{
    // cout << "Appel presentData   (update directly the view) \n";
    this->view.presentData();
}
