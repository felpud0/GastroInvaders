#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include "Pantalla.h"
#include "personaje.h"

/**
    \file Enemigo.h
    \brief TDA Enemigo nos permite crear una Enemigo estatico para posteriormente insertarlo en una Flota.
 */

typedef struct EnemigoRep * Enemigo;

/** \brief Crea una enemigo con diferentes parametros.
 *
 * \param i Imagen del enemigo.
 * \param iExpl Imagen del explosion del enemigo.
 * \param x Coordenada horizontal inicial del enemigo.
 * \param y Coordenada vertical inicial del enemigo.
 * \param w Anchura del enemigo.
 * \param h Altura del enemigo.
 * \param vx Velocidad en el eje horizontal del enemigo.
 * \param vy Velocidad en el eje vertical del enemigo.
 * \param nivel Nivel del enemigo.
 * \param frames Tiempo que queremos que este la explosion.
 * \return Un tipo enemigo.
 *
 */
Enemigo EnemigoCrea(Imagen i,Imagen iExpl, int x,int y, int w, int h,int vx,int vy,int nivel,int frames);

/** \brief Libera la memoria reservada de un enemigo.
 *
 * \param e Enemigo a liberar.
 *
 */
void EnemigoLibera(Enemigo e);

/** \brief Mueve un enemigo (dependera de la vx y vy) y a veces persiguen a un personaje.
 * \param e Enemigo a mover.
 * \param p Personaje al que se moveran ciertos enemigos.
 */
int EnemigoMueve(Enemigo e,Personaje p);

/** \brief Fija el estado de muerte del enemigo.
 * \param e Enemigo a fijar su estado.
 * \param estado Estado de muerte.
 */
void EnemigoSetMuerte(Enemigo e,int estado);

/** \brief Devuelve el estado de muerte de un enemigo.
 *
 * \param e Enemigo del que queremos saber su estado de muerte.
 *
 */
int EnemigoGetMuerte(Enemigo e);

/** \brief Dibuja un enemigo.
 * \param e Enemigo a dibujar.
 */
void EnemigoDibuja(Enemigo e);

/** \brief Devuelve la coordenada x de un enemigo.
 *
 * \param e Enemigo del que se obtiene la coordenada.
 * \return La coordenada x del enemigo.
 */
int EnemigoGetX(Enemigo e);

/** \brief Devuelve la coordenada y de un enemigo.
 *
 * \param e Enemigo del que se obtiene la coordenada.
 * \return La coordenada y del enemigo.
 */
int EnemigoGetY(Enemigo e);

/** \brief Devuelve la anchura de un enemigo.
 *
 * \param e Enemigo del que se obtiene la anchura.
 * \return La anchura del enemigo.
 */
int EnemigoGetW(Enemigo e);

/** \brief Devuelve la altura de un enemigo.
 *
 * \param e enemigo del que se obtiene la altura.
 * \return La altura del enemigo.
 */
int EnemigoGetH(Enemigo e);


#endif // ENEMIGO_H_INCLUDED
