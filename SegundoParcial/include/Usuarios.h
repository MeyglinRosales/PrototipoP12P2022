#ifndef USUARIOS_H
#define USUARIOS_H
#include <string>
using namespace std;


class Usuarios
{
    public:
        Usuarios();
        virtual ~Usuarios();
        bool loginUsuarios();
        void menuUsuarios();
        void obtenerUser(string);
        string userP;
    protected:

    private:
};

#endif // USUARIOS_H

