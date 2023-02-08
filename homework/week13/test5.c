#include<stdio.h>
#include<string.h>
#define N 50

int main() {
  char s[N];
  printf("Enter the text: ");
  fgets(s, sizeof(s), stdin);

  printf("%s\n", s);
  int count = 0;
  for (int i = 0; i < strlen(s); i++) {
	if (s[i] == ' ') count++;
  }
  printf("The number of blanks: %d\n", count);

  return 0;
}