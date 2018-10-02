typedef struct {
    int idSerie;
    char nombre[50];
    char genero[20];
    int cantidadTemporadas;
    int estado;
} eSerie;

void inicializarSeriesEstado(eSerie[], int);
void inicializarSeriesHardCode(eSerie[]);

void mostrarNombreDeSerie(eSerie);
void mostrarSerie(eSerie);
void mostrarListadoSeries(eSerie[], int);

int retornarIndiceSerie(eSerie listado[], int cantidad, eSerie unaSerie);
int retornarIndiceSerieInt(eSerie listado[], int cantidad, int idSerie);

