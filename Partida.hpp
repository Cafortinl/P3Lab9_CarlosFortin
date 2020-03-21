#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Partida{
    private:
        string nombre, pieza;
        vector<string> movimientos;
    public:
        Partida(string n, string p, string m);
        string getNombre();
        string getPieza();
        void getMovimientos();
};