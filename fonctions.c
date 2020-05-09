#include "fonctions.h"
#include "constantes.h"

void clicAssembleur(int* isAssembleur){
  if(*isAssembleur==VRAI){
    *isAssembleur = FAUX;
    /*décommenter les lignes assembleur dans la recette*/
  }
  else{
    *isAssembleur = VRAI;
    /*commenter les lignes assembleur dans la recette*/
  }
}

void clicC(int* isC){
  if(*isC==VRAI){
    *isC = FAUX;
    /*décommenter les lignes c/c++ dans la recette*/
  }
  else{
    *isC = VRAI;
    /*commenter les lignes c/c++ dans la recette*/
  }
}

void clicJava(int* isJava){
  if(*isJava==VRAI){
    *isJava = FAUX;
    /*décommenter les lignes java dans la recette*/
  }
  else{
    *isJava = VRAI;
    /*commenter les lignes java dans la recette*/
  }
}

void clicR(int* isR){
  if(*isR==VRAI){
    *isR = FAUX;
    /*décommenter les lignes R dans la recette*/
  }
  else{
    *isR = VRAI;
    /*commenter les lignes R dans la recette*/
  }
}

void clicReseau(int* isReseau){
  if(*isReseau==VRAI){
    *isReseau = FAUX;
    /*décommenter les lignes réseau dans la recette*/
  }
  else{
    *isReseau = VRAI;
    /*commenter les lignes réseau dans la recette*/
  }
}

void clicScilab(int* isScilab){
  if(*isScilab==VRAI){
    *isScilab = FAUX;
    /*décommenter les lignes scilab dans la recette*/
  }
  else{
    *isScilab = VRAI;
    /*commenter les lignes scilab dans la recette*/
  }
}

void clicWeb(int* isWeb){
  if(*isWeb==VRAI){
    *isWeb = FAUX;
    /*décommenter les lignes web dans la recette*/
  }
  else{
    *isWeb = VRAI;
    /*commenter les lignes web dans la recette*/
  }
}

void clicWebsql(int* isWebsql){
  if(*isWebsql==VRAI){
    *isWebsql = FAUX;
    /*décommenter les lignes web+sql dans la recette*/
  }
  else{
    *isWebsql = VRAI;
    /*commenter les lignes web+sql dans la recette*/
  }
}

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

void clicBuild(){
  /*code du build*/
}
