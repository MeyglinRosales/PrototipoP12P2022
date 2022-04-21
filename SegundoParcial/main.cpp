#include <iostream>
#include<conio.h>
#include "Persona.h"
#include "Bitacora.h"
#include "Puesto.h"
#include "Departamento.h"
#include "Usuarios.h"
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <ctime>
#include <vector>
#include <fstream>

using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>

using std::setw;
using std::setprecision;

#include <cstdlib>
using namespace std;
//Declaracion de las funciones para abrir los menus
void Catalogoclientes();
void CatalogoVendedores();
void CatalogoMarcas();
void CatalogoLineas();
void CatalogoProductos();
void Informes();
void seguridad();
void bitacoramenu();


//Inicio de main
int main(int argc, char *argv[])
{
    Puesto gesPuesto;
    Bitacora control;

    //Llamado a clase Usuarios para el Login
    bool accesoUsuarios;
    Usuarios usuarioRegistrado;
    accesoUsuarios=usuarioRegistrado.loginUsuarios();


//inicio menu principal
int choice;
	char x;
	do
    {
	system("cls");
	//Funcion que imprime Fecha  y Hora
	control.fechaHora();
	cout<<"\t\t\t    SISTEMA RECURSOS HUMANOS    "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Catalogo clientes"<<endl;
	cout<<"\t\t\t 2. Catalogo Vendedores"<<endl;
	cout<<"\t\t\t 3. Catalogo Marcas"<<endl;
	cout<<"\t\t\t 4. Catalogo Lineas"<<endl;
	cout<<"\t\t\t 5. Catalogo Productos"<<endl;
	cout<<"\t\t\t 6. Procesos"<<endl;
	cout<<"\t\t\t 7. Informes"<<endl;
	cout<<"\t\t\t 8. salir "<<endl;


	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6/7/8]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;
//Llamadas a los menus secundarios
    switch(choice)
    {
    case 1:
        //Se envia a la Bitacora la accion realizada por el usuario
        control.nuevaActividadTxt(1);
        control.nuevaActividad(1);
        Catalogoclientes();
		break;
	case 2:
        control.nuevaActividadTxt(2);
        control.nuevaActividad(2);
        CatalogoVendedores();
		break;
	case 3:
	    control.nuevaActividadTxt(3);
        control.nuevaActividad(3);
        CatalogoMarcas();
		break;
    case 4:
	    control.nuevaActividadTxt(3);
        control.nuevaActividad(3);
        CatalogoLineas();
		break;
    case 5:
	    control.nuevaActividadTxt(3);
        control.nuevaActividad(3);
        CatalogoProductos();
		break;
   case 6:
        control.nuevaActividadTxt(4);
        control.nuevaActividad(4);
        gesPuesto.menu();
		break;
    case 7:
	    control.nuevaActividadTxt(3);
        control.nuevaActividad(3);
        Informes();
		break;
	case 8:
	    control.nuevaActividadTxt(6);
        control.nuevaActividad(6);
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(choice!= 8);
    return 0;
}
//Declaracion menu consultas

void Catalogoclientes()
{
    Bitacora control;
    Persona empleado;

    fstream empleadosEntradaSalida = empleado.inicioArchivo();
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    Catalogo Clientes "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consulta Cliente"<<endl;
	cout<<"\t\t\t 2. Busqueda de Cliente"<<endl;
	cout<<"\t\t\t 3. Agregar Cliente"<<endl;
	cout<<"\t\t\t 4. Modificar Cliente"<<endl;
	cout<<"\t\t\t 5. Eliminar Cliente"<<endl;
	cout<<"\t\t\t 6. Imprimir Archivo Cliente"<<endl;
	cout<<"\t\t\t 7. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6/7]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        control.nuevaActividadTxt(16);
        control.nuevaActividad(16);
        empleado.consultarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 2:
	    control.nuevaActividadTxt(17);
        control.nuevaActividad(17);
        empleado.busquedaRegistro(empleadosEntradaSalida);
		break;
	case 3:
	    control.nuevaActividadTxt(18);
        control.nuevaActividad(18);
        empleado.nuevoRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado agregado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 4:
	    control.nuevaActividadTxt(19);
        control.nuevaActividad(19);
        empleado.actualizarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado modificado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 5:
	    control.nuevaActividadTxt(20);
        control.nuevaActividad(20);
        empleado.eliminarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado eliminado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
    case 6:
        control.nuevaActividadTxt(21);
        control.nuevaActividad(21);
        empleado.imprimirRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Informacion impresa satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 7:
	        cout<<"Presione Enter para confirmar"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	empleadosEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    getch();
    }while(choice!= 7);
}
void CatalogoVendedores()
{
    Bitacora control;
    Persona empleado;

    fstream empleadosEntradaSalida = empleado.inicioArchivo();
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    Catalogo Vendedores "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consulta Cliente"<<endl;
	cout<<"\t\t\t 2. Busqueda de Cliente"<<endl;
	cout<<"\t\t\t 3. Agregar Cliente"<<endl;
	cout<<"\t\t\t 4. Modificar Cliente"<<endl;
	cout<<"\t\t\t 5. Eliminar Cliente"<<endl;
	cout<<"\t\t\t 6. Imprimir Archivo Cliente"<<endl;
	cout<<"\t\t\t 7. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6/7]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        control.nuevaActividadTxt(16);
        control.nuevaActividad(16);
        empleado.consultarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 2:
	    control.nuevaActividadTxt(17);
        control.nuevaActividad(17);
        empleado.busquedaRegistro(empleadosEntradaSalida);
		break;
	case 3:
	    control.nuevaActividadTxt(18);
        control.nuevaActividad(18);
        empleado.nuevoRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado agregado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 4:
	    control.nuevaActividadTxt(19);
        control.nuevaActividad(19);
        empleado.actualizarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado modificado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 5:
	    control.nuevaActividadTxt(20);
        control.nuevaActividad(20);
        empleado.eliminarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado eliminado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
    case 6:
        control.nuevaActividadTxt(21);
        control.nuevaActividad(21);
        empleado.imprimirRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Informacion impresa satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 7:
	        cout<<"Presione Enter para confirmar"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	empleadosEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    getch();
    }while(choice!= 7);
}
void CatalogoMarcas()
{
    Bitacora control;
    Persona empleado;

    fstream empleadosEntradaSalida = empleado.inicioArchivo();
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    Catalogo Marcas "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consulta Marcas"<<endl;
	cout<<"\t\t\t 2. Busqueda de Marcas"<<endl;
	cout<<"\t\t\t 3. Agregar Marcas"<<endl;
	cout<<"\t\t\t 4. Modificar Marcas"<<endl;
	cout<<"\t\t\t 5. Eliminar Marcas"<<endl;
	cout<<"\t\t\t 6. Imprimir Archivo Marcas"<<endl;
	cout<<"\t\t\t 7. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6/7]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        control.nuevaActividadTxt(16);
        control.nuevaActividad(16);
        empleado.consultarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 2:
	    control.nuevaActividadTxt(17);
        control.nuevaActividad(17);
        empleado.busquedaRegistro(empleadosEntradaSalida);
		break;
	case 3:
	    control.nuevaActividadTxt(18);
        control.nuevaActividad(18);
        empleado.nuevoRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado agregado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 4:
	    control.nuevaActividadTxt(19);
        control.nuevaActividad(19);
        empleado.actualizarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado modificado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 5:
	    control.nuevaActividadTxt(20);
        control.nuevaActividad(20);
        empleado.eliminarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado eliminado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
    case 6:
        control.nuevaActividadTxt(21);
        control.nuevaActividad(21);
        empleado.imprimirRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Informacion impresa satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 7:
	        cout<<"Presione Enter para confirmar"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	empleadosEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    getch();
    }while(choice!= 7);
}
void CatalogoLineas()
{
    Bitacora control;
    Persona empleado;

    fstream empleadosEntradaSalida = empleado.inicioArchivo();
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    Catalogo Lineas "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consulta Lineas"<<endl;
	cout<<"\t\t\t 2. Busqueda de Lineas"<<endl;
	cout<<"\t\t\t 3. Agregar Lineas"<<endl;
	cout<<"\t\t\t 4. Modificar Lineas"<<endl;
	cout<<"\t\t\t 5. Eliminar Lineas"<<endl;
	cout<<"\t\t\t 6. Imprimir Archivo Lineas"<<endl;
	cout<<"\t\t\t 7. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6/7]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        control.nuevaActividadTxt(16);
        control.nuevaActividad(16);
        empleado.consultarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 2:
	    control.nuevaActividadTxt(17);
        control.nuevaActividad(17);
        empleado.busquedaRegistro(empleadosEntradaSalida);
		break;
	case 3:
	    control.nuevaActividadTxt(18);
        control.nuevaActividad(18);
        empleado.nuevoRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado agregado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 4:
	    control.nuevaActividadTxt(19);
        control.nuevaActividad(19);
        empleado.actualizarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado modificado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 5:
	    control.nuevaActividadTxt(20);
        control.nuevaActividad(20);
        empleado.eliminarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado eliminado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
    case 6:
        control.nuevaActividadTxt(21);
        control.nuevaActividad(21);
        empleado.imprimirRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Informacion impresa satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 7:
	        cout<<"Presione Enter para confirmar"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	empleadosEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    getch();
    }while(choice!= 7);
}
void CatalogoProductos()
{
    Bitacora control;
    Persona empleado;

    fstream empleadosEntradaSalida = empleado.inicioArchivo();
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    Catalogo Productos "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consulta Productos"<<endl;
	cout<<"\t\t\t 2. Busqueda de Productos"<<endl;
	cout<<"\t\t\t 3. Agregar Productos"<<endl;
	cout<<"\t\t\t 4. Modificar Productos"<<endl;
	cout<<"\t\t\t 5. Eliminar Productos"<<endl;
	cout<<"\t\t\t 6. Imprimir Archivo Productos"<<endl;
	cout<<"\t\t\t 7. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6/7]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        control.nuevaActividadTxt(16);
        control.nuevaActividad(16);
        empleado.consultarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 2:
	    control.nuevaActividadTxt(17);
        control.nuevaActividad(17);
        empleado.busquedaRegistro(empleadosEntradaSalida);
		break;
	case 3:
	    control.nuevaActividadTxt(18);
        control.nuevaActividad(18);
        empleado.nuevoRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado agregado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 4:
	    control.nuevaActividadTxt(19);
        control.nuevaActividad(19);
        empleado.actualizarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado modificado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 5:
	    control.nuevaActividadTxt(20);
        control.nuevaActividad(20);
        empleado.eliminarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado eliminado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
    case 6:
        control.nuevaActividadTxt(21);
        control.nuevaActividad(21);
        empleado.imprimirRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Informacion impresa satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 7:
	        cout<<"Presione Enter para confirmar"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	empleadosEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    getch();
    }while(choice!= 7);
}


