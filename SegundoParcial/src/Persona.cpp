#include "Persona.h"
#include <iostream>
#include<conio.h>
using namespace std;
using std::string;
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>



// constructor Persona
Persona::Persona( int valorNumerocodigo,
   string valorApellido, string valorPrimerNombre,
   string valorNit, string valorDepartamento, string valorTelefono, string valorCodVen,
   string valorDireccion, string valorestatus)
{
   establecercodigo( valorNumerocodigo );
   establecerApellido( valorApellido );
   establecerPrimerNombre( valorPrimerNombre );
   establecerTelefono( valorTelefono );
   establecerCodVen(valorCodVen);
   establecerDepartamento(valorDepartamento);
   establecerDireccion(valorDireccion);
   establecerestatus(valorestatus);
   establecerNit( valorNit );

}

// obtener el valor del ID
int Persona::obtenerNumerocodigo() const
{
   return numerocodigo;

}

// establecer el valor del ID
void Persona::establecercodigo( int valorNumerocodigo )
{
   numerocodigo = valorNumerocodigo;

}

// obtener el valor del apellido
string Persona::obtenerApellido() const
{
   return apellido;

}

// establecer el valor del apellido
void Persona::establecerApellido( string apellidoString )
{
   // copiar a lo más 15 caracteres de la cadena en apellido
   const char *valorApellido = apellidoString.data();
   int longitud = strlen( valorApellido );
   longitud = ( longitud < 15 ? longitud : 14 );
   strncpy( apellido, valorApellido, longitud );

   // anexar caracter nulo al apellido
   apellido[ longitud ] = '\0';

}

// obtener el valor del primer nombre
string Persona::obtenerPrimerNombre() const
{
   return primerNombre;

}

// establecer el valor del primer nombre
void Persona::establecerPrimerNombre( string primerNombreString )
{

   const char *valorPrimerNombre = primerNombreString.data();
   int longitud = strlen( valorPrimerNombre );
   longitud = ( longitud < 10 ? longitud : 9 );
   strncpy( primerNombre, valorPrimerNombre, longitud );


   primerNombre[ longitud ] = '\0';

}

string Persona::obtenerTelefono() const
{
   return telefono;

}


void Persona::establecerTelefono( string telefonoString )
{

   const char *valorTelefono = telefonoString.data();
   int longitud = strlen( valorTelefono );
   longitud = ( longitud < 9 ? longitud : 8 );
   strncpy( telefono, valorTelefono, longitud );


   telefono[ longitud ] = '\0';

}

string Persona::obtenerNit() const
{
   return Nit;

}


void Persona::establecerNit( string NitString )
{

   const char *valorNit = NitString.data();
   int longitud = strlen( valorNit );
   longitud = ( longitud < 15 ? longitud : 14 );
   strncpy( Nit, valorNit, longitud );


   Nit[ longitud ] = '\0';

}


string Persona::obtenerDepartamento() const
{
   return departamento;

}

void Persona::establecerDepartamento( string departamentoString )
{

   const char *valorDepartamento = departamentoString.data();
   int longitud = strlen( valorDepartamento );
   longitud = ( longitud < 22 ? longitud : 21 );
   strncpy( departamento, valorDepartamento, longitud );

   departamento[ longitud ] = '\0';

}

string Persona::obtenerCodVen() const
{
   return CodVen;

}


void Persona::establecerCodVen( string CodVenString )
{

   const char *valorCodVen = CodVenString.data();
   int longitud = strlen( valorCodVen );
   longitud = ( longitud < 32 ? longitud : 31 );
   strncpy( CodVen, valorCodVen, longitud );


   CodVen[ longitud ] = '\0';

}

string Persona::obtenerDireccion() const
{
   return direccion;

}


void Persona::establecerDireccion( string direccionString )
{

   const char *valorDireccion = direccionString.data();
   int longitud = strlen( valorDireccion );
   longitud = ( longitud < 4 ? longitud : 3 );
   strncpy( direccion, valorDireccion, longitud );


   direccion[ longitud ] = '\0';

}

