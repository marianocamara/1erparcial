#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED



#endif // VALIDAR_H_INCLUDED
void myFgets(char* buffer, int limite ,FILE* archivo);
int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarNombre(char* buffer);
int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarUnsignedInt(char* buffer);
int val_esNumericoFlotante(char* buffer);
int val_getFloat(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getDireccion(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);

