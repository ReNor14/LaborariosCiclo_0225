#include <iostream>
using namespace std;

/*Crea un programa en C++ que tenga un "numero secreto" y solicite al usuario adivinarlo. Mienttras el numero 
    ingresasdo ssea distinto, el programa debe indicar si es muy bajo o muy alto hasta que acierte
    Utiliza if, else, else-if, while, do while*/

int main (){
    int Secret_number=37, Number=0;
    cout<<"NUMERO SECRETO"<<endl<<endl;
    do{
        cout<<"Ingrese un numero:\n";
        cin>>Number;
        if(Number<Secret_number){
            cout<<"El numero ingresado es MENOR que el Numero Seccreto."<<endl;
        }else if(Number>Secret_number){
            cout<<"EL numero ingresado es MAYOR que el Numero Secreto."<<endl;
        }else{
            cout<<"FELICIDADES!!!"<<endl; 
            cout<<"Encontraste el numero Secreto: "<<Secret_number<<endl;
        }    
    }while(Number!=Secret_number);
    

    return 0;
}