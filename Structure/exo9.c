#include <stdio.h>

#define MAX 5

typedef struct {
  int ageH;
  int ageF;
} Couple;

int main() {
    Couple p1[MAX];
    int compteur = 0;

    for(int i = 0; i < MAX; i++) {
      printf("Saisis un age\n");
        scanf("%d %d", &p1[i].ageF, &p1[i].ageH);
    }

for(int i = 0; i < MAX; i++) {
    if(p1[i].ageF > p1[i].ageH)
        compteur+= 1;
    }

printf("%d%", (compteur/MAX) *100);
  return 0;
}