#include <bits/stdc++.h>
using namespace std;

#define v vector
#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define all(v) v.begin(), v.end()

// Function to calculate the minimum cost of cutting a stick
long long mincostcuts(v<ll>& cuts, ll i, ll j, vector<vector<ll>>& dp) {
    if (i + 1 >= j) return 0; // Base case: No cuts possible in this range
    if (dp[i][j] != -1) return dp[i][j]; // Return if already computed

    ll mincost = LLONG_MAX;
    // Loop through all positions for possible cuts
    for (ll k = i + 1; k < j; k++) {
        // Calculate the cost of cutting at position k
        ll cost = cuts[j] - cuts[i];
        cost += mincostcuts(cuts, i, k, dp); // Left part
        cost += mincostcuts(cuts, k, j, dp); // Right part

        mincost = min(mincost, cost); // Find the minimum cost
    }
    
    return dp[i][j] = mincost; // Save the result in dp
}

int main() {
    fast_io;
    ll n, m;
    cin >> n >> m; // Input: length of the stick and number of cuts
    v<ll> cuts(m);

    // Input cuts and add 0 and n to the cuts vector
    for (ll i = 0; i < m; i++) {
        cin >> cuts[i];
    }
    cuts.pb(0); // Add the starting point (0)
    cuts.pb(n); // Add the ending point (n)

    sort(all(cuts)); // Sort the cuts to facilitate dynamic programming

    // DP table initialization
    vector<vector<ll>> dp(m + 2, vector<ll>(m + 2, -1));

    // Call the function and output the result
    cout << mincostcuts(cuts, 0, m + 1, dp) << endl;

    return 0;
}
