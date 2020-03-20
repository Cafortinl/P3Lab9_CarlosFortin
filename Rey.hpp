#pragma once
#include "Pieza.hpp"
#include <string>

using namespace std;

class Rey: public Pieza{
    public:
        Rey();
        Rey(string c, int t);
        bool validarMovimiento(string c, char tablero[8][8]);
        string mov(string c);
        char toChar(){ return 'K'; };
};