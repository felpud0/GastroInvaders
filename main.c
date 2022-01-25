#include <stdlib.h>
#include <stdio.h>
#include "Pantalla.h"
#include "personaje.h"
#include "Enemigo.h"
#include "Colision.h"
#include "Galaxia.h"
#include "Astro.h"
#include "Flota.h"
#include "Rafaga.h"
#include <time.h>


//Definimos el tamaño de la ventana
#define WPANTALLA 1280
#define HPANTALLA  720

//Atributos personaje.
#define VXPERSONAJE 8
#define VYPERSONAJE 8
#define WPERSONAJE 60
#define HPERSONAJE 60
#define VIDAS 5
#define WCORAZON 20
#define HCORAZON 25

#define TMUERTE 40

//Atributos enemigo.
#define VXENEMIGO 5
#define VYENEMIGO 2
#define WENEMIGO 50
#define HENEMIGO 40
#define TMENEMIGO 10

//Atributos para la galaxia.
#define MAXASTROS 5
#define TIPOSASTROS 4
#define FRECASTROS 400
#define PUNTOSEXTRA 2

//Atributos para las balas.
#define WBALA 10
#define HBALA 40

//Atributos para flota.
#define FRECENEMIGOS 150

//Atributos rayo.
#define WRAYO 5
#define HRAYO 30
#define TMAXRAYO 150
#define TESCUDO 300


/**
* \author Felipe Sánchez González.
* \mainpage Proyecto: Gastro Invaders - Tecnología de la Programación.
* \file main.c
* \brief  Programa en el que objetivo es aguantar el maximo tiempo posible sin que te golpeen las albondigas asesinas. El usuario controla una nave con diferentes armas.
*/

int main(int argc, char *argv[])

