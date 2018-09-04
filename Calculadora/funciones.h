#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief  Recibe dos float y devuelve suma
 *
 * \param   float
 * \param   float
 * \return  float   -   Resultado de la suma
 */
float sumarDos(float,float);


/** \brief  Recibe dos float y devuelve resta
 *
 * \param   float
 * \param   float
 * \return  float   -   Resultado de la resta
 */
float restarDos(float,float);


/** \brief  Recibe dos float y devuelve multiplicación
 *
 * \param   float
 * \param   float
 * \return  float   -   Resultado de la multiplicación
 */
float multiplicarDos(float,float);

/** \brief  Recibe dos float y devuelve división
 *          No chequea división por cero
 *
 * \param   float
 * \param   float
 * \return  float   -   Resultado de la división
 */
float dividirDos(float,float);

/** \brief  Recibe un float y devuelve factorial
 *          Castea el float a long
 *
 * \param   float
 * \return  long    -   Factorial del número recibido
 */
long factorialDe(float);

/** \brief  Muestra un printf, pide y devuelve float
 *
 * \param   char[]  -   Mensaje a mostrar en el printf
 * \return  float   -   float ingresado por el usuario
 */
float ingresarFloat(char[]);

/** \brief  Muestra un printf, pide y devuelve int
 *
 * \param   char[]  -   Mensaje a mostrar en el printf
 * \return  int     -   int ingresado por el usuario
 */
int ingresarInt(char[]);

/** \brief  Pausa el programa. Limpia la pantalla al continuar
 *
 * \param   void
 * \return  void
 */
void pausaYClear(void);

/** \brief  Pregunta al usuario si quiere continuar
 *
 * \param   void
 * \return  int     -   1 si continúa
 *                  -   2 si no continúa
 */
int continuar(void);

/** \brief  Muestra el título de la calculadora
 *
 * \param   void
 * \return  void
 */
void imprimirTituloCalculadora(void);

#endif // FUNCIONES_H_INCLUDED
