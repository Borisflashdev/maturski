#include "datoteka.h"
#include <stdio.h>

void prikaziKnjige() {
  int i = 0, je_isti = 1, izbor, izbor_input, id, broj_strana, iznajmljena,
      kategorija, kategorija_id, broj_kategorija = 0;
  char naslov[100], text_input[100], autor[100], kategorija_ime[100],
      lista_kategorija[100][100];

  FILE *knjige = fopen("knjige.txt", "r");
  FILE *kategorije = fopen("kategorije.txt", "r");

  if (knjige == NULL | kategorije == NULL) {
    printf("Greška prilikom otvaranja datoteke!\n");
    return;
  }

  while (fscanf(kategorije, "%d, %[^\n]\n", &kategorija_id,
                lista_kategorija[broj_kategorija]) != EOF) {
    broj_kategorija++;
  }

  printf("\n----- FILTERI -----\n1. Sve Knjige\n2. Knjige Po Imenu\n3. Knjige "
         "po Autoru\n4. Knjige po Kategoriji\n5. Iznajmljene Knjige\n6. "
         "Slobodne Knjige\n----------------\n\n");
  scanf("%d", &izbor);

  if (izbor == 2) {
    printf("\n----------------\n\nUnesite Ime Knjige:\n");
    scanf(" %[^\n]", text_input);
  } else if (izbor == 3) {
    printf("\n----------------\n\nUnesite Ime Autora:\n");
    scanf(" %[^\n]", text_input);
  } else if (izbor == 4) {
    printf("\n----- KATEGORIJE -----\n");
    for (int i = 0; i < broj_kategorija; i++) {
      printf("%d. %s\n", i + 1, lista_kategorija[i]);
    }
    printf("----------------\n\n");
    scanf("%d", &izbor_input);
  }

  printf(
      "\n----------------\n\n+----+--------------------------------+----------------------+-------"
      "----------+---------------+-------------+\n");
  printf("| ID |             Naslov             |         Autor        |   "
         "Kategorija    | Broj Stranica | Iznajmljena |\n");
  printf("+----+--------------------------------+----------------------+-------"
         "----------+---------------+-------------+\n");
  while (fscanf(knjige, "%d, %[^,], %[^,], %d, %d, %d\n", &id, naslov, autor,
                &kategorija, &broj_strana, &iznajmljena) != EOF) {

    je_isti = 1;
    i = 0;

    if (izbor == 1) {
      printf("| %-2d | %-30s | %-20s | %-15s | %-13d | %-11s |\n", id, naslov,
             autor, lista_kategorija[kategorija - 1], broj_strana,
             iznajmljena ? "DA" : "NE");
    } else if (izbor == 2) {
      while (naslov[i] != '\0' || text_input[i] != '\0') {
        if (naslov[i] != text_input[i] &&
            naslov[i] != text_input[i] - 'A' + 'a' &&
            naslov[i] != text_input[i] + 'A' - 'a') {
          je_isti = 0;
          break;
        }
        i++;
      }
      if (je_isti) {
        printf("| %-2d | %-30s | %-20s | %-15s | %-13d | %-11s |\n", id, naslov,
               autor, lista_kategorija[kategorija - 1], broj_strana,
               iznajmljena ? "DA" : "NE");
      }
    } else if (izbor == 3) {
      while (autor[i] != '\0' || text_input[i] != '\0') {
        if (autor[i] != text_input[i] &&
            autor[i] != text_input[i] - 'A' + 'a' &&
            autor[i] != text_input[i] + 'A' - 'a') {
          je_isti = 0;
          break;
        }
        i++;
      }
      if (je_isti) {
        printf("| %-2d | %-30s | %-20s | %-15s | %-13d | %-11s |\n", id, naslov,
               autor, lista_kategorija[kategorija - 1], broj_strana,
               iznajmljena ? "DA" : "NE");
      }
    } else if (izbor == 4) {
      if (kategorija == izbor_input) {
        printf("| %-2d | %-30s | %-20s | %-15s | %-13d | %-11s |\n", id, naslov,
               autor, lista_kategorija[kategorija - 1], broj_strana,
               iznajmljena ? "DA" : "NE");
      }
    } else if ((izbor == 5 && iznajmljena == 1) ||
               (izbor == 6 && iznajmljena == 0)) {
      printf("| %-2d | %-30s | %-20s | %-15s | %-13d | %-11s |\n", id, naslov,
             autor, lista_kategorija[kategorija - 1], broj_strana,
             iznajmljena ? "DA" : "NE");
    }
  }
  printf("+----+--------------------------------+----------------------+-------"
         "----------+---------------+-------------+\n");

  fclose(knjige);
  fclose(kategorije);
}