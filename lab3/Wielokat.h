#pragma once

#include <iostream>
#include "Punkt.h"

class Wielokat {

private:
    Punkt* punkty;
    int tabSize;
    int elementCount;

public:
    Wielokat(): Wielokat(3) {};
    explicit Wielokat(int size);
    Wielokat(const Wielokat &other);
    Wielokat(Wielokat && other) noexcept;
    Wielokat& operator = (Wielokat&& other);
    Wielokat& operator = (const Wielokat&& other);
    ~Wielokat() { delete[](punkty); }

    Punkt & operator[](size_t el);
    const Punkt & operator[](size_t el) const;

    int getTabSize() const { return tabSize; };
    int getElementCount() const { return elementCount;};
    void addPunkt(Punkt & osoba);
};