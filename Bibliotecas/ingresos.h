#ifndef INGRESOS_H_INCLUDED
#define INGRESOS_H_INCLUDED

/** \brief  Muestra un printf, pide y devuelve float
 *
 * \param   char[]  -   Mensaje a mostrar en el printf
 * \return  float   -   float ingresado por el usuario
 */
float getFloat(char[]);

/** \brief  Muestra un printf, pide un float entre dos valores y lo devuelve
 *
 * \param   float   -   Mínimo
 * \param   float   -   Máximo
 * \param   char[]  -   Mensaje a mostrar
 * \return  float   -   float ingresado por el usuario
 *
 */
float getFloatBetween(float, float, char[]);

/** \brief  Muestra un printf, pide y devuelve int
 *
 * \param   char[]  -   Mensaje a mostrar en el printf
 * \return  int     -   int ingresado por el usuario
 */
int getInt(char[]);

/** \brief  Muestra un printf, pide un int entre dos valores y lo devuelve
 *
 * \param   int     -   Mínimo
 * \param   int     -   Máximo
 * \param   char[]  -   Mensaje a mostrar
 * \return  int     -   int ingresado por el usuario
 *
 */
int getIntBetween(int, int, char[]);

/** \brief  Muestra un printf, pide y devuelve short
 *
 * \param   char[]  -   Mensaje a mostrar en el printf
 * \return  int     -   int ingresado por el usuario
 */
short getShort(char[]);

/** \brief  Muestra un printf, pide un short entre dos valores y lo devuelve
 *
 * \param   short   -   Mínimo
 * \param   short   -   Máximo
 * \param   char[]  -   Mensaje a mostrar
 * \return  short   -   short ingresado por el usuario
 *
 */
short getShortBetween(short, short, char[]);

#endif
