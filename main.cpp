/* Se presenta un modelo simplificado de un banco el cual recibe
cheques, los registra (almacenándolos temporalmente en pilas), y
posteriormente los procesa. Se usan las clases Cheque, ChequeRechazado,
Banco y Pila (esta última no se define sino que se incluye en la
biblioteca PlanPila.h). */

#include <iostream>
#include <string.h>
#include <fstream>
#include "pila.h"

using namespace std;

/* Definición de la clase Cheque. */
class Cheque{
    public:
        Cheque();
        Cheque(int, char[], int, double);
        ~Cheque();
        void ImprimeDatos();

    private:
        int Numero, CuentaADepositar;
        char Banco[10];
        double Monto;
};

/* Declaración del método constructor por omisión. */
Cheque::Cheque(){

}

/* Declaración del método constructor con parámetros. */
Cheque::Cheque(int NumCta, char *NomBco, int Cta, double Mon){
    Numero= NumCta;
    CuentaADepositar= Cta;
    Monto= Mon;
    strcpy(Banco, NomBco);
}

/* Declaración del método destructor. */
Cheque::~Cheque(){

}

/* Método que despliega en pantalla los valores de todos los atributos
de un cheque. */
void Cheque::ImprimeDatos(){
    cout<< "\nNúmero de cheque: " << Numero;
    cout<< "\nDel banco: " << Banco;
    cout<< "\nDepositado en la cuenta: " << CuentaADepositar;
    cout<< "\nMonto: " << Monto<<endl;
}


/* Definición de la clase ChequeRechazado como clase derivada de la
clase Cheque. */
class ChequeRechazado: public Cheque{ //Se hereda de manera publica
    public:
        ChequeRechazado();
        ChequeRechazado(int, char[], int, double);
        ~ChequeRechazado();
        void ImprimeDatos();

    private:
        double Cargo;
};

/* Declaración del método constructor por omisión. */
ChequeRechazado::ChequeRechazado(){

}

/* Declaración del método constructor con parámetros. Invoca al
constructor de la clase base. */
ChequeRechazado::ChequeRechazado (int NumCta, char *NomBco, int Cta,
                                    double Mon): Cheque(NumCta, NomBco,Cta, Mon){
// Calcula el valor del atributo Cargo como el 10% del Monto del cheque.
Cargo= Mon*0.10;
}

/* Declaración del método destructor. */
ChequeRechazado::~ChequeRechazado(){

}

/* Método que despliega los valores de los atributos de un cheque
rechazado. */
void ChequeRechazado::ImprimeDatos(){
    Cheque::ImprimeDatos();//Puede hacer uso de este metodo en la clase Cheque, gracias a que hereda
    cout<<"\nCargo por rechazo: " << Cargo<<endl;
}

/* Definición de la clase Banco, la cual tiene dos atributos: uno
de ellos representa los cheques, que se almacenan en una pila hasta
su procesamiento. El otro atributo son los cheques rechazados, que se
almacenan en una pila diferente. Es decir, se usa la plantilla de la
clase Pila con las clases Cheque y ChequeRechazado. */
class Banco{ 
    public:
        Banco();
        ~Banco();
        void ProcesarCheque();
        void ProcesarChequeR();
        void RegistroCheque(Cheque);
        void RegistroChequeR(ChequeRechazado);
    private:
        Pila<Cheque> Cheques; 
        Pila<ChequeRechazado> ChequesRe;
};

/* Declaración del método constructor por omisión. */
Banco::Banco(){

}

/* Declaración del método destructor. */
Banco::~Banco(){

}

/* Método que procesa un cheque: lo quita de la pila de cheques e
imprime sus datos. Dado que se usa la plantilla de la clase Pila del
programa 5.2, se debe verificar que la pila no esté vacía antes de
quitar un cheque. */
void Banco::ProcesarCheque(){
    Cheque ChequeCli;
    
    if (!Cheques.PilaVacia()){
        Cheques - &ChequeCli; //Quita el ChequeCli de la pila de cheques
        cout<< "\n\n\nCheque procesado: ";
        ChequeCli.ImprimeDatos();
    }
    else{
        cout<<"\n\nNo hay cheques por procesar.\n\n ";
    }
}

