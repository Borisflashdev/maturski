#include "datoteka.h"
#include <stdio.h>

void iznajmiVratiKnjigu() {
    int izbor, id_knjige;
    char linija[300];

    FILE *knjige = fopen("knjige.txt", "r+");
    FILE *temp = fopen("temp.txt", "w");
    if (knjige == NULL | temp == NULL) {
      printf("Greška prilikom otvaranja datoteke!\n");
      return;
    }

    printf("\n----- MENU -----\n1. Iznajmi Knjigu\n2. Vrati Knjigu\n----------------\n\n");
    scanf("%d", &izbor);

    if (izbor != 1 && izbor != 2) {
        printf("Neispravan izbor.\n");
        return;
    }

    printf("\n----------------\n\nUnesite ID knjige: ");
    scanf("%d", &id_knjige);

    int nadjena_knjiga = 0;
    while (fgets(linija, sizeof(linija), knjige)) {
        int id;
        sscanf(linija, "%d,", &id);
        if (id == id_knjige) {
            nadjena_knjiga = 1;
            char zadnji_char = linija[strlen(linija) - 2];
            if (izbor == 1 && zadnji_char == '0') {
                  zadnji_char = '1';
                printf("\nKnjiga iznajmljena!\n");
            } else if (izbor == 2 && zadnji_char == '1') {
                  zadnji_char = '0';
                printf("\nKnjiga vraćena!\n");
            }
          linija[strlen(linija) - 2] = zadnji_char;
        }
        fprintf(temp, "%s", linija);
    }

    fclose(knjige);
    fclose(temp);

    if (!nadjena_knjiga) {
        printf("Knjiga sa ID %d nije pronađena.\n", id_knjige);
        remove("temp.txt");
        return;
    }

    remove("knjige.txt");
    rename("temp.txt", "knjige.txt");
}