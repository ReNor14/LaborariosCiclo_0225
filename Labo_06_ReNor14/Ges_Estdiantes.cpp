 #include <iostream>
 #include <string>//Nos permite ocupar el getline y cin.ignore()
 #include <cstdlib>//limpia y hace pausa en la terminal
 using namespace std;
 /*Crear un programa interactivo en el que el usuario podrá gestionar la 
información de los estudiantes de una escuela. El programa permitirá ingresar 
datos como el nombre, la edad, las calificaciones y la dirección de cada 
estudiante, y ofrecerá diversas opciones para gestionar y visualizar esta 
información.*/
   struct direccion {//estructura de la direccion
    int numero;
    string calle;
    string ciudad;
};
struct estudiante {//estructura de los estudiantes
    string nombre;
    int edad;
    float notas[5];
    direccion Dccion;
};
void ingresarEstudiantes(estudiante estudiantes[], int &cantidad);//esto '&' hace que el valor de la variable cantidad se modifique y no se pierda, luego de que la funcion haya hecho su proceso
void buscarestudiante(estudiante estudiantes[], int cantidad);
void mostrarEstudiantes(estudiante estudiantes[], int cantidad);
void modificarEstudiantes(estudiante estuiantes[], int cantidad);


int main() {
    int opcion;
    int cantidad=0;
    estudiante estudiantes[50]; 
    do {
        system("cls");//Aca ocupo  system("cls")' para limpiar la consola y que se vea mas ordenado
        cout<<"..Gestion de Estudiantes(GES).."<<endl<<endl;
        cout<<"|----------- MENU -----------|"<<endl;
        cout<<"|1. Ingresar Estudiante------|"<<endl;
        cout<<"|2. Mostrar Estudiantes------|"<<endl;
        cout<<"|3. Buscar Estudiante--------|"<<endl;
        cout<<"|4. Modificar Estudiante-----|"<<endl;
        cout<<"|5. Salir--------------------|"<<endl;
        cout<<"|----------------------------|"<<endl;
        cin>>opcion;
        cin.ignore();//Esto hace que no haya saltos de lineas innecesarios y que nos vaya a dar problemas para meter datos

        switch (opcion) {
            case 1:
                ingresarEstudiantes(estudiantes, cantidad);
                break;
            case 2:
                mostrarEstudiantes(estudiantes, cantidad);
                break;
            case 3:
                buscarestudiante(estudiantes,cantidad);
                break;
            case 4:
                modificarEstudiantes(estudiantes, cantidad);
                break;
            case 5:
            cout<<"Saliendo..."<<endl;
            break;
            default:
                cout<<"Opcion no valida, intente de nuevo."<<endl;
        }
        system("pause");//aca ocupo el system("pause") para hacer una pausa antes de que suceda lo siguiente

    } while (opcion != 5);
    system("cls");

    return 0;
}
 void ingresarEstudiantes(estudiante estudiantes[], int &cantidad) {
    int n;
    cout<<"Cuantos estudiantes desea ingresar? ";
    cin>>n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        system("cls");
        cout<<"Ingresando estudiante No. " << cantidad + 1 << endl;
        cout<<"Nombre: ";
        getline(cin, estudiantes[cantidad].nombre);//Esto permite que pueda escribir las palabras con espacios entre ellas
        cout<<"Edad: ";
        cin>>estudiantes[cantidad].edad;
        cin.ignore();
        cout<<"Ingrese las 5 calificaciones:" << endl;
        for(int j = 0; j < 5; j++) {
            cout << "Nota " << j + 1 << ": ";
            cin >> estudiantes[cantidad].notas[j];
        }
        cin.ignore();
        cout<<"Direccion del estudiante:"<<endl;
        cout<<"Calle: ";
        getline(cin, estudiantes[cantidad].Dccion.calle);
        cout <<"Numero: ";
        cin>>estudiantes[cantidad].Dccion.numero;
        cin.ignore();
        cout<< "Ciudad: ";
        getline(cin, estudiantes[cantidad].Dccion.ciudad);
        cantidad++;
    }
    cout << "Se ingresaron los Datos correctamente."<<endl;
}
void buscarestudiante(estudiante estudiantes[], int cantidad){
    system("cls");
    if (cantidad==0){//con esto se verifica si hay datos ingresados anteriormente en el "sistema de datos", en pocas palabras es una validacion(se repite en el codigo)
        cout<<"No hay informacion guardada. "<<endl;
        return;
    }else{//Cuando no es lo otro y si hay datos en el "sistema", se va a proceder a relizar este apartado del codigo
        string BuscarNombreEst;
        cout<<"Ingrese el dombre del Estudiante al que desea buscar: ";
        getline(cin,BuscarNombreEst);

        bool SeEncontro= false;//Se declara como falso, por que mas adelate se cambia a 'true'
        for(int i=0;i<cantidad;i++){//Con el for Buscamos en el Arreglo los estudiante guardados
            if(estudiantes[i].nombre == BuscarNombreEst){//cuando uno de los nombre guardados en arreglo coincide con el que escribio el usuarip
                cout<<"El Estudiante se ha encontrado en el sistema de datos: "<<endl;
                cout<<"Nombre: "<<estudiantes[i].nombre<<endl;
                cout<<"Edad: "<<estudiantes[i].edad<<endl;
                cout<<"Notas: ";
                for(int m=0;m<5;m++){//repasa las notas guardadas
                    cout<<estudiantes[i].notas[m]<<" ";
                }
                cout<< endl;
                cout<<"Direccion: "<<estudiantes[i].Dccion.numero<<", "<<estudiantes[i].Dccion.ciudad<<endl;
                SeEncontro=true;
                break;
            }
        }
        if(!SeEncontro){//como anteriormete se declaro como 'true', el '!' indica que no se encontro nada.
            cout<<"No se encontro informacion en la base de datos. "<<endl;
        }
    }
};
void mostrarEstudiantes(estudiante estudiantes[], int cantidad){//Esta funcion basicamente hace exactamete lo mismo que "buscarEstudiante()", solo que esta no busca nada en especifico, muestra a todos los alumnos que estan en el "sistema"
    system("cls");
    if (cantidad==0){
        cout<<"No hay informacion guardada. "<<endl;
        return;
    }else{
        for(int i=0; i<cantidad; i++){
            cout<<"---------Listado de estudiantes en el Sitema---------"<<endl;
            cout<<"Estudiante No. "<<i+1<<endl;
            cout<<"Nombre: "<<estudiantes[i].nombre<<endl;
            cout<<"Edad: "<<estudiantes[i].edad<<endl;
            cout<<"Notas: ";
            for(int k=0;k<5;k++){
                cout<<estudiantes[i].notas[k]<<", ";
            }
            cout<<endl;
            cout<<"direccion: "<<estudiantes[i].Dccion.calle<<" "<<estudiantes[i].Dccion.numero<<", "<<estudiantes[i].Dccion.ciudad<<endl;
        }
    }
};
void modificarEstudiantes(estudiante estudiantes[], int cantidad){
    system("cls");
    if (cantidad==0){
        cout<<"No hay informacion guardada. "<<endl;
        return;
    }else{
        string BuscarNombre;
        cout<<"NOmbre del estudiante que quiera modificar: ";
        getline(cin, BuscarNombre);
        bool SeEncontro=false;
        for(int i=0; i<cantidad;i++){
            if (estudiantes[i].nombre==BuscarNombre){
                cout<<"Nuevo Nombre: ";
                getline(cin, estudiantes[i].nombre);
                cout<<"Nueva edad: ";
                cin>>estudiantes[i].edad;
                cin.ignore();
                cout<<"Nuevas Notas: ";
                for(int l=0;l<5;l++){
                    cout<<"Nota "<<l+1<<": ";
                    cin>> estudiantes[i].notas[l];
                }
                cin.ignore();
                cout<<"Nueva Direccion."<<endl;
                cout<<"Nueva calle:";
                getline(cin, estudiantes[i].Dccion.calle);
                cout<<"Nuevo Numero: ";
                cin>> estudiantes[i].Dccion.numero;
                cin.ignore();
                cout<<"Nueva Ciudad: ";
                getline(cin, estudiantes[i].Dccion.ciudad);
                cout<<"Datos actualizados correctamente. "<<endl;
                SeEncontro=true;
                break;
            }
        }
        if (!SeEncontro){
            cout<<"No HAy datos del estudiante."<<endl;
        }
    }
}