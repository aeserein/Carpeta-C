#ifndef ESTRUCTURAGENERICA_H_INCLUDED
#define ESTRUCTURAGENERICA_H_INCLUDED
#define NOMBRE 50

typedef struct {
    char nombre[NOMBRE];
    //------------
    int idGenerica;
    int estado;
} eGenerica;

int eGen_init(eGenerica[],int limite);

//////////////////////////////////////////////////////////////////

int eGen_buscarPorId(eGenerica[] ,int limite, int id);
int eGen_siguienteId(eGenerica[] ,int limite);
int eGen_buscarLugarLibre(eGenerica listado[],int limite);

//////////////////////////////////////////////////////////////////

void eGen_mostrarUno(eGenerica parametro);
void eGen_mostrarListado(eGenerica[] ,int limite);
void eGen_mostrarListadoConBorrados(eGenerica[] ,int limite);

//////////////////////////////////////////////////////////////////

void eGen_alta(eGenerica[] ,int limite);
void eGen_baja(eGenerica[] ,int limite, int id);
void eGen_modificacion(eGenerica[] ,int limite, int id);

int eGen_ordenar(eGenerica[] ,int limite, int orden);

#endif // ESTRUCTURAGENERICA_H_INCLUDED
