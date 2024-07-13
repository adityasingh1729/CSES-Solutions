#include <stdio.h>

int main()
{
  unsigned long int num;
  scanf("%ld", &num);
  printf("%lu ", num);
    
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = num * 3 + 1;
    }
    printf("%lu ", num);
  }
  puts("");
  return 0;
}
