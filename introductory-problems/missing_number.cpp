#include <iostream>

using namespace std;

int main()
{
  int64_t n; cin >> n;
  int64_t totalSum = (n)*(n + 1) >> 1;
  int64_t sum = 0;
  for (int i = 1; i < n; i++) {
    int num; cin >> num;
    sum += num;
  }
  cout << totalSum - sum << endl;
  return 0;
}
