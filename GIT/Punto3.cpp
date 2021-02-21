#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void inicializar(){
    fstream ficheroSalida;
    ficheroSalida.open ("ficheroTexto.txt");
    if(!ficheroSalida.is_open()){
        ofstream ficheroSalida;
        ficheroSalida.open ("ficheroTexto.txt");
        ficheroSalida.close();
    }else{
        ficheroSalida.close();
    }
}

void guardarContacto(string nombre, string apellidos, int numero){
    ofstream ficheroSalida;
    ficheroSalida.open ("ficheroTexto.txt", ios_base::app);
    ficheroSalida << "Nombre: " << nombre << ", Apellidos: " << apellidos << ", Numero: " << numero << "\n";
    ficheroSalida.close();
}

int main(){
    int input = -1, numero;
    string nombre, apellidos;
    inicializar();
    while (input != 0){
        cout << "\n1. Ingresar contacto" << endl;
        cout << "2. Mostrar contactos" << endl;
        cout << "0. Salir" << endl;
        cout << "\nQue desea hacer?: ";
        cin >> input;
        if(input == 1){
            cout << "\nIngrese el nombre del contacto a guardar: ";
            cin >> nombre;
            cout << "Ingrese los apellidos del contacto a guardar: ";
            cin >> apellidos;
            cout << "Ingrese el numero del contacto a guardar: ";
            cin >> numero;
            guardarContacto(nombre, apellidos, numero);
        }else if(input == 2){
            string texto;
            fstream ficheroSalida;
            ficheroSalida.open ("ficheroTexto.txt");
            if(ficheroSalida.is_open()){
                while(getline(ficheroSalida, texto)){
                    cout << texto << endl;
                }
                ficheroSalida.close();
            }
        }else if(input == 0){
            cout << "\nDe nada, vuelva pronto" << endl;
        }
    }
}