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
    int getVida() const;
    void setVida(int vida);
    int getMunicao() const;
    void setMunicao(int municao);
    int getPosX() const;
    void setPosX(int posX);
    int getPosY() const;
    void setPosY(int posY);
    void move(int posX, int posY);

};


#endif //TRABALHOBASEDEFENSE_HEROI_HPP
