#include "Partida.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Partida::Partida(string n, string p, string m){
    nombre = n;
    pieza = p;
    int pos = 0;
    char delimiter = ';';
    for(int i = 0;i<m.size();i++){
        if(m[i] == delimiter){
            movimientos.push_back(m.substr(pos,i));
            pos = i+1;
        }
    }
}

string Partida::getNombre(){
    return nombre;
}
string Partida::getPieza(){
    return pieza;
}
void Partida::getMovimientos(){
    for(int i = 0; i < movimientos.size();i++){
        cout << movimientos[i] << endl;
    }
}