#include <stdlib.h>
#include "Bala.h"
#include "Pantalla.h"



struct BalaRep
{

    Imagen i;
    int x;
    int y;
    int w;
    int h;
    int vx;
    int vy;

};


Bala BalaCrea(Imagen i, int x, int y, int w, int h,int vx, int vy)
{
    Bala b = malloc(sizeof(struct BalaRep));
    b->i=i;
    b->x=x;
    b->y=y;
    b->w=w;
    b->h=h;
    b->vx=vx;
    b->vy=vy;


    return b;
};

void BalaLibera(Bala b)
{
    free(b);
};

int BalaMueve(Bala b)
{


    b->x+=b->vx;
    b->y+=b->vy;

    if (b->x<0) BalaLibera(b); //Para que no se salga el personaje por (0,y),(x,0),(WPANTALLA,y),(x,YPANTALLA) respectivamente
    return b->y<0;
//    if (b->x> (wPantalla-p->w)) p->x = (wPantalla-p->w);
//    if (b->y> (hPantalla-p->h)) p->y = (hPantalla-p->h);

};

void BalaDibuja (Bala b)
{
    Pantalla_DibujaImagen(b->i,b->x,b->y,b->w,b->h);
};


int BalaGetX(Bala b)
{
    return b->x;
};

int BalaGetY(Bala b)
{
    return b->y;
};
int BalaGetW(Bala b)
{
    return b->w;
};
int BalaGetH(Bala b)
{
    return b->h;
};
