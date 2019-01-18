#include "main.h"

using namespace std;

viewDataObserver::viewDataObserver()
{
    cout << "Appel du constructeur viewDataObserver\n";
}

void viewDataObserver::update()
{
    cout << "Appel Update de la liste des viewDataObserver";
}
