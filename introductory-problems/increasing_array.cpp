#include <iostream>

using namespace std;

int main()
{
  long long int size = 0;
  long long int newNum = 0;
  long long int check = 0;
  long long int result = 0;
  cin >> size;  
  long long int arr[size];
  for (long long int i = 0; i < size; i++) {
    cin >> newNum;
    arr[i] = newNum;
  }
  for (long long int i = 0; i < size - 1; i++) {
    check = arr[i + 1] - arr[i];
    if (check < 0) {
      result -= check;
      arr[i + 1] = arr[i];
    }
  }
  cout << result << endl;
  return 0;
}
