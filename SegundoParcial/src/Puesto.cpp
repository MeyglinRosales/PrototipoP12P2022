#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Puesto.h"
#include "Bitacora.h"

Puesto::Puesto()
{
    //ctor
}

Puesto::~Puesto()
{
    //dtor
}
//menu principal de puestos
void Puesto::menu()
{
    Bitacora control;
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t .  SISTEMA GESTION PUESTOS Y DEPARTAMENTOS   ."<<endl;
	cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t 1. Ingreso Puesto"<<endl;
	cout<<"\t\t\t 2. Actualizar Puesto"<<endl;
	cout<<"\t\t\t 3. Consultar Puestos"<<endl;
	cout<<"\t\t\t 4. Imprimir Puesto"<<endl;
	cout<<"\t\t\t 5. Borra Puesto"<<endl;
	cout<<"\t\t\t 6. Consulta Departamentos"<<endl;
	cout<<"\t\t\t 7. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t Opcion a escoger:[1/2/3/4/5/6/7]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    	    control.nuevaActividadTxt(25);
            control.nuevaActividad(25);
    		Ingresar();
    		cout<<"\n\t\t\t Agrega otro Puesto(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		cout <<"Puestos agregados satisfactoriamente"<<endl;
		break;
	case 2:
	    control.nuevaActividadTxt(26);
        control.nuevaActividad(26);
		Actualizar();
		cout <<"Puesto actualizado satisfactoriamente"<<endl;
		break;
	case 3:
	    control.nuevaActividadTxt(27);
        control.nuevaActividad(27);
		Consultar();
		cout <<"Presiona Enter para salir"<<endl;
		break;
	case 4:
	    control.nuevaActividadTxt(28);
        control.nuevaActividad(28);
		Imprimir();
		cout <<"Impresion realizada satisfactoriamente"<<endl;
		break;
	case 5:
	    control.nuevaActividadTxt(33);
        control.nuevaActividad(33);
		Borrar();
		cout <<"Puesto eliminado satisfactoriamente"<<endl;
		break;
    case 6:
        control.nuevaActividadTxt(29);
        control.nuevaActividad(29);
        consultarDep();
        cout <<"Presiona Enter para confirmar"<<endl;
        break;
	case 7:
	    cout << "Presiona Enter para confirmar"<<endl;
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 7);
}

