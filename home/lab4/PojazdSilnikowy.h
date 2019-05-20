//
// Created by mleko on 4/8/19.
//

#ifndef LAB4_POJAZDSILNIKOWY_H
#define LAB4_POJAZDSILNIKOWY_H

#include "Pojazd.h"

namespace program {

    class PojazdSilnikowy : public Pojazd {
    public:
        float mocKW();
    protected:
        float pojemnosc;
        int moc;
    };

}


#endif //LAB4_POJAZDSILNIKOWY_H
