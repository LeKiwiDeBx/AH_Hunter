#include "main.h"
/**
 * @brief Construct a new lieux Controller::lieux Controller object
 *               constructeur simple 
 * @todo to trash !??
 * @param v 
 */
lieuxController::lieuxController(View &v)
{ // std::cout << "Appel constructeur lieuxController (attach a view)\n";
    static bool onLoad = true;
    if (onLoad)
    {
        view = v;
    }
}
/**
 * @brief Construct a new lieux Controller::lieux Controller object
 * @pattern MVP
 * @todo voir comment utiliser le onLoad, kikadezidees?
 * @param m roomModel
 * @param v  view vue 
 */
lieuxController::lieuxController(const roomModel &m, const View &v)
{ // cout << "Appel constructeur lieuxController (attach a view)\n";
    static bool onLoad = true;
    if (onLoad)
    {
        setView(v);
        setModel(m);
    }
}
lieuxController::~lieuxController()
{
}

/**
 * @brief affecte la vue
 * @todo tester la validité du param
 * @param v la vue
 */
void lieuxController::setView(const View &v)
{
    view = v;
}
/**
 * @brief affecte le model
 * @todo tester la validité du param
 * @param m le modèle
 */
void lieuxController::setModel(const roomModel &m)
{ // cout << "passage lieuxController::setModel\n";
    model = m;
}
/**
 * @brief fonction encore mysterieuse, pourquoi j'ai voulu ça???
 * @todo rechercher dans un pattern AkoiSaSert
 */
void lieuxController::invocator()
{ // cout << "Appel invocator (command's trigger)\n";
}
/**
 * @brief fonction dont le but est declencher une action particulière du contolleur
 * @todo plein de chose!
 * @param action 
 */
void lieuxController::useCaseController(const std::string action)
{
}
/**
 * @brief presente la mécanique d'ordonancement de la vue et du model
 * @pattern MVP ici le Presenter
 * @todo cf au commentaire
 *                et faire la boucle d'ordonancement
 */
void lieuxController::useCaseController()
{
    /* attache une vue de saisie */
    extern bool enBoucle;

    while (enBoucle)
    {
        model.attach(this->view);
        /* récupère les data de la vue qui a une reponse du client */
        // model.getdata(this->view);
        /* voir la zone texte statique [vue du contexte]*/
        //view.presentData(roomName, roomNumber);
        view.presentData(model.getdata(this->view));
        // appel des interactions avec la vue
        view.receptor();
        /*traitement des data */
        std::string rep{view.modifyModel()};
        // texte consequence de la reponse
        view.presentData(model.getdata(this->view)->getData("Consequence", rep), 0);
        // on fait rien sur rep mais il faudra vérifier que cela puisse être un nombre valide
        model.setdata(rep);
        // update du model
        model.update();
        /* mise à jour de toutes les vues [pulling] */
        model.notify();
        //retour à la nouvelle vue
        // il faut récupérer la nouvelle vue =>  void viewDataObserver::update(subjectDataObject *sDO)
        // setView(view);
        setView(this->view);
    }
}
/**
 * @brief modifie le sDO en cours (pointeur sur roomData par exemple)
 * 
 */
void lieuxController::modifyModel()
{
    model.setdata(view.modifyModel());
}
/**
 * @brief appel directe sans parametre de la vue
 * @todo prevoir un comportement par defaut de la vue
 *                pour l'instant ne fait rien :))
 */
void lieuxController::presentData()
{ // std::cout << "Appel presentData   (update directly the view) \n";
    this->view.presentData();
}
