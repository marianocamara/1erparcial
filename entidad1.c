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
int ent1_init (sEntidad1* array, int lenArray)
{
    int retorno = -1;
    int i;
    if(array != NULL && lenArray > 0)
    {
        for(i=0; i<lenArray ; i++)
        {
            array[i].flagOcupado = ENTIDAD1_LIBRE;
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

int ent1_generarProximoId (void)
{
    ultimoValorIdAutoincrementable ++ ;
    return ultimoValorIdAutoincrementable;
}

/** \brief busca el proximo index libre donde cargar la entidad
 * \param puntero array de entidad
 * \param lenArray int Longitud del array
 * \return int el primer index libre encontrado // -1 Error en parametros pasados o no hay posicion libre
 *
 */

int ent1_buscarPosicionLibre (sEntidad1* array,int lenArray)
{
    int retorno = -1;
    int i;
    if(array != NULL && lenArray > 0)
    {
        for(i=0; i<lenArray ; i++)
        {
            if(array[i].flagOcupado == ENTIDAD1_LIBRE)
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
 * \param puntero array de entidad
 * \param lenArray int Longitud del array
 * \return 0 si pudo cargar los datos correctanmente, -1 error de carga o de parametros pasados
 *
 */

int ent1_alta(sEntidad1* array, int lenArray)
{
    int retorno = -1;
    int indexVacio;
    int idNuevo;
    // 1. buscar posiscion libre
    // 2. gererar id
    // 3. pedir datos al usuario (validados)
    // 4. cargar datos en item vacio

    if(array != NULL && lenArray > 0)
    {

        indexVacio = ent1_buscarPosicionLibre (array,lenArray);
        if (indexVacio >= 0)
        {
            char bufferAuxNombre[50];
            char bufferAuxChar[50];
            char bufferAuxInt[50];
            if (val_getNombre(bufferAuxNombre,"Ingrese nombre","ERROR",2,50)!= -1)
            {
                if (val_getUnsignedInt(bufferAuxInt,"Ingrese int edad por ejemplo","ERROR",2,50) != -1 )
                {
                    if (val_getUnsignedInt(bufferAuxChar,"Ingrese char","ERROR",2,50) != -1 )       //este es otro campo de char que no llene despues
                    {
                        // genera id y lo carga, estado ocupado
                        idNuevo = ent1_generarProximoId();
                        array[indexVacio].flagOcupado = ENTIDAD1_OCUPADO;
                        array[indexVacio].id = idNuevo;

                        // campos a cargar
                        strncpy(array[indexVacio].a,bufferAuxNombre,50);
                        array[indexVacio].b = atoi(bufferAuxInt);

                        retorno = 0;
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief busca el index de id pasado como parametro
 *
 * \param puntero array de entidad
 * \param lenArray int Longitud del array
 * \param int id para buscar su index
 * \return int index de la entidad donde se encuentra ese id // -1 Error de parametros pasados o no se encontro el index
 *
 */

int ent1_buscarIndicePorId(sEntidad1* array, int lenArray, int id)
{
    int i;
    int retorno = -1;
    if(array != NULL && lenArray > 0 && id >= 0)
    {
        for(i=0; i<lenArray ; i++)
        {
            if(array[i].flagOcupado == ENTIDAD1_OCUPADO)
            {
                if(id == array[i].id)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}

/** \brief busca el index a partir de un campo de caracteres pasado como parametro
 *
 * \param puntero array de entidad
 * \param lenArray int Longitud del array
 * \param char campo para buscar su index
 * \return int index de la entidad donde se encuentra ese campo // -1 Error de parametros pasados o no se encontro el index
 *
 */
int ent1_buscarIndicePorCampoTexto (sEntidad1* array, int len,  char texto[])
{
    int retorno;
    int i;
    for(i=0; i<len; i++)
    {
        if (array[i].flagOcupado == ENTIDAD1_OCUPADO)
        {
            if (strcmp (array[i].a,texto) == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief busca el index del id pasado como parametro y modifica los campos en ese index
 *
 * \param puntero array de entidad
 * \param lenArray int Longitud del array
 * \param int id para buscar su index
 * \return 0 si pudo modificar los datos correctanmente, -1 error de carga o de parametros pasados
 *
 */

int ent1_modificar (sEntidad1* array, int lenArray, int id)
{
    int retorno = -1;
    // 1. busco la pos donde esta el id
    // 2. pido datos nuevos
    // 3.cargo en los campos
    if(array != NULL && lenArray > 0)
    {
        int index = ent1_buscarIndicePorId(array,lenArray,id);
        if(index >= 0)
        {
            // el id esta
            // pido los datos a modificar
            char bufferAuxNombre[50];
            char bufferAuxChar[50];
            char bufferAuxInt[50];
            if (val_getNombre(bufferAuxNombre,"Ingrese nombre","ERROR",2,50)!= -1)
            {
                if (val_getUnsignedInt(bufferAuxInt,"Ingrese int edad por ejemplo","ERROR",2,50) != -1 )
                {
                    if (val_getUnsignedInt(bufferAuxChar,"Ingrese char","ERROR",2,50) != -1 )       //este es otro campo de char que no llene despues
                    {
                        strncpy(array[index].a,bufferAuxNombre,50);    //nombre en campo a
                        array[index].b = atoi(bufferAuxInt);           // convierte a int numeros
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
 * \param puntero array de entidad
 * \param lenArray int Longitud del array
 * \param int id para buscar su index
 * \return 0 si dio de baja correctamente -1 error parametros o index no encontrado
 *
 */

int ent1_baja(sEntidad1* array, int lenArray, int id)
{
    int retorno = -1;
    if(array != NULL && lenArray > 0)
    {
        int index = ent1_buscarIndicePorId(array,lenArray,id);
        if(index >= 0)
        {
            array[index].flagOcupado = ENTIDAD1_LIBRE;
            retorno = 0;
        }
        else
        {
            // o puedo hacer retorno = -2 y el print en el main
            printf("\nNo se ha encontrado el ID ingresado.\n");
        }
    }
    return retorno;
}





