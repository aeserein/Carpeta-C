#ifndef ARITMETICA_H_INCLUDED
#define ARITMETICA_H_INCLUDED

///////////////////////////////////////////////////////////////////////

/** \brief  Recibe dos float y devuelve la suma
 *
 * \param   float
 * \param   float
 * \return  float   -   Resultado de la suma
 */
float sumarDosFloat(float, float);

/** \brief  Recibe dos int y devuelve la suma
 *          No chequea división por cero
 *
 * \param   int
 * \param   int
 * \return  int     -   Resultado de la suma
 */
int sumarDosInt(int, int);

/** \brief  Recibe dos short y devuelve la suma
 *          No chequea división por cero
 *
 * \param   short
 * \param   short
 * \return  short     -   Resultado de la suma
 */
short sumarDosShort(int, int);

///////////////////////////////////////////////////////////////////////

/** \brief  Recibe dos float y devuelve la resta
 *
 * \param   float
 * \param   float
 * \return  float   -   Resultado de la resta
 */
float restarDosFloat(float, float);

/** \brief  Recibe dos int y devuelve la resta
 *
 * \param   int
 * \param   int
 * \return  int     -   Resultado de la resta
 */
int restarDosInt(int, int);

/** \brief  Recibe dos short y devuelve la resta
 *
 * \param   short
 * \param   short
 * \return  short   -   Resultado de la resta
 */
short restarDosShort(short, short);

///////////////////////////////////////////////////////////////////////

/** \brief  Recibe dos float y devuelve multiplicación
 *
 * \param   float
 * \param   float
 * \return  float   -   Resultado de la multiplicación
 */
float multiplicarDosFloat(float, float);

/** \brief  Recibe dos int y devuelve multiplicación
 *
 * \param   int
 * \param   int
 * \return  int     -   Resultado de la multiplicación
 */
int multiplicarDosInt(int, int);

/** \brief  Recibe dos short y devuelve multiplicación
 *
 * \param   short
 * \param   short
 * \return  short     -   Resultado de la multiplicación
 */
short multiplicarDosShort(short, short);

///////////////////////////////////////////////////////////////////////

/** \brief  Recibe dos float y devuelve división
 *          No chequea división por cero
 *
 * \param   float
 * \param   float
 * \return  float   -   Resultado de la división
 */
float dividirDosFloat(float, float);

/** \brief  Recibe dos int y devuelve división
 *          No chequea división por cero
 *
 * \param   int
 * \param   int
 * \return  float   -   Resultado de la división
 */
float dividirDosInt(int, int);

///////////////////////////////////////////////////////////////////////

/** \brief  Recibe un float y devuelve factorial
 *          Ignora los decimales, solo usa la parte entera
 *	        No chequea negativo ni número con coma
 *
 * \param   float
 * \return  long    -   Factorial del número recibido
 */
long factorialDeFloat(float);

/** \brief  Recibe un int y devuelve factorial
 *	    No chequea negativo
 *
 * \param   int
 * \return  long    -   Factorial del número recibido
 */
long factorialDeInt(int);

///////////////////////////////////////////////////////////////////////

/** \brief  ¿Tiene decimales este float?
 *
 * \param   float
 * \return  short   -   1 si tiene decimales
 *                      0 si es n,000000
 *
 */
short tieneDecimalesEsteFloat(float numero);

///////////////////////////////////////////////////////////////////////

/** \brief  Calcula superficie de un triángulo de lados int
 *
 * \param   int     Base
 * \param   int     Altura
 * \return  float   Superficie
 *
 */
float superficieTrianguloInt(int, int);

/** \brief  Calcula superficie de un triángulo de lados float
 *
 * \param   float   Base
 * \param   float   Altura
 * \return  float   Superficie
 *
 */
float superficieTrianguloFloat(float, float);

///////////////////////////////////////////////////////////////////////

#endif