{

    Pantalla_Crea("Gastro Invaders", WPANTALLA,HPANTALLA);

    Imagen fondoB = Pantalla_ImagenLee("portada.bmp",0);
    Imagen fondoJ = Pantalla_ImagenLee("fondoJ1edit.bmp",0);
    Imagen chicoteB = Pantalla_ImagenLee("chicote2.bmp",1);

    Imagen naveEnemiga = Pantalla_ImagenLee("meatball.bmp",1);
    Imagen navePersonaje = Pantalla_ImagenLee("chicote.bmp",1);
    Imagen iEscudo= Pantalla_ImagenLee("escudo.bmp",1);
    Imagen eImagen = Pantalla_ImagenLee("meatball.bmp",1);
    Imagen eImagen2 = Pantalla_ImagenLee("meatball2.bmp",1);
    Imagen eImagen3 = Pantalla_ImagenLee("meatball3.bmp",1);
    Imagen bImagen = Pantalla_ImagenLee("falcon.bmp",1);
    Imagen explosion = Pantalla_ImagenLee("explosion.bmp",1);
    Imagen corazon = Pantalla_ImagenLee("corazon.bmp",1);
    Imagen iRayo = Pantalla_ImagenLee("rayo.bmp",0);
    Imagen iRayoBig = Pantalla_ImagenLee("rayoBig.bmp",0);
    Imagen iRayoMod = Pantalla_ImagenLee("rayoMod.bmp",0);
    Imagen iRayoBan = Pantalla_ImagenLee("rayoBan.bmp",0);
    Imagen bImagenMod = Pantalla_ImagenLee("falconMod.bmp",1);
    Imagen iEscudoBig = Pantalla_ImagenLee("iEscudo.bmp",1);
    Imagen iEscudoMod = Pantalla_ImagenLee("IEscudoMod.bmp",1);



    srand(time(NULL));

    int ajusteTextoRecord = 0;

    int fin = 0;
    int menuB=1;
    int seleccion=0;

    //##################################################################################################################################################
    //##################################################################################################################################################
    //##################################################################################################################################################
    //#########################################          FASE DE BIENVENIDA        #####################################################################
    //##################################################################################################################################################
    //##################################################################################################################################################
    //##################################################################################################################################################

    while ((Pantalla_Activa()) && !(fin))

    {
        //Condicion de terminacion.
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_RETURN))fin = 1;

        //Seleccion de nivel.
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN)&&(!(seleccion)))
        {
            menuB++;
            seleccion =1;
        }
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_UP)&&(!(seleccion)))
        {
            menuB--;
            seleccion =1;
        }

        if (!(Pantalla_TeclaPulsada(SDL_SCANCODE_UP)||Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN))) seleccion=0;

        if (menuB>3) menuB=1;
        if (menuB<1) menuB=3;

        //Dibujar fondo.
        Pantalla_DibujaImagen(fondoB,0,0,WPANTALLA,HPANTALLA);

        //Dibuja chicote.
        Pantalla_DibujaImagen(naveEnemiga,WPANTALLA/2,HPANTALLA/2 - 170,300,300);
        Pantalla_DibujaImagen(chicoteB,WPANTALLA/2 + 150,HPANTALLA/2 - 100,300,300);

        //Rectangulo para texto.
        Pantalla_ColorTrazo(255,0,0,255);
        Pantalla_ColorRelleno(50,50,50,255);
        Pantalla_DibujaRectangulo((WPANTALLA-270)/2 - 300,(HPANTALLA)/2 -45 ,270,150);

        //Texto.
        Pantalla_ColorTrazo(rand()%255,rand()%255,rand()%255,255);
        Pantalla_DibujaTexto("Seleccione dificultad:", 240   , HPANTALLA/2 - 35 );
        Pantalla_DibujaTexto("Pulsa [ENTER] jugar", 240 , HPANTALLA/2 +83);

        //Seleccion de dificultad.
        switch (menuB)
        {
        case 1:
        {
            Pantalla_ColorTrazo(255,0,0,255);
            Pantalla_DibujaTexto("Baja",250,HPANTALLA/2-2 );
            Pantalla_ColorTrazo(0,0,0,255);
            Pantalla_DibujaTexto("Media",250,HPANTALLA/2+30-2);
            Pantalla_ColorTrazo(0,0,0,255);
            Pantalla_DibujaTexto("Alta",250,HPANTALLA/2+60-2 );
            break;
        }
        case 2:
        {
            Pantalla_ColorTrazo(0,0,0,255);
            Pantalla_DibujaTexto("Baja",250,HPANTALLA/2-2 );
            Pantalla_ColorTrazo(255,0,0,255);
            Pantalla_DibujaTexto("Media",250,HPANTALLA/2+30-2);
            Pantalla_ColorTrazo(0,0,0,255);
            Pantalla_DibujaTexto("Alta",250,HPANTALLA/2+60-2 );
            break;
        }
        case 3:
        {
            Pantalla_ColorTrazo(0,0,0,255);
            Pantalla_DibujaTexto("Baja",250,HPANTALLA/2-2);
            Pantalla_ColorTrazo(0,0,0,255);
            Pantalla_DibujaTexto("Media",250,HPANTALLA/2+30-2);
            Pantalla_ColorTrazo(255,0,0,255);
            Pantalla_DibujaTexto("Alta",250,HPANTALLA/2+60-2 );
            break;
        }
        }

        Pantalla_Actualiza();
        Pantalla_Espera(50);

    };
    //##################################################################################################################################################
    //##################################################################################################################################################
    //##################################################################################################################################################


    fin = 0;

    typedef struct
    {
        Imagen img;
        int w;
        int h;
    } imagen_astro;

    imagen_astro img_astros[TIPOSASTROS];
    img_astros[0].img = Pantalla_ImagenLee("churrasco.bmp",1);
    img_astros[0].w = 30;
    img_astros[0].h = 30;
    img_astros[1].img = Pantalla_ImagenLee("tortitas.bmp",1);
    img_astros[1].w = 30;
    img_astros[1].h = 30;
    img_astros[2].img = Pantalla_ImagenLee("platano.bmp",1);
    img_astros[2].w = 30;
    img_astros[2].h = 30;
    img_astros[3].img = Pantalla_ImagenLee("manzana.bmp",1);
    img_astros[3].w = 30;
    img_astros[3].h = 35;

    //Variable para vxEnemigo.
    int vxE = VXENEMIGO;
    if (rand()%2 ==0) vxE*=-1;

    //Creacion de personaje,enemigo y galaxia.
    Personaje p = PersonajeCrea(navePersonaje,iEscudo, explosion,rand()%(WPANTALLA - WPERSONAJE),HPANTALLA- HPERSONAJE,WPERSONAJE,HPERSONAJE,TMUERTE);
    Galaxia galaxia = GalaxiaCrea(MAXASTROS);
    Flota f1 = FlotaCrea();
    Rafaga r = RafagaCrea();
    int disparoRafaga=0;



    //Variables para el calculo de puntuacion
    int t1 = time(NULL);
    int t2;
    int puntos=0;
    char puntuacion[100];

    //Preparacion de fichero para records.
    int puntuacionMax = 0;
    int datoFichero;    //Variable para recoger el dato de fscan
    char textoRecord[100];

    //Abriendo el fichero como lectura y leyendo puntuaciones.
    FILE *f;
    f=  fopen("records.txt","r");

    if (f!=NULL)
    {
        while (!feof(f))
        {
            //Recorre el fichero y obtiene la puntuacion mas alta.
            fscanf(f,"%d",&datoFichero);
            if (datoFichero>puntuacionMax)
                puntuacionMax = datoFichero; //La mas alta, la almacena en puntuacionMax.
        }
        fclose(f);
    };


    //Variable y texto de vidas.
    char textoVidas[100];
    int vidas = VIDAS;
    sprintf(textoVidas,"VIDAS: %d",vidas);

    //Variables debug.
    //char textoDificultad[100];
    char selDificultad[100];
    sprintf(selDificultad,"Modo %d",menuB);

    //Variables dificultad y stages.
    int dificultadMin = FRECENEMIGOS;
    //si elijes una dificultad que no sea la 1 se multiplica.
    switch (menuB)
    {
    case 2:
    {
        vxE*=1.5;
        dificultadMin*=0.75;
        break;
    };
    case 3:
    {
        vxE*=2;
        dificultadMin *= 0.5;
        break;
    };
    };
    int dificultad=dificultadMin;
    int stage=1;
    char textoStage[100];
    sprintf(textoStage,"STAGE: %d",stage);

    //Variables escudo.
    char textoEscudo[100]="ESCUDO: ";
    int puntosExtra=0;
    int puntosExtraGoal=10;


    //Variables menu.
    int menuJ=0;
    seleccion=0;
    int tMenu=0;

    //Rellenando nuestro cuadro de vidas.
    Imagen corazones[vidas];
    for (int i=0; i<=vidas-1; i++) corazones[i]=corazon;

    //Variables para el rayo.
    int enemigosMatados=0;
    int enemigosMatadosGoal=20;
    int tRayo=0;
    char textoRayo[100]="RAYO: ";

    //Variables para mostrar las armas y escudo.
    int arma=0;
    Imagen armero[3][3]= {{bImagen,bImagenMod},{iRayoBig,iRayoMod,iRayoBan},{iEscudoBig,iEscudoMod}};

    int seleccionESC=0;
    int esperaMuerte=0;



    //##################################################################################################################################################
    //##################################################################################################################################################
    //##################################################################################################################################################
    //#########################################          FASE DE JUEGO        ##########################################################################
    //##################################################################################################################################################
    //##################################################################################################################################################
    //##################################################################################################################################################

    while (((Pantalla_Activa()))&& (!(fin)))

    {
        //Te quedas sin vidas, se sale del bucle.
        if (vidas <= 0)   fin = 1;

        //Cuando presionas escape, vas al menu.
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE)&&(!(seleccionESC)))
        {
            menuJ=1;
            tMenu=time(NULL);
            seleccionESC=1;
        };
        if (menuJ>0)
        {
            //Condicion de terminacion del MENU.
            if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE)&&(!(seleccionESC)))
            {
                menuJ=0;
                seleccionESC=1;
            };
            if (Pantalla_TeclaPulsada(SDL_SCANCODE_RETURN))
            {
                switch (menuJ)
                {
                case 2:
                {
                    fin=1;
                    menuJ=0;
                    break;
                };
                case 1:
                {
                    menuJ=0;
                    t1=t1+(time(NULL)-tMenu);
                    break;
                };
                };

            }
            else
            {

                //Seleccion de opcion.
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN)&&(!(seleccion)))
                {
                    menuJ++;
                    seleccion =1;
                }
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_UP)&&(!(seleccion)))
                {
                    menuJ--;
                    seleccion =1;
                }

                if (!(Pantalla_TeclaPulsada(SDL_SCANCODE_UP)||Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN))) seleccion=0;
                if (!(seleccionESC)) seleccionESC=0;

                if (menuJ>2) menuJ=1;
                if (menuJ<1) menuJ=2;

                //Para mostrar, el tiempo en menu(DEBUG).
                //sprintf(textotMenu,"TMenu: %d",time(NULL)-tMenu);

                //Fondo.
                Pantalla_DibujaImagen(fondoJ,0,0,WPANTALLA,HPANTALLA);

                //Personajes.
                GalaxiaDibuja(galaxia);
                PersonajeDibuja(p);
                FlotaDibuja(f1);
                RafagaDibuja(r);

                //HUD.
                //parte derecha
                Pantalla_ColorTrazo(255,0,0,255);
                Pantalla_DibujaTexto(puntuacion,WPANTALLA-145,5);
                Pantalla_DibujaTexto(textoRecord,WPANTALLA-110-ajusteTextoRecord,20);
                Pantalla_DibujaTexto(textoVidas,WPANTALLA-100,35);
                Pantalla_DibujaTexto(textoStage,WPANTALLA/2-5,5);
                for (int i=vidas-1; i>=0; i--)Pantalla_DibujaImagen(corazones[i],WPANTALLA-20-(VIDAS*WCORAZON)+i*WCORAZON,50,WCORAZON,HCORAZON);
                //parte izquierda
                Pantalla_DibujaTexto("Pulsa [ESC] para abrir el menu.", 5 , 5);
                Pantalla_DibujaTexto(textoEscudo,5,30);
                if (PersonajeGetProteccion(p)) {Pantalla_ColorRelleno(255,0,0,255); Pantalla_DibujaRectangulo(5,45,PersonajeGetProteccion(p)/3,5);}
                else
                {
                    Pantalla_ColorRelleno(50,50,50,255);
                    Pantalla_DibujaRectangulo(5,45,puntosExtraGoal*10,5);
                    Pantalla_ColorRelleno(255,0,0,255);
                    Pantalla_DibujaRectangulo(5,45,puntosExtra%puntosExtraGoal*10,5);
                };

                Pantalla_DibujaTexto(textoRayo,5,60);

                switch (arma)
                {
                case 0:
                {
                    Pantalla_DibujaImagen(armero[0][0],5,100,WBALA*2,HBALA*2);
                    Pantalla_DibujaImagen(armero[1][1],35,100,WBALA*2,HBALA*2);
                    break;
                };
                case 1:
                {
                    Pantalla_DibujaImagen(armero[0][1],5,100,WBALA*2,HBALA*2);
                    Pantalla_DibujaImagen(armero[1][0],35,100,WBALA*2,HBALA*2);
                    break;
                };
                };

                if (PersonajeGetProteccion(p)) Pantalla_DibujaImagen(armero[2][0],5,200,50,65);
                else Pantalla_DibujaImagen(armero[2][1],5,200,50,65);

                if (tRayo)
                {
                    Pantalla_ColorRelleno(255,0,0,255);
                    Pantalla_DibujaRectangulo(5,75,tRayo/1.5,5);
                }
                else
                {
                    Pantalla_ColorRelleno(50,50,50,255);
                    Pantalla_DibujaRectangulo(5,75,enemigosMatadosGoal*5,5);
                    Pantalla_ColorRelleno(255,0,0,255);
                    Pantalla_DibujaRectangulo(5,75,enemigosMatados%enemigosMatadosGoal*5,5);
                    Pantalla_DibujaImagen(armero[1][2],35,100,WBALA*2,HBALA*2);
                }


                //Menu.
                Pantalla_ColorRelleno(50,50,50,255);
                Pantalla_DibujaRectangulo(WPANTALLA/2-70,HPANTALLA/2-30,120,80);

                switch (menuJ)
                {
                case 1:
                {
                    Pantalla_ColorTrazo(255,0,0,255);
                    Pantalla_DibujaTexto("Continuar",WPANTALLA/2-50,HPANTALLA/2-15);
                    Pantalla_ColorTrazo(255,255,255,255);
                    Pantalla_DibujaTexto("Salir",WPANTALLA/2-50,HPANTALLA/2+5);
                    break;
                };
                case 2:
                {
                    Pantalla_ColorTrazo(255,255,255,255);
                    Pantalla_DibujaTexto("Continuar",WPANTALLA/2-50,HPANTALLA/2-13);
                    Pantalla_ColorTrazo(255,0,0,255);
                    Pantalla_DibujaTexto("Salir",WPANTALLA/2-50,HPANTALLA/2+7);
                    break;
                };

                };
                Pantalla_ColorTrazo(255,255,255,255);
                Pantalla_DibujaTexto("[ENTER]",WPANTALLA/2-50,HPANTALLA/2+30);


                Pantalla_Actualiza();
                Pantalla_Espera(40);
            }
        }


        //Si no, sigues jugando...
        else
        {
            //Deteccion de control del personaje
            if (!(esperaMuerte))
            {
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT))
                {
                    PersonajeMueve(p,-VXPERSONAJE,0);
                };
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT))
                {
                    PersonajeMueve(p,VXPERSONAJE,0);
                };
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_UP))
                {
                    PersonajeMueve(p,0,-VYPERSONAJE);
                };
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN))
                {
                    PersonajeMueve(p,0,VYPERSONAJE);
                };
            }


            //Calculo de puntuacion.
            t2= time(NULL);
            puntos = t2-t1+puntosExtra;
            sprintf(puntuacion,"PUNTUACION: %d",puntos);

            //Aumentando la dificultad.
            if ((puntos>=50)&&(!(stage>=2)))
            {
                dificultadMin *= 0.85;
                stage = 2;
                sprintf(textoStage,"STAGE: %d",stage);
            };
            if ((puntos>=100)&&(!(stage>=3)))
            {
                dificultadMin *= 0.85;
                stage = 3;
                sprintf(textoStage,"STAGE: %d",stage);
            };


            //Dificultad en aumento de manera sencilla.
            if (dificultad<15) dificultad = 14;
            else  dificultad=dificultadMin-(t2-t1);


            //Condiciones de carga del escudo.
            if (((puntosExtra%puntosExtraGoal==0)&&(PersonajeGetProteccion(p)==0))&&(puntosExtra!=0))
            {
                PersonajeSetProteccion(p,TESCUDO);
                puntosExtra += PUNTOSEXTRA;
            };
            if (PersonajeGetProteccion(p)==TESCUDO) sprintf(textoEscudo,"ESCUDO: Disponible [M]");
            else sprintf(textoEscudo,"ESCUDO: ");

            //printf("Protec: %d\n",PersonajeGetProteccion(p));

            //Condiciones escudo.
            if ((Pantalla_TeclaPulsada(SDL_SCANCODE_M))&&(PersonajeGetProteccion(p)))
            {
                PersonajeSetProteccion(p,PersonajeGetProteccion(p)-1);
            };


            //Que mensaje de record mostrar.
            if (puntuacionMax>puntos)
                sprintf(textoRecord,"RECORD: %d",puntuacionMax);
            else
            {
                ajusteTextoRecord =40;
                sprintf(textoRecord,"NUEVO RECORD!!");
            };


            //Generacion aleatoria de astros(galaxia) en pantalla.
            if (!(rand()%FRECASTROS))
            {
                int tipo=rand()%(TIPOSASTROS);
                GalaxiaInsertaNuevoAstro(galaxia,
                                         AstroCrea(img_astros[tipo].img,
                                                   rand()%(WPANTALLA-img_astros[tipo].w),
                                                   rand()%(HPANTALLA-img_astros[tipo].h),
                                                   img_astros[tipo].w,
                                                   img_astros[tipo].h));
            };

            //Colision de astros y personaje.
            if (GalaxiaColision(galaxia,PersonajeGetX(p),PersonajeGetY(p),PersonajeGetW(p),PersonajeGetH(p)))
            {
                puntosExtra+=PUNTOSEXTRA;
            };

            if ((Pantalla_TeclaPulsada(SDL_SCANCODE_B)&&(!(seleccion))))
            {
                arma++;
                if (arma>1) arma=0;
                seleccion=1;
            }

            if (!(Pantalla_TeclaPulsada(SDL_SCANCODE_B))) seleccion=0;
            if (!(tRayo)) arma=0;


            //(DISPAROS)Generacion de balas(rafaga) en papntalla.
            if ((Pantalla_TeclaPulsada(SDL_SCANCODE_N))&&(!(disparoRafaga))&&(!(esperaMuerte)))
            {
                if (rand()%2)
                {
                    if (arma)
                    {
                        RafagaInsertaNuevaBala(r,
                                               BalaCrea(iRayo,PersonajeGetX(p),PersonajeGetY(p)-5,WRAYO,HRAYO,5,-20));
                        disparoRafaga=1;
                        tRayo--;
                    }
                    else
                    {
                        RafagaInsertaNuevaBala(r,
                                               BalaCrea(bImagen,PersonajeGetX(p),PersonajeGetY(p),WBALA,HBALA,0,-20));
                        disparoRafaga=1;
                    }

                }
                else
                {
                    if (arma)
                    {
                        RafagaInsertaNuevaBala(r,
                                               BalaCrea(iRayo,PersonajeGetX(p)+50,PersonajeGetY(p)-5,WRAYO,HRAYO,-5,-20));
                        disparoRafaga=1;
                        tRayo--;
                    }
                    else
                    {
                        RafagaInsertaNuevaBala(r,
                                               BalaCrea(bImagen,PersonajeGetX(p)+50,PersonajeGetY(p),WBALA,HBALA,0,-20));
                        disparoRafaga=1;
                    }
                }

            }
            //Si no se esta pulsando la tecla, se podra volver a disparar.
            if (!(Pantalla_TeclaPulsada(SDL_SCANCODE_N))) disparoRafaga=0;
            if (!(Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE))) seleccionESC=0;

            //Movimiento refaga.
            RafagaMueve(r);


            //Generacion aleatoria de enemigos(flota) en pantalla.
            switch (stage)
            {
            case 1:
            {
                if (!(rand()%dificultad))
                {
                    if (rand()%2 ==0) vxE*=-1;
                    FlotaInsertaNuevoEnemigo(f1,
                                             EnemigoCrea(eImagen,explosion,rand()%(WPANTALLA - WENEMIGO),5,WENEMIGO,HENEMIGO,vxE,VYENEMIGO,stage,TMENEMIGO));
                };
                break;
            };

            case 2:
            {
                if (!(rand()%dificultad))
                {
                    if (rand()%2 ==0) vxE*=-1;
                    FlotaInsertaNuevoEnemigo(f1,
                                             EnemigoCrea(eImagen2,explosion,rand()%(WPANTALLA - WENEMIGO),5,WENEMIGO,HENEMIGO,vxE,VYENEMIGO,stage,TMENEMIGO));
                };
                break;
            };

            case 3:
            {
                if (!(rand()%dificultad))
                {
                    if (rand()%2 ==0) vxE*=-1;
                    FlotaInsertaNuevoEnemigo(f1,
                                             EnemigoCrea(eImagen3,explosion,rand()%(WPANTALLA - WENEMIGO),5,WENEMIGO,HENEMIGO,vxE,VYENEMIGO,stage,TMENEMIGO));
                };
                break;
            };
            }


            //printf("Dificultad %d\n",dificultad);

            //Movimiento de la flota
            if (!(esperaMuerte)) FlotaMueve(f1,p);

            //Colision de flota y personaje.
            if ((FlotaColision(f1,PersonajeGetX(p),PersonajeGetY(p),PersonajeGetW(p),PersonajeGetH(p)))&&(!((Pantalla_TeclaPulsada(SDL_SCANCODE_M))&&(PersonajeGetProteccion(p))))&&(!(esperaMuerte)))
            {
                vidas--;
                sprintf(textoVidas,"VIDAS: %d",vidas);
                PersonajeSetMuerte(p,1);
                esperaMuerte=TMUERTE;


            }
            if (esperaMuerte) esperaMuerte--;
            //if (esperaMuerte==30)  PersonajeFixCoords(p,rand()%(WPANTALLA - WPERSONAJE),HPANTALLA- HPERSONAJE);
            if (PersonajeGetMuerte(p)==2)
            {
                PersonajeFixCoords(p,rand()%(WPANTALLA - WPERSONAJE),HPANTALLA- HPERSONAJE);
                PersonajeSetMuerte(p,0);
            }



            FlotaDestruirMuertos(f1);


            //Nos detecta las colisiones entre flota y rafaga.
            if ((RafagaColision(r,f1))&&((!(tRayo))||(enemigosMatados%enemigosMatadosGoal==0))) enemigosMatados++;


            if (((enemigosMatados%enemigosMatadosGoal)==0)&&(enemigosMatados!=0))
            {
                tRayo=TMAXRAYO;
                enemigosMatados++;
            };
            if (tRayo==TMAXRAYO) sprintf(textoRayo,"RAYO: Usa [B] para cambiar de arma!");
            else sprintf(textoRayo,"RAYO: ");

            if ((tRayo>0)&&(arma==1)) disparoRafaga=0;

