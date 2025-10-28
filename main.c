#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    char *artist;
    short int minutes;
    short int seconds;
} Canzone;
void aggiunta();
void stampa();

int dimensione = 0;

int main(void) {
    int s;
    Canzone *playlist = malloc(sizeof(Canzone) * dimensione);
    while (s!=3) {
        printf("Inserire il numero della scelta desiderata:\n");
        printf("1: Aggiungi una canzone\n");
        printf("2: Visualizza il contenuto:\n");
        printf("3: Esci\n");
        s = getchar();
        fflush(stdin);
        switch (s) {
            case '1':
                char *nome = (char*)malloc(sizeof(char)*100);
                printf("Inserire il nome della canzone:\n");
                fgets(nome, 100, stdin);

                char *artista = (char*)malloc(sizeof(char)*100);
                printf("Inserire il nome dell'artista:\n");
                fgets(artista, 100, stdin);

                printf("Inserire la durata della canzone (prima minuti poi secondi):\n");

                int minuti = 0;
                printf("Minuti:\n");
                while (1) {
                    while (!scanf("%d", &minuti)) {
                        printf("Valore non valido, riprovare:\n");
                        fflush(stdin);
                    }
                    break;
                }

                int secondi = 0;
                printf("Secondi:\n");
                while (1) {
                    while (!scanf("%d", &secondi)) {
                        printf("Valore non valido, riprovare:\n");
                        fflush(stdin);
                    }
                    break;
                }
                fflush(stdin);

                dimensione++;
                Canzone *nuovo = realloc(playlist, dimensione * sizeof(Canzone));
                playlist = nuovo;
                playlist[dimensione-1] = (Canzone){nome, artista, minuti, secondi};
                break;
            case '2':
                stampa(playlist);
                break;
            case '3':
                return 0;
            default:
                printf("Inserire una scelta valida!\n");
                break;
        }
    }
    return 0;
}
void stampa(Canzone *playlist) {
    fflush(stdin);
    for (int i=0; i<dimensione; i++) {
        printf("Canzone %d:\n",i+1);
        printf("Nome: %s", playlist[i].name);
        printf("Artista: %s", playlist[i].artist);
        if (playlist[i].seconds<10) printf("Durata: %d:0%d\n\n", playlist[i].minutes, playlist[i].seconds);
        else printf("Durata: %d:%d\n\n", playlist[i].minutes, playlist[i].seconds);
    }
}
