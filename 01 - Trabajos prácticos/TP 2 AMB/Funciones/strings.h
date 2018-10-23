#ifndef STRINGS_H_INCLUDED
#define STRINGS_H_INCLUDED

/** \brief Pide un string
 *
 * \param char[]    String a modificar
 * \param char[]    Mensaje a mostrar al usuario
 * \param int       Tamaño del string
 * \return void
 */
void getString(char[], char[], int);

/** \brief  Convierte las primeras letras de cada palabra
 *          a mayúsculas y las demás a minúsculas
 *
 * \param char[]    String genérico a modificar
 * \return void
 */
void primerasLetrasMayusculas(char[]);

/** \brief  Pide un nombre completo al usuario y lo devuelve en un string
 *
 * \param char[]    String del nombre completo
 * \param int       Tamaño del string
 * \return void
 */
void nombreYApellido(char[], int);

/** \brief  Ordena dos strings. Ignora mayúsculas y minúsculas
 *
 * \param char[]    Primer string
 * \param char[]    Segundo string
 * \return void
 */
void ordenarDosStrings(char[], char[]);

/** \brief  Ordena todos los strings en una matriz de char
 *
 * \param char[][50]    Matriz de char
 * \param int           Tamaño de los strings en cada fila
 * \return void
 *
 */
void ordenarEstosStrings(char[][50], int);

/** \brief  ¿Tiene letras este string?
 *
 * \param char[]    Un string genérico
 * \return short    1 si tiene letras
 *                  0 si no tiene letras
 *
 */
short tieneLetrasEsteString(char[]);

#endif
