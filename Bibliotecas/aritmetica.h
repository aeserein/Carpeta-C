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
 *          No chequea divisi�n por cero
 *
 * \param   int
 * \param   int
 * \return  int     -   Resultado de la suma
 */
int sumarDosInt(int, int);

/** \brief  Recibe dos short y devuelve la suma
 *          No chequea divisi�n por cero
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

/** \brief  Recibe dos float y devuelve multiplicaci�n
 *
 * \param   float
 * \param   float
 * \return  float   -   Resultado de la multiplicaci�n
 */
float multiplicarDosFloat(float, float);

/** \brief  Recibe dos int y devuelve multiplicaci�n
 *
 * \param   int
 * \param   int
 * \return  int     -   Resultado de la multiplicaci�n
 */
int multiplicarDosInt(int, int);

/** \brief  Recibe dos short y devuelve multiplicaci�n
 *
 * \param   short
 * \param   short
 * \return  short     -   Resultado de la multiplicaci�n
 */
short multiplicarDosShort(short, short);

///////////////////////////////////////////////////////////////////////

/** \brief  Recibe dos float y devuelve divisi�n
 *          No chequea divisi�n por cero
 *
 * \param   float
 * \param   float
 * \return  float   -   Resultado de la divisi�n
 */
float dividirDosFloat(float, float);

/** \brief  Recibe dos int y devuelve divisi�n
 *          No chequea divisi�n por cero
 *
 * \param   int
 * \param   int
 * \return  float   -   Resultado de la divisi�n
 */
float dividirDosInt(int, int);

///////////////////////////////////////////////////////////////////////

/** \brief  Recibe un float y devuelve factorial
 *          Ignora los decimales, solo usa la parte entera
 *	        No chequea negativo ni n�mero con coma
 *
 * \param   float
 * \return  long    -   Factorial del n�mero recibido
 */
long factorialDeFloat(float);

/** \brief  Recibe un int y devuelve factorial
 *	    No chequea negativo
 *
 * \param   int
 * \return  long    -   Factorial del n�mero recibido
 */
long factorialDeInt(int);

///////////////////////////////////////////////////////////////////////

/** \brief  �Tiene decimales este float?
 *
 * \param   float
 * \return  short   -   1 si tiene decimales
 *                      0 si es n,000000
 *
 */
short tieneDecimalesEsteFloat(float numero);

///////////////////////////////////////////////////////////////////////

/** \brief  Calcula superficie de un tri�ngulo de lados int
 *
 * \param   int     Base
 * \param   int     Altura
 * \return  float   Superficie
 *
 */
float superficieTrianguloInt(int, int);

/** \brief  Calcula superficie de un tri�ngulo de lados float
 *
 * \param   float   Base
 * \param   float   Altura
 * \return  float   Superficie
 *
 */
float superficieTrianguloFloat(float, float);

///////////////////////////////////////////////////////////////////////

#endif
