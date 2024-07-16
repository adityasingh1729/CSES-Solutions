#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n, W;
    cin >> n >> W;
    vector<int> weights(n);  // To store the weights of the people
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    vector<pair<int,int> > dp(1<<n, pair<int,int>(1e9, 1e9)); // We initialise the dp array of size 2^n and with all value set to (10^9, 10^9)
    dp[0] = pair<int,int>(1,0);  // This is the base case
    for (int mask = 1; mask < (1 << n); mask++) {   // We go through each subset
        for (int bit = 0; bit < n; bit++) {   // We go through each bit
            if ((1 << bit)&mask) {  // Checking if the bit is set
                int checkMask = (1 << bit)^mask;
                int spaceTaken = dp[checkMask].second;
                if (spaceTaken + weights[bit] <= W) {   /// VERY IMPORTANT: A bit represents a person, that's why we have n bits. When we unset a set bit, we are seeing what was the optimal solution without that person, and then we add that person back using + weights[bit]
                    dp[mask] = min(dp[mask], pair<int,int>(dp[checkMask].first, spaceTaken + weights[bit]));
                } else {
                    dp[mask] = min(dp[mask], pair<int,int>(dp[checkMask].first + 1, weights[bit]));
                }
            }
        }
    }
    cout << dp[(1 << n) - 1].first << endl;
    return 0;
}
