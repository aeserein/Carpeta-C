#ifndef VECTORES_PARALELOS_H_INCLUDED
#define VECTORES_PARALELOS_H_INCLUDED
#define NOMBRE 61

void cargaSecuencial(int[], char[][NOMBRE], int[], float[], int);

void cargaAleatoria(int[], char[][NOMBRE], int[], float[], short);

void mostrarAlumnos(int[], char[][NOMBRE], int[], float[], short);

void ordenarAlumnos(int[], char[][NOMBRE], int[], float[], short);

void mostrarJuanes(int[], char[][NOMBRE], int[], float[], short);

void mostrarAprobados(int[], char[][NOMBRE], int[], float[], short);

void mostrarNombresConP(int[], char[][NOMBRE], int[], float[], short);

void mostrarMejorNota(int[], char[][NOMBRE], int[], float[], short);

void mostrarElMasMediocre(int[], char[][NOMBRE], int[], float[], short);

void modificarNota(int[], int[], char[][NOMBRE], short);

void programa();

#endif
