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
 * \return  int     -   1 si continúa
 *                  -   0 si no continúa
 */
unsigned short continuar(void);

/** \brief  Toma S o N sin mostrar ningún texto
 *
 * \param   void
 * \return  int     -   1 si continúa
 *                  -   0 si no continúa
 */
unsigned short siONo(void);

#endif
