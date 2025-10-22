#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    char *artist;
    short minutes;
    short seconds;
} Canzone;
void aggiunta();
void stampa();

Canzone *playlist;
int dimensione = 1;

int main(void) {
    int scelta = 0;
    while (scelta!=3) {
        printf("Inserire il numero della scelta:\n");
        printf("1: Aggiungere una canzone\n");
        printf("2: Mostrare la playlist\n");
        printf("3: Esci\n");
        scelta = getchar();
        switch (scelta) {
            case 1:
                aggiunta();
                break;
            case 2:
                stampa();
                break;
            default:
                printf("Numero della scelta non valida\n");
                break;
        }
    }
    return 0;
}
void aggiunta() {

}
void stampa() {

}
