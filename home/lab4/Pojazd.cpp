//
// Created by mleko on 4/8/19.
//

#include "Pojazd.h"

using namespace program;

std::string Pojazd::opis() const {
    return wlasciciel.pobierzImie() + "," + wlasciciel.pobierzNazwisko() + "," + std::to_string(wlasciciel.pobierzRok());
}
