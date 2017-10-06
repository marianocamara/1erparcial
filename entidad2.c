#include <stdio.h>
#include <stdlib.h>
#include "entidad2.h"
#include <string.h>
#include "validar.h"
#include "entidad1.h"


int contra_init (sContrataciones* listaContrataciones, int lenlistaContrataciones)
{
    int retorno = -1;
    int i;
    if(listaContrataciones != NULL && lenlistaContrataciones > 0)
    {
        for(i=0; i<lenlistaContrataciones ; i++)
        {
            listaContrataciones[i].flagOcupado = CONTRATACIONES_LIBRE;
        }
    }
    return retorno;
}

/** \brief Genera un id(+1) a partir del ultimo generado
 * \param
 * \param
 * \return int el id generado
 */
static int ultimoValorIdAutoincrementable = -1;

int contra_generarProximoId (void)
{
    ultimoValorIdAutoincrementable ++ ;
    return ultimoValorIdAutoincrementable;
}

int contra_buscarPosicionLibre (sContrataciones* listaContrataciones,int lenlistaContrataciones)
{
    int retorno = -1;
    int i;
    if(listaContrataciones != NULL && lenlistaContrataciones > 0)
    {
        for(i=0; i<lenlistaContrataciones ; i++)
        {
            if(listaContrataciones[i].flagOcupado == CONTRATACIONES_LIBRE)
            {
                retorno =  i;
                break;
            }
        }
    }
    return retorno;
}

int contra_alta(sContrataciones* listaContrataciones, int lenlistaContrataciones)
{
    int retorno = -1;

    int indexVacio = contra_buscarPosicionLibre (listaContrataciones,lenlistaContrataciones);
    if (indexVacio >= 0)
    {
        int idNuevo = contra_generarProximoId();

        char bufferAuxNombre[50];
        char bufferAuxCuit[50];
        char bufferAuxId[50];
        char bufferDias[50];
        if (val_getUnsignedInt(bufferAuxId,"\nIngrese el ID de la pantalla que desea contratar\n","\nERROR\n",2,50)!= -1)
        {
            if (val_getNombre(bufferAuxNombre,"\nIngrese su nombre\n","\nERROR\n",2,50)!= -1)
            {
                if (val_getUnsignedInt(bufferAuxCuit,"\nIngrese su CUIT\n","\nERROR\n",2,50)!= -1)
                {
                    if (val_getNombre(bufferDias,"\nIngrese la cantidad de dias que desea contratar la pantalla\n","\nERROR\n",2,50)!= -1)
                    {
                        listaContrataciones[indexVacio].flagOcupado = CONTRATACIONES_OCUPADO;
                        listaContrataciones[indexVacio].idContrataciones = idNuevo;
                        strncpy(listaContrataciones[indexVacio].nombre,bufferAuxNombre,50);
                        strncpy(listaContrataciones[indexVacio].cuitCliente,bufferAuxCuit,50);
                        listaContrataciones[indexVacio].dias = atoi(bufferDias);
                        listaContrataciones[indexVacio].idPantalla = atoi(bufferAuxId);

                        retorno = 0;
                    }
                }
            }
        }
    }
    return retorno;
}
/*
int contra_alta(sEntidad1* listaContrataciones1,sContrataciones* listaContrataciones, int lenEntidad1, int lenEntidad2)
{
   int retorno = -1;
   char bMotivo[51];
   char bOtros[51];
   int idNuevo;
   char b_idEnt1[100];
   int indexVacio = contra_buscarPosicionLibre(listaContrataciones,len);

   if (listaContrataciones != NULL && indexVacio >=0 && indexVacio < len)
   {
       if(val_getUnsignedInt(b_idEnt1,"\nIngrese ID entidad1 \n","\nSolo numeros:\n",2,100)==0)
       {
           int index = ent1_buscarIndicePorId(listaContrataciones1,lenEntidad1,atoi(b_idEnt1));
           if (index != -1)
           {
               if (val_getUnsignedInt(bMotivo,"\nMotivo:\n  INFARTO [0]\n  ACV [1]\n  GRIPE [2]\n Opcion:","\nMotivo invalido\n",2,51)==0)
               {

                  if (val_getNombre(bOtros, "\nIngrese ..........\n", "\n............ invalido\n",3,50)==0)
                  {
                           idNuevo = contra_generarProximoId(listaContrataciones,len);

                           strncpy(listaContrataciones[indexVacio].otros,bOtros,51);
                           listaContrataciones[indexVacio].motivo = atoi(bMotivo);
                           listaContrataciones[indexVacio].idEntidad1 = atoi(b_idEnt1);
                           listaContrataciones[indexVacio].id = idNuevo;
                           listaContrataciones[indexVacio].estado = ESTADO_PENDIENTE;
                           listaContrataciones[indexVacio].flagOcupado = 1;
                           retorno = 0;
                  }
               }
           }
           else
           {
               printf("El ID elegido no existe\n");
               system("pause");
           }
       }
   }
   return retorno;
}
*/

/*
int contra_fin(Entidad2 listaContrataciones[], int len)
{
   int retorno = -1;
   char bufferId[100];
   char bufferTiempo[100];
   char bufferEstado[2];


   if (listaContrataciones != NULL && len >=0)
   {
       if(val_getUnsignedInt(bufferId,"\nIngrese ID del caso a cerrar \n","\nSolo numeros:\n",2,100)==0);
       {
           int index = contra_buscarIndicePorId(listaContrataciones,len,atoi(bufferId));
           if (index == -1)
           {
               printf("El ID elegido no existe\n");
               system("pause");

           }
           else if (listaContrataciones[index].estado != ESTADO_PENDIENTE)
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
                               listaContrataciones[index].tiempoInsumido = atoi(bufferTiempo);
                               listaContrataciones[index].estado = atoi(bufferEstado);
                               retorno = 0;
                      }
               }
           }
       }
   }
   return retorno;
}
*/
