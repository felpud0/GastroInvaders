#include <stdlib.h>
#include "personaje.h"

struct PersonajeRep
{
    Imagen i, iEsc, iExpl;
    int x;
    int y;
    int w;
    int h;
    int proteccion;
    int muerte;
    int frames;
    int framesVar;
};


Personaje PersonajeCrea(Imagen i, Imagen iEscudo,Imagen iExpl, int x, int y, int w, int h,int frames)
{
    Personaje p = malloc(sizeof(struct PersonajeRep));
    p->i=i;
    p->iEsc=iEscudo;
    p->iExpl=iExpl;
    p->x=x;
    p->y=y;
    p->w=w;
    p->h=h;
    p->proteccion=0;
    p->muerte=0;
    p->frames=frames;
    p->framesVar=frames;

    return p;
};

void PersonajeLibera(Personaje p)
{
    free(p);
};

void PersonajeMueve(Personaje p, int vx, int vy)
{
    if (!p->muerte)
    {
        p->x+=vx;
        p->y+=vy;
    }


    if (p->x<0) p->x = 0; //Para que no se salga el personaje por (0,y),(x,0),(WPANTALLA,y),(x,YPANTALLA) respectivamente
    if (p->y<0) p->y = 0;
    if (p->x> (Pantalla_Anchura()-p->w)) p->x = (Pantalla_Anchura()-p->w);
    if (p->y> (Pantalla_Altura()-p->h)) p->y = (Pantalla_Altura()-p->h);

};

void PersonajeSetMuerte(Personaje p, int stageMuerte)
{
    p->muerte=stageMuerte;
}

int PersonajeGetMuerte(Personaje p)
{
    return (p->muerte);
}

void PersonajeDibuja (Personaje p)
{

    if ((p->proteccion)&&(Pantalla_TeclaPulsada(SDL_SCANCODE_M))) Pantalla_DibujaImagen(p->iEsc,p->x,p->y,p->w,p->h);
    switch (p->muerte)
    {
        case 0: Pantalla_DibujaImagen(p->i,p->x,p->y,p->w,p->h);break;
        case 1:
            {
                Pantalla_DibujaImagen(p->iExpl,p->x+p->framesVar/p->frames,p->y,p->w*p->framesVar/p->frames,p->h*p->framesVar/p->frames);
                if (p->framesVar) p->framesVar--;
                else {p->muerte=2; p->framesVar=p->frames;};
            }
    }
};

void PersonajeSetProteccion(Personaje p, int nProtec)
{
    p->proteccion=nProtec;
};
int PersonajeGetProteccion(Personaje p)
{
    return p->proteccion;
};

void PersonajeFixCoords(Personaje p, int x, int y)
{
    p->x=x;
    p->y=y;
};

int PersonajeGetX(Personaje p)
{
    return p->x;
};

int PersonajeGetY(Personaje p)
{
    return p->y;
};
int PersonajeGetW(Personaje p)
{
    return p->w;
};
int PersonajeGetH(Personaje p)
{
    return p->h;
};