void Informes()
{
    //Creacion de un objeto de la clase Persona
    Persona empleado;
    Bitacora control;
    fstream empleadosEntradaSalida = empleado.inicioArchivo();

    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    CONSULTAS    "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consulta Empleados"<<endl;
	cout<<"\t\t\t 2. Consulta Departamentos"<<endl;
	cout<<"\t\t\t 3. Consulta Sueldos"<<endl;
	cout<<"\t\t\t 4. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        control.nuevaActividadTxt(7);
        control.nuevaActividad(7);
        empleado.consultarRegistro(empleadosEntradaSalida);
		break;
	case 2:
	    control.nuevaActividadTxt(8);
        control.nuevaActividad(8);
        cout<<"Estamos trabajando en la Consulta de Departamentos"<<endl;
        cout << "Presiona Enter para aceptar"<<endl;
		break;
	case 3:
	    control.nuevaActividadTxt(9);
        control.nuevaActividad(9);
        cout<<"Estamos trabajando en la Consulta de Sueldos"<<endl;
        cout << "Presiona Enter para aceptar"<<endl;
		break;
	case 4:
	        cout<<"Presione Enter para confirmar"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	empleadosEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    getch();
    }while(choice!= 4);
}

void seguridad()
{
    Bitacora control;
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    SEGURIDAD    "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Cambio de Usuario"<<endl;
	cout<<"\t\t\t 2. Cambio de Contraseña"<<endl;
	cout<<"\t\t\t 3. Bitacoras"<<endl;
	cout<<"\t\t\t 4. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        control.nuevaActividadTxt(22);
        control.nuevaActividad(22);
        cout<<"Estamos trabajando en el Cambio de Usuario"<<endl;
        cout << "Presiona Enter para aceptar"<<endl;
		break;
	case 2:
	    control.nuevaActividadTxt(23);
        control.nuevaActividad(23);
        cout<<"Estamos trabajando en la Cambio de Contraseña"<<endl;
        cout << "Presiona Enter para aceptar"<<endl;
		break;
	case 3:
	    control.nuevaActividadTxt(24);
        control.nuevaActividad(24);
        cout<<"Archivo Bitacora creado satisfactoriamente"<<endl;
        cout << "Presiona Enter para aceptar"<<endl;
		break;
	case 4:
	    cout <<"Presiona Enter para confirmar"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}getch();
    }while(choice!= 4);
}


