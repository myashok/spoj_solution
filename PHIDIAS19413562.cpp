#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;cin >> t;
    while(t--) {
        int W, H;
        cin >> W >> H;
        int n; cin >> n;
        int w, h;
        vector<vector<int> >  dp(H+1, vector<int>(W+1, INT_MAX));
        for (int i = 0; i < n; ++i) {
            cin >> w >> h;
            dp[h][w] = 0;
        }
        for (int i = 0; i <= H; ++i) {
                for (int j = 0; j <= W; ++j) {
                    dp[i][j] = min(dp[i][j], i*j);
                    for (int k = 1; k < j; ++k) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k]);
                    for (int k = 1; k < i; ++k) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j]);
                }
        }
        cout << (dp[H][W]) << endl;
   }
}
