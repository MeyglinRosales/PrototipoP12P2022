#ifndef BITACORA_H
#define BITACORA_H
#include <iostream>
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


class Bitacora
{
    public:
        string app;
        string valorApp;
        string dia;
        string mesch;
        string usuario;
        int year;
        string minutos;
        string segundos;
        string horas;
        Bitacora();
        virtual ~Bitacora();
        int fechaHora ();
        string obtenerAccion(int);
        int nuevaActividad(int);
        void crearArchivoBitacora();
        int nuevaActividadTxt(int);
        void crearArchivoBitacoraTxt();
        int consultarBitacora();
        fstream inicioArchivo();
        fstream inicioArchivoTxt();


    protected:

    private:
};

#endif // BITACORA_H
