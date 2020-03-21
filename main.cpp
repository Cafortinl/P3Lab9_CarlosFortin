#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Pieza.hpp"
#include "Rey.hpp"
#include "Reina.hpp"
#include "Alfil.hpp"
#include "Caballo.hpp"
#include "Torre.hpp"
#include "Peon.hpp"
#include "Partida.hpp"

using namespace std;

void printMatrix();

char tablero[8][8];
vector<Pieza*> piezas;
vector<Partida> partidas;

string moverPieza(string c){
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

    string mov = x + " " + y;

    return mov;
}

int piezaActual(string c){
    int cy = c[1];
    int cx = stoi(c.substr(2,2));
    int x,y;
    int jug = -1;
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

    for(int i = 0;i < piezas.size();i++){
        if((*piezas[i]).getX() == x && (*piezas[i]).getY() == y){
            jug = i;
            break;
        }
    }

    //cout << jug << endl;

    return jug;
}

void mover(){
    for(int i=0;i < 8;i++){
        for(int j = 0;j < 8;j++){
            for(int c = 0;c < piezas.size(); c++){
                if((*piezas[c]).getX() == i && (*piezas[c]).getY() == j){
                    tablero[i][j] = (*piezas[c]).toChar();
                }
            }
        }
    }
}

void leer(){
    ifstream fr("bitacoraPartidas.txt", ios::in);
    if(!fr){
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }
    string separador, nombre, pieza, movimientos;
    while(fr >> nombre >> nombre >> pieza >> movimientos){
        Partida t(nombre, pieza, movimientos);
        partidas.push_back(t);
    }
}

void escribir(string nombre, string pieza, vector<string> movimientos){
    ofstream fw("bitacoraPartidas.txt", ios::app);
    fw << "--------------------\n" << nombre << endl << pieza << endl;
    for(int i=0;i<movimientos.size();i++){
        fw << movimientos[i] << ";";
    }
    fw << endl;
}

void repeticion(){

}

void juego(string nombre, string pieza){
    vector<string> movimientos;
    string mov;
    int opcion = 0;
    mover();
    printMatrix();
    do{
        cout << "Turno del jugador blanco" << endl;
        cout << "Ingrese las coordenadas de la forma [posActual,posDestino]: ";
        cin >> mov;
        while(piezaActual(mov) == -1){
            cout << "No hay ningun jugador en la posicion ingresada. Ingrese el par de coordenadas de nuevo: ";
            cin >> mov;
        }
        if((*piezas[piezaActual(mov)]).validarMovimiento(mov, tablero, piezas)){
            string m = moverPieza(mov);
            int xAnt = (*piezas[piezaActual(mov)]).getX();
            int yAnt = (*piezas[piezaActual(mov)]).getY();
            tablero[xAnt][yAnt] = '*';
            int x = atoi(m.substr(0,0).c_str());
            int y = atoi(m.substr(2,2).c_str());
            cout << "aqui" << endl;
            mover();
            printMatrix();
            movimientos.push_back(mov);
        }
        cout << "Turno del jugador negro" << endl;
        cout << "Ingrese las coordenadas de la forma [posActual,posDestino]: ";
        cin >> mov;
        while(piezaActual(mov) == -1){
            cout << "No hay ningun jugador en la posicion ingresada. Ingrese el par de coordenadas de nuevo: ";
            cin >> mov;
        }
        if((*piezas[piezaActual(mov)]).validarMovimiento(mov, tablero, piezas)){
            string m = moverPieza(mov);
            int xAnt = (*piezas[piezaActual(mov)]).getX();
            int yAnt = (*piezas[piezaActual(mov)]).getY();
            tablero[xAnt][yAnt] = '*';
            int x = atoi(m.substr(0,0).c_str());
            int y = atoi(m.substr(2,2).c_str());
            mover();
            printMatrix();
            movimientos.push_back(mov);
        }
        cout << "Desea continuar?\n1. Si\n2. No" << endl;
        cin >> opcion;
    }while(opcion != 2);
    piezas.clear();
    escribir(nombre,pieza,movimientos);
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
                cout << "[" << tablero[i][j] << "]";
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
            cin >> nombre;
            mostrarPiezas();
            cin >> pieza;
            switch(pieza){
                case 1:{
                    Reina rb("d1",1);
                    Reina rn("d8",2);
                    piezas.push_back(&rb);
                    piezas.push_back(&rn);
                    juego(nombre, "Reina");
                    break;
                }

                case 2:{
                    Alfil rb("c1",1);
                    Alfil rn("f8",2);
                    piezas.push_back(&rb);
                    piezas.push_back(&rn);
                    juego(nombre, "Reina");
                    break;
                }

                case 3:{
                    Caballo rb("b1",1);
                    Caballo rn("g8",2);
                    piezas.push_back(&rb);
                    piezas.push_back(&rn);
                    juego(nombre, "Reina");
                    break;
                }

                case 4:{
                    Torre rb("a1",1);
                    Torre rn("h8",2);
                    piezas.push_back(&rb);
                    piezas.push_back(&rn);
                    juego(nombre, "Reina");
                    break;
                }

                case 5:{
                    Peon rb("e2",1);
                    Peon rn("e7",2);
                    piezas.push_back(&rb);
                    piezas.push_back(&rn);
                    juego(nombre, "Reina");
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
            partidas.clear();
            leer();
            int opcion;
            for(int i = 0;i < partidas.size();i++){
                cout << i << "-" << partidas[i].getNombre() << endl;
            }
            cin >> opcion;
            if(opcion <= partidas.size() -1 && opcion > -1){
                cout << "Nombre: " << partidas[opcion].getNombre() << endl;
                cout << "Pieza: " << partidas[opcion].getPieza() << endl;
                cout << "Movimientos" << endl;
                partidas[opcion].getMovimientos();
            }else{
                cout << "La posicion ingresada no es valida" << endl;
            }
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