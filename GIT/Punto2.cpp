#include <iostream>

using namespace std;

void displayResults(int edad, char sexo[], float altura){
    cout << endl << "Edad: " << edad << endl << "Sexo: " << sexo << endl << "Altura: " << altura << endl;
}

int main(){
    int edad;
    char sexo[9];
    float altura;
    cout << "Ingrese su edad: ";
    cin >> edad;
    cout << "Ingrese su sexo: ";
    cin >> sexo;
    cout << "Ingrese su altura: ";
    cin >> altura;
    displayResults(edad, sexo, altura);
}