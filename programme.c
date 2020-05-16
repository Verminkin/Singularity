#include "interface.h"
#include "fonctions.h"
#include "constantes.h"
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <regex.h>

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
  char* filename;
  int err;
  int match;
  regex_t regex;
  const char* param;
  const char* str_regex;


  /*vérification des arguments*/
  if(argc!=2){
    fprintf(stderr, "Erreur: Nombre d'arguments incorrect\n");
    exit(EXIT_FAILURE);
  }
  param = argv[1];
  str_regex = "^[a-zA-Z]+$";
  err = regcomp(&regex, str_regex, REG_NOSUB | REG_EXTENDED);
  if(err==0){
    match = regexec(&regex, param, 0, NULL, 0);
    regfree(&regex);
    if(match==0){
      filename = argv[1];
    }
    else if(match == REG_NOMATCH){
      fprintf(stderr, "Erreur: Le nom de fichier spécifié n'est pas valide\n");
      exit(EXIT_FAILURE);
    }
  }
  else if(err!=0){
    fprintf(stderr, "Erreur: une erreur s'est produite lors de la compilation de l'expression régulière\n");
    exit(EXIT_FAILURE);
  }


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
            if(ySouris==1 && xSouris>=22 && xSouris<=40) clicNcurses(&isNcurses, isC);
            /*clic sur pthread*/
            if(ySouris==2 && xSouris>=22 && xSouris<=40) clicPthread(&isPthread, isC);
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
  printf("%s\n", filename);
  printf("\n");
  return EXIT_SUCCESS;
}
