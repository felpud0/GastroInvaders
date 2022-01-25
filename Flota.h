#ifndef FLOTA_H_INCLUDED
#define FLOTA_H_INCLUDED

#include "Enemigo.h"
#include "personaje.h"

/**
    \file Flota.h
    \brief TDA Flota nos sirve como estructura para diferentes enemigos.
 */

typedef struct FlotaRep * Flota;

/** \brief Crea la estructura donde seran introducidos los enemigos.
 * \return Una Flota.
 */
Flota FlotaCrea();
/** \brief Libera el espacio en memoria de una flota.
 * \param f Flota a liberar.
 */
void FlotaLibera(Flota f);
/** \brief Mueve una flota.
 * \param f Flota a mover.
 * \param p Personaje al que persiguen ciertos enemigos de la flota.
 */
void FlotaMueve(Flota f,Personaje p);
/** \brief Dibuja una flota.
 * \param f Flota a dibujar.
 */
void FlotaDibuja(Flota f);
/** \brief Inserta un nuevo enemigo en una flota.
 * \param f Flota donde se inserta el enemigo.
 * \param enemigo Enemigo a insertar.
 */
void FlotaInsertaNuevoEnemigo(Flota f, Enemigo enemigo);

/** \brief Detecta la colision entre una flota y cierto objeto.
 * \param f Flota a detectar.
 * \param x Coordenada x de un objeto a detectar.
 * \param y Coordenada y de un objeto a detectar.
 * \param w Anchura de un objeto a detectar.
 * \param h Altura de un objeto a detectar
 * \return 0, si no hay colision. 1, si hay colision.
 */
int FlotaColision(Flota f, int x, int y, int w, int h);

/** \brief Destruye los enemigos muertos en una flota.
 * \param f Flota a la que le queremos quitar los elementos muertos.
 */
void FlotaDestruirMuertos(Flota f);


#endif // FLOTA_H_INCLUDED
