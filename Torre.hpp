#pragma once
#include "Pieza.hpp"
#include <string>
#include <vector>

using namespace std;

class Torre: public Pieza{
    public:
        Torre();
        Torre(string c, int t);
        bool validarMovimiento(string c, char tablero[8][8], vector<Pieza*> piezas);
        string mov(string c);
        char toChar(){ return 'T'; };
};