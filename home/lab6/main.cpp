#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include "Osoba.h"
using namespace std;

Osoba RandPeople() {
    return Osoba();
}

int main() {
    cout << "start" << endl;

    vector<Osoba> peopleVec;
    for(int i = 0; i < 5; i++){
        peopleVec.push_back(Osoba());
    }
    vector<Osoba>::iterator it;
    _Rb_tree_const_iterator<Osoba> result;
    for(it = peopleVec.begin(); it != peopleVec.end(); it++ )    {
        cout << (*it).getDesc() << endl;
    }

    cout << "-------------------------" << endl;

    set<Osoba> peopleSet;
    set<Osoba>::iterator itSet;
    for(it = peopleVec.begin(); it != peopleVec.end(); it++ ) {
        if(peopleSet.find(*it) != peopleSet.end()){
            cout << (*it).getDesc() << " - already exist" << endl;
        }
        else {
            peopleSet.insert(*it);
        }
    }
    for(it = peopleVec.begin(); it != peopleVec.end(); it++ )    {
        cout << (*it).getDesc() << endl;
    }

    cout << "Mapa" << endl;
    map<string, Osoba> peopleMap;
    map<string, Osoba>::iterator itMap;
    for(it = peopleVec.begin(); it != peopleVec.end(); it++ )    {
        peopleMap.insert(pair<string, Osoba>((*it).getDesc(), *it));
    }

    for(itMap = peopleMap.begin(); itMap != peopleMap.end(); itMap++ )    {
        cout << (*itMap).second.getDesc() << endl;
    }

    /////////////////////////////////////////////////////

    vector<Osoba> people(20);

    generate(people.begin(), people.end(), RandPeople);

    it = find (people.begin(), people.end(), 20);
    if (it != people.end())
        std::cout << "Element found in people: " << (*it).getDesc() << '\n';
    else
        std::cout << "Element not found in people\n";

    cout << "end" << endl;

    return 0;
}