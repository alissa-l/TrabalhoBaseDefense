#ifndef SRC_TRABALHOBASEDEFENSEEXE_DROPAVELVIDABASESTRATEGY_H
#define SRC_TRABALHOBASEDEFENSEEXE_DROPAVELVIDABASESTRATEGY_H

#include "IDropavelStrategy.h"
#include "../Base.hpp"

class DropavelVidaBaseStrategy : public IDropavelStrategy {
public:
    void effectImpl(void* t) override {
        auto* obj = static_cast<Base*>(t);
        obj->setVida(obj->getVida() + 10);
    }

};

#endif //SRC_TRABALHOBASEDEFENSEEXE_DROPAVELVIDABASESTRATEGY_H