string Persona::obtenerestatus() const
{
   return estatus;

}


void Persona::establecerestatus( string estatusString )
{

   const char *valorestatus = estatusString.data();
   int longitud = strlen( valorestatus );
   longitud = ( longitud < 3 ? longitud : 2 );
   strncpy( estatus, valorestatus, longitud );


   estatus[ longitud ] = '\0';

}

// crear archivo de texto con formato para imprimirlo
void Persona::imprimirRegistro( fstream &leerDeArchivo )
{
   // crear archivo de texto
   ofstream archivoImprimirSalida( "imprimir.txt", ios::out );

   // salir del programa si ofstream no puede crear el archivo
   if ( !archivoImprimirSalida ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   }

   archivoImprimirSalida << left << setw( 10 ) << "ID" << setw( 16 )
       << "Apellido" << setw( 14 ) << "Primer nombre"
       << setw( 14 ) << "Nit" <<setw( 21 )<<"Departamento"<<setw( 31 )<<"CodVen"
       <<setw( 9 )<<"Telefono"<<setw( 10 )<<"Zona"<<setw( 5 )<<"estatus"<<endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   Persona empleado;
   leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( empleado.obtenerNumerocodigo() != 0 )
         mostrarLinea( archivoImprimirSalida, empleado );

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
         sizeof( Persona ) );

   }

}

// actualizar el saldo en el registro
void Persona::actualizarRegistro( fstream &actualizarArchivo )
{
   // obtener el número codigo a actualizar
   int numerocodigo = obtenercodigo( "Escriba el codigo del cliente a modificar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numerocodigo - 1 ) * sizeof( Persona ) );

   // leer el primer registro del archivo
   Persona empleado;
   actualizarArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );
    int choice;
   // actualizar el registro
   if ( empleado.obtenerNumerocodigo() != 0 ) {

         cout << left << setw( 10 ) << "ID" << setw( 16 )
       << "Apellido" << setw( 14 ) << "Primer nombre" <<
       setw( 14 )<<"Nit"<<setw(21)<<"Departamento"<<setw(31)<<"CodVen"
       <<setw( 9 )<< "Telefono"<<setw(10)<<"Zona"<<setw(5)<<"estatus" << endl;
      mostrarLinea( cout, empleado );


      // solicitar al usuario que especifique la transacción
      cout<<""<<endl;
      cout <<"¿Que desea modificar?"<<endl;
	  cout<<"1. Departamento"<<endl;
	  cout<<"2. Zona"<<endl;
	  cout<<"3. Telefono"<<endl;
	  cout<<"4. Codigo vendedor"<<endl;
	  cout<<"5. Cancelar"<<endl;
	  cin >> choice;
    switch(choice)
    {
        case 1:
            //cambio de departamento
            {cout << "Ingrese el nuevo departamento: "<<endl;
            string cambioDpto;
            cin >> cambioDpto;
            empleado.establecerDepartamento( cambioDpto );}
            break;
        case 2:
            //cambio de direccion
            {cout << "Ingrese la nueva zona: "<<endl;
            string cambioAdress;
            cin >> cambioAdress;
            empleado.establecerDireccion( cambioAdress );}
            break;
        case 3:
            //cambio de telefono
            {cout << "Ingrese el nuevo telefono: "<<endl;
            string cambioTel;
            cin >> setw( 9 )>> cambioTel;
            empleado.establecerTelefono( cambioTel );}
            break;
        case 4:
            {cout << "Ingrese el codigo de vendedor: "<<endl;
            string cambioCodVen;
            cin >> cambioCodVen;
            empleado.establecerCodVen( cambioCodVen );}
            break;
        case 5:
            cout << "Modificacion cancelada, empleado sin cambios: "<<endl;
            break;
        default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}

      cout << left << setw( 10 ) << "ID" << setw( 16 )
       << "Apellido" << setw( 14 ) << "Primer nombre" <<
       setw( 14 )<<"Nit"<<setw(21)<<"Departamento"<<setw(31)<<"CodVen"
       <<setw( 9 )<< "Telefono"<<setw(10)<<"Zona"<<setw(5)<<"estatus" << endl;
      mostrarLinea( cout, empleado );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numerocodigo - 1 ) * sizeof( Persona ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      actualizarArchivo.write(
         reinterpret_cast< const char * >( &empleado ),
         sizeof( Persona ) );

   }

   // mostrar error si el codigo no existe
   else
      cerr << "El codigo #" << numerocodigo
         << " aun no existe" << endl;

}

