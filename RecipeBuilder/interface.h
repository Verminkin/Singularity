#ifndef __INTERFACE__
#define __INTERFACE__

#include <ncurses.h>

typedef struct{
  WINDOW* sf;
  WINDOW* win;
}fenetre_t;

typedef struct{
  fenetre_t selection;
  fenetre_t options;
  fenetre_t build;
}interface_t;

void ncurses_initialiser();
void ncurses_stopper();
void interface_initialiser(interface_t *interface);
void fenetre_initialiser(fenetre_t *fenetre, int tailleX, int tailleY, int coordY, int coordX, char* nom);
void ncurses_couleurs();
void ncurses_souris();
int souris_getpos(int *x, int *y, int *bouton);
void affiche_selection(fenetre_t *fenetre, int isAssembleur, int isC, int isJava, int isR, int isReseau, int isScilab);
void affiche_options(fenetre_t *fenetre, int isNcurses, int isPthread, int isLexYacc);
void affiche_build(fenetre_t *fenetre);

#endif
