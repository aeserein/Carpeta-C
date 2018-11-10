#ifndef FLOW_H_INCLUDED
#define FLOW_H_INCLUDED

/** \brief  Pausa el programa. Limpia la pantalla al continuar
 *
 * \param   void
 * \return  void
 */
void pausaYClear(void);

/** \brief  Pregunta algo usuario
 *
 * \param   void
 * \return  int     -   1 si continúa
 *                  -   0 si no continúa
 */
unsigned short pregunta(char texto[50]);

/** \brief  Baja el cursor una línea
 *
 * \return void
 */
void renglon(void);

#endif
