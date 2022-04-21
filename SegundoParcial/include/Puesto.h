#include<iomanip>
using namespace std;

class Puesto
{

    public:
        string Dpuesto,Crpuesto,Spuesto,Hentrada,Hsalida;
        void menu ();
            void Ingresar();
            void Actualizar ();
            void Consultar ();
            void Imprimir ();
            void Borrar ();
            void consultarDep();

        Puesto();
        virtual ~Puesto();

    protected:

    private:
};

#endif // PUESTO_H