//            printf("EnemigosM: %d\n",enemigosMatados);
//            printf("EnemigosM/Goal: %d\n",enemigosMatados%enemigosMatadosGoal);
//            printf("tRayo: %d\n",tRayo);


            //Fondo.
            Pantalla_DibujaImagen(fondoJ,0,0,WPANTALLA,HPANTALLA);

            //Personajes.
            GalaxiaDibuja(galaxia);
            PersonajeDibuja(p);
            FlotaDibuja(f1);
            RafagaDibuja(r);

            //HUD.
            //parte derecha
            Pantalla_ColorTrazo(255,0,0,255);
            Pantalla_DibujaTexto(puntuacion,WPANTALLA-145,5);
            Pantalla_DibujaTexto(textoRecord,WPANTALLA-110-ajusteTextoRecord,20);
            Pantalla_DibujaTexto(textoVidas,WPANTALLA-100,35);
            Pantalla_DibujaTexto(textoStage,WPANTALLA/2-5,5);
            for (int i=vidas-1; i>=0; i--)Pantalla_DibujaImagen(corazones[i],WPANTALLA-20-(VIDAS*WCORAZON)+i*WCORAZON,50,WCORAZON,HCORAZON);
            //parte izquierda
            Pantalla_DibujaTexto("Pulsa [ESC] para abrir el menu.", 5 , 5);
            Pantalla_DibujaTexto(textoEscudo,5,30);
            if (PersonajeGetProteccion(p)) Pantalla_DibujaRectangulo(5,45,PersonajeGetProteccion(p)/3,5);

            else
            {
                Pantalla_ColorRelleno(50,50,50,255);
                Pantalla_DibujaRectangulo(5,45,puntosExtraGoal*10,5);
                Pantalla_ColorRelleno(255,0,0,255);
                Pantalla_DibujaRectangulo(5,45,puntosExtra%puntosExtraGoal*10,5);
            };

            Pantalla_DibujaTexto(textoRayo,5,60);
            switch (arma)
            {
            case 0:
            {
                Pantalla_DibujaImagen(armero[0][0],5,100,WBALA*2,HBALA*2);
                Pantalla_DibujaImagen(armero[1][1],35,100,WBALA*2,HBALA*2);
                break;
            };
            case 1:
            {
                Pantalla_DibujaImagen(armero[0][1],5,100,WBALA*2,HBALA*2);
                Pantalla_DibujaImagen(armero[1][0],35,100,WBALA*2,HBALA*2);
                break;
            };
            };

            if (PersonajeGetProteccion(p)) Pantalla_DibujaImagen(armero[2][0],5,200,50,65);
            else Pantalla_DibujaImagen(armero[2][1],5,200,50,65);

            if (tRayo)
            {
                Pantalla_DibujaRectangulo(5,75,tRayo/1.5,5);
            }
            else
            {
                Pantalla_ColorRelleno(50,50,50,255);
                Pantalla_DibujaRectangulo(5,75,enemigosMatadosGoal*5,5);
                Pantalla_ColorRelleno(255,0,0,255);
                Pantalla_DibujaRectangulo(5,75,enemigosMatados%enemigosMatadosGoal*5,5);
                Pantalla_DibujaImagen(armero[1][2],35,100,WBALA*2,HBALA*2);
            }

