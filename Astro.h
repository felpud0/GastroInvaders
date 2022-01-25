#ifndef ASTRO_H_INCLUDED
#define ASTRO_H_INCLUDED
#include "Pantalla.h"

/**
    \file Astro.h
    \brief TDA Astro nos posibilita crear una astro con diferentes parametros.
 */


typedef struct AstroRep * Astro;

/** \brief Crea una astro con diferentes parametros.
 *
 * \param i Imagen del astro.
 * \param x Coordenada horizontal del astro.
 * \param y Coordenada vertical del astro.
 * \param w Anchura de la astro.
 * \param h Altura de la astro.
 * \return Un astro.
 *
 */
Astro AstroCrea(Imagen i,int x, int y,int w, int h);

/** \brief Libera la memoria reservada de un astro.
 *
 * \param a Astro a liberar.
 *
 */
void AstroLibera(Astro a);

/** \brief Dibuja un astro.
 *
 * \param a Astro a dibujar.
 *
 */
void AstroDibuja(Astro a);

/** \brief Devuelve la anchura de un astro.
 *
 * \param a Astro del que se obtiene la anchura.
 * \return La anchura del astro.
 */
int AstroGetW(Astro a);

/** \brief Devuelve la altura de un astro.
 *
 * \param a Astro del que se obtiene la altura.
 * \return La altura del astro.
 */
int AstroGetH(Astro a);

/** \brief Devuelve la coordenada x de un astro.
 *
 * \param a Astro del que se obtiene la coordenada.
 * \return La coordenada x del astro.
 */
int AstroGetX(Astro a);

/** \brief Devuelve la coordenada y de un astro.
 *
 * \param a Astro del que se obtiene la coordenada.
 * \return La coordenada y del astro.
 */
int AstroGetY(Astro a);

#endif // ASTRO_H_INCLUDED
