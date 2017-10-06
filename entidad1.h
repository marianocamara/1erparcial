#ifndef ENTIDAD1_H_INCLUDED
#define ENTIDAD1_H_INCLUDED

typedef struct{
    int id;
    char nombrePantalla[51];
    char direccion[51];
    int tipoPantalla;
    float precio;
    int flagOcupado;
}sPantalla;


#endif // ENTIDAD1_H_INCLUDED

#define PANTALLA_LIBRE 0
#define PANTALLA_OCUPADO 1

#define PANTALLA_LCD 0
#define PANTALLA_LED 1

int pant_init (sPantalla* listaPantallas, int lenLista);
int pant_buscarPosicionLibre (sPantalla* listaPantallas,int lenLista);
int pant_alta(sPantalla* listaPantallas, int lenLista);
//int ent1_buscarIndicePorCampoTexto (sPantalla* array, int len,  char texto[]);
int pant_modificarPantalla (sPantalla* listaPantallas, int lenLista);
int pant_bajaPantalla(sPantalla* listaPantallas, int lenLista, int id);

