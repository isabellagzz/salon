#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void servicios (){
    cout<<"Servicios=========================================================="<<endl;
    cout<<"A) Corte    B) Lavado    C) Tinte    D) Retoque    E) Tratamiento"<<endl;
    cout<<"==================================================================="<<endl;
}

void fechas (){
    cout<<"Fechas disponibles==========================================================="<<endl;
    cout<<"A) Junio 1    B) Junio 3    C) Junio 5    D) Junio 7    E) Junio 9"<<endl;
    cout<<"============================================================================="<<endl;
}

void horarios (){
    cout<<"Horarios disponibles========================================================="<<endl;
    cout<<"A) 11:30-1:00    B) 1:30-3:00    C) 3:30-5:00    D)5:30-7:00    E)7:30-9:00"<<endl;
    cout<<"============================================================================="<<endl;
}

void estilistas (){
    cout<<"Estilistas====================================================="<<endl;
    cout<<"A) Carolina   B) Mabel    C) Valeria    D) Ana   E) Mariana"<<endl;
    cout<<"==============================================================="<<endl;
}

int main(){
char reservaciones[60][4],servicio, fecha, horario, estilista;
int contador = 0, opc;
bool in_loop=true;
ifstream fileIn;
ofstream fileOut;

fileIn.open("Reservaciones.txt");

while(fileIn>>servicio>>fecha>>horario>>estilista){

    
 reservaciones[contador][0]=servicio;
 reservaciones[contador][1]=fecha;
 reservaciones[contador][2]=horario;
 reservaciones[contador][3]=estilista;
    
    
contador++;
}
fileIn.close();


     //Despliego mi menu
     do{
     opc=0;
     cout<<"FACHI BEAUTY========================="<<endl;
     cout<<"     1) Servicios"<<endl;
     cout<<"     2) Fechas disponibles"<<endl;
     cout<<"     3) Estilistas disponibles"<<endl;
     cout<<"     4) Agendar cita"<<endl;
     cout<<"     5) Salir"<<endl;
     cout<<"====================================="<<endl;

     cout<<"Elija una opcion: ";
        cin>>opc;
        switch (opc)
        {  case 1:          
        //Imprimo mi tabla
                 servicios();
                 break;   //cierro el caso 1

           case 2:
        //Imprimo mi tabla
                 fechas();
                 horarios();
                 break;   //cierro el caso 2
                      
           case 3:
        //Imprimo mi tabla   
                 estilistas();
                 break;     //cierro el caso 3

           case 4:  
                  //Coloco en orden las variables definidas 
                 servicios();
                 cout<<"Inserte la letra del servicio deseado: "<<endl;
                 cin>>servicio;
                 fechas();
                 cout<<"Inserte la letra de la fecha deseada: "<<endl;
                 cin>>fecha;
                 horarios();
                 cout<<"Inserte la letra del horario deseado: "<<endl;
                 cin>>horario;
                 estilistas();
                 cout<<"Inserte la letra de la estilista deseada: "<<endl;
                 cin>>estilista;
                 cout<<"Tu numero de cita es: "<<contador<<endl;

                  reservaciones[contador][0]=servicio;
                  reservaciones[contador][1]=fecha;
                  reservaciones[contador][2]=horario;
                  reservaciones[contador][3]=estilista;  

                 contador++;

                 break;   //cierro el caso 4
           
          case 5: 
                 cout<<"Recuerde mostrar su numero de cita en el mostrador ¡Hasta la proxima!"<<endl;
                 in_loop=false;         
                 break; //cierro el caso 5

          default:
            std::cout<<"Inserte una opcion valida"<<endl;
            system("pause");
            break;
        }

        
          //cierro mi switch
    } while(in_loop); //cierro mi while

fileOut.open("Reservaciones.txt");
     for (int i=0 ; i<contador;i++) {
         fileOut<<reservaciones[i][0]<<" "<<reservaciones[i][1]<<" "<<reservaciones[i][2]<<" "<<reservaciones[i][3]<<endl;


     }
fileOut.close();
   




}

