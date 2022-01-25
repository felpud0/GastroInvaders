#include <stdlib.h>
#include "Astro.h"
#include "Pantalla.h"

struct AstroRep
{
    Imagen i;
    int x;
    int y;
    int w;
    int h;
};



Astro AstroCrea(Imagen i,int x, int y, int w, int h )
{
    Astro a = malloc(sizeof(struct AstroRep));
    a->i=i;
    a->x=x;
    a->y=y;
    a->w=w;
    a->h=h;

    return a;
};

void AstroLibera(Astro a)
{
    free(a);
};

void AstroDibuja(Astro a)
{
    Pantalla_DibujaImagen(a->i,a->x,a->y,a->w,a->h);

};


int AstroGetW(Astro a)
{
    return a->w;
};

int AstroGetH(Astro a)
{
    return a->h;
};

int AstroGetX(Astro a)
{
    return a->x;
};

int AstroGetY(Astro a)
{
    return a->y;
};
