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

void affiche_selection(fenetre_t *fenetre){
  wattron(fenetre->sf, COLOR_PAIR(DESELECT));
  wmove(fenetre->sf, 0,0);
  wprintw(fenetre->sf, "Assembleur-------");
  wmove(fenetre->sf, 1,0);
  wprintw(fenetre->sf, "C/C++------------");
  wmove(fenetre->sf, 2,0);
  wprintw(fenetre->sf, "Java-------------");
  wmove(fenetre->sf, 3,0);
  wprintw(fenetre->sf, "R----------------");
  wmove(fenetre->sf, 4,0);
  wprintw(fenetre->sf, "Réseau-----------");
  wmove(fenetre->sf, 5,0);
  wprintw(fenetre->sf, "Scilab-----------");
  wmove(fenetre->sf, 6,0);
  wprintw(fenetre->sf, "Web--------------");
  wmove(fenetre->sf, 7,0);
  wprintw(fenetre->sf, "Web + SQL--------");
  wattroff(fenetre->sf, COLOR_PAIR(DESELECT));
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
