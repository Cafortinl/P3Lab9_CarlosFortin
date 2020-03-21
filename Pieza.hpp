#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Pieza{
        int cX, cY, tipo;
    public:
        Pieza();
        Pieza(string c, int t);
        virtual bool validarMovimiento(string c, char tablero[8][8], vector<Pieza*> piezas) = 0;
        int getX(){ return cX; };
        int getY(){ return cY; };
        void setX(int x){ cout << "set!" << endl; cX = x; };
        void setY(int y){ cY = y; };
        virtual char toChar() = 0;
};