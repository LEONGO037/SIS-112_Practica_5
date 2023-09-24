// Materia: Programacion I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creacion: 25/09/2023
// Fecha modificacion: 25/09/2023
// Numero de ejericio: 2
// Problema planteado: La información de todos los empleados de la UCB se almacena en una variable tipo struct llamada “empleado”.
// La información con que se cuenta es: nombre, ci, departamento y salario.
#include <iostream>
#include <string>
using namespace std;
//Definimos las 2 estructuras
struct datos
{
    string nombre;
    string pais;
};
struct atleta
{
    string deporte;
    datos persona;
    int medallas;
};
int main ()
{
    int N;
    cout<<"Ingrese la cantidad de atletas\n";
    cin>>N;
    atleta atletas[N];
    atleta medallista;
    medallista.medallas=0;
    for(int i=0;i<N;i++)
    {
        cout<<"Atleta #"<<i+1<<":\n";
        cout<<"Nombre: ";
        cin>>atletas[i].persona.nombre;
        cout<<"Pais: ";
        cin>>atletas[i].persona.pais;
        cout<<"Deporte: ";
        cin>>atletas[i].deporte;
        cout<<"Numero de medallas: ";
        cin>>atletas[i].medallas;
        if(atletas[i].medallas>medallista.medallas)
        {
            medallista.persona.nombre=atletas[i].persona.nombre;
            medallista.persona.pais=atletas[i].persona.pais;
            medallista.deporte=atletas[i].deporte;
            medallista.medallas=atletas[i].medallas;
        }
    }
    cout<<"    **Deportista con mas medallas**\n";
    cout<<"Nombre: "<<medallista.persona.nombre<<endl;
    cout<<"Pais: "<<medallista.persona.pais<<endl;
    cout<<"Deporte: "<<medallista.deporte<<endl;
    cout<<"Numero de medallas: "<<medallista.medallas<<endl;
    return 0;
}
