#include "datoteka.h"
#include <stdio.h>

int main(void) {
  int izbor;

  printf("  ____    _   _       _   _           _            _             \n");
  printf(
      " |  _ \\  (_) | |     | | (_)         | |          | |            \n");
  printf(" | |_) |  _  | |__   | |  _    ___   | |_    ___  | | __   __ _  \n");
  printf(
      " |  _ <  | | | '_ \\  | | | |  / _ \\  | __|  / _ \\ | |/ /  / _` | \n");
  printf(" | |_) | | | | |_) | | | | | | (_) | | |_  |  __/ |   <  | (_| | \n");
  printf(" |____/  |_| |_.__/  |_| |_|  \\___/   \\__|  \\___| |_|\\_\\  "
         "\\__,_| \n");

  do {
    printf("\n----- MENU -----\n1. Lista Knjiga\n2. Dodaj Knjigu\n3. "
           "Izbrisi Knjigu\n4. Iznajmi/Vrati Knjigu\n5. Izadji Iz "
           "Programa\n----------------\n\n");

    scanf("%d", &izbor);

    switch (izbor) {
    case 1:
      prikaziKnjige();
      break;
    case 2:
      dodajKnjigu();
      break;
    case 3:
      izbrisiKnjigu();
      break;
    case 4:
      iznajmiVratiKnjigu();
      break;
    case 5:
      printf("\n----------------\nHvala na koriscenju!\n----------------\n");
      break;
    default:
      printf("Neispravan izbor! Molimo unesite broj između 1 i 5.\n");
    }
  } while (izbor != 5);

  return 0;
}