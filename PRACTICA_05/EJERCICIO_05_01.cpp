// Materia: Programacion I, Paralelo 4
// Autor: Leonardo Delgado Medrano
// Fecha creacion: 25/09/2023
// Fecha modificacion: 25/09/2023
// Numero de ejericio: 1
// Problema planteado: La información de todos los empleados de la UCB se almacena en una variable tipo struct llamada “empleado”.
// La información con que se cuenta es: nombre, ci, departamento y salario.
// Realizar un programa en C++ que lea un array de estructura de los datos de N
// empleados e imprima los siguiente:
// • Empleado con mayor salario
// • Empleado con menor salario
// • Promedio salarial
// • Promedio por departamento
// • Departamento con mayor salario en promedio
// • Departamento con menor salario en promedio
#include <iostream>
#include <string>
using namespace std;
struct Empleado
{
    string nombre;
    int ci;
    string departamento;
    double salario;
};
int main()
{
    int N;
    cout << "Ingrese el numero de empleados: ";
    cin >> N;
    Empleado empleados[N];
    // Leer datos de los empleados
    for (int i = 0; i < N; i++)
    {
        cout << "Empleado #" << i + 1 << ":\n";
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, empleados[i].nombre);
        cout << "CI: ";
        cin >> empleados[i].ci;
        cout << "Departamento: \n";
        char depa;
        cout<<"(L) La Paz\n"<<"(C) Cochabamba\n"<<"(S) Santa Cruz\n"<<"(T) Tarija\n";
        cin>>depa;
        if(depa=='L')
            empleados[i].departamento="La Paz";
        if(depa=='C')
            empleados[i].departamento="Cochabamba";
        if(depa=='S')
            empleados[i].departamento="Santa Cruz";
        if(depa=='T')
            empleados[i].departamento="Tarija";
        cout << "Salario: ";
        cin >> empleados[i].salario;
    }
    Empleado empleadoMayorSalario = empleados[0];
    Empleado empleadoMenorSalario = empleados[0];
    double sumaSalarios = 0;
    double promedioSalario;
    double sumaSalariosPorDepartamento = 0;
    int conteoEmpleadosPorDepartamento = 0;
    string departamentoMayorSalario;
    double mayorSalarioPromedio = 0;
    string departamentoMenorSalario;
    double menorSalarioPromedio = empleados[0].salario;
    //Calcula el promedio salarialy el mejor y peor sueldo
    for (int i = 0; i < N; i++)
    {
        if (empleados[i].salario > empleadoMayorSalario.salario)
            empleadoMayorSalario = empleados[i];
        if (empleados[i].salario < empleadoMenorSalario.salario)
            empleadoMenorSalario = empleados[i];
        sumaSalarios += empleados[i].salario;
    }
    promedioSalario = sumaSalarios / N;
    //Calcula el promedio salarial por departamento
    for (int i = 0; i < N; i++)
    {
        sumaSalariosPorDepartamento = 0;
        conteoEmpleadosPorDepartamento = 0;
        for (int j = 0; j < N; j++)
        {
            if (empleados[i].departamento == empleados[j].departamento)
            {
                sumaSalariosPorDepartamento += empleados[j].salario;
                conteoEmpleadosPorDepartamento++;
            }
        }
        double promedioPorDepartamento = sumaSalariosPorDepartamento / conteoEmpleadosPorDepartamento;
        if (promedioPorDepartamento > mayorSalarioPromedio)
        {
            mayorSalarioPromedio = promedioPorDepartamento;
            departamentoMayorSalario = empleados[i].departamento;
        }
        if (promedioPorDepartamento < menorSalarioPromedio)
        {
            menorSalarioPromedio = promedioPorDepartamento;
            departamentoMenorSalario = empleados[i].departamento;
        }
    }
    // Imprimir resultados
    cout << "Empleado con mayor salario:\n";
    cout << "Nombre: " << empleadoMayorSalario.nombre << ", CI: " << empleadoMayorSalario.ci << ", Departamento: " << empleadoMayorSalario.departamento << ", Salario: " << empleadoMayorSalario.salario << endl;
    cout << "Empleado con menor salario:\n";
    cout << "Nombre: " << empleadoMenorSalario.nombre << ", CI: " << empleadoMenorSalario.ci << ", Departamento: " << empleadoMenorSalario.departamento << ", Salario: " << empleadoMenorSalario.salario << endl;
    cout << "Promedio salarial: " << promedioSalario << endl;
    cout << "Promedio por departamento:\n";
    cout << "Departamento con mayor salario en promedio: " << departamentoMayorSalario << ", Salario promedio: " << mayorSalarioPromedio << endl;
    cout << "Departamento con menor salario en promedio: " << departamentoMenorSalario << ", Salario promedio: " << menorSalarioPromedio << endl;
    return 0;
}

