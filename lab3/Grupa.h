#pragma once

#include <iostream>
#include "Osoba.h"

using namespace std;

class Grupa {

private:
    Osoba* grupa;
    int tabSize;
    int elementCount;

public:
    Grupa(): Grupa(20) {};
    Grupa(int size);
    Grupa(const Grupa &other);
    Grupa(Grupa &&other);
    Grupa& operator=(Grupa&& other);
    ~Grupa() { delete[](grupa); }

    Osoba & operator[](size_t el);
    const Osoba & operator[](size_t el) const;

    int getTabSize() const { return tabSize; };
    int getElementCount() const { return elementCount;};
    void addOsoba(Osoba & osoba);

};