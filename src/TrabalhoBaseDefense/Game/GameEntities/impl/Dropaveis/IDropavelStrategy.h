#ifndef SRC_TRABALHOBASEDEFENSEEXE_IDROPAVELSTRATEGY_H
#define SRC_TRABALHOBASEDEFENSEEXE_IDROPAVELSTRATEGY_H

#include "../Base.hpp"
#include "../Heroi.hpp"

class IDropavelStrategy {
public:
    virtual ~IDropavelStrategy() = default;
    virtual void effectImpl(Base &base, Heroi &heroi) {};
};

#endif //SRC_TRABALHOBASEDEFENSEEXE_IDROPAVELSTRATEGY_H
