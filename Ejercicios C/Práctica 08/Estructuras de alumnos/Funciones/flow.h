#ifndef FLOW_H_INCLUDED
#define FLOW_H_INCLUDED

/** \brief  Pausa el programa. Limpia la pantalla al continuar
 *
 * \param   void
 * \return  void
 */
void pausaYClear(void);

/** \brief  Pregunta al usuario si quiere continuar
 *
 * \param   void
 * \return  int     -   1 si contin�a
 *                  -   0 si no contin�a
 */
unsigned short continuar(void);

#endif
