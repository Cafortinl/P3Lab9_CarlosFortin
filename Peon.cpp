#include "Pieza.hpp"
#include "Peon.hpp"
#include <string>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

Peon::Peon() : Pieza(){
}

Peon::Peon(string c, int t) : Pieza(c,t){
}

bool Peon::validarMovimiento(string c, char tablero[8][8], vector<Pieza*> piezas){
    bool valido = false;
    string nmov = mov(c);
    int nx = nmov[0] - '0';
    int ny = atoi(nmov.substr(2,2).c_str());
    if((nx > 7 || nx < 0) || (ny > 7 || ny < 0)){
        valido = false;
    }else{
        if(abs((*this).getY()-ny) == 0 && abs((*this).getX()-nx) == 1){
            valido = true;
        }
    }
    return valido;
}

string Peon::mov(string c){
    char cy = c[4];
    int cx = atoi(c.substr(5,5).c_str());
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
    cout << "revisa: " << x << " " << y;
    salida = to_string(x) + "y" + to_string(y);
    return salida;
}