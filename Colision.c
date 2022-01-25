#include "Pantalla.h"
#include "Enemigo.h"
#include "math.h"


int ColisionDeDos(int x1,int y1, int w1,int h1,int x2,int y2,int w2, int h2)
{
    double cx1 = x1+w1/2.0;
    double cy1 = y1+h1/2.0;
    double cx2 = x2+w2/2.0;
    double cy2 = y2+h2/2.0;
    double r1  = sqrt(pow(w1/2.0,2.0)+pow(h1/2.0,2.0));
    double r2  = sqrt(pow(w2/2.0,2.0)+pow(h2/2.0,2.0));
    double porcentaje = (r1+r2)*0.25;
    return sqrt(pow(cx1-cx2,2.0)+pow(cy1-cy2,2.0))<((r1+r2)-porcentaje);

};
int Colision2(int x1, int y1, int h1, int w1, int x2, int y2, int h2, int w2)
{
    return ((x2<=x1+w1) &&
            (x2+w2>=x1) &&
            (y2+h2>=y1) &&
            (y2<=y1+h1));

};


