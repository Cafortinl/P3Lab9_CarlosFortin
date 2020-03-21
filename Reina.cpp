#include "Pieza.hpp"
#include "Reina.hpp"
#include <string>
#include <cmath>
#include <vector>

using namespace std;

Reina::Reina() : Pieza(){
}

Reina::Reina(string c, int t) : Pieza(c, t){
}

bool Reina::validarMovimiento(string c, char tablero[8][8], vector<Pieza*> piezas){
    bool valido = false;
    string nmov = mov(c);
    int nx = nmov[0];
    int ny = nmov[2];
    if(nx > 7 || nx < 0 || ny > 7 || ny < 0){
        valido = false;
    }else{
        if(((*this).getX() == nx) || ((*this).getY() == ny) || abs((*this).getX()-nx) == abs((*this).getY() - nx)){
            valido = true;
            this->setX(nx);
            this->setY(ny);
        }
    }
    return valido;
}

string Reina::mov(string c){
    int cy = c[4];
    int cx = stoi(c.substr(5,5));
    int x,y;
    
    string salida;

    switch(cy){
        case 'a':{
            y = 0;
            break;
        }

        case 'b':{
            y = 1;
            break;
        }

        case 'c':{
            y = 2; 
            break;
        }

        case 'd':{
            y = 3;
            break;
        }

        case 'e':{
            y = 4;
            break;
        }

        case 'f':{
            y = 5;
            break;
        }

        case 'g':{
            y = 6;
            break;
        }

        case 'h':{
            y = 7;
            break;
        }
    }

    switch(cx){
        case 1:{
            x = 7;
            break;
        }

        case 2:{
            x = 6;
            break;
        }

        case 3:{
            x = 5; 
            break;
        }

        case 4:{
            x = 4;
            break;
        }

        case 5:{
            x = 3;
            break;
        }

        case 6:{
            x = 2;
            break;
        }

        case 7:{
            x = 1;
            break;
        }

        case 8:{
            x = 0;
            break;
        }
    }

    salida = to_string(x) + " " + to_string(y);
    return salida;
}