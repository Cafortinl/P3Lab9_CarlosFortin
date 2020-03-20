#include "Pieza.hpp"
#include <string>

using namespace std;

Pieza::Pieza(){

}

Pieza::Pieza(string c){
    int x = tolower(c[0]);
    int y = c[1];
    
    switch(x){
        case 'a':{
            cX = 0;
            break;
        }

        case 'b':{
            cX = 1;
            break;
        }

        case 'c':{
            cX = 2; 
            break;
        }

        case 'd':{
            cX = 3;
            break;
        }

        case 'e':{
            cX = 4;
            break;
        }

        case 'f':{
            cX = 5;
            break;
        }

        case 'g':{
            cX = 6;
            break;
        }

        case 'h':{
            cX = 7;
            break;
        }
    }

    switch(y){
        case 1:{
            cY = 0;
            break;
        }

        case 2:{
            cY = 1;
            break;
        }

        case 3:{
            cY = 2; 
            break;
        }

        case 4:{
            cY = 3;
            break;
        }

        case 5:{
            cY = 4;
            break;
        }

        case 6:{
            cY = 5;
            break;
        }

        case 7:{
            cY = 6;
            break;
        }

        case 8:{
            cY = 7;
            break;
        }
    }

}