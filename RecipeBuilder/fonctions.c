#include "fonctions.h"
#include "constantes.h"
#include <stdlib.h>
#include <stdio.h>

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
  if(isC == VRAI){
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

void clicLexYacc(int* isLexYacc, int isC){
  if(isC==VRAI){
    if(*isLexYacc==VRAI){
      *isLexYacc = FAUX;
    }
    else{
      *isLexYacc = VRAI;
    }
  }
}

void build_def(char* filename_def, int isAssembleur, int isC, int isNcurses, int isPthread, int isLexYacc, int isJava,
  int isR, int isReseau, int isScilab){
  FILE* def;
  FILE* assembleur;
  FILE* base;
  FILE* c;
  FILE* clean;
  FILE* java;
  FILE* lexyacc;
  FILE* ncurses;
  FILE* pthread;
  FILE* r;
  FILE* reseau;
  FILE* scilab;
  char ch;

  def = fopen(filename_def, "a");

  if(def==NULL){
    fprintf(stderr, "Erreur: ouverture des fichiers impossible\n");
    exit(EXIT_FAILURE);
  }

  base = fopen("./lib/base.txt", "r");
  if(base==NULL){
    fprintf(stderr, "Erreur: ouverture des fichiers impossible\n");
    exit(EXIT_FAILURE);
  }
  while((ch=fgetc(base))!=EOF) fputc(ch, def);
  fclose(base);

  if(isAssembleur == VRAI){
    assembleur = fopen("./lib/assembleur.txt", "r");
    if(assembleur==NULL){
      fprintf(stderr, "Erreur: ouverture des fichiers impossible\n");
      exit(EXIT_FAILURE);
    }
    while((ch=fgetc(assembleur))!=EOF)fputc(ch, def);
    fclose(assembleur);
  }

  if(isC == VRAI){
    c = fopen("./lib/c.txt", "r");
    if(c==NULL){
      fprintf(stderr, "Erreur: ouverture des fichiers impossible\n");
      exit(EXIT_FAILURE);
    }
    while((ch=fgetc(c))!=EOF)fputc(ch, def);
    fclose(c);
    if(isNcurses == VRAI){
      ncurses = fopen("./lib/ncurses.txt", "r");
      if(ncurses==NULL){
        fprintf(stderr, "Erreur: ouverture des fichiers impossible\n");
        exit(EXIT_FAILURE);
      }
      while((ch=fgetc(ncurses))!=EOF)fputc(ch, def);
      fclose(ncurses);
    }
    if(isPthread == VRAI){
      pthread = fopen("./lib/pthread.txt", "r");
      if(pthread==NULL){
        fprintf(stderr, "Erreur: ouverture des fichiers impossible\n");
        exit(EXIT_FAILURE);
      }
      while((ch=fgetc(pthread))!=EOF)fputc(ch, def);
      fclose(pthread);
    }
    if(isLexYacc == VRAI){
      lexyacc = fopen("./lib/lexyacc.txt", "r");
      if(lexyacc==NULL){
        fprintf(stderr, "Erreur: ouverture des fichiers impossible\n");
        exit(EXIT_FAILURE);
      }
      while((ch=fgetc(lexyacc))!=EOF)fputc(ch, def);
      fclose(lexyacc);
    }
  }

  if(isJava == VRAI){
    java = fopen("./lib/java.txt", "r");
    if(java==NULL){
      fprintf(stderr, "Erreur: ouverture des fichiers impossible\n");
      exit(EXIT_FAILURE);
    }
    while((ch=fgetc(java))!=EOF)fputc(ch, def);
    fclose(java);
  }

  if(isR == VRAI){
    r = fopen("./lib/r.txt", "r");
    if(r==NULL){
      fprintf(stderr, "Erreur: ouverture des fichiers impossible\n");
      exit(EXIT_FAILURE);
    }
    while((ch=fgetc(r))!=EOF)fputc(ch, def);
    fclose(r);
  }

  if(isReseau == VRAI){
    reseau = fopen("./lib/reseau.txt", "r");
    if(reseau==NULL){
      fprintf(stderr, "Erreur: ouverture des fichiers impossible\n");
      exit(EXIT_FAILURE);
    }
    while((ch=fgetc(reseau))!=EOF)fputc(ch, def);
    fclose(reseau);
  }

  if(isScilab == VRAI){
    scilab = fopen("./lib/scilab.txt", "r");
    if(scilab==NULL){
      fprintf(stderr, "Erreur: ouverture des fichiers impossible\n");
      exit(EXIT_FAILURE);
    }
    while((ch=fgetc(scilab))!=EOF)fputc(ch, def);
    fclose(scilab);
  }

  clean = fopen("./lib/clean.txt", "r");
  if(clean==NULL){
    fprintf(stderr, "Erreur: ouverture des fichiers impossible\n");
    exit(EXIT_FAILURE);
  }
  while((ch=fgetc(clean))!=EOF) fputc(ch, def);
  fclose(clean);

  fclose(def);

}
