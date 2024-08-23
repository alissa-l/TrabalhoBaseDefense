#ifndef SRC_TRABALHOBASEDEFENSEEXE_IDROPAVELSTRATEGY_H
#define SRC_TRABALHOBASEDEFENSEEXE_IDROPAVELSTRATEGY_H

class IDropavelStrategy {
public:
    virtual ~IDropavelStrategy() = default;
    virtual void effectImpl(void* t) = 0;
};

#endif //SRC_TRABALHOBASEDEFENSEEXE_IDROPAVELSTRATEGY_H
