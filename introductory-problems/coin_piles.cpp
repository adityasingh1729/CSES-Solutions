#include <stdio.h>

int check(int a, int b);

int main()
{
  unsigned long long int tries;
  unsigned long long int a, b;
  
  scanf("%lld", &tries);
  for (int i = 0; i < tries; i++) {
    scanf("%lld %lld", &a, &b);
    if (check(a, b) == 1) {
      printf("YES\n");
    } else if (check(a, b) == 0) {
      printf("NO\n");
    }
  }
  
  return 0;
}

int check(int a, int b)
{
  if ((a + b) % 3 != 0) {
    return 0;
  }
  
  int greater, lesser;
  if (a >= b) {
    greater = a;
    lesser = b;
  } else {
    greater = b;
    lesser = a;
  }
  
  int sumxy = (greater + lesser)/3; // this is the sum of x and y - which are the number of times we perform each of the operations
  int diffxy = greater - lesser;
  if ((sumxy + diffxy) % 2 == 0 && (sumxy - diffxy) % 2 == 0 && sumxy >= diffxy) {
    return 1;
  } else {
    return 0;
  }
}
