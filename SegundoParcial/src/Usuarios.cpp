#include "Usuarios.h"
#include<cstdlib>
#include<conio.h>
#include<iostream>
#include <string>
#include "Bitacora.h"
//Declaracion provicional de usuario y contraseña
#define USER "Grupo4"
#define PASS "4444"
using namespace std;
#include "Usuarios.h"


Usuarios::Usuarios()
{

}

Usuarios::~Usuarios()
{
    //dtor
}

//Funcion que envia el usuario a Bitacora
void Usuarios::obtenerUser(string valorUsuario)
{

    userP = valorUsuario;

}

//Funcion para el login
bool Usuarios::loginUsuarios(){
    Bitacora control;
    string Usuarios, contra;
    int contador=0;
    bool ingresa=false;
    do{
        system("cls");
        cout<<"**********************"<<endl;
        cout<<" INGRESAR AL SISTEMA "<<endl;
        cout<<"**********************"<<endl;
        cout<<"Ingrese Usuario: ";
        getline(cin, Usuarios);
        obtenerUser(Usuarios);
        cout<<"\nContrasena: ";
        //getline(cin, contra);
        char caracter;
        caracter = getch();
        contra="";
        //En este while se trasnforma lo que ingresa el usuario en *
        while (caracter != 13) //ASCII TECLA ENTER
        {
            if (caracter != 8) //ASCII TECLA RETROCESO
            {
                contra.push_back(caracter);
                cout<<"*";
            } else
            {
                if (contra.length() > 0)
                {
                    cout<<"\b \b"; //Efecto caracter borrado en pantalla
                    contra = contra.substr(0,contra.length()-1); //Toma todos los caracteres menos el ultimo
                }
            }
            caracter = getch();
        }
        //instancia de clase USUARIOS, para consultar: primero se consulta el usuario, si existe, se consulta la contraseña
        if (Usuarios==USER && contra==PASS){
            ingresa=true;

        } else {
            control.nuevaActividadTxt(30);
            control.nuevaActividad(30);
            cout<<"\nEl usuario y/o contrasena son incorrectos"<<endl;
            cin.get();
            contador++;

        }
        //Si se pasa de 3 fallos se detiene el ingreso y muestra error
    } while (ingresa==false && contador<3);
    if (ingresa==false){
        control.nuevaActividadTxt(31);
        control.nuevaActividad(31);
        cout<<"\nLo siento, no puede ingresar al sistema, sus contrasenas son invalidas o agoto intentos"<<endl;
        cout<<"** REGRESE PRONTO **";
        exit(0);}
     else {
        control.nuevaActividadTxt(32);
        control.nuevaActividad(32);
        cout<<"\n*** Bienvenido al Sistema ***"<<endl;
        cout << "Presione enter para aceptar"<<endl;
        cin.get();
    }
    return ingresa;
}

