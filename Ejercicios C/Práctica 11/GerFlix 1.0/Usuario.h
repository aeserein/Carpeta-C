
#include "Serie.h"

typedef struct {
    int idUsuario;
    char nombre[50];
    int idSerie;
    int estado;
} eUsuario;

void inicializarUsuariosEstado(eUsuario[], int);
void inicializarUsuariosHardCode(eUsuario[]);

void mostrarUsuario(eUsuario lista);
void mostrarListadoUsuarios(eUsuario[], int);

void mostrarListadoUsuariosConSerie(eUsuario[], int, eSerie[], int);

int retornarIndiceUsuario(eUsuario listado[], int cantidad, eUsuario unUsuario);
