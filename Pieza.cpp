#include "Pieza.hpp"
#include <string>
#include <iostream>

using namespace std;

Pieza::Pieza(){

}

Pieza::Pieza(string c, int t){
    tipo = t;
    char y = c[0];
    int x = stoi(c.substr(1,1));

    switch(y){
        case 'a':{
            cY = 0;
            break;
        }

        case 'b':{
            cY = 1;
            break;
        }

        case 'c':{
            cY = 2; 
            break;
        }

        case 'd':{
            cY = 3;
            break;
        }

        case 'e':{
            cY = 4;
            break;
        }

        case 'f':{
            cY = 5;
            break;
        }

        case 'g':{
            cY = 6;
            break;
        }

        case 'h':{
            cY = 7;
            break;
        }
    }

    switch(x){
        case 1:{
            cX = 7;
            break;
        }

        case 2:{
            cX = 6;
            break;
        }

        case 3:{
            cX = 5; 
            break;
        }

        case 4:{
            cX = 4;
            break;
        }

        case 5:{
            cX = 3;
            break;
        }

        case 6:{
            cX = 2;
            break;
        }

        case 7:{
            cX = 1;
            break;
        }

        case 8:{
            cX = 0;
            break;
        }
    }

}