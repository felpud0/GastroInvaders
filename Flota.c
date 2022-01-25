#include <stdlib.h>
#include <stdio.h>
#include "Flota.h"
#include "Colision.h"
#include "Enemigo.h"
#include "Rafaga.h"


struct FlotaRep
{
    Enemigo e;
    Flota sig;
};

Flota FlotaCrea()
{
    Flota f = malloc(sizeof(struct FlotaRep));
    f->sig = NULL;
    return f;
}

void FlotaLibera(Flota f)
{
    while(f->sig!=NULL)
    {
        Flota aux = f->sig;
        f->sig = f->sig->sig;
        EnemigoLibera(aux->e);
        free(aux);
    }
    free(f);
}

void FlotaMueve(Flota f, Personaje p)
{

    while(f->sig!=NULL)
    {
//        #error TODO (F#1#): Aqui intento que los enemigos tiren balas
//
//        if (rand()%20)
//        {
//            RafagaInsertaNuevaBala(r2,BalaCrea(iBalaE,EnemigoGetX(f->sig->e),EnemigoGetX(f->sig->e),20,20,0,8));
//        };
        if (EnemigoMueve(f->sig->e,p))
        {
            Flota aux = f->sig;
            f->sig = f->sig->sig;
            EnemigoLibera(aux->e);
            free(aux);
        }
        else f = f->sig;
    }
}
void FlotaDibuja(Flota f)
{
    for(; f->sig!=NULL; f=f->sig)
        EnemigoDibuja(f->sig->e);
}

void FlotaInsertaNuevoEnemigo(Flota f, Enemigo enemigo)
{
    Flota aux = malloc(sizeof(struct FlotaRep));
    aux->e = enemigo;
    aux->sig = f->sig;
    f->sig = aux;
}

int FlotaColision(Flota f, int x, int y, int w, int h)
{
    while((f->sig!=NULL)&&(!ColisionDeDos(EnemigoGetX(f->sig->e),EnemigoGetY(f->sig->e),EnemigoGetW(f->sig->e),EnemigoGetH(f->sig->e),x,y,w,h)))
        f=f->sig;
    int colision=f->sig!=NULL;



    if (colision)
    {

        EnemigoSetMuerte(f->sig->e,1);

    }

    return (colision);
}
void FlotaDestruirMuertos(Flota f)
{
    while((f->sig!=NULL)&&(EnemigoGetMuerte(f->sig->e)!=2))
        f=f->sig;
    int remuerto=f->sig!=NULL;

    if (remuerto)
    {
        Flota aux = f->sig;
        f->sig = f->sig->sig;
        EnemigoLibera(aux->e);
        free(aux);
    }
}
