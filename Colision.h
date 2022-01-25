#ifndef COLISION_H_INCLUDED
#define COLISION_H_INCLUDED
#include "Enemigo.h"

/**
    \file Colision.h
    \brief El modulo Colision nos ofrece tener diferentes funciones para detectar colisiones.
 */

int ColisionDeDos(int x1,int y1, int w1,int h1,int x2,int y2,int w2, int h2);
/** \brief Nos devuelve si dos elementos (con ciruclos virtuales) han colisionado.
 *
 * \param x1 La coordenada x del primer elemento.
 * \param y1 La cordenada y del primer elemento.
 * \param w1 La anchura del primer elemento.
 * \param h1 La altura del primer elemento.
 * \param x2 La coordenada x del segundo elemento.
 * \param y2 La cordenada y del segundo elemento.
 * \param w2 La anchura del segundo elemento.
 * \param h2 La altura del segundo elemento.
 * \return 0, si no hay colision. 1, si hay colision.
 *
 */

int Colision2(int x1, int y1, int h1, int w1, int x2, int y2, int h2, int w2);

/** \brief Nos devuelve si dos elementos (sus cuadrados) han colisionado.
 *
 * \param x1 La coordenada x del primer elemento.
 * \param y1 La cordenada y del primer elemento.
 * \param w1 La anchura del primer elemento.
 * \param h1 La altura del primer elemento.
 * \param x2 La coordenada x del segundo elemento.
 * \param y2 La cordenada y del segundo elemento.
 * \param w2 La anchura del segundo elemento.
 * \param h2 La altura del segundo elemento.
 * \return 0, si no hay colision. 1, si hay colision.
 *
 */

#endif // COLISION_H_INCLUDED
