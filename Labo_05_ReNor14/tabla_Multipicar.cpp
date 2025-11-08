#include<iostream>
using namespace std;
int main(){
    cout<<"Tabla de Multiplicar"<<endl<<endl;
    int numero, tabla;
    cout<<"Ingrese un numero: ";
    cin>>numero;
    for (int i=1;i<=20;i++){
    tabla=numero*i;
    cout<<numero<<" X "<<i<<" = "<<tabla<<endl;
    }
    return 0;
}