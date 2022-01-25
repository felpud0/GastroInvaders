#include <stdlib.h>
#include "Galaxia.h"
#include "Astro.h"
#include "Colision.h"

struct GalaxiaRep
{
    Astro * a;
    int max,n;
};
Galaxia GalaxiaCrea(int max)
{
    Galaxia g = malloc(sizeof(struct GalaxiaRep));
    g->a = malloc(sizeof(Astro)*max);
    g->max = max;
    g->n = 0;
    return g;
}
void GalaxiaLibera(Galaxia g)
{
    for(int i=0; i<g->n; i++) AstroLibera(g->a[i]);
    free(g->a);
    free(g);
}
void GalaxiaInsertaNuevoAstro(Galaxia g, Astro a)
{
    if (g->n<g->max)
    {
        g->a[g->n] = a;
        g->n++;
    }
}
void GalaxiaDibuja(Galaxia g)
{
    for(int i=0; i<g->n; i++) AstroDibuja(g->a[i]);
}
int GalaxiaColision(Galaxia g, int x, int y, int w, int h)
{
    int i=0;
    while((i<g->n)&&
            (!Colision2(AstroGetX(g->a[i]),
                       AstroGetY(g->a[i]),
                       AstroGetW(g->a[i]),
                       AstroGetH(g->a[i]),
                       x,y,w,h)))
        i++;
    int colision = (i<g->n);
    if (colision)
    {
        AstroLibera(g->a[i]);
        g->a[i] = g->a[g->n-1];
        g->n--;
    }
    return colision;
};
