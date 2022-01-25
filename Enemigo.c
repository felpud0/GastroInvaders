#include <stdlib.h>
#include "Enemigo.h"
#include "Colision.h"
#include "Pantalla.h"
#include "personaje.h"
#include "Bala.h"
#include <math.h>
#include <stdio.h>

struct EnemigoRep
{

    Imagen i,iExpl;
    int x;
    int y;
    int w;
    int h;
    int vMod;
    int vx;
    int vy;
    short int enc;
    int nivel;
    int muerte;
    int frames;


};


Enemigo EnemigoCrea(Imagen i,Imagen iExpl,int x, int y, int w, int h,int vx,int vy,int nivel,int frames)
{
    Enemigo e = malloc(sizeof(struct EnemigoRep));
    e->i=i;
    e->iExpl=iExpl;
    e->x=x;
    e->y=y;
    e->w=w;
    e->h=h;
    e->vMod=1;
    e->vx=vx;
    e->vy=vy;
    e->enc=0;
    e->nivel=nivel;
    e->muerte=0;
    e->frames=frames;

    return e;
};


void EnemigoLibera(Enemigo e)
{
    free(e);
};

int EnemigoMueve(Enemigo e, Personaje p)
{

    if (e->nivel>=2)
    {

        double d = sqrt(pow(PersonajeGetX(p)+PersonajeGetW(p)/2-e->x-e->w/2,2)+pow(PersonajeGetY(p)+PersonajeGetH(p)/2-e->y-e->h/2,2));
        if ((!e->enc)) e->vMod = sqrt(pow(e->vx,2)+pow(e->vy,2));

    // actualización de la posición del objeto perseguidor
        if (((d<400) || (e->enc))&&(!(e->y>Pantalla_Altura()-200)))
        {
            e->vx = e->vMod*(PersonajeGetX(p)-e->x)/d;
            e->vy = e->vMod*(PersonajeGetY(p)-e->y)/d;
            e->enc = 1; //El enemigo queda encantado.
        };

    }

    if (!e->muerte)
    {
        e->x+=e->vx;
        e->y+=e->vy;
    }


    //Para que no se salga el Enemigo por (0,y),(x,0),(WeANTALLA,y),(x,YeANTALLA) reseectivamente
    if (e->x<=0)
    {
        e->x = 0;
        e->vx *= -1;
    };
    //if (e->y<0) e->y = 0;
    if (e->x> (Pantalla_Anchura()-e->w))
    {
         e->x = (Pantalla_Anchura()-e->w);
         e->vx *= -1;
    };
    //if (e->y> (Pantalla_Altura()-e->h)) e->y = (Pantalla_Altura()-e->h);
    return e->y> (Pantalla_Altura()-e->h);

};

void EnemigoSetMuerte(Enemigo e,int estado)
{
    e->muerte=estado;
}
int EnemigoGetMuerte(Enemigo e)
{
    return (e->muerte);
}

void EnemigoDibuja (Enemigo e)
{

    switch (e->muerte)
    {
    case 0:
        Pantalla_DibujaImagen(e->i,e->x,e->y,e->w,e->h);
        break;
    case 1:
    {
        Pantalla_DibujaImagen(e->iExpl,e->x,e->y,e->w,e->h);
        if (e->frames)
        {
            e->w-=2;
            e->h-=2;
            e->x++;
            e->y++;
            e->frames--;
        }

        else e->muerte =2;
        break;
    }
    }


};

int EnemigoGetX(Enemigo e)
{
    return e->x;
};

int EnemigoGetY(Enemigo e)
{
    return e->y;
};
int EnemigoGetW(Enemigo e)
{
    return e->w;
};
int EnemigoGetH(Enemigo e)
{
    return e->h;
};