// crear e insertar registro
void Persona::nuevoRegistro( fstream &insertarEnArchivo )
{
   // obtener el codigo a crear
   int numerocodigo = obtenercodigo( "Ingrese el codigo del nuevo empleado: " );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   insertarEnArchivo.seekg(
      ( numerocodigo - 1 ) * sizeof( Persona ) );

   // leer el registro del archivo
   Persona empleado;
   insertarEnArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );

   // crear el registro, si éste no existe ya
   if ( empleado.obtenerNumerocodigo() == 0 ) {

      char apellido[ 15 ];
      char primerNombre[ 10 ];
      char telefono[ 9 ];
      char Nit[ 14 ];
      char departamento[21];
      char CodVen[31];
      char direccion[21];
      char estatus[2];

      // el usuario introduce los datos
      cout << "Escriba el apellido : " << endl;
      cin >> setw( 15 ) >> apellido;
      cout << "Escriba el nombre: " << endl;
      cin >> setw( 10 ) >> primerNombre;
      cout << "Escriba el Nit: "<<endl;
      cin >> setw( 14 ) >> Nit;
      cout << "Escriba el departamento: "<<endl;
      cin >> setw(21)>> departamento;
      cout << "Escriba el Codigo de Vendedor: "<<endl;
      cin >> setw(21)>> CodVen;
      cout << "Escriba el telefono: " << endl;
      cin >> setw( 9 ) >> telefono;
      cout << "Escriba la Zona: "<<endl;
      cin >> setw(3)>> direccion;
      cout << "Escriba el estatus: "<<endl;
      cin >> setw(2)>> estatus;

      // usar valores para llenar los valores del empleado
      empleado.establecerApellido( apellido );
      empleado.establecerPrimerNombre( primerNombre );
      empleado.establecerNit( Nit );
      empleado.establecerTelefono( telefono );
      empleado.establecercodigo( numerocodigo );
      empleado.establecerDepartamento(departamento);
      empleado.establecerCodVen(CodVen);
      empleado.establecerDireccion(direccion);
      empleado.establecerestatus(estatus);

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivo.seekp( ( numerocodigo - 1 ) *
         sizeof( Persona ) );

      // insertar el registro en el archivo
      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &empleado ),
         sizeof( Persona ) );

   }
   else
      cerr << "El codigo numero #" << numerocodigo
           << " ya está registrado." << endl;

}

// eliminar un registro existente
void Persona::eliminarRegistro( fstream &eliminarDeArchivo )
{
   // obtener número de ID a eliminar
   int numerocodigo = obtenercodigo( "Escriba el codigo del empleado a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   eliminarDeArchivo.seekg(
      ( numerocodigo - 1 ) * sizeof( Persona ) );

   // leer el registro del archivo
   Persona empleado;
   eliminarDeArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );

   // eliminar el registro, si es que existe en el archivo
   if ( empleado.obtenerNumerocodigo() != 0 ) {
      Persona empleadoEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      eliminarDeArchivo.seekp( ( numerocodigo - 1 ) *
         sizeof( Persona ) );

      // reemplazar el registro existente con un registro en blanco
      eliminarDeArchivo.write(
         reinterpret_cast< const char * >( &empleadoEnBlanco ),
         sizeof( Persona ) );

      cout << "Cliente con codigo #" << numerocodigo << " eliminado.\n";

   }

   else
      cerr << "No existe ningun cliente con el codigo #" << numerocodigo<<endl;

}
//Consulta de los empleados
void Persona::consultarRegistro( fstream &leerDeArchivo )
{

   cout << left << setw( 10 ) << "ID" << setw( 16 )
       << "Apellido" << setw( 14 ) << "Primer nombre" <<
       setw( 14 )<<"Nit"<<setw(21)<<"Departamento"<<setw(31)<<"CodVen"
       <<setw( 9 )<< "Telefono"<<setw(10)<<"Zona"<<setw(5)<<"estatus" << endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   Persona empleado;
   leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( empleado.obtenerNumerocodigo() != 0 )
         mostrarLineaPantalla(empleado);

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
         sizeof( Persona ) );

   }

}

