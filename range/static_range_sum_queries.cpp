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

int64_t solve(int a, int b, vector<int64_t>& nums)
{
    if (a == 1) {
        return nums[b - 1];
    }
    return nums[b - 1] - nums[a - 2];
}

int main()
{
    int n, q; cin >> n >> q;
    vector<int64_t> x; x.reserve(n);
    int64_t cumSum = 0;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        cumSum += num;
        x.push_back(cumSum);
    }
    for (int i = 0; i < q; i++) {
        int a,b; cin >> a >> b;
        cout << solve(a,b,x) << endl;
    }
    return 0;
}