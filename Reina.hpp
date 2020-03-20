#pragma once
#include "Pieza.hpp"
#include <string>

using namespace std;

class Reina: public Pieza{
    public:
        Reina();
        Reina(string c, int t);
        bool validarMovimiento(string c, char tablero[8][8]);
        string mov(string c);
        char toChar(){ return 'Q'; };
};