#include "fonctions.h"
#include "constantes.h"

void clicAssembleur(int* isAssembleur){
  if(*isAssembleur==VRAI){
    *isAssembleur = FAUX;
  }
  else{
    *isAssembleur = VRAI;
  }
}

void clicC(int* isC){
  if(*isC==VRAI){
    *isC = FAUX;
  }
  else{
    *isC = VRAI;
  }
}

void clicJava(int* isJava){
  if(*isJava==VRAI){
    *isJava = FAUX;
  }
  else{
    *isJava = VRAI;
  }
}

void clicR(int* isR){
  if(*isR==VRAI){
    *isR = FAUX;
  }
  else{
    *isR = VRAI;
  }
}

void clicReseau(int* isReseau){
  if(*isReseau==VRAI){
    *isReseau = FAUX;
  }
  else{
    *isReseau = VRAI;
  }
}

void clicScilab(int* isScilab){
  if(*isScilab==VRAI){
    *isScilab = FAUX;
  }
  else{
    *isScilab = VRAI;
  }
}

void clicWeb(int* isWeb){
  if(*isWeb==VRAI){
    *isWeb = FAUX;
  }
  else{
    *isWeb = VRAI;
  }
}

void clicWebsql(int* isWebsql){
  if(*isWebsql==VRAI){
    *isWebsql = FAUX;
  }
  else{
    *isWebsql = VRAI;
  }
}

void clicNcurses(int* isNcurses, int isC){
  if(isC){
    if(*isNcurses==VRAI){
      *isNcurses = FAUX;
    }
    else{
      *isNcurses = VRAI;
    }
  }
}

void clicPthread(int* isPthread, int isC){
  if(isC==VRAI){
    if(*isPthread==VRAI){
      *isPthread = FAUX;
    }
    else{
      *isPthread = VRAI;
    }
  }
}

void clicBuild(){
  /*code du build*/
}
