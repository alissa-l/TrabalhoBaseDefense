// DropavelMunicaoStrategy.h
#ifndef SRC_TRABALHOBASEDEFENSEEXE_DROPAVELMUNICAOSTRATEGY_H
#define SRC_TRABALHOBASEDEFENSEEXE_DROPAVELMUNICAOSTRATEGY_H

#include "IDropavelStrategy.h"
#include "../Heroi.hpp"

class DropavelMunicaoStrategy : public IDropavelStrategy {
public:
    void effectImpl(void* t) override {
        auto* obj = static_cast<Heroi*>(t);
        obj->setMunicao(obj->getMunicao() + 10);
    }
};

#endif //SRC_TRABALHOBASEDEFENSEEXE_DROPAVELMUNICAOSTRATEGY_H