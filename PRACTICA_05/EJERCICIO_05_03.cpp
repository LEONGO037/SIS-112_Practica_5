// Materia: Programacion I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creacion: 25/09/2023
// Fecha modificacion: 25/09/2023
// Numero de ejericio: 3
// Problema planteado: Realice un programa en C++ con funciones y estructuras para el estacionamiento del Multicine.
// Este estacionamiento cuenta con 4 pisos, cada piso tiene distintas capacidades de autos
#include<iostream>
#include<string>
#include<random>
#include<cstdlib>
#include<ctime>
using namespace std;
struct Auto
{
    string tipo;
    string marca;
    string modelo;
    string color;
};
//Funcion que saca al azar
string TipoModelo(string tip1, string tip2, string tip3, string tip4);
Auto Model();
int main ()
{
    Auto Piso1[50];
    Auto Piso2[40];
    Auto Piso3[30];
    Auto Piso4[45];
    int total = 165;
    int cantidad=1;
    int p1=0,p2=0,p3=0,p4=0;
    srand(time(0));
    while(total>0 && cantidad>0)
    {
        cout<<"Ingrese la cantidad de vehiculos que entran al parqueo: ";
        cin>>cantidad;
        total-=cantidad;
        for(int i=0;i<cantidad;i++)
        {
            bool repetir=true;
            while(repetir)
            {
                int pisito=rand()%(5);
                switch(pisito)
                {
                case 1:
                    {
                        if(p1<50)
                        {
                            Piso1[p1]=Model();
                            p1++;
                            repetir=false;
                        }
                        else
                            repetir=true;
                        break;
                    }
                case 2:
                    {
                        if(p2<40)
                        {
                            Piso2[p2]=Model();
                            p2++;
                            repetir=false;
                        }
                        else
                            repetir=true;
                        break;
                    }
                case 3:
                    {
                        if(p3<30)
                        {
                            Piso3[p3]=Model();
                            p3++;
                            repetir=false;
                        }
                        else
                            repetir=true;
                        break;
                    }
                case 4:
                    {
                        if(p4<45)
                        {
                            Piso4[p4]=Model();
                            p4++;
                            repetir=false;
                        }
                        else
                            repetir=true;
                        break;
                    }
                }
            }
        }
    }
    cout<<"  ***Piso 1***\n";
    for(int i=0;i<p1;i++)
    {
        cout<<"*Espacio de estacionamiento "<<i+1<<endl;
        cout<<"Tipo: "<<Piso1[i].tipo<<endl;
        cout<<"Marca: "<<Piso1[i].marca<<endl;
        cout<<"Modelo: "<<Piso1[i].modelo<<endl;
        cout<<"Color: "<<Piso1[i].color<<endl;
    }
    cout<<"  ***Piso 2***\n";
    for(int i=0;i<p2;i++)
    {
        cout<<"*Espacio de estacionamiento "<<i+1<<endl;
        cout<<"Tipo: "<<Piso2[i].tipo<<endl;
        cout<<"Marca: "<<Piso2[i].marca<<endl;
        cout<<"Modelo: "<<Piso2[i].modelo<<endl;
        cout<<"Color: "<<Piso2[i].color<<endl;
    }
    cout<<"  ***Piso 3***\n";
    for(int i=0;i<p3;i++)
    {
        cout<<"*Espacio de estacionamiento "<<i+1<<endl;
        cout<<"Tipo: "<<Piso3[i].tipo<<endl;
        cout<<"Marca: "<<Piso3[i].marca<<endl;
        cout<<"Modelo: "<<Piso3[i].modelo<<endl;
        cout<<"Color: "<<Piso3[i].color<<endl;
    }
    cout<<"  ***Piso 4***\n";
    for(int i=0;i<p4;i++)
    {
        cout<<"*Espacio de estacionamiento "<<i+1<<endl;
        cout<<"Tipo: "<<Piso4[i].tipo<<endl;
        cout<<"Marca: "<<Piso4[i].marca<<endl;
        cout<<"Modelo: "<<Piso4[i].modelo<<endl;
        cout<<"Color: "<<Piso4[i].color<<endl;
    }
    return 0;
}
string TipoModelo(string tip1, string tip2, string tip3, string tip4)
{
    int des=rand()%(5);
    switch(des)
    {
    case 1:
        return tip1;
        break;
    case 2:
        return tip2;
        break;
    case 3:
        return tip3;
        break;
    case 4:
        return tip4;
        break;
    }
}
Auto Model()
{
    Auto autito;
    autito.tipo=TipoModelo("Vagoneta","Camioneta","Deportivo","Motocicleta");
    autito.marca=TipoModelo("Mercedez Benz","BMW","Audi","Mazda");
    autito.modelo=TipoModelo("GLE","M","R8","CX-5");
    autito.color=TipoModelo("Rojo","Negro","Plomo","Azul");
    return autito;
}
