#define NOMBRE 50

typedef struct {
    int legajo;
    char nombre[NOMBRE];
    short nota;
    float altura;
} eAlumno;

void inicializarLista(eAlumno[], short);

void ingresarAlumno(eAlumno[], short);

void ordenarAlumnos(eAlumno[], short);

void mostrarLista(eAlumno[], short);

void mostrarAprobados(eAlumno[], short);

void mostrarJuanes(eAlumno[], short);

void mostrarAlumnosConP(eAlumno[], short);


void programa();
