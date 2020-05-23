#include "interface.h"
#include "fonctions.h"
#include "constantes.h"
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <regex.h>
#include <string.h>

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
  int isNcurses;
  int isPthread;
  int isLexYacc;
  int isBuild;
  char* filename_def;
  char* filename_simg;
  int err;
  int match;
  regex_t regex;
  const char* param;
  const char* str_regex;


  /*vérification des arguments*/
  /*vérification du nombre d'arguments*/
  if(argc!=2){
    fprintf(stderr, "Erreur: Nombre d'arguments incorrect\n");
    exit(EXIT_FAILURE);
  }
  /*vérification de la validité du nom spécifié en arguments*/
  param = argv[1];
  str_regex = "^[a-zA-Z]+$";
  err = regcomp(&regex, str_regex, REG_NOSUB | REG_EXTENDED);
  if(err==0){
    match = regexec(&regex, param, 0, NULL, 0);
    regfree(&regex);
    if(match==0){
      filename_def = argv[1];
      filename_simg=(char*)malloc(strlen(argv[1])+7);
      strcpy(filename_simg, argv[1]);
      strcat(filename_def, ".def");
      strcat(filename_simg, ".simg");
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
  isNcurses = FAUX;
  isPthread = FAUX;
  isLexYacc = FAUX;
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
            /*clic sur ncurses*/
            if(ySouris==1 && xSouris>=22 && xSouris<=40) clicNcurses(&isNcurses, isC);
            /*clic sur pthread*/
            if(ySouris==2 && xSouris>=22 && xSouris<=40) clicPthread(&isPthread, isC);
            /*clic sur Lex&Yacc*/
            if(ySouris==3 && xSouris>=22 && xSouris<=40) clicLexYacc(&isLexYacc, isC);
            /*clic sur build*/
            if(ySouris==7 && xSouris>=22 && xSouris<=40) isBuild = VRAI;
          }
        }
        break;
    }
    affiche_selection(&interface.selection, isAssembleur, isC, isJava, isR, isReseau, isScilab);
    affiche_options(&interface.options, isNcurses, isPthread, isLexYacc);
    affiche_build(&interface.build);
  }
  ncurses_stopper();
  printf("%s\n", filename_def);
  printf("%s\n", filename_simg);
  if(isBuild == VRAI){
      build_def(filename_def, isAssembleur, isC, isNcurses, isPthread, isLexYacc, isJava, isR, isReseau, isScilab);
  }
  free(filename_simg);
  return EXIT_SUCCESS;
}
