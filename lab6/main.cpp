#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include "Zwierze.h"
using namespace std;
string type;

Zwierze RandZwierze() {
    return Zwierze();
}

bool cmpFunction(const Zwierze& zw1, const Zwierze& zw2) {
    return zw1.getAge() > zw2.getAge();
}

bool isType(const Zwierze& zw) {
    return zw.getType() == type;
}

void growUp(Zwierze zw) {  // function:
    zw.setAge(zw.getAge() + 1);
}

bool RemoveIF(Zwierze & zwierze){
    return zwierze.getAge() > 10;
}

int main() {
    cout << "start" << endl;

    vector<Zwierze> petVec;
    for(int i = 0; i < 5; i++){
        petVec.push_back(Zwierze());
    }
    //vector<Zwierze>::iterator it;
    for(auto it = petVec.begin(); it != petVec.end(); it++ )    {
        cout << (*it).getDesc() << endl;
    }

    cout << "-------------------------" << endl;

    cout << "Set" << endl;
    set<Zwierze> petSet;
    set<Zwierze>::iterator itSet;
    auto pos = 0;
    for(it = petVec.begin(); it != petVec.end(); it++ ) {
        if(petSet.find(*it) == petSet.end()){
            petSet.insert(*it);
        } else {
            cout << (*it).getDesc() << " - duplicate" << endl;
        }
    }

    cout << "-------------------------" << endl;

    cout << "Mapa" << endl;
    map<string, Zwierze> petMap;
    map<string, Zwierze>::iterator itMap;
    for(int i = 0; i < 5; i++){
        Zwierze zwierze = Zwierze();
        petMap.insert(pair<string, Zwierze>(zwierze.getKey(), zwierze));
    }

    for(itMap = petMap.begin(); itMap != petMap.end(); itMap++ )    {
        cout << (*itMap).second.getDesc() << endl;
    }

    cout << "-------------------------" << endl;

    cout << "Algo" << endl;
    vector<Zwierze> pet(15);
    generate(pet.begin(), pet.end(), RandZwierze);

    cout << "Najstarsze " <<
    std::min_element(pet.begin(), pet.end(), cmpFunction)->getDesc() << endl;

    cout << "typ:";
    cin >> type;

    int count = count_if (pet.begin(), pet.end(), isType);
    cout << "Tle:" << count << endl;

    for_each(pet.begin(), pet.end(), growUp);


    it = remove_if(pet.begin(), pet.end(), RemoveIF);

    return 0;
}