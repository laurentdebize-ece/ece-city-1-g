//
// Created by lepou on 15/11/2022.
//

#include "JEU.h"

#include "menu.h"
#include "plateau.h"
#include "stdio.h"




void dessinerTout(bool * etatdebut,ALLEGRO_BITMAP * imagemenu, Fonts fonts,ALLEGRO_TIMER* timer2, bool* etatregle,Maire* maire, ALLEGRO_BITMAP* imagefond, ALLEGRO_BITMAP* imageville,ALLEGRO_BITMAP* imageeau,bool* etage0,bool* etage_1,bool* etage_2,int x1,int x2,int y1,int y2, ALLEGRO_BITMAP*imageRoutes40x40,ALLEGRO_EVENT event, ALLEGRO_BITMAP*imageRoutes,int etage, ALLEGRO_BITMAP* imageelec, ALLEGRO_BITMAP* imageMaison, ALLEGRO_BITMAP* imageCentrale,ALLEGRO_BITMAP* imageChateaudeau,ALLEGRO_BITMAP* imagecurseur ) {
    al_clear_to_color(al_map_rgb(0, 0, 0));

    if (*etatdebut) {
        dessinerMenu(imagemenu, fonts, timer2);
    } else if (*etatregle) {
        regles(fonts);
    } else {
        al_clear_to_color(al_map_rgb(150,255,0));
        if(*etage0){ // horizon etage niveau 0

            dessinerfond(imagefond);
        }
        else if(*etage_1){ // niveau -1
            al_draw_filled_rectangle(124,0,1024,700,al_map_rgb(0,0,0));
            dessinerplateau();
        }

        else { // niveau-2
            al_draw_filled_rectangle(124,0,1024,700,al_map_rgb(255,255,255));


        }

        affichageressources(maire,fonts);
        affichagetimer(fonts,timer2);

        dessinerLigne();
        dessinerBoutons(fonts,imageville,imageeau,imageRoutes40x40,imageelec,imageMaison,imageCentrale,imageChateaudeau,imagecurseur);
        choixBoutons(event,x1,x2,y1,y2,imageRoutes,etage0,etage_1,etage_2);





    }

    al_flip_display();
}
void initialisationresource(Maire* maire){
    maire->argent=500000;
    maire->capacites=0;
    maire->habitants=1;
}

void affichageressources(Maire* maire, Fonts fonts){
    al_draw_filled_rectangle(0,0,123,130, al_map_rgb(0,100,140));
    al_draw_textf(fonts.font4, al_map_rgb(255,0,0),0,30,0,"Argent :");
    al_draw_textf(fonts.font2, al_map_rgb(0,0,0),0,50,0,"%d",maire->argent);
    al_draw_textf(fonts.font4, al_map_rgb(255,0,0),0,60,0,"Habitants : ");
    al_draw_textf(fonts.font2, al_map_rgb(0,0,0),0,80,0,"%d",maire->habitants);
    al_draw_textf(fonts.font4, al_map_rgb(255,0,0),0,90,0,"Capacités :");
    al_draw_textf(fonts.font2, al_map_rgb(0,0,0),0,110,0,"%d",maire->capacites);

}




void choixBoutons(ALLEGRO_EVENT event,int x1,int x2,int y1,int y2,ALLEGRO_BITMAP* imageRoutes, bool* etage0,bool* etage_1,bool* etage_2) {
    //bouton route
    // il faut : un if pour savoir si il y a une maison ? si oui pas de routes
    if ((event.mouse.x > 10 && event.mouse.x < 50) && (event.mouse.y > 360 && event.mouse.y < 400)) {
        al_draw_bitmap(imageRoutes, x1, y1, 0);
    } else {
        if (*etage0) { al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(0, 0, 0)); }
        if (*etage_1) { al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(255, 255, 255)); }
        if (*etage_2) { al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(0, 0, 0)); }
    }


}

