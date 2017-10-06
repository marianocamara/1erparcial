#include <stdio.h>
#include <stdlib.h>
#include "entidad1.h"
#include <string.h>
#include "validar.h"

/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado en 0
 * \param puntero array de entidad
 * \param lenArray int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 */
int pant_init (sPantalla* listaPantallas, int lenLista)
{
    int retorno = -1;
    int i;
    if(listaPantallas != NULL && lenLista > 0)
    {
        for(i=0; i<lenLista ; i++)
        {
            listaPantallas[i].flagOcupado = PANTALLA_LIBRE;
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

int pant_generarProximoId (void)
{
    ultimoValorIdAutoincrementable ++ ;
    return ultimoValorIdAutoincrementable;
}

/** \brief busca el proximo index libre donde cargar la entidad
 * \param puntero listaPantallas de entidad
 * \param lenLista int Longitud del listaPantallas
 * \return int el primer index libre encontrado // -1 Error en parametros pasados o no hay posicion libre
 *
 */

int pant_buscarPosicionLibre (sPantalla* listaPantallas,int lenLista)
{
    int retorno = -1;
    int i;
    if(listaPantallas != NULL && lenLista > 0)
    {
        for(i=0; i<lenLista ; i++)
        {
            if(listaPantallas[i].flagOcupado == PANTALLA_LIBRE)
            {
                retorno =  i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Carga todos los campos de la entidad en un index vacio y genera su id, validando datos ingresados en cada caso
 *
 * \param puntero listaPantallas de entidad
 * \param lenLista int Longitud del listaPantallas
 * \return 0 si pudo cargar los datos correctanmente, -1 error de carga o de parametros pasados
 *
 */

int pant_alta(sPantalla* listaPantallas, int lenLista)
{

    int retorno = -1;
    int indexVacio;
    int idNuevo;

    if(listaPantallas != NULL && lenLista > 0)
    {


        indexVacio = pant_buscarPosicionLibre (listaPantallas,lenLista);
        if (indexVacio >= 0)
        {


            char bufferAuxNombre[50];
            char bufferAuxDireccion[50];
            char bufferAuxPrecio[50];
            char bufferAuxTipo[50];

            if (val_getNombre(bufferAuxNombre,"Ingrese nombre de la pantalla\n","Ingrese un nombre valido\n",2,50)!= -1)
            {
                if (val_getFloat(bufferAuxPrecio,"Ingrese precio de la pantalla\n","Ingrese un numero valido\n",2,50) != -1 )
                {
                    if (val_getDireccion(bufferAuxDireccion,"Ingrese la direccion\n","Ingrese una direccion valida\n",2,50) != -1 )       //este es otro campo de char que no llene despues
                    {
                        if (val_getUnsignedInt(bufferAuxTipo,"Ingrese la el tipo de pantalla: 0 - Pantalla LCD // 1 - Pantalla LED\n","Ingrese una direccion valida\n",2,50) != -1 )       //este es otro campo de char que no llene despues
                        {
                            idNuevo = pant_generarProximoId();
                            listaPantallas[indexVacio].id = idNuevo;
                            listaPantallas[indexVacio].flagOcupado = PANTALLA_OCUPADO;

                            strncpy(listaPantallas[indexVacio].nombrePantalla,bufferAuxNombre,50);
                            strncpy(listaPantallas[indexVacio].direccion,bufferAuxDireccion,50);
                            listaPantallas[indexVacio].precio = atof(bufferAuxPrecio);
                            listaPantallas[indexVacio].tipoPantalla = atoi(bufferAuxTipo);

                            retorno = 0;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief busca el index de id pasado como parametro
 *
 * \param puntero listaPantallas de entidad
 * \param lenLista int Longitud del listaPantallas
 * \param int id para buscar su index
 * \return int index de la entidad donde se encuentra ese id // -1 Error de parametros pasados o no se encontro el index
 *
 */

int pant_buscarIndicePorId(sPantalla* listaPantallas, int lenLista, int id)
{
    int i;
    int retorno = -1;
    if(listaPantallas != NULL && lenLista > 0 && id >= 0)
    {
        for(i=0; i<lenLista ; i++)
        {
            if(listaPantallas[i].flagOcupado == PANTALLA_OCUPADO)
            {
                if(id == listaPantallas[i].id)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}




/*
int pant_buscarIndicePorCampoTexto (sPantalla* listaPantallas, int len,  char texto[])
{
   int retorno;
   int i;
   for(i=0; i<len; i++)
   {
       if (listaPantallas[i].flagOcupado == PANTALLA_OCUPADO)
       {
           if (strcmp (listaPantallas[i].a,texto) == 0)
           {
               retorno = i;
               break;
           }
       }
   }
   return retorno;
}
*/

/** \brief busca el index del id pasado como parametro y modifica los campos en ese index
 *
 * \param puntero listaPantallas de entidad
 * \param lenLista int Longitud del listaPantallas
 * \param int id para buscar su index
 * \return 0 si pudo modificar los datos correctanmente, -1 error de carga o de parametros pasados
 *
 */

int pant_modificarPantalla (sPantalla* listaPantallas, int lenLista)
{
    int retorno = -1;
    char bufferIdModificar[50];
    // 1. busco la pos donde esta el id
    // 2. pido datos nuevos
    // 3.cargo en los campos
    if(listaPantallas != NULL && lenLista > 0)
    {
        val_getUnsignedInt(bufferIdModificar,"\nIngrese ID de la pantalla a modificar\n","\nIngese un ID valido\n",2,50);
        int index = pant_buscarIndicePorId(listaPantallas,lenLista,atoi(bufferIdModificar));
        if(index >= 0)
        {

            char bufferAuxNombre[50];
            char bufferAuxDireccion[50];
            char bufferAuxPrecio[50];

            if (val_getNombre(bufferAuxNombre,"Ingrese nuevo nombre de la pantalla","Ingrese un nombre valido",2,50)!= -1)
            {
                if (val_getFloat(bufferAuxPrecio,"Ingrese nuevo precio de la pantalla","Ingrese un numero valido",2,50) != -1 )
                {
                    if (val_getNombre(bufferAuxDireccion,"Ingrese nueva direccion","Ingrese una direccion valida",2,50) != -1 )       //este es otro campo de char que no llene despues
                    {
                        strncpy(listaPantallas[index].nombrePantalla,bufferAuxNombre,50);
                        strncpy(listaPantallas[index].direccion,bufferAuxDireccion,50);
                        listaPantallas[index].precio = atof(bufferAuxPrecio);

                        retorno = 0;
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief realiza baja de una entidad colocando el flag estado en libre (0)
 *
 * \param puntero listaPantallas de entidad
 * \param lenLista int Longitud del listaPantallas
 * \param int id para buscar su index
 * \return 0 si dio de baja correctamente -1 error parametros o index no encontrado
 *
 */

int pant_bajaPantalla(sPantalla* listaPantallas, int lenLista, int id)
{
    int retorno = -1;
    if(listaPantallas != NULL && lenLista > 0)
    {
        int index = pant_buscarIndicePorId(listaPantallas,lenLista,id);
        if(index >= 0)
        {
            listaPantallas[index].flagOcupado = PANTALLA_LIBRE;
            retorno = 0;
        }
        else
        {
            printf("\nNo se ha encontrado el ID ingresado.\n");
        }
    }
    return retorno;
}





