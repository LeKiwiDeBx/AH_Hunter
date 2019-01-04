#include <iostream>
#include <string>
#include <map>

using namespace std;

template <class Cle, class T>
void AfficherMultimap(const multimap<Cle, T>& m);

template <class Cle, class T>
void AfficherMultimapRange(const multimap<Cle, T>& m, const Cle& k);

int main() {
  // On crée un multimap multimap
  multimap<string, string> MonMultimap;
  // On y stocke des éléments
  MonMultimap.insert(make_pair((string) "cle_1", (string) "Elément 1"));
  MonMultimap.insert(make_pair((string) "cle_1", (string) "Elément 2"));
  MonMultimap.insert(make_pair((string) "cle_1", (string) "Elément 3"));
  MonMultimap.insert(make_pair((string) "cle_2", (string) "Elément 4"));
  MonMultimap.insert(make_pair((string) "cle_3", (string) "Elément 5"));
  cout << "Voici le contenu de notre multimap:\n";
  AfficherMultimap(MonMultimap);
  cout << "Voici les éléments de valeur de";
  cout << " clé \"cle_1\":\n";
  AfficherMultimapRange(MonMultimap, (string) "cle_1");
}

template <class Cle, class T>
void AfficherMultimap(const multimap<Cle, T>& m) {
  typedef typename multimap<Cle, T>::const_iterator Itor;
  for (Itor i = m.begin(); i != m.end(); ++i)
    cout << i->first << "\t" << i->second << "\n";
  cout << "\n";
}
template <class Cle, class T>
void AfficherMultimapRange(const multimap<Cle, T>& m, const Cle& k) {
  typedef typename multimap<Cle, T>::const_iterator Itor;
  pair<Itor, Itor> p = m.equal_range(k);
  for (Itor i = p.first; i != p.second; ++i)
    cout << i->first << "\t" << i->second << "\n";
  cout << "\n";
}
