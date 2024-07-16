#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <cmath>
#include <chrono>
 
using namespace std;

template <typename T>
void printVector(vector<T> vec) {
  cout << "size = " << vec.size() << ": ";
  for (auto &elem: vec) {
    cout << elem << " ";
  }
  cout << endl;
}

void solve(string& s, string& p)
{
    int end = s.size() - p.size();
    int rsl = 0;
    for (int i = 0; i <= end; i++) {
        if (s[i] == p[0] && s.substr(i, p.size()) == p) {
            rsl++;
        }
    }
    cout << rsl << endl;
}

int main()
{
    string s; cin >> s;
    string p; cin >> p;
    solve(s,p);
    return 0;
}