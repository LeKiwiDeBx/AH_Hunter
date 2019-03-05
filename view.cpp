#include "main.h"

using namespace std;

View::View()
{
    // cout << "Appel du constructeur View\n";
}
void View::client(){
    //presente les data au client
};

void View::receptor()
{
    //getline()
    std::string s;
    std::cout << "Votre réponse: ";
    std::getline(std::cin, sReceptor);
};
/* 
 */
void View::presentData(const string s, const int n)
{
    // cout << "Chaine directe à afficher\n";
    cout << s << endl;
}

void View::presentData(subjectDataObject *sDO)
{ // ??? faire une sorte template
    // std::map<string, string> mapData = {{"presentData de la view", ""},
    //                                     {"La situation: ", "Texte"},
    //                                     {"La question: ", "Question"},
    //                                     {"Les réponses possibles: ", "Reponse"},
    //                                     {"Les conséquences: ", "Consequence"}};
    // for (auto d : mapData)
    // {
    //     cout << d.first << sDO->getAllData(d.second) << endl;
    // }
    cout << "presentData de la view" << sDO->getName() << endl;
    cout << "La situation: " << sDO->getAllData("Texte") << endl;
    cout << "La question:" << sDO->getAllData("Question") << endl;
    cout << "Les réponses possibles:" << sDO->getAllData("Reponse") << endl;
    cout << "Les conséquences: " << sDO->getAllData("Consequence") << endl;
}

std::string View::modifyModel()
{
    // demande au Controller adéquat de modifier les data du model
    return sReceptor;
};

void View::presentData(){
    // cout << "View des data jeu Bla Bla Bla de presentData\n";
};

void View::update()
{
}