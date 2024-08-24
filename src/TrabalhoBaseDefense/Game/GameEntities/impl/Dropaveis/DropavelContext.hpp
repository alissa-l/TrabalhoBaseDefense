#ifndef SRC_TRABALHOBASEDEFENSEEXE_DROPAVELCONTEXT_HPP
#define SRC_TRABALHOBASEDEFENSEEXE_DROPAVELCONTEXT_HPP

#include "../Base.hpp"
#include "../Dropavel.h"
#include "../Heroi.hpp"

class DropavelContext {
public:
    static void applyEffect(Heroi &heroi, Base &base, Dropavel &dropavel) {
        if (dropavel.getStrategy() != nullptr) {
            dropavel.effect(base, heroi);
        }
    }
};

#endif //SRC_TRABALHOBASEDEFENSEEXE_DROPAVELCONTEXT_HPP