//            //Debug.
//            Pantalla_DibujaTexto(textoDificultad,WPANTALLA/2,5);
//            Pantalla_DibujaTexto(selDificultad,WPANTALLA/2,20);



            Pantalla_Actualiza();
            Pantalla_Espera(15);

        };
    }


    //##################################################################################################################################################
    //##################################################################################################################################################
    //##################################################################################################################################################
    fin = 0;

    PersonajeLibera(p);
    RafagaLibera(r);
    GalaxiaLibera(galaxia);
    FlotaLibera(f1);

    Pantalla_ImagenLibera(navePersonaje);
    Pantalla_ImagenLibera(iEscudo);
    Pantalla_ImagenLibera(iEscudoBig);
    Pantalla_ImagenLibera(iEscudoMod);
    Pantalla_ImagenLibera(eImagen);
    Pantalla_ImagenLibera(eImagen2);
    Pantalla_ImagenLibera(eImagen3);
    Pantalla_ImagenLibera(bImagen);
    Pantalla_ImagenLibera(bImagenMod);
    Pantalla_ImagenLibera(explosion);
    Pantalla_ImagenLibera(corazon);
    Pantalla_ImagenLibera(iRayo);
    Pantalla_ImagenLibera(iRayoBig);
    Pantalla_ImagenLibera(iRayoMod);
    Pantalla_ImagenLibera(iRayoBan);


    //Solo se registra los puntos en el fichero si has hecho un record.
    if (puntos>puntuacionMax)
    {
        f = fopen("records.txt","a");
        fprintf(f,"%d\n",puntos);
        fclose(f);
    }


    //##################################################################################################################################################
    //##################################################################################################################################################
    //##################################################################################################################################################
    //#########################################          FASE DE DESPEDIDA        ######################################################################
    //##################################################################################################################################################
    //##################################################################################################################################################
    //##################################################################################################################################################

    while (((Pantalla_Activa()))&& (!(fin)))
    {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE)) fin = 1;


        //Fondo.
        Pantalla_DibujaImagen(fondoJ,0,0,WPANTALLA,HPANTALLA);
        Pantalla_DibujaImagen(chicoteB,WPANTALLA/2 + 150,HPANTALLA/2 - 100,300,300);

        //Cuadrado para el texto.
        Pantalla_ColorTrazo(255,0,0,255);
        Pantalla_ColorRelleno(50,50,50,255);
        Pantalla_DibujaRectangulo((WPANTALLA-270)/2 - 245,(HPANTALLA-150)/2 ,270,150);

        //Texto.
        Pantalla_ColorTrazo(rand()%255,rand()%255,rand()%255,255);
        Pantalla_DibujaTexto("Hasta pronto.", WPANTALLA/2 - 300   , HPANTALLA/2 - 30);
        Pantalla_DibujaTexto(puntuacion, WPANTALLA/2 - 300, HPANTALLA/2 - 10);
        Pantalla_DibujaTexto(textoRecord, WPANTALLA/2 - 300, HPANTALLA/2 + 10);
        Pantalla_DibujaTexto("Pulsa [ESC] para salir ", WPANTALLA/2 - 350 , HPANTALLA/2 + 50);

        Pantalla_Actualiza();
        Pantalla_Espera(40);

    };


    //##################################################################################################################################################
    //##################################################################################################################################################
    //##################################################################################################################################################


    Pantalla_ImagenLibera(chicoteB);
    Pantalla_ImagenLibera(fondoJ);
    Pantalla_Libera();


    return 0;

}
