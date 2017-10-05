#ifndef ENTIDAD1_H_INCLUDED
#define ENTIDAD1_H_INCLUDED

typedef struct{
    char a[51];
    int b;
    int id;
    int flagOcupado;
}sEntidad1;


#endif // ENTIDAD1_H_INCLUDED

#define ENTIDAD1_LIBRE 0
#define ENTIDAD1_OCUPADO 1

int ent1_init (sEntidad1* array, int lenArray);
int ent1_buscarPosicionLibre (sEntidad1* array,int lenArray);
int ent1_alta(sEntidad1* array, int lenArray);
int ent1_buscarIndicePorId(sEntidad1* array, int lenArray, int id);
int ent1_buscarIndicePorCampoTexto (sEntidad1* array, int len,  char texto[]);
int ent1_modificar (sEntidad1* array, int len, int id);
int ent1_baja(sEntidad1* array, int lenArray, int id);

