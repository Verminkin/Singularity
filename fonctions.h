#ifndef __FONCTIONS__
#define __FONCTIONS__

void clicAssembleur(int* isAssembleur);
void clicC(int* isC);
void clicJava(int* isJava);
void clicR(int* isR);
void clicReseau(int* isReseau);
void clicScilab(int* isScilab);
void clicWeb(int* isWeb);
void clicWebsql(int* isWebsql);
void clicNcurses(int* isNcurses, int isC);
void clicPthread(int* isPthread, int isC);
void build_def(char* filename_def, int isAssembleur, int isC, int isNcurses, int isPthread, int isJava, int isR, int isReseau, int isScilab, int isWeb, int isWebsql);

#endif