void dessinerBoutons(Fonts fonts,ALLEGRO_BITMAP* imageville,ALLEGRO_BITMAP* imageeau,ALLEGRO_BITMAP* imageRoutes40x40, ALLEGRO_BITMAP* imageelec,ALLEGRO_BITMAP* imageMaison,ALLEGRO_BITMAP* imageCentrale, ALLEGRO_BITMAP* imageChateaudeau, ALLEGRO_BITMAP* imagecurseur){
    al_draw_bitmap(imageville,10,210,0);
    al_draw_bitmap(imageeau,10,290,0);
    al_draw_bitmap(imageelec,10,330,0);

    al_draw_bitmap(imagecurseur,0,430,0) ;
    al_draw_textf(fonts.font2, al_map_rgb(0,0,0),55,450,0,"Curseur");
    al_draw_bitmap(imageRoutes40x40,5,470,0) ;
    al_draw_textf(fonts.font2, al_map_rgb(0,0,0),50,480,0,"Routes");
    al_draw_bitmap(imageMaison,0,520,0) ;
    al_draw_textf(fonts.font2, al_map_rgb(0,0,0),50,535,0,"Habitations ");

    al_draw_bitmap(imageCentrale,0,570,0) ;
    al_draw_textf(fonts.font2, al_map_rgb(0,0,0),55,590,0,"Centrale");
    al_draw_textf(fonts.font2, al_map_rgb(0,0,0),60,605,0,"Electrique");


    al_draw_bitmap(imageChateaudeau,0,620,0) ;
    al_draw_textf(fonts.font2, al_map_rgb(0,0,0),55,630,0,"Chateau");
    al_draw_textf(fonts.font2, al_map_rgb(0,0,0),60,645,0,"D'Eau");


}

void changementetage(ALLEGRO_EVENT event,bool* etage0,bool* etage_1,bool* etage_2,int etage){

    if(event.mouse.x>10 && event.mouse.x<70 && event.mouse.y>210&&event.mouse.y<280){
        etage=0;
    }
    if(event.mouse.x > 10 && event.mouse.x < 70 && event.mouse.y > 285 && event.mouse.y < 330){
        etage=-1;
    }
    if ((event.mouse.x > 10 && event.mouse.x < 70) && (event.mouse.y > 330 && event.mouse.y < 390)){
        etage=-2;
    }
    if(etage==0){*etage0=true;*etage_1=false;*etage_2=false;}
    if(etage==-1){*etage0=false;*etage_1=true;*etage_2=false;}
    if(etage==-2){*etage0=false;*etage_1=false;*etage_2=true;}

}
void detectionboutons(ALLEGRO_EVENT event,bool* curseur,bool* routes,bool* habitations,bool*centrales,bool*chateaudeau){

    if(event.mouse.x>0 && event.mouse.x<40 && event.mouse.y>430 &&event.mouse.y<470){//bouton curseur
        *curseur=true;
        *routes=false;
        *habitations=false;
        *centrales=false;
        *chateaudeau=false;
    }
    if(event.mouse.x>5 && event.mouse.x<45 && event.mouse.y>470 &&event.mouse.y<510){//bouton routes
        *routes=true;
        *curseur=false;
        *habitations=false;
        *centrales=false;
        *chateaudeau=false;

    }
    if(event.mouse.x>4 &&event.mouse.x<60 &&event.mouse.y>524 &&event.mouse.y<570){// bouton maison
        *habitations=true;
        *curseur=false;
        *routes=false;
        *centrales=false;
        *chateaudeau=false;

    }
    if(event.mouse.x>5 &&event.mouse.x< 45 &&event.mouse.y>570 &&event.mouse.y<615){//bouton centrale
        *centrales=true;
        *curseur=false;
        *routes=false;
        *habitations=false;
        *chateaudeau=false;

    }
    if(event.mouse.x>0 &&event.mouse.x< 40 &&event.mouse.y>620 &&event.mouse.y<670){//bouton Chateaudeau
        *chateaudeau=true;
        *curseur=false;
        *routes=false;
        *habitations=false;
        *centrales=false;
    }
}


void affichageroute(Cases cases[45][35],ALLEGRO_BITMAP* imagesroute){
    for (int i = 0; i < 45; i++) {
        for (int j = 0; j < 35; j++) {
            if(cases[i][j].routes==1){
                al_draw_bitmap(imagesroute,124+(j*20),(i*20),0);
            }

        }

    }
}