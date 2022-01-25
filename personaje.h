#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED

#include "Pantalla.h"
/**
    \file personaje.h
    \brief TDA personaje posibilita crear un personaje que sera controlado por el usuario.
 */

typedef struct PersonajeRep * Personaje;

/** \brief Crea una personaje con diferentes parametros.
 *
 * \param i Imagen del personaje.
 * \param iEscudo Imagen del escudo del personaje
 * \param iExpl Imagen de la explosion del personaje
 * \param x Coordenada horizontal inicial del personaje.
 * \param y Coordenada vertical inicial del personaje.
 * \param w Anchura del personaje.
 * \param h Altura del personaje.
 * \param frames Tiempo que queremos que tenga la explosion.
 * \return Un tipo personaje.
 *
 */
Personaje PersonajeCrea(Imagen i, Imagen iEscudo,Imagen iExpl, int x, int y, int w, int h, int frames);

/** \brief Libera la memoria reservada de un personaje.
 *
 * \param p Personaje a liberar.
 *
 */
void PersonajeLibera(Personaje p);

/** \brief Mueve un personaje.
 * \param p Personaje a mover.
 * \param vx Velocidad en el eje horizontal del personaje.
 * \param vy Velocidad en el eje vertical del personaje.
 */
void PersonajeMueve(Personaje p, int vx, int vy);

/** \brief Fija el estado de muerte del personaje
 * \param p Personaje a fijar su estado.
 * \param stageMuerte Estado de muerte.
 */
void PersonajeSetMuerte(Personaje p, int stageMuerte);

/** \brief Devuelve el estado de muerte de un personaje.
 *
 * \param p Personaje del que queremos saber su estado de muerte.
 *
 */
int PersonajeGetMuerte(Personaje p);

/** \brief Dibuja un personaje.
 *
 * \param p Personaje a dibujar.
 *
 */
void PersonajeDibuja (Personaje p);

/** \brief Fija el estado del escudo del personaje (el escudo gasta estado si lo utilizas, hasta llegar a 0)
 * \param p Personaje al que otorgar el nuevo estado del escudo.
 * \param nProtec Estado que le queremos dar al escudo.
 */
void PersonajeSetProteccion(Personaje p, int nProtec);

/** \brief Devuelve el estado del escudo de un personaje.
 * \param p Personaje del que queremos saber el estado de su escudo.
 * \return El estado del escudo.
 *
 */
int PersonajeGetProteccion(Personaje p);

/** \brief Pone el personaje en las cordenadas que le ordenemos al procedimiento.
 *
 * \param p Personaje al cual queremos modificar sus coordenadas.
 * \param x Coordenada x donde queremos llevar al personaje.
 * \param y Coordenada y donde queremos llevar al personaje.
 */
void PersonajeFixCoords(Personaje p, int x, int y);

/** \brief Devuelve la coordenada x de un personaje.
 *
 * \param p personaje del que se obtiene la coordenada.
 * \return La coordenada x del personaje.
 */
int PersonajeGetX(Personaje p);

/** \brief Devuelve la coordenada y de un personaje.
 *
 * \param p personaje del que se obtiene la coordenada.
 * \return La coordenada y del personaje.
 */
int PersonajeGetY(Personaje p);

/** \brief Devuelve la anchura de un personaje.
 *
 * \param p personaje del que se obtiene la anchura.
 * \return La anchura del personaje.
 */
int PersonajeGetW(Personaje p);

/** \brief Devuelve la altura de un personaje.
 *
 * \param p personaje del que se obtiene la altura.
 * \return La altura del personaje.
 */
int PersonajeGetH(Personaje p);

#endif // PERSONAJE_H_INCLUDED
