#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Pieza.hpp"
#include "Rey.hpp"
#include "Reina.hpp"

using namespace std;

void printMatrix();

char tablero[8][8];
vector<Pieza*> piezas;

void mover(){
    for(int i=0;i < 8;i++){
        for(int j = 0;j < 8;j++){
            for(int c = 0;c < piezas.size(); c++){
                if((*piezas[c]).getX() == i && (*piezas[c]).getY() == j){
                    tablero[i][j] = (*piezas[c]).toChar();
                    cout << (*piezas[c]).toChar() << endl;
                }
            }
        }
    }
}

void leer(){

}

void escribir(string nombre, string pieza, vector<string> movimientos){

}

void repeticion(){

}

void juego(string nombre, string pieza){
    mover();
    printMatrix();
}

void fillMatrix(){
    for(int i = 0;i < 8;i++){
        for(int j = 0;j < 8;j++){
            tablero[i][j] = '*';
        }
    }
}

void printMatrix(){
    for(int i = 0;i < 8;i++){
        for(int j = 0;j < 8;j++){
            if(tablero[i][j] == '*'){
                cout << "[ ]";
            }else{
                cout << tablero[i][j];
            }
        }
        cout << endl;
    }
}

void mostrarPiezas(){
    cout << "Seleccione la pieza con la que desea jugar" << endl;
    cout << "1. Reina" << endl;
    cout << "2. Alfil" << endl;
    cout << "3. Caballo" << endl;
    cout << "4. Torre" << endl;
    cout << "5. Peon" << endl;
}

void opciones(int x){
    switch(x){
        case 1:{
            Rey blanco("e1", 1);
            Rey negro("e8", 2);
            piezas.push_back(&blanco);
            piezas.push_back(&negro);
            string nombre;
            int pieza;
            cout << "Ingrese el nombre de la partida: ";
            getline(cin,nombre);
            mostrarPiezas();
            cin >> pieza;
            switch(pieza){
                case 1:{
                    Reina rb("d1",1);
                    Reina rn("d8",2);
                    juego(nombre, "Reina");
                    break;
                }

                case 2:{
                    break;
                }

                case 3:{
                    break;
                }

                case 4:{
                    break;
                }

                case 5:{
                    break;
                }

                default:{
                    cout << "La opcion ingresada no es valida" << endl;
                    break;
                }
            }
            break;
        }

        case 2:{
            break;
        }

        case 0:{
            break;
        }

        default:{
            cout << "La opcion ingresada no es valida" << endl;
            break;
        }
    }
}

void menu(){
    cout << "----------Menu----------" << endl;
    cout << "1. Jugar partida" << endl;
    cout << "2. Recrear partida" << endl;
    cout << "0. Salir" << endl;
}

int main(){
    int opcion = 0;
    fillMatrix();
    do{
        menu();
        cin >> opcion;
        opciones(opcion);
    }while(opcion != 0);
    cout << "Fin del Programa" << endl;
    return 0;
}