#include "datoteka.h"
#include <stdio.h>

void izbrisiKnjigu() {
  int id_knjige;
  char linija[300];

  FILE *knjige = fopen("knjige.txt", "r");
  FILE *temp = fopen("temp.txt", "w");

  if (knjige == NULL | temp == NULL) {
    printf("Greška prilikom otvaranja datoteke!\n");
    return;
  }

  printf("\n----------------\n\nUnesite ID knjige koju želite da izbrišete: ");
  scanf("%d", &id_knjige);

  int nadjena_knjiga = 0;
  while (fgets(linija, sizeof(linija), knjige)) {
    int id;
    sscanf(linija, "%d,", &id);
    if (id != id_knjige) {
      fprintf(temp, "%s", linija);
    } else {
      nadjena_knjiga = 1;
    }
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
  printf("\nKnjiga sa ID %d uspešno izbrisana!\n", id_knjige);
}