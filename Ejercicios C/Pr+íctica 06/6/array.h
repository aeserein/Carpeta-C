#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

/** \brief  Cargar un vector de n slots con un solo valor int.
 *
 * \param   int Primer argumento    Vector
 * \param   int Segundo argumento   Cantidad de slots
 * \param   int Tercer argumento    Número a cargar
 * \return  void
 */
void cargarVectorInt(int[], int, int);

/** \brief  Cargar un vector de n slots con un solo valor float.
 *
 * \param   float[] Primer argumento    Vector
 * \param   int     Segundo argumento   Cantidad de slots
 * \param   float   Tercer argumento    Número a cargar
 * \return  void
 */
void cargarVectorFloat(float[], int, float);

/** \brief  Imprime los valores de un vector de int
 *
 * \param   int[]   Vector
 * \param   int     Cantidad de slots
 * \return void
 */
void mostrarVectorInt(int[], int);

/** \brief  Imprime los valores de un vector de float
 *
 * \param   float[]   Vector
 * \param   int     Cantidad de slots
 * \return void
 */
void mostrarVectorFloat(float[], int);

#endif
