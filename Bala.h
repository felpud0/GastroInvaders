#ifndef BALA_H_INCLUDED
#define BALA_H_INCLUDED
#include "Pantalla.h"

/**
    \file Bala.h
    \brief TDA Bala nos permite crear una bala estatica para posteriormente insertarla en una Rafaga
 */


typedef struct BalaRep * Bala;

/** \brief Crea una bala con diferentes parametros.
 *
 * \param i Imagen de la bala.
 * \param x Coordenada horizontal inicial de la bala.
 * \param y Coordenada vertical inicial de la bala.
 * \param w Anchura de la bala.
 * \param h Altura de la bala.
 * \param vx Velocidad en el eje horizontal de la bala.
 * \param vy Velocidad en el eje vertical de la bala.
 * \return Un tipo Bala.
 *
 */
Bala BalaCrea(Imagen i, int x, int y, int w, int h,int vx,int vy);

/** \brief Libera la memoria reservada de una bala.
 *
 * \param b Bala a liberar.
 *
 */
void BalaLibera(Bala b);

/** \brief Mueve una bala (dependera de la vx y vy).
 *
 * \param b Bala a mover.
 *
 */
int BalaMueve(Bala b);

/** \brief Dibuja una bala.
 *
 * \param b Bala a dibujar.
 *
 */
void BalaDibuja (Bala b);

/** \brief Devuelve la coordenada x de una bala.
 *
 * \param b Bala de la que se obtiene la coordenada.
 * \return La coordenada x de la bala.
 */
int BalaGetX(Bala b);

/** \brief Devuelve la coordenada y de una bala.
 *
 * \param b Bala de la que se obtiene la coordenada.
 * \return La coordenada y de la bala.
 */
int BalaGetY(Bala b);

/** \brief Devuelve la anchura de una bala.
 *
 * \param b Bala de la que se obtiene la anchura.
 * \return La anchura de la bala.
 */
int BalaGetW(Bala b);

/** \brief Devuelve la altura de una bala.
 *
 * \param b Bala de la que se obtiene la altura.
 * \return La altura de la bala.
 */
int BalaGetH(Bala b);

#endif // BALA_H_INCLUDED
