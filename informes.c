#include <stdio.h>
#include <stdlib.h>
#include "entidad1.h"
#include "entidad2.h"
#include "informes.h"

void inf_imprimirTodo (sEntidad1* arrayEntidad1, sEntidad2* arrayEntidad2, int lenEntidad1, int lenEntidad2)
{
    int indexE2;
    for (indexE2=0; indexE2<lenEntidad2; indexE2++)
    {
        if(arrayEntidad2[indexE2].flagOcupado == ENTIDAD2_OCUPADO)
        {
            int idE1 = arrayEntidad2[indexE2].idEntidad1;
            int indexE1 = ent1_buscarIndicePorId(arrayEntidad1,lenEntidad1,idE1);

            printf("%d\t%s  |  %d\t%s",arrayEntidad1[indexE1].id,arrayEntidad1[indexE1].a,
                   arrayEntidad2[indexE2].id,arrayEntidad2[indexE2].a);
        }
    }

}


void informes_buscarUsuarioConMasLLamadas (sEntidad1* arrayEntidad1, sEntidad2* arrayEntidad2, int lenEntidad1, int lenEntidad2)
{
    if(arrayEntidad1 != NULL && lenEntidad1 > 0 && arrayEntidad2 != NULL && lenEntidad2 > 0)
    {

        int llamadasPorUsuario[lenEntidad1];
        int i;
        //incializa el array contador en 0
        for(i=0; i<lenEntidad1; i++)
        {
            llamadasPorUsuario[i] = 0;
        }

        //carga el array, //el indice del array va a coincidir con el id de usuario
        for(i=0; i<lenEntidad2; i++)
        {
            if(arrayEntidad2[i].flagOcupado == ENTIDAD2_OCUPADO)
            {
                int indexLlamadasPorUsuario = arrayEntidad2[i].idEntidad1;
                llamadasPorUsuario[indexLlamadasPorUsuario] ++;
            }
        }

        // busca el numro mas alto
        int mayorLlamados = llamadasPorUsuario[0];
        for(i=1; i<lenEntidad1; i++)
        {
            if (llamadasPorUsuario[i] > mayorLlamados)
            {
                mayorLlamados = llamadasPorUsuario[i];
            }
        }
        int idUsuario;
        //imprime todos los campos de el/losiusuarios con mas llamadas
        for(idUsuario=0; idUsuario<lenEntidad1; idUsuario++)
        {
            if (llamadasPorUsuario[idUsuario] == mayorLlamados)
            {
                int indexFinal = ent1_buscarIndicePorId(arrayEntidad1,lenEntidad1,idUsuario);
                printf("\nID: %d\Nombre: %s\n",arrayEntidad1[indexFinal].id,arrayEntidad1[indexFinal].a);
            }
        }
    }
}

int OrdenarAlfabeticamentePorCampoChar(sEntidad1* array, int lenArray)
{
    int retorno = -1;
    int i, j;
    sEntidad1 temporal;
    int temporalNumerico;

    if(array != NULL && lenArray > 0)
    {
        for (i = 1; i < lenArray; i++)
        {
            temporal = array[i];
            temporalNumerico = array[i].b;
            j = i-1;

            // orden menor a mayor, cambiar el < por > para mayor a menor
            while (j >= 0 && strcmp(temporal.a,array[j].a)<0)
            {
                array[j+1]=array[j];  // es igual porque es la estructura completa, si fuese solo un campo seria strcpy
                --j;
            }
            while(j>=0 && strcmp(temporal.a,array[j].a)==0)      // aca ordena por otro criterio, no se si esta bien, sino borrar
            {
                if (temporalNumerico < array[j].b)
                {
                   array[j+1]=array[j];
                    --j;
                }
            } //borrar hasta aca
            array[j+1] = temporal;
        }
    retorno = 0;
    }
    return retorno;
}

