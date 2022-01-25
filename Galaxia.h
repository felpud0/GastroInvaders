#ifndef GALAXIA_H_INCLUDED
#define GALAXIA_H_INCLUDED
#include "Astro.h"

/**
    \file Galaxia.h
    \brief TDA Galaxia nos sirve como estructura para diferentes astros.
 */
typedef struct GalaxiaRep * Galaxia;

/** \brief Crea una estructura donde insertar diferentes astros.
 * \param max Numero maximo de astros en galaxia.
 * \return Una Galaxia.
 */
Galaxia GalaxiaCrea(int max);

/** \brief Libera la memoria reservada de una galaxia.
 * \param g Galaxia a liberar.
 */
void GalaxiaLibera(Galaxia g);

/** \brief Inserta un nuevo astro en una galaxia.
 * \param g Galaxia donde se inserta el astro.
 * \param a Astro a insertar.
 */
void GalaxiaInsertaNuevoAstro(Galaxia g, Astro a);

/** \brief Dibuja una galaxia.
 * \param g Galaxia a dibujar.
 */
void GalaxiaDibuja(Galaxia g);

/** \brief Detecta la colision entre una flota y cierto objeto, ademas, crea una explosion del enemigo colisionado.
 * \param g Galaxia a detectar.
 * \param x Coordenada x de un objeto a detectar.
 * \param y Coordenada y de un objeto a detectar.
 * \param w Anchura de un objeto a detectar.
 * \param h Altura de un objeto a detectar
 * \return 0, si no hay colision. 1, si hay colision.
 */
int GalaxiaColision(Galaxia g, int x, int y, int w, int h);

#endif // GALAXIA_H_INCLUDED