//Funcion que ingresa puestos y departamentos
void Puesto::Ingresar()
{
    Bitacora control;
	system("cls");
	fstream file;
	cout<<"\n.....................................................................................................................";
	cout<<"\n.....................................Agregar detalles de Puesto......................................................"<<endl;
	cout<<"\t\t\tIngresa Departamento del Puesto       : ";
	cin>>Dpuesto;
	cout<<"\t\t\tIngresa el Cargo del Puesto     : ";
	cin>>Crpuesto;
	cout<<"\t\t\tIngresa Salario del Puesto   : ";
	cin>>Spuesto;
	cout<<"\t\t\tIngresa hora de entrada  : ";
	cin>>Hentrada;
	cout<<"\t\t\tIngresa hora de salida  : ";
	cin>>Hsalida;
	file.open("PUESTO.dat", ios::out | ios::binary);
	file<<std::left<<std::setw(15)<< Dpuesto <<std::left<<std::setw(15)<< Crpuesto <<std::left<<std::setw(15)<< Spuesto <<std::left<<std::setw(15)<< Hentrada <<std::left<<std::setw(15)<< Hsalida << "\n";
	file.close();
    file.open("PUESTO.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< Dpuesto <<std::left<<std::setw(15)<< Crpuesto <<std::left<<std::setw(15)<< Spuesto <<std::left<<std::setw(15)<< Hentrada <<std::left<<std::setw(15)<< Hsalida << "\n";
	file.close();
}

//Funcion para imprimir los datos de puestos
void Puesto::Imprimir()
{
    Bitacora control;
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n..............................Tabla de Detalles de Puesto ........................"<<endl;
	file.open("PUESTO.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> Dpuesto >> Crpuesto>> Spuesto >> Hentrada >> Hsalida;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Departamento: "<<Dpuesto<<endl;
			cout<<"\t\t\t Nombre del cargo: "<<Crpuesto<<endl;
			cout<<"\t\t\t Salario: "<<Spuesto<<endl;
			cout<<"\t\t\t Hora de entrada: "<<Hentrada<<endl;
			cout<<"\t\t\t Hora de salida: "<<Hsalida<<endl;
			file >> Dpuesto >> Crpuesto>> Spuesto >> Hentrada >> Hsalida;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}

//funcion para modificar puestos y departamentos
void Puesto::Actualizar()
{
    Bitacora control;
	system("cls");
	fstream file,file1;
	string participant_Dp;
	int found=0;
	cout<<"\n.............................Modificacion Detalles Puesto................................."<<endl;
	file.open("PUESTO.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Departamento de la personas que quiere modificar: ";
		cin>>participant_Dp;
		file1.open("Record.txt",ios::app | ios::out);
		file >> Dpuesto >> Crpuesto>> Spuesto >> Hentrada >> Hsalida;
		while(!file.eof())
		{
			if(participant_Dp!=Dpuesto)
			{
			 file1<<std::left<<std::setw(15)<< Dpuesto <<std::left<<std::setw(15)<< Crpuesto <<std::left<<std::setw(15)<< Spuesto <<std::left<<std::setw(15)<< Hentrada <<std::left<<std::setw(15)<< Hsalida << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Departamento del Puesto: ";
				cin>>Dpuesto;
				cout<<"\t\t\tIngrese Cargo del Puesto: ";
				cin>>Crpuesto;
				cout<<"\t\t\tIngresa Salario del Puesto: ";
				cin>>Spuesto;
				cout<<"\t\t\tIngrese hora de entrada: ";
				cin>>Hentrada;
				cout<<"\t\t\tIngresa hora de salida: ";
				cin>>Hsalida;
				file1<<std::left<<std::setw(15)<< Dpuesto <<std::left<<std::setw(15)<< Crpuesto <<std::left<<std::setw(15)<< Spuesto <<std::left<<std::setw(15)<< Hentrada <<std::left<<std::setw(15)<< Hsalida << "\n";
				found++;
			}
			file >> Dpuesto >> Crpuesto >>Spuesto >> Hentrada >> Hsalida;

		}
		file1.close();
		file.close();
		remove("ParticipantRecord.txt");
		rename("Record.txt","ParticipantRecord.txt");
	}
}

//funcion para conultar puestos y departamentos
void Puesto::Consultar()
{
    Bitacora control;
	system("cls");
	fstream file;
	int found=0;
	file.open("PUESTO.txt",ios::in);
	if(!file)
	{
		cout<<"\n..................................Datos del Puesto buscado......................................"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_Dp;
		cout<<"\n..................................Datos del puesto buscado......................................"<<endl;
		cout<<"\nIngrese Departamento de la Persona que quiere buscar: ";
		cin>>participant_Dp;
		file >> Dpuesto >> Crpuesto >> Spuesto >> Hentrada >> Hsalida;
		while(!file.eof())
		{
			if(participant_Dp==Dpuesto)
			{
				cout<<"\n\n\t\t\t Departamento: "<<Dpuesto<<endl;
                cout<<"\t\t\t Nombre del cargo: "<<Crpuesto<<endl;
                cout<<"\t\t\t Salario: "<<Spuesto<<endl;
                cout<<"\t\t\t Hora de entrada: "<<Hentrada<<endl;
                cout<<"\t\t\t Hora de salida: "<<Hsalida<<endl;

				found++;
			}
			file >> Dpuesto >> Crpuesto>> Spuesto >> Hentrada >> Hsalida;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Puesto no encontrado...";
		}
		file.close();
	}
}
void Puesto::Borrar()
{
    Bitacora control;
	system("cls");
	fstream file,file1;
	string participant_Dp;
	int found=0;
	cout<<"\n.......................................Detalles Puesto a Borrar.................................."<<endl;
	file.open("PUESTOS.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Departamento de la Persona que quiere borrar: ";
		cin>>participant_Dp;
		file1.open("Record.txt",ios::app | ios::out);
		file >> Dpuesto >> Crpuesto>> Spuesto >> Hentrada >> Hsalida;
		while(!file.eof())
		{
			if(participant_Dp!= Dpuesto)
			{
				file1<<std::left<<std::setw(15)<< Dpuesto <<std::left<<std::setw(15)<< Crpuesto <<std::left<<std::setw(15)<< Spuesto <<std::left<<std::setw(15)<< Hentrada <<std::left<<std::setw(15)<< Hsalida << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> Dpuesto >> Crpuesto>> Spuesto >> Hentrada >> Hsalida;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Departamento de Puesto no encontrado...";
		}
		file1.close();
		file.close();
		remove("PUESTO.txt");
		rename("Record.txt","PUESTO.txt");
	}
}


    void Puesto::consultarDep()
{
    Bitacora control;
	system("cls");
	fstream file;
	int found=0;
	file.open("PUESTO.txt",ios::in);
	if(!file)
	{
		cout<<"\n..................................Datos del Departamento buscado......................................"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_Dp;
		cout<<"\n..................................Datos del Departamento buscado......................................"<<endl;
		cout<<"\nIngrese el Departamento que desea ver: ";
		cin>>participant_Dp;
		file >> Dpuesto >> Crpuesto >> Spuesto >> Hentrada >> Hsalida;
		while(!file.eof())
		{
			if(participant_Dp==Dpuesto)
			{
				cout<<"\n\n\t\t\t Departamento: "<<Dpuesto<<endl;
                cout<<"\t\t\t Nombre del cargo: "<<Crpuesto<<endl;
                cout<<"\t\t\t Salario: "<<Spuesto<<endl;
                cout<<"\t\t\t Hora de entrada: "<<Hentrada<<endl;
                cout<<"\t\t\t Hora de salida: "<<Hsalida<<endl;

				found++;
			}
			file >> Dpuesto >> Crpuesto>> Spuesto >> Hentrada >> Hsalida;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Puesto no encontrado...";
		}
		file.close();
	}
}

