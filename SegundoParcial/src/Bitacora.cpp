#include "Bitacora.h"
#include "Persona.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Usuarios.h"

using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>

using std::setw;
using std::setprecision;

#include <cstdlib>
using namespace std;

Bitacora::Bitacora()
{
}

Bitacora::~Bitacora()
{
    //dtor
}

string Bitacora::obtenerAccion(int opcion)
{

}


//Funcion que establece la fecha y la hora
Bitacora::fechaHora()
{
    //se establece la hora
    time_t now = time(0);
    tm * time = localtime(&now);

    //se establece el dia de la semana
    vector<string> dia_semana;
    dia_semana.push_back("Domingo");
    dia_semana.push_back("Lunes");
    dia_semana.push_back("Martes");
    dia_semana.push_back("Miercoles");
    dia_semana.push_back("Jueves");
    dia_semana.push_back("Viernes");
    dia_semana.push_back("Sabado");

    //se establece el mes
    vector<string> mes;
    mes.push_back("Enero");
    mes.push_back("Febrero");
    mes.push_back("Marzo");
    mes.push_back("Abril");
    mes.push_back("Mayo");
    mes.push_back("Junio");
    mes.push_back("Julio");
    mes.push_back("Agosto");
    mes.push_back("Septiembre");
    mes.push_back("Octubre");
    mes.push_back("Noviembre");
    mes.push_back("Diciembre");

    //se establece el año
    int year = 1900 + time->tm_year;

    cout<<"\t\t\t-----------------------------------------------------------------"<<endl;
    cout << "\t\t\tHoy " << dia_semana[time->tm_wday] << ", ";
    cout << time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
    cout <<"\t\t\tHora: "<< time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;
    cout<<"\t\t\t-----------------------------------------------------------------"<<endl;
}

