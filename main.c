#include <stdio.h>
#include <stdlib.h>
#include "entidad1.h"
#include "entidad2.h"
#include "validar.h"

#define LEN_ENTIDADES1 50
#define LEN_ENTIDADES2 50

int main()
{
    char menuPrincipalMensaje[] =
                "\n1- opcion3\
                 \n2- opcion2\
                 \n3- Salir\
                 \nIngrese opcion: ";
    char menuPrincipalMensajeError[] = "\nIngrese una opcion valida";

    sEntidad1 listaEntidades1[LEN_ENTIDADES1];
    sEntidad2 listaEntidades2[LEN_ENTIDADES2];

    ent1_init(listaEntidades1,LEN_ENTIDADES1);
    ent2_init(listaEntidades2,LEN_ENTIDADES2);

    char bufferOpcion[50];

    do
    {
        if (val_getUnsignedInt(bufferOpcion,menuPrincipalMensaje,menuPrincipalMensajeError,2,40) == 0);
        {
            switch(atoi(bufferOpcion))
            {
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;
            default:
                printf("\nIngrese una opcion dentro del menu\n\n");
                break;

            }
        }

    }
    while( atoi(bufferOpcion) != 8);

    return 0;
}
