#include <stdio.h>


void entasser(int tab[], int n, int i) {
    int max = i;
    int gauche = 2 * i + 1;
    int droite = 2 * i + 2;


    if (gauche < n && tab[gauche] > tab[max])
        max = gauche;


    if (droite < n && tab[droite] > tab[max])
        max = droite;


    if (max != i) {
        int temp = tab[i];
        tab[i] = tab[max];
        tab[max] = temp;


        entasser(tab, n, max);
    }
}


void construireTas(int tab[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        entasser(tab, n, i);
}


void triParTas(int tab[], int n) {

    construireTas(tab, n);


    for (int i = n - 1; i > 0; i--) {

        int temp = tab[0];
        tab[0] = tab[i];
        tab[i] = temp;


        entasser(tab, i, 0);
    }
}


void afficherTab(int tab[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", tab[i]);
    printf("\n");
}


int main() {
    int tab[] = {10, 9, 8, 7, 3, 4, 1, 6};
    int n = sizeof(tab) / sizeof(tab[0]);

    printf("Tableau avant tri : \n");
    afficherTab(tab, n);

    triParTas(tab, n);

    printf("Tableau après tri : \n");
    afficherTab(tab, n);

    return 0;
}