// mostrar registro individual
void Persona::mostrarLinea( ostream &salida, const Persona &registro )
{
   salida << left << setw( 10 ) << registro.obtenerNumerocodigo()
          << setw( 16 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerPrimerNombre().data()
          << setw( 14 ) << registro.obtenerNit().data()
          << setw( 21 ) << registro.obtenerDepartamento().data()
          << setw( 31 ) << registro.obtenerCodVen().data()
          << setw( 9 ) << registro.obtenerTelefono().data()
          << setw( 4 ) << registro.obtenerDireccion().data()
          << setw( 2 ) << registro.obtenerestatus().data()<<endl;

}
void Persona::mostrarLineaPantalla( const Persona &registro )
{
   cout << left << setw( 10 ) << registro.obtenerNumerocodigo()
          << setw( 16 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerPrimerNombre().data()
          << setw( 14 ) << registro.obtenerNit().data()
          << setw( 21 ) << registro.obtenerDepartamento().data()
          << setw( 31 ) << registro.obtenerCodVen().data()
          << setw( 9 ) << registro.obtenerTelefono().data()
          << setw( 4 ) << registro.obtenerDireccion().data()
          << setw( 2 ) << registro.obtenerestatus().data()<<endl;
}

// obtener el valor del número ID del usuario
int Persona::obtenercodigo( const char * const indicador )
{
   int numerocodigo;

   do {
      cout << indicador << " (1 - 1000): ";
      cin >> numerocodigo;

   } while ( numerocodigo < 1 || numerocodigo > 1000 );

   return numerocodigo;

}
void Persona::crearArchivoEmpleados()
{
    ofstream empleadosSalida( "empleados.dat", ios::out | ios::binary );
   // salir del programa si ofstream no pudo abrir el archivo
   if ( !empleadosSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );

   }

   // crear espacios sin informacion
   Persona empleadoEnBlanco;

   for ( int i = 0; i < 1000; i++ )
      empleadosSalida.write(
         reinterpret_cast< const char * >( &empleadoEnBlanco ),
         sizeof( Persona ) );
}

fstream Persona::inicioArchivo(){
    Persona empleado;
        fstream empleadosEntradaSalida( "empleados.dat", ios::in | ios::out | ios::binary);

   // salir del programa si fstream no puede abrir el archivo
    if ( !empleadosEntradaSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      empleado.crearArchivoEmpleados();
      cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
      exit ( 1 );

    }
    return empleadosEntradaSalida;
}

//Funcion para encontrar empleado especifico
void Persona::busquedaRegistro(fstream &actualizarArchivo)
{
//Se obtiene el ID a buscar
       int numerocodigo = obtenercodigo( "Escriba el codigo del empleado a buscar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numerocodigo - 1 ) * sizeof( Persona ) );

   // leer el primer registro del archivo
   Persona empleado;
   actualizarArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );
if ( empleado.obtenerNumerocodigo() != 0 ) {
      //MOstrar la informacion obtenida
      cout << left << setw( 10 ) << "ID" << setw( 16 )
       << "Apellido" << setw( 14 ) << "Primer nombre" <<
       setw( 14 )<<"Nit"<<setw(21)<<"Departamento"<<setw(31)<<"CodVen"
       <<setw( 9 )<< "Telefono"<<setw(10)<<"Zona"<<setw(5)<<"estatus" << endl;
      mostrarLinea( cout, empleado );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numerocodigo - 1 ) * sizeof( Persona ) );

   }

   // mostrar error si el ID no existe
   else
      cerr << "El codigo #" << numerocodigo
         << " aun no existe" << endl;

}