//Funcion para agregar informacion a la bitacora(binario)
Bitacora::nuevaActividad(int opcion)
{
    Usuarios user;
    fstream file;
    Bitacora control;
        time_t now = time(0);
    tm * time = localtime(&now);

    vector<string> dia_semana;
    dia_semana.push_back("Domingo");
    dia_semana.push_back("Lunes");
    dia_semana.push_back("Martes");
    dia_semana.push_back("Miercoles");
    dia_semana.push_back("Jueves");
    dia_semana.push_back("Viernes");
    dia_semana.push_back("Sabado");

    vector<string> mes;
    mes.push_back("01");
    mes.push_back("02");
    mes.push_back("03");
    mes.push_back("04");
    mes.push_back("05");
    mes.push_back("06");
    mes.push_back("07");
    mes.push_back("08");
    mes.push_back("09");
    mes.push_back("10");
    mes.push_back("11");
    mes.push_back("12");

    int year = 1900 + time->tm_year;
    control.year = year;
    std::stringstream ss1;
    ss1 << time->tm_mday;
    std::string diass = ss1.str();

    std::stringstream ss2;
    ss2 << mes[time->tm_mon];
    std::string messs = ss2.str();

    std::stringstream ss3;
    ss3 << time->tm_hour;
    std::string horass = ss3.str();

    std::stringstream ss4;
    ss4 << time->tm_min;
    std::string minutoss = ss4.str();

    std::stringstream ss5;
    ss5 << time->tm_sec;
    std::string segundoss = ss5.str();
    string accion = control.app;

    control.dia = diass;
    control.mesch = messs;
    control.horas = horass;
    control.minutos = minutoss;
    control.segundos = segundoss;
    string accion1;
    string userPP = "Grupo4";

    //switch que define que está haciendo el usuario
    switch(opcion){

    case 1:
        accion1 = "Ingreso a Menu Consultas";
        break;
    case 2:
        accion1 = "Ingreso a Menu Contabilidad";
        break;
    case 3:
        accion1 = "Ingreso a Gestion de Empleados";
        break;
    case 4:
        accion1 = "Ingreso a Gestion de Puestos";
        break;
    case 5:
        accion1 = "Ingreso a Menu Seguridad";
        break;
    case 6:
        accion1 = "Cierre del Programa";
        break;
    case 7:
        accion1 = "Se realizo consulta de Empleados";
        break;
    case 8:
        accion1 = "Se realizo consulta de Departamentos";
        break;
    case 9:
        accion1 = "Se realizo consulta de Sueldos";
        break;
    case 10:
        accion1 = "Se realizo consulta de Nomina";
        break;
    case 11:
        accion1 = "Se realizo consulta de Poliza";
        break;
    case 12:
        accion1 = "Se realizo consulta de Planillas";
        break;
    case 13:
        accion1 = "Se realizo consulta de Retenciones";
        break;
    case 14:
        accion1 = "Se realizo consulta de Salarios";
        break;
    case 15:
        accion1 = "Se ingreso al Menu Transferencias";
        break;
    case 16:
        accion1 = "Se realizo consulta de Empleados";
        break;
    case 17:
        accion1 = "Se realizo Busqueda de Empleado";
        break;
    case 18:
        accion1 = "Se agrego un nuevo Empleado";
        break;
    case 19:
        accion1 = "Se actualizo a un empleado";
        break;
    case 20:
        accion1 = "Se elimino a un empleado";
        break;
    case 21:
        accion1 = "Se imprimio el registro de empleados";
        break;
    case 22:
        accion1 = "Se realizo un cambio de usuario";
        break;
    case 23:
        accion1 = "Se realizo un cambio de contraseña";
        break;
    case 24:
        accion1 = "Se imprimio la Bitacora";
        break;
    case 25:
        accion1 = "Se agrego un nuevo puesto";
        break;
    case 26:
        accion1 = "Se modifico un puesto";
        break;
    case 27:
        accion1 = "Se realizo consulta de Puestos";
        break;
    case 28:
        accion1 = "Se imprimio el registro de puestos";
        break;
    case 33:
        accion1 = "Se elimino un puesto";
        break;
    case 29:
        accion1 = "Se realizo consulta de Departamentos";
        break;
    case 30:
        accion1 = "Ingreso de Contrasena y Usuario Incorrectos";
        break;
    case 31:
        accion1 = "3 fallos de ingreso, cierre del programa";
        break;
    case 32:
        accion1 = "Ingreso de usuario y contrasena exitoso";
        break;

    }

	file.open("bitacora.dat", ios::binary | ios::out);
	file<<std::left<<std::setw(15)<< userPP <<"\n"<< control.dia <<"/"<< control.mesch <<"/"<< control.year <<"\n"<<control.horas<<":"
	<< control.minutos<<":"<<control.segundos<<"\n"<< accion1 <<endl<< "\n";
	file.close();
}
//Funcion para crear la bitacora pero en texto
Bitacora::nuevaActividadTxt(int opcion)
{
    Usuarios user;
    fstream file;
    Bitacora control;
        time_t now = time(0);
    tm * time = localtime(&now);

    vector<string> dia_semana;
    dia_semana.push_back("Domingo");
    dia_semana.push_back("Lunes");
    dia_semana.push_back("Martes");
    dia_semana.push_back("Miercoles");
    dia_semana.push_back("Jueves");
    dia_semana.push_back("Viernes");
    dia_semana.push_back("Sabado");

    vector<string> mes;
    mes.push_back("01");
    mes.push_back("02");
    mes.push_back("03");
    mes.push_back("04");
    mes.push_back("05");
    mes.push_back("06");
    mes.push_back("07");
    mes.push_back("08");
    mes.push_back("09");
    mes.push_back("10");
    mes.push_back("11");
    mes.push_back("12");

    int year = 1900 + time->tm_year;
    control.year = year;
    std::stringstream ss1;
    ss1 << time->tm_mday;
    std::string diass = ss1.str();

    std::stringstream ss2;
    ss2 << mes[time->tm_mon];
    std::string messs = ss2.str();

    std::stringstream ss3;
    ss3 << time->tm_hour;
    std::string horass = ss3.str();

    std::stringstream ss4;
    ss4 << time->tm_min;
    std::string minutoss = ss4.str();

    std::stringstream ss5;
    ss5 << time->tm_sec;
    std::string segundoss = ss5.str();
    string accion = control.app;

    control.dia = diass;
    control.mesch = messs;
    control.horas = horass;
    control.minutos = minutoss;
    control.segundos = segundoss;
    string accion1;
    string userPP = "Grupo4";
    switch(opcion){

    case 1:
        accion1 = "Ingreso a Menu Catalogos";
        break;
    case 2:
        accion1 = "Ingreso a Menu Procesos ";
        break;
    case 3:
        accion1 = "Ingreso a informes";
        break;
    case 4:
        accion1 = "Ingreso a clientes";
        break;
    case 5:
        accion1 = "Ingreso a Menu Seguridad";
        break;
    case 6:
        accion1 = "Cierre del Programa";
        break;
    case 7:
        accion1 = "Se realizo catalogo clientes";
        break;
    case 8:
        accion1 = "Se realizo catalogos vendedores";
        break;
    case 9:
        accion1 = "Se realizo catalogos marcas";
        break;
    case 10:
        accion1 = "Se realizo catalogos lineas";
        break;
    case 11:
        accion1 = "Se realizo catalogos productos";
        break;
    case 12:
        accion1 = "Se realizo consulta de Planillas";
        break;
    case 13:
        accion1 = "Se realizo consulta de Retenciones";
        break;
    case 14:
        accion1 = "Se realizo consulta de Salarios";
        break;
    case 15:
        accion1 = "Se ingreso al Menu Transferencias";
        break;
    case 16:
        accion1 = "Se realizo consulta de Empleados";
        break;
    case 17:
        accion1 = "Se realizo Busqueda de Empleado";
        break;
    case 18:
        accion1 = "Se agrego un nuevo Empleado";
        break;
    case 19:
        accion1 = "Se actualizo a un empleado";
        break;
    case 20:
        accion1 = "Se elimino a un empleado";
        break;
    case 21:
        accion1 = "Se imprimio el registro de empleados";
        break;
    case 22:
        accion1 = "Se realizo un cambio de usuario";
        break;
    case 23:
        accion1 = "Se realizo un cambio de contraseña";
        break;
    case 24:
        accion1 = "Se imprimio la Bitacora";
        break;
    case 25:
        accion1 = "Se agrego un nuevo puesto";
        break;
    case 26:
        accion1 = "Se modifico un puesto";
        break;
    case 27:
        accion1 = "Se realizo consulta de Puestos";
        break;
    case 28:
        accion1 = "Se imprimio el registro de puestos";
        break;
    case 33:
        accion1 = "Se elimino un puesto";
        break;
    case 29:
        accion1 = "Se realizo consulta de Departamentos";
        break;
    case 30:
        accion1 = "Ingreso de Contrasena y Usuario Incorrectos";
        break;
    case 31:
        accion1 = "3 fallos de ingreso, cierre del programa";
        break;
    case 32:
        accion1 = "Ingreso de usuario y contrasena exitoso";
        break;

    }

	file.open("Bitacora.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< userPP <<"\n"<< control.dia <<"/"<< control.mesch <<"/"<< control.year <<"\n"<<control.horas<<":"
	<< control.minutos<<":"<<control.segundos<<"\n"<< accion1 <<endl<< "\n";
	file.close();
}
