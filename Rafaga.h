#ifndef RAFAGA_H_INCLUDED
#define RAFAGA_H_INCLUDED

#include "Bala.h"
#include "Flota.h"

/**
    \file Rafaga.h
    \brief TDA Rafaga nos permite agrupar un conjunto de balas.
 */

typedef struct RafagaRep * Rafaga;
/** \brief Crea la estructura donde seran introducidas las balas.
 * \return Una Rafaga.
 */
Rafaga RafagaCrea();

/** \brief Libera el espacio en memoria de una rafaga.
 * \param r Rafaga a liberar.
 */
void RafagaLibera(Rafaga r);

/** \brief Mueve una rafaga.
 * \param r Rafaga a mover.
 */
void RafagaMueve(Rafaga r);

/** \brief Dibuja una rafaga.
 * \param r Rafaga a dibujar.
 */
void RafagaDibuja(Rafaga r);

/** \brief Inserta una nueva bala en una rafaga.
 * \param r Rafaga donde se inserta la bala.
 * \param bala Bala a insertar.
 */
void RafagaInsertaNuevaBala(Rafaga r, Bala bala);

/** \brief Detecta la colision entre una rafaga y una flota.
 * \param r Rafaga a detectar.
 * \param f Flota a detectar.
 * \return 0, si no hay colision. 1 si hay colision.
 */
int RafagaColision(Rafaga r, Flota f);


#endif // RAFAGA_H_INCLUDED
