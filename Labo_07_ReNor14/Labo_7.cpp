#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;
/* 1. Crea un archivo 
datos.txt con varios números enteros.

 2. El programa debe:
 Separar los números pares e impares en archivos distintos.
 Ordenar cada archivo de menor a mayor (usando el método burbuja).
 Mostrar el contenido antes y después del ordenamiento.

 3.  Usa funciones para cada tarea:
 leerArchivo()
 clasificarNumeros()
 ordenarArchivo()
 mostrarArchivo() */
void clasificarNumeros();
void ordenarArchivo(string nombre);
void mostrarArchivo(string nombre);
int menu();

int main() {
    int opcion;

    do {
        opcion = menu();

        switch(opcion) {
            case 1:
                cout << "Clasificando numeros...\n";
                clasificarNumeros();
                break;

            case 2:
                cout << "Ordenando archivos...\n";
                ordenarArchivo("pares.txt");
                ordenarArchivo("impares.txt");
                break;

            case 3:
                cout << "Mostrando resultados...\n";

                cout << "--- ARCHIVO PARES ---\n";
                mostrarArchivo("pares.txt");

                cout << "--- ARCHIVO IMPARES ---\n";
                mostrarArchivo("impares.txt");

                break;

            case 4:
                cout << "Saliendo del programa...\n";
                break;
        }

        if(opcion != 4){
            system("pause");
            system("cls");
        }

    } while(opcion != 4);

    system("pause");
    system("cls");
    return 0;
}

int menu() {
    int x;

    while (true) {
        cout<<"|----------MENU---------|\n";
        cout<<"|Elija una opcion:......|\n";
        cout<<"|1. Clasificar Numeros..|\n";
        cout<<"|2. Ordenar Numeros.....|\n";
        cout<<"|3. Mostrar Numeros.....|\n";
        cout<<"|4. Salir...............|\n";
        cout<<"|-----------------------|\n";
        cin >> x;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida, solo numeros.\n";
            continue;
        }

        cin.ignore(10000, '\n');

        if (x < 1 || x > 4) {
            cout << "Esa opcion no existe, Intentelo de nuevo. \n";
        }

        return x;
    }
}
/*Esta funcion lee el archivo donde estan los numeros, luego crea losotros archivos 
donde se van a guardar dependiendo de si son pares o impares*/
void clasificarNumeros() {
    ifstream entrada("NumerosE.txt");
    ofstream pares("pares.txt");
    ofstream impares("impares.txt");

    int n;

    while (entrada >> n) {
        if (n % 2 == 0)
            pares << n << endl;
        else
            impares << n << endl;
    }

    entrada.close();
    pares.close();
    impares.close();

    cout << "Numeros clasificados desde NumerosE.txt.\n";
}

void ordenarArchivo(string nombre) {
    ifstream entrada(nombre);

    int arreglo[100];
    int n = 0;
//Mete el contenido de archivo en el array para que luego se pueda ordenar
    while (entrada >> arreglo[n]) {
        n++;
    }
    entrada.close();
//Nos ayuda a ordenar los numeros comparandolos y moviendolos de posicion dentro del array(metodo burbuja)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
//Luego ya ordenado se guarda en el archivo
    ofstream salida(nombre);
    for (int i = 0; i < n; i++) {
        salida << arreglo[i] << endl;
    }
    salida.close();

    cout << "Archivo " << nombre << " ordenado correctamente.\n";
}
//Aca se lee el contenido de los archivos
void mostrarArchivo(string nombre) {
    ifstream archivo(nombre);
    int n;

    while (archivo >> n) {
        cout << n << endl;
    }

    archivo.close();
}
