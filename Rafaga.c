#include <stdlib.h>
#include "Rafaga.h"
#include "personaje.h"

struct RafagaRep
{
    Bala b;
    Rafaga sig;
};

Rafaga RafagaCrea()
{
    Rafaga r = malloc(sizeof(struct RafagaRep));
    r->sig = NULL;
    return r;
}

void RafagaLibera(Rafaga r)
{
    while(r->sig!=NULL)
    {
        Rafaga aux = r->sig;
        r->sig = r->sig->sig;
        BalaLibera(aux->b);
        free(aux);
    }
    free(r);
}

void RafagaMueve(Rafaga r)
{
    while(r->sig!=NULL)
    {
        if (BalaMueve(r->sig->b))
        {
            Rafaga aux = r->sig;
            r->sig = r->sig->sig;
            BalaLibera(aux->b);
            free(aux);
        }
        else r = r->sig;
    }
}
void RafagaDibuja(Rafaga r)
{
    for(; r->sig!=NULL; r=r->sig)
        BalaDibuja(r->sig->b);
}

void RafagaInsertaNuevaBala(Rafaga r, Bala bala)
{
    Rafaga aux = malloc(sizeof(struct RafagaRep));
    aux->b = bala;
    aux->sig = r->sig;
    r->sig = aux;

}

int RafagaColision(Rafaga r, Flota f)
{
    while((r->sig!=NULL)&&(!FlotaColision(f,BalaGetX(r->sig->b),BalaGetY(r->sig->b), BalaGetW(r->sig->b),BalaGetH(r->sig->b))))
    {
        r=r->sig;
    };
    int colision=r->sig!=NULL;
    if (colision)
    {

        Rafaga aux = r->sig;
        r->sig = r->sig->sig;
        BalaLibera(aux->b);
        free(aux);
    };
    return (colision);
}


//int RafagaColisionEjemplo(Rafaga r, Flota f)
//{
//    while((r->sig!=NULL)&&(!FlotaColision(f,BalaGetX(r->sig->b),BalaGetY(r->sig->b), BalaGetW(r->sig->b),BalaGetH(r->sig->b))))
//    {
//        r=r->sig;
//    };
//    int colision=r->sig!=NULL;
//    if (colision) return BalaGetX(r->sig->b);
//    else return 255;
//
//}

