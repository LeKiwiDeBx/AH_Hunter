#include "main.h"

using namespace std;

View::View()
{
    // cout << "Appel du constructeur View\n";
}
void View::client(){
    //presente les data au client
};

void View::receptor() const
{
    //getline()
    string str;
    cout << "getline : ";
    getline(cin, str);
};
/* 
 */
void View::presentData(const string s, const int n)
{
    // cout << "View des data jeu Bla Bla Bla avec param\n";
}

void View::modifyModel(
    // demande au Controller adéquat de modifier les data du model
)
{
    ;
};

void View::presentData(){
    // cout << "View des data jeu Bla Bla Bla de presentData\n";
};

void View::update()
{
}