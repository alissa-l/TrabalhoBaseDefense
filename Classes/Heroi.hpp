#ifndef TRABALHOBASEDEFENSE_HEROI_HPP
#define TRABALHOBASEDEFENSE_HEROI_HPP


class Heroi {

private:
    int vida;
    int municao;
    int posX;
    int posY;
public:
    Heroi();
    void setVida(int vida);
    void setMunicao(int municao);
    int getVida() const;
    int getMunicao() const;
    void move(int posX, int posY);

};


#endif //TRABALHOBASEDEFENSE_HEROI_HPP
