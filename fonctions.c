#include "fonctions.h"
#include "constantes.h"

void clicNcurses(int* isNcurses){
  if(*isNcurses==VRAI){
    *isNcurses = FAUX;
    /*décommenter les lignes ncurses dans la recette*/
  }
  else{
    *isNcurses = VRAI;
    /*commenter les lignes ncurses dans la recette*/
  }
}

void clicPthread(int* isPthread){
  if(*isPthread==VRAI){
    *isPthread = FAUX;
    /*décommenter les lignes pthread dans la recette*/
  }
  else{
    *isPthread = VRAI;
    /*commenter les lignes pthread dans la recette*/
  }
}
