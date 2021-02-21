#include <iostream>

using namespace std;

int calcularIva(int precio){
    int iva;
    iva = (precio * 0.19) + precio;
    return iva;
}

int main(){
    int precio;
    cout << "Ingrese el precio del producto: ";
    cin >> precio;
    cout << "El precio final del producto es: " << calcularIva(precio) << endl;
}