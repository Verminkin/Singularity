#include "interface.h"
#include "constantes.h"
#include <ncurses.h>
#include <stdlib.h>

void ncurses_initialiser(){
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  refresh();
  curs_set(FALSE);
}

void ncurses_stopper(){
  endwin();
}


void interface_initialiser(interface_t *interface){
  fenetre_initialiser(&interface->selection, 10, 20, 0, 0, "Sélection");
  fenetre_initialiser(&interface->options, 5, 20, 0, 21, "Options");
  fenetre_initialiser(&interface->build, 3, 20, 6, 21, "Build");
}

void fenetre_initialiser(fenetre_t *fenetre, int tailleY, int tailleX, int coordY, int coordX, char* nom){
  fenetre->win = newwin(tailleY, tailleX, coordY, coordX);
  box(fenetre->win, 0, 0);
  fenetre->sf = subwin(fenetre->win, tailleY-2, tailleX-2, coordY+1, coordX+1);
  wmove(fenetre->win, 0, 1);
  wprintw(fenetre->win, nom);
  wrefresh(fenetre->win);
}

void ncurses_couleurs(){
  if(has_colors() == FALSE) {
    ncurses_stopper();
    fprintf(stderr, "Le terminal ne supporte pas les couleurs.\n");
    exit(EXIT_FAILURE);
  }
  start_color();
  init_pair(DESELECT, COLOR_WHITE, COLOR_BLACK);
  init_pair(SELECT, COLOR_BLACK, COLOR_WHITE);
}

void ncurses_souris() {
  if(!mousemask(ALL_MOUSE_EVENTS, NULL)) {
    ncurses_stopper();
    fprintf(stderr, "Erreur lors de l'initialisation de la souris.\n");
    exit(EXIT_FAILURE);
  }

  if(has_mouse() != TRUE) {
    ncurses_stopper();
    fprintf(stderr, "Aucune souris n'est détectée.\n");
    exit(EXIT_FAILURE);
  }
}

int souris_getpos(int *x, int *y, int *bouton) {
  MEVENT event;
  int resultat;
  resultat = getmouse(&event);

  if(resultat == OK) {
    *x = event.x;
    *y = event.y;
    *bouton = event.bstate;
  }
  return resultat;
}

void affiche_selection(fenetre_t *fenetre, int isAssembleur, int isC, int isJava, int isR, int isReseau, int isScilab, int isWeb, int isWebsql){
  if(isAssembleur == FAUX) wattron(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isAssembleur == VRAI) wattron(fenetre->sf, COLOR_PAIR(SELECT));
    wmove(fenetre->sf, 0,0);
    wprintw(fenetre->sf, "Assembleur-------");
  if(isAssembleur == FAUX) wattroff(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isAssembleur == VRAI) wattroff(fenetre->sf, COLOR_PAIR(SELECT));

  if(isC == FAUX) wattron(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isC == VRAI) wattron(fenetre->sf, COLOR_PAIR(SELECT));
    wmove(fenetre->sf, 1,0);
    wprintw(fenetre->sf, "C/C++------------");
  if(isC == FAUX) wattroff(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isC == VRAI) wattroff(fenetre->sf, COLOR_PAIR(SELECT));

  if(isJava == FAUX) wattron(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isJava == VRAI) wattron(fenetre->sf, COLOR_PAIR(SELECT));
    wmove(fenetre->sf, 2,0);
    wprintw(fenetre->sf, "Java-------------");
  if(isJava == FAUX) wattroff(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isJava == VRAI) wattroff(fenetre->sf, COLOR_PAIR(SELECT));

  if(isR == FAUX) wattron(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isR == VRAI) wattron(fenetre->sf, COLOR_PAIR(SELECT));
    wmove(fenetre->sf, 3,0);
    wprintw(fenetre->sf, "R----------------");
  if(isR == FAUX) wattroff(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isR == VRAI) wattroff(fenetre->sf, COLOR_PAIR(SELECT));

  if(isReseau == FAUX) wattron(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isReseau == VRAI) wattron(fenetre->sf, COLOR_PAIR(SELECT));
    wmove(fenetre->sf, 4,0);
    wprintw(fenetre->sf, "Réseau-----------");
  if(isReseau == FAUX) wattroff(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isReseau == VRAI) wattroff(fenetre->sf, COLOR_PAIR(SELECT));

  if(isScilab == FAUX) wattron(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isScilab == VRAI) wattron(fenetre->sf, COLOR_PAIR(SELECT));
    wmove(fenetre->sf, 5,0);
    wprintw(fenetre->sf, "Scilab-----------");
  if(isScilab == FAUX) wattroff(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isScilab == VRAI) wattroff(fenetre->sf, COLOR_PAIR(SELECT));

  if(isWeb == FAUX) wattron(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isWeb == VRAI) wattron(fenetre->sf, COLOR_PAIR(SELECT));
    wmove(fenetre->sf, 6,0);
    wprintw(fenetre->sf, "Web--------------");
  if(isWeb == FAUX) wattroff(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isWeb == VRAI) wattroff(fenetre->sf, COLOR_PAIR(SELECT));

  if(isWebsql == FAUX) wattron(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isWebsql == VRAI) wattron(fenetre->sf, COLOR_PAIR(SELECT));
    wmove(fenetre->sf, 7,0);
    wprintw(fenetre->sf, "Web + SQL--------");
  if(isWebsql == FAUX) wattroff(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isWebsql == VRAI) wattroff(fenetre->sf, COLOR_PAIR(SELECT));

  wrefresh(fenetre->sf);
}

void affiche_options(fenetre_t *fenetre, int isNcurses, int isPthread){
  if(isNcurses == FAUX) wattron(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isNcurses == VRAI) wattron(fenetre->sf, COLOR_PAIR(SELECT));
    wmove(fenetre->sf, 0,0);
    wprintw(fenetre->sf, "Ncurses-----------");
  if(isNcurses == FAUX) wattroff(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isNcurses == VRAI) wattroff(fenetre->sf, COLOR_PAIR(SELECT));

  if(isPthread == FAUX) wattron(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isPthread == VRAI) wattron(fenetre->sf, COLOR_PAIR(SELECT));
    wmove(fenetre->sf, 1,0);
    wprintw(fenetre->sf, "Pthread-----------");
  if(isPthread == FAUX) wattroff(fenetre->sf, COLOR_PAIR(DESELECT));
  if(isPthread == VRAI) wattroff(fenetre->sf, COLOR_PAIR(SELECT));
  wrefresh(fenetre->sf);
}

void affiche_build(fenetre_t *fenetre){
  wmove(fenetre->sf, 0,0);
  wprintw(fenetre->sf, "Build-------------");
  wrefresh(fenetre->sf);
}
