#include <stdio.h>
#include <stdlib.h>
#include "entidad1.h"
#include "entidad2.h"
#include "informes.h"

/*void inf_imprimirTodo (sPantalla* listaPantallas, sContrataciones* listaContrataciones, int lenListaPantallas, int lenListaContrataciones)
{
    int indexE2;
    for (indexE2=0; indexE2<lenListaContrataciones; indexE2++)
    {
        if(listaContrataciones[indexE2].flagOcupado == ENTIDAD2_OCUPADO)
        {
            int idE1 = listaContrataciones[indexE2].idEntidad1;
            int indexE1 = ent1_buscarIndicePorId(listaPantallas,lenListaPantallas,idE1);

            printf("%d\t%s  |  %d\t%s",listaPantallas[indexE1].id,listaPantallas[indexE1].a,
                   listaContrataciones[indexE2].id,listaContrataciones[indexE2].a);
        }
    }

}
*/

void inf_listarPantallas (sPantalla* listaPantallas,int lenListaPantallas)
{
    int index;
    for (index=0; index<lenListaPantallas; index++)
    {
        if(listaPantallas[index].flagOcupado == PANTALLA_OCUPADO)
        {


            printf("\nID: %d\nNombre: %s\nPrecio: %.2f\nDireccion: %s\nTipo (1-LCD // 2_LED): %d\n",listaPantallas[index].id,listaPantallas[index].nombrePantalla,
                                    listaPantallas[index].precio,listaPantallas[index].direccion,
                                    listaPantallas[index].tipoPantalla);
        }
    }

}


/*void informes_buscarUsuarioConMasLLamadas (sPantalla* listaPantallas, sContrataciones* listaContrataciones, int lenListaPantallas, int lenListaContrataciones)
{
    if(listaPantallas != NULL && lenListaPantallas > 0 && listaContrataciones != NULL && lenListaContrataciones > 0)
    {

        int llamadasPorUsuario[lenListaPantallas];
        int i;
        //incializa el array contador en 0
        for(i=0; i<lenListaPantallas; i++)
        {
            llamadasPorUsuario[i] = 0;
        }

        //carga el array, //el indice del array va a coincidir con el id de usuario
        for(i=0; i<lenListaContrataciones; i++)
        {
            if(listaContrataciones[i].flagOcupado == CONTRATACIONES_OCUPADO)
            {
                int indexLlamadasPorUsuario = listaContrataciones[i].idEntidad1;
                llamadasPorUsuario[indexLlamadasPorUsuario] ++;
            }
        }

        // busca el numro mas alto
        int mayorLlamados = llamadasPorUsuario[0];
        for(i=1; i<lenListaPantallas; i++)
        {
            if (llamadasPorUsuario[i] > mayorLlamados)
            {
                mayorLlamados = llamadasPorUsuario[i];
            }
        }
        int idUsuario;
        //imprime todos los campos de el/losiusuarios con mas llamadas
        for(idUsuario=0; idUsuario<lenListaPantallas; idUsuario++)
        {
            if (llamadasPorUsuario[idUsuario] == mayorLlamados)
            {
                int indexFinal = ent1_buscarIndicePorId(listaPantallas,lenListaPantallas,idUsuario);
                printf("\nID: %d\Nombre: %s\n",listaPantallas[indexFinal].id,listaPantallas[indexFinal].a);
            }
        }
    }
}


int OrdenarAlfabeticamentePorCampoChar(sPantalla* array, int lenArray)
{
    int retorno = -1;
    int i, j;
    sPantalla temporal;
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
*/
