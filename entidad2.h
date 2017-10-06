#ifndef ENTIDAD2_H_INCLUDED
#define ENTIDAD2_H_INCLUDED

typedef struct{
    char cuitCliente[51];
    char nombre[50];
    int idContrataciones;
    int dias;
    int idPantalla;
    int flagOcupado;
}sContrataciones;

#endif // ENTIDAD2_H_INCLUDED

#define CONTRATACIONES_LIBRE 0
#define CONTRATACIONES_OCUPADO 1



int contra_init (sContrataciones* listaContrataciones, int lenlistaContrataciones);
int ent2_generarProximoId ();
int contra_buscarPosicionLibre (sContrataciones* listaContrataciones,int lenlistaContrataciones);
int contra_alta(sContrataciones* listaContrataciones, int lenlistaContrataciones);


/*
#ifndef ENTIDAD2_H_INCLUDED
#define ENTIDAD2_H_INCLUDED

#define ESTADO_PENDIENTE 0
#define ESTADO_CUMPLIDO 1
#define ESTADO_NO_CUMPLIDO 2

#define INFARTO 0
#define ACV 1
#define GRIPE 2

#include "entidad1.h"

typedef struct{
   int motivo;
   char otros[51];
   int estado;
   int tiempoInsumido;
   int id;
   int idEntidad1;
   int flagOcupado;


}Entidad2;

int ent2_init(Entidad2 array[], int len);
int ent2_generarProximoId(Entidad2 array[], int len); //static
int ent2_buscarPosicionLibre(Entidad2 array[], int len); //static
int ent2_buscarIndicePorId(Entidad2 array[],int len,int id); //static

int ent2_alta(Entidad1 array1[],Entidad2 array[], int lenEntidad1, int lenEntidad2);
int ent2_fin(Entidad2 array[], int len);

void ent2_printArray(Entidad2 array[] , int len);


#endif // ENTIDAD2_H_INCLUDED
int ent2_fin(Entidad2 array[], int len)
{
   int retorno = -1;
   char bufferId[100];
   char bufferTiempo[100];
   char bufferEstado[2];


   if (array != NULL && len >=0)
   {
       if(val_getUnsignedInt(bufferId,"\nIngrese ID del caso a cerrar \n","\nSolo numeros:\n",2,100)==0);
       {
           int index = ent2_buscarIndicePorId(array,len,atoi(bufferId));
           if (index == -1)
           {
               printf("El ID elegido no existe\n");
               system("pause");

           }
           else if (array[index].estado != ESTADO_PENDIENTE)
           {
               printf("Caso cumplido, Solo se pueden cerrar casos pendientes\n");
               system("pause");
           }
           else
           {
               if (val_getUnsignedInt(bufferTiempo,"\nIngrese tiempo insumido\n","\nSolo numeros:\n",2,100)==0)
               {
                   if (val_getUnsignedInt(bufferEstado,"\nEstado de Cierre:\n  Resuelto [1]\n  No Resuelto [2]\n\n Opcion: ","\nRango valido 1-2",2,2)==0)
                      {
                               array[index].tiempoInsumido = atoi(bufferTiempo);
                               array[index].estado = atoi(bufferEstado);
                               retorno = 0;
                      }
               }
           }
       }
   }
   return retorno;
}

*/