/* Método que procesa un cheque rechazado: lo quita de la pila de
cheques rechazados e imprime sus datos. Dado que se usa la plantilla
de la clase Pila del programa 5.2, se debe verificar que la pila no
esté vacía antes de quitar un cheque rechazado. */
void Banco::ProcesarChequeR(){
    ChequeRechazado ChequeCli;
    if (!ChequesRe.PilaVacia()){
        ChequesRe - &ChequeCli; //Quita el ChequeCli de la pila de cheques rechazados
        cout<< "\n\n\nCheque rechazado procesado: ";
        ChequeCli.ImprimeDatos();
    }
    else{
        cout<<"\n\nNo hay cheques rechazados por procesar.\n\n ";
    }
}

/* Método que registra un cheque: imprime sus datos y lo almacena en
la pila de cheques. Dado que se usa la plantilla de la clase Pila del
programa 5.2, se debe verificar que la pila no esté llena antes de
insertar un nuevo cheque. */
void Banco::RegistroCheque(Cheque ChequeCli){
    if (!Cheques.PilaLlena()){
        cout<< "\n\n\nRegistrando el cheque: ";
        ChequeCli.ImprimeDatos();
        Cheques + ChequeCli;//Agrega el cheque recibido a la pila de cheques
    }
    else{
        cout<<"\n\nNo se pudo registrar el cheque por falta de espacio. \n\n ";
    }
}

/* Método que registra un cheque rechazado: imprime sus datos y lo
almacena en la pila de cheques rechazados. Dado que se usa la plantilla
de la clase Pila del programa 5.2, se debe verificar que la pila no
esté llena antes de insertar un nuevo cheque rechazado. */
void Banco::RegistroChequeR(ChequeRechazado ChequeCli){
    if (!ChequesRe.PilaLlena()){
        cout<< "\n\n\nRegistrando el cheque rechazado: ";
        ChequeCli.ImprimeDatos();
        ChequesRe + ChequeCli;//Agrega el cheque recibido, a la pila de cheques rechazados
    }
    else{
    cout<<"\n\nNo se pudo registrar el cheque rechazado por falta de espacio. \n\n ";
    }
}

/* Función principal. En esta aplicación se crean algunos objetos y
se usan para simular algunas operaciones de un banco de manera muy
simplificada. */
int main(){
    /* Declaración de objetos tipo Cheque y tipo ChequeRechazado, usando
    los constructores con parámetros. */
    Cheque Uno (1718, "Banamex", 14418, 18000.00);
    Cheque Dos (1105, "Bancomer", 13200, 12319.62);

    ChequeRechazado Tres (1816, "Banorte", 12850, 14000.00);
    ChequeRechazado Cuatro (1905, "Bancomer", 13468, 50000.00);

    /* Declaración de un objeto tipo Banco. */ 
    Banco MiBanco; 
    size_t i;
    
    /* Se registran en MiBanco los cheques recibidos, usando la pila
    que les corresponde según si el cheque fue aceptado o rechazado. */
    MiBanco.RegistroCheque(Uno);
    MiBanco.RegistroCheque(Dos);
    MiBanco.RegistroChequeR(Tres);
    MiBanco.RegistroChequeR(Cuatro);

    /* Se procesan en MiBanco los cheques registrados. Debido a que se
    almacenaron en una pila, se procesan en el orden inverso al que
    fueron registrados. */
    MiBanco.ProcesarCheque();
    MiBanco.ProcesarChequeR();
    MiBanco.ProcesarCheque();
    MiBanco.ProcesarChequeR();

    /* Se intenta procesar otros cheques en MiBanco. Sin embargo ya no habrá
    elementos y los métodos desplegarán un mensaje indicando este caso. */
    MiBanco.ProcesarCheque();
    MiBanco.ProcesarChequeR();
    
    return 0;
}