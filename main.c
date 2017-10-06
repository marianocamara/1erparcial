#include <stdio.h>
#include <stdlib.h>
#include "entidad1.h"
#include "entidad2.h"
#include "validar.h"
#include "informes.h"

#define LEN_PANTALLAS 100
#define LEN_CONTRATACIONES 1000


int main()
{


    sPantalla listaPantallas[LEN_PANTALLAS];
    sContrataciones listaContrataciones[LEN_CONTRATACIONES];

    pant_init (listaPantallas,LEN_PANTALLAS);

    contra_init (listaContrataciones,LEN_CONTRATACIONES);


    char bufferIdBaja[50];

    char bufferOpcion[10];


    do
    {
        val_getUnsignedInt(bufferOpcion,"\n\n1- Alta de pantalla\n2- Modificar datos de pantalla\n3- Baja de pantalla\n4- Contratar pubicidad\n5- Modificar condiciones de contratacion\n6- Cancelar contratacion\n7- Modificar condiciones de contratacion\n","\nIngrese una opcion valida. \n",3,10);

        switch(atoi(bufferOpcion))
            {
            case 1:
                pant_alta(listaPantallas,LEN_PANTALLAS);
                break;

            case 2:

                pant_modificarPantalla(listaPantallas,LEN_PANTALLAS);
                break;

            case 3:
                val_getUnsignedInt(bufferIdBaja,"\nIngrese ID de la pantalla a dar de baja\n","\nIngese un ID valido\n",2,50);
                pant_bajaPantalla(listaPantallas,LEN_PANTALLAS,atoi(bufferIdBaja));
                //falta dar de baja lascontrataciones
                break;
            case 4:
                inf_listarPantallas(listaPantallas,LEN_PANTALLAS);
                contra_alta(listaContrataciones,LEN_CONTRATACIONES);
                break;

            case 5:
                break;

            case 6:
                break;

            }

    }while( atoi(bufferOpcion) != 11);

    return 0;
}
