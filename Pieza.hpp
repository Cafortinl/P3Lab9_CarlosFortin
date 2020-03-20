#pragma once

using namespace std;

class Pieza{
    private:
        int cX, cY;
    public:
        Pieza();
        Pieza(string c);
        virtual bool validarMovimiento(string c, char tablero[8][8]) = 0;
        int getX(){ return cX; };
        int getY(){ return cY; };
        void setX(int x){ cX = x; };
        void setY(int y){ cY = y; };
};