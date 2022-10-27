#include <stdio.h>

#define MAX 10
typedef struct {
  int age;
} Personne;

int main(void) {

    Personne a[MAX], b[MAX];

    for(int i = 0; i < MAX; i++) {
    printf("Saisis un age\n");
    scanf("%d", &a[i].age);
    }

    for(int i = 0; i < MAX; i++) {
      if(a[i].age >= 20 ) {
        b[i].age = a[i].age;
      } else {
        b[i].age = 0;
      }
    }

    for(int i = 0; i < MAX; i++) {
      printf("Age : %d\n", b[i].age);
    }

  return 0;
}