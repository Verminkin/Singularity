#include "interface.h"
#include "fonctions.h"
#include "constantes.h"
#include <ncurses.h>
#include <stdlib.h>

interface_t interface;

int main(int argc, char** argv){
  int i;
  /*variables pour la souris*/
  int xSouris;
  int ySouris;
  int bouton;
  /*variables pour les boutons*/
  int isAssembleur;
  int isC;
  int isJava;
  int isR;
  int isReseau;
  int isScilab;
  int isWeb;
  int isWebsql;
  int isNcurses;
  int isPthread;
  int isBuild;

  /*initialisations*/
  isAssembleur = FAUX;
  isC = FAUX;
  isJava = FAUX;
  isR = FAUX;
  isReseau = FAUX;
  isScilab = FAUX;
  isWeb = FAUX;
  isWebsql = FAUX;
  isNcurses = FAUX;
  isPthread = FAUX;
  isBuild = FAUX;
  ncurses_initialiser();
  interface_initialiser(&interface);
  ncurses_couleurs();
  ncurses_souris();

  /*boucle principale*/
  timeout(10);
  while((i=getch())!=KEY_F(2) && isBuild==FAUX){
    /*gestion des clics*/
    switch(i){
      case KEY_MOUSE:
      if(souris_getpos(&xSouris, &ySouris, &bouton)==OK){
          if(bouton & BUTTON1_CLICKED){
            /*clic sur Assembleur*/
            if(ySouris==1 && xSouris>=1 && xSouris<=19) clicAssembleur(&isAssembleur);
            /*clic sur c/c++*/
            if(ySouris==2 && xSouris>=1 && xSouris<=19) clicC(&isC);
            /*clic sur java*/
            if(ySouris==3 && xSouris>=1 && xSouris<=19) clicJava(&isJava);
            /*clic sur R*/
            if(ySouris==4 && xSouris>=1 && xSouris<=19) clicR(&isR);
            /*clic sur réseau*/
            if(ySouris==5 && xSouris>=1 && xSouris<=19) clicReseau(&isReseau);
            /*clic sur scilab*/
            if(ySouris==6 && xSouris>=1 && xSouris<=19) clicScilab(&isScilab);
            /*clic sur Assembleur*/
            if(ySouris==7 && xSouris>=1 && xSouris<=19) clicWeb(&isWeb);
            /*clic sur Assembleur*/
            if(ySouris==8 && xSouris>=1 && xSouris<=19) clicWebsql(&isWebsql);
            /*clic sur ncurses*/
            if(ySouris==1 && xSouris>=22 && xSouris<=40) clicNcurses(&isNcurses);
            /*clic sur pthread*/
            if(ySouris==2 && xSouris>=22 && xSouris<=40) clicPthread(&isPthread);
            /*clic sur build*/
            if(ySouris==7 && xSouris>=22 && xSouris<=40) isBuild = VRAI;
          }
        }
        break;
    }
    affiche_selection(&interface.selection, isAssembleur, isC, isJava, isR, isReseau, isScilab, isWeb, isWebsql);
    affiche_options(&interface.options, isNcurses, isPthread);
    affiche_build(&interface.build);
  }
  ncurses_stopper();
  return EXIT_SUCCESS;
}
