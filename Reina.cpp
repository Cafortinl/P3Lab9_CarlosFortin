#include "Pieza.hpp"
#include "Reina.hpp"
#include <string>
#include <cmath>

using namespace std;

Reina::Reina() : Pieza(){
}

Reina::Reina(string c, int t) : Pieza(c, t){
}

bool Reina::validarMovimiento(string c, char tablero[8][8]){
    bool valido = false;
    string nmov = mov(c);
    int nx = nmov[0];
    int ny = nmov[2];
    if(nx > 7 || nx < 0 || ny > 7 || ny < 0){
        valido = false;
    }else{
        if(abs(nx-this->getX()) > 1 || abs(ny-this->getY()) > 1){
            valido = false;
        }else{
            valido = true;
            this->setX(nx);
            this->setY(ny);
        }
    }
    return valido;
}

string Reina::mov(string c){
    int cx = tolower(c[4]);
    int cy = c[5];
    int x,y;
    
    string salida;

    switch(cx){
        case 'a':{
            x = 0;
            break;
        }

        case 'b':{
            x = 1;
            break;
        }

        case 'c':{
            x = 2; 
            break;
        }

        case 'd':{
            x = 3;
            break;
        }

        case 'e':{
            x = 4;
            break;
        }

        case 'f':{
            x = 5;
            break;
        }

        case 'g':{
            x = 6;
            break;
        }

        case 'h':{
            x = 7;
            break;
        }
    }

    switch(cy){
        case 1:{
            y = 0;
            break;
        }

        case 2:{
            y = 1;
            break;
        }

        case 3:{
            y = 2; 
            break;
        }

        case 4:{
            y = 3;
            break;
        }

        case 5:{
            y = 4;
            break;
        }

        case 6:{
            y = 5;
            break;
        }

        case 7:{
            y = 6;
            break;
        }

        case 8:{
            y = 7;
            break;
        }
    }

    salida = to_string(x) + " " + to_string(y);
    return salida;
}