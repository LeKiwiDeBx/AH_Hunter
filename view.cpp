#include "main.h"
/**
 * @brief Construct a new View:: View object
 * 
 */
View::View()
{
}
/**
 * @brief presente les data au client
 * @todo utile?
 */
void View::client(){};
/**
 * @brief récupère la reponse de la ligne de commande
 *               getline primaire car pour l'instant récupère juste le numero de la reponse
 *  
 */
void View::receptor()
{
    presentData("Votre réponse: ", 0);
    std::getline(std::cin, sReceptor);
};
/**
 * @brief écrit directement une chaine en sortie
 * 
 * @param s la chaîne a écrire
 * @param n pour le moment inutile
 */
void View::presentData(const std::string s, const int n)
{
    std::cout << "****************************************************************************************************" << std::endl;
    std::cout << s << std::endl;
    std::cout << "****************************************************************************************************" << std::endl;
}
/**
 * @brief écriture en sortie du scenario
 * @todo c'est vraiment du brut....Texte Introductif->Question->Reponses possibles
 * @param sDO le sDO concerné (roomData)
 */
void View::presentData(subjectDataObject *sDO)
{
    std::cout << "****************************************************************************************************"
              << std::endl;
    std::cout << "La situation:\n " << sDO->getAllData("Texte") << std::endl;
    std::cout << "****************************************************************************************************" << std::endl;
    std::cout << "La question: \n"
              << sDO->getAllData("Question") << std::endl;
    std::cout << "Les réponses possibles: " << sDO->getAllData("Reponse") << std::endl;
}
/**
 * @brief va retourner la reponse pour le nouveau scenario en cours
 * demande au Controller adéquat de modifier les data du model
 * @todo verifier ce que l'on renvoi
 * @return std::string 
 */
std::string View::modifyModel()
{
    return sReceptor;
};
/**
 * @brief View des data jeu Bla Bla Bla de presentData\n
 * @todo sert à rien?
 */
void View::presentData(){};
/**
 * @brief mise a jour directe d'un sDO
 * @todo ne respecte pas le le MVP
 * @param sDO 
 */
void View::update(subjectDataObject *sDO)
{
}