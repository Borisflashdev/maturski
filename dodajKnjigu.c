#include "datoteka.h"
#include <stdio.h>

void dodajKnjigu() {
  int id, kategorija, broj_strana, iznajmljena, zadnji_id = -1, kategorija_id,
                                                broj_kategorija = 0, izbor;
  char naslov[100], autor[100], lista_kategorija[100][100];

  FILE *knjige = fopen("knjige.txt", "a");
  FILE *broj_knjiga = fopen("knjige.txt", "r");
  FILE *kategorije = fopen("kategorije.txt", "r");

  if (knjige == NULL | broj_knjiga == NULL | kategorije == NULL) {
    printf("Greška prilikom otvaranja datoteke!\n");
    return;
  }

  while (fscanf(broj_knjiga, "%d,", &id) == 1) {
    zadnji_id = id;
    fscanf(broj_knjiga, "%*[^\n]");
  }
  id++;

  while (fscanf(kategorije, "%d, %[^\n]\n", &kategorija_id,
                lista_kategorija[broj_kategorija]) != EOF) {
    broj_kategorija++;
  }

  printf("\n----------------\n\nUnesite naslov knjige: ");
  scanf(" %[^\n]", naslov);
  printf("Unesite ime autora: ");
  scanf(" %[^\n]", autor);

  printf("Unesite kategoriju knjige:\n");
  for (int i = 0; i < broj_kategorija; i++) {
    printf("%d. %s\n", i + 1, lista_kategorija[i]);
  }
  scanf("%d", &kategorija);

  printf("Unesite broj stranica: ");
  scanf("%d", &broj_strana);

  printf("Da li je knjiga iznajmljena?:\n1. Da\n2. Ne\n");
  scanf("%d", &iznajmljena);

  fprintf(knjige, "%d, %s, %s, %d, %d, %d\n", id, naslov, autor, kategorija,
          broj_strana, iznajmljena);

  printf("\nKnjiga uspešno dodata!\n");

  fclose(knjige);
  fclose(broj_knjiga);
  fclose(kategorije);
}