/*int informe_ReclamosTiempos(sEntidad1 array, int lenEntidad2)
{
    int retorno=-1;
    i, maximoReclamo,maximoTiempoPromedioReclamo;
    int arrayParalelo[CANTIDAD_TIPOS_RECLAMO];
    int reclamosTiempoAcumulado[CANTIDAD_TIPOS_RECLAMO];   //si son 3 reclamos va a tener 3 posicions, donde el indice coicide con el tipo de reclamo
    float reclamosTiempoPromedio[CANTIDAD_TIPOS_RECLAMO];

    //iniciaizo los 3 arrays dependiendo la cantidad
    for(i=0;i<CANTIDAD_TIPOS_RECLAMO;i++)
    {
        reclamosOcurrencia[i] = 0;
        reclamosTiempoAcumulado[i] = 0;
        reclamosTiempoPromedio[i] = 0;
    }

    if(array != NULL && lenEntidad2 > 0)
    {
        for(i=0;i<lengthLlamada;i++)
        {
            if( ((pLlamadas+i)->flagEstado == LLAMADA_USED) && (((pLlamadas+i)->estado) == SOLUCIONADO || ((pLlamadas+i)->estado) == NOSOLUCIONADO))
            {
                reclamosOcurrencia[(pLlamadas+i)->motivo]++;
                reclamosTiempoAcumulado[(pLlamadas+i)->motivo] = reclamosTiempoAcumulado[(pLlamadas+i)->motivo] + (pLlamadas+i)->tiempo;
            }
        }
*/

void prueba(Entidad1 arrayEntidad1[], Entidad2 arrayEntidad2[], int lenEntidad1, int lenEntidad2)
{

       int indexVacio = ent1_buscarPosicionLibre(arrayEntidad1,lenEntidad1);
       int indexVacio2;
       int idNuevo;
       int idNuevo2;

       if (arrayEntidad1 != NULL && indexVacio >=0 && indexVacio < lenEntidad1)
       {
           int idNuevo = ent1_generarProximoId(arrayEntidad1,lenEntidad1);

           strncpy(arrayEntidad1[indexVacio].nombre,"Juan",51);
           strncpy(arrayEntidad1[indexVacio].apellido,"Perez",51);
           arrayEntidad1[indexVacio].edad = 30;
           arrayEntidad1[indexVacio].dni = 30666777;
           arrayEntidad1[indexVacio].flagOcupado = 1;
           arrayEntidad1[indexVacio].id = idNuevo;
       }

       indexVacio = ent1_buscarPosicionLibre(arrayEntidad1,lenEntidad1);

       if (arrayEntidad1 != NULL && indexVacio >=0 && indexVacio < lenEntidad1)
       {
           idNuevo = ent1_generarProximoId(arrayEntidad1,lenEntidad1);

           strncpy(arrayEntidad1[indexVacio].nombre,"Ariel",51);
           strncpy(arrayEntidad1[indexVacio].apellido,"Traut",51);
           arrayEntidad1[indexVacio].edad = 33;
           arrayEntidad1[indexVacio].dni = 30859667;
           arrayEntidad1[indexVacio].flagOcupado = 1;
           arrayEntidad1[indexVacio].id = idNuevo;
       }


       indexVacio2 = ent2_buscarPosicionLibre(arrayEntidad2,lenEntidad2);

       if (arrayEntidad2 != NULL && indexVacio2 >=0 && indexVacio2 < lenEntidad2)
       {
           idNuevo2 = ent2_generarProximoId(arrayEntidad2,lenEntidad2);

           arrayEntidad2[indexVacio2].motivo=0;
           strncpy(arrayEntidad2[indexVacio2].otros,"Cualquier otro",51);
           arrayEntidad2[indexVacio2].idEntidad1 = 0;
           arrayEntidad2[indexVacio2].id = idNuevo2;
           arrayEntidad2[indexVacio2].estado = ESTADO_PENDIENTE;
           arrayEntidad2[indexVacio2].flagOcupado = 1;
       }

       indexVacio2 = ent2_buscarPosicionLibre(arrayEntidad2,lenEntidad2);

       if (arrayEntidad2 != NULL && indexVacio2 >=0 && indexVacio2 < lenEntidad2)
       {
           idNuevo2 = ent2_generarProximoId(arrayEntidad2,lenEntidad2);

           arrayEntidad2[indexVacio2].motivo=1;
           strncpy(arrayEntidad2[indexVacio2].otros,"Cualquier otro 2",51);
           arrayEntidad2[indexVacio2].idEntidad1 = 1;
           arrayEntidad2[indexVacio2].id = idNuevo2;
           arrayEntidad2[indexVacio2].estado = ESTADO_PENDIENTE;
