#ifndef AMB_H_INCLUDED
#define AMB_H_INCLUDED
#define NOMBRE 20

typedef struct {
    int legajo;
    char nombre[NOMBRE];
    short nota;
    float altura;
    short bEstado;
} alumno;

//////////////////////////////////////////////////////////////

void menu(void);
void encabezadoDeLista();
void inicializarLista(alumno[], short);

//////////////////////////////////////////////////////////////

void ordenarAlumnos(alumno[], short);

//////////////////////////////////////////////////////////////

void mostrarAlumno(alumno[], short);
void mostrarListaDeAlumnos(alumno[], short);

//////////////////////////////////////////////////////////////

/** \brief  Busca espacio disponible en un array
 *
 * \param   short[] -   Lista de shorts
 * \param   short   -   Tamaño de la lista
 * \param   int     -   Valor ilógico
 * \return  short   -   -1 si no hay espacio
 *                  -   >=0 indice donde guardar
 *
 */
short buscarLibre(alumno[] , short);
void cargarAlumno(alumno[], short);

//////////////////////////////////////////////////////////////

void hardcodeAlumno(alumno lista[]);

//////////////////////////////////////////////////////////////

void programa(void);



#endif // AMB_H_INCLUDED
