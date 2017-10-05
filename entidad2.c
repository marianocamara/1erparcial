#include <stdio.h>
#include <stdlib.h>
#include "entidad2.h"
#include <string.h>
#include "validar.h"
#include "entidad1.h"


int ent2_init (sEntidad2* array, int lenArray)
{
    int retorno = -1;
    int i;
    if(array != NULL && lenArray > 0)
    {
        for(i=0; i<lenArray ; i++)
        {
            array[i].flagOcupado = ENTIDAD2_LIBRE;
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

int ent2_generarProximoId (void)
{
    ultimoValorIdAutoincrementable ++ ;
    return ultimoValorIdAutoincrementable;
}

int ent2_buscarPosicionLibre (sEntidad2* array,int lenArray)
{
    int retorno = -1;
    int i;
    if(array != NULL && lenArray > 0)
    {
        for(i=0; i<lenArray ; i++)
        {
            if(array[i].flagOcupado == ENTIDAD2_LIBRE)
            {
                retorno =  i;
                break;
            }
        }
    }
    return retorno;
}

/*int ent2_alta(sEntidad2* array, int lenArray)
{
    int retorno = -1;
    // 1. buscar posiscion libre
    // 2. gererar id
    // 3. pedir datos al usuario (validados)
    // 4. cargar datos en item vacio

    int indexVacio = ent2_buscarPosicionLibre (array,lenArray);
    if (indexVacio >= 0)
    {
        int idNuevo = ent2_generarProximoId();

        char bufferAuxNombre[50];
        if (val_getNombre(bufferAuxNombre,"Ingrese nombre","ERROR",2,50)!= -1)
        {
            array[indexVacio].flagOcupado = ENTIDAD2_OCUPADO;
            array[indexVacio].id = idNuevo;
            strncpy(array[indexVacio].a,bufferAuxNombre,51);
            retorno = 0;
        }
    }
    return retorno;
}
*/
int ent2_alta(sEntidad1* array1,sEntidad2* array, int lenEntidad1, int lenEntidad2)
{
   int retorno = -1;
   char bMotivo[51];
   char bOtros[51];
   int idNuevo;
   char b_idEnt1[100];
   int indexVacio = ent2_buscarPosicionLibre(array,len);

   if (array != NULL && indexVacio >=0 && indexVacio < len)
   {
       if(val_getUnsignedInt(b_idEnt1,"\nIngrese ID entidad1 \n","\nSolo numeros:\n",2,100)==0)
       {
           int index = ent1_buscarIndicePorId(array1,lenEntidad1,atoi(b_idEnt1));
           if (index != -1)
           {
               if (val_getUnsignedInt(bMotivo,"\nMotivo:\n  INFARTO [0]\n  ACV [1]\n  GRIPE [2]\n Opcion:","\nMotivo invalido\n",2,51)==0)
               {

                  if (val_getNombre(bOtros, "\nIngrese ..........\n", "\n............ invalido\n",3,50)==0)
                  {
                           idNuevo = ent2_generarProximoId(array,len);

                           strncpy(array[indexVacio].otros,bOtros,51);
                           array[indexVacio].motivo = atoi(bMotivo);
                           array[indexVacio].idEntidad1 = atoi(b_idEnt1);
                           array[indexVacio].id = idNuevo;
                           array[indexVacio].estado = ESTADO_PENDIENTE;
                           array[indexVacio].flagOcupado = 1;
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
