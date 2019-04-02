#include "Grupa.h"
#include <iostream>
Grupa::Grupa(int size) {
    elementCount = 0;
    tabSize = size;
    grupa = new Osoba[size];
}

Grupa::Grupa(const Grupa &other) {
    this->elementCount = other.elementCount;
    this->tabSize = other.tabSize;
    this->grupa = new Osoba[other.tabSize];

    for(int i = 0; i < other.elementCount; i++){
        this->grupa[i] = other.grupa[i];
    }
}

Grupa::Grupa(Grupa &&other) {
    elementCount = other.elementCount;
    tabSize = other.tabSize;
    grupa = other.grupa;

    other.elementCount = 0;
    other.tabSize = 0;
    other.grupa = nullptr;
}

Grupa& Grupa::operator = (Grupa&& other)
{
    if (this != &other)
    {
        delete[] grupa;

        grupa = other.grupa;
        elementCount = other.elementCount;
        tabSize = other.tabSize;

        other.grupa = nullptr;
        other.elementCount = 0;
        other.tabSize = 0;
    }
    return *this;
}

void Grupa::addOsoba(Osoba &osoba) {
    if(elementCount < tabSize){
        grupa[elementCount] = osoba;
        elementCount++;
    } else {
        throw std::runtime_error("Brak miejsca na kolejną osobę w tablic grupy");
    }
}


Osoba & Grupa::operator[](size_t index) {
    if(index >= 0 && index < elementCount){
        return grupa[index];
    } else {
        throw std::runtime_error("Indeks z poza tablicy.");
    }
}

const Osoba & Grupa::operator[](size_t index) const {
    if(index >= 0 && index < elementCount){
        return grupa[index];
    } else {
        throw std::runtime_error("Indeks z poza tablicy.");
    }
}