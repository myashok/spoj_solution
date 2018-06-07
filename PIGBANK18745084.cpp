#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se  second
using namespace std;
int main() {
    int t, n, E, F, cost;
    cin >> t;
    vector<pair<int, int> > wv(501);
    vector<int> dp(10001, INT_MAX);
    while(t--) {
        cin >> E >> F;
        cost = F - E;
       // cout << cost << endl;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> wv[i].se >> wv[i].fi;
      	sort(wv.begin(), wv.begin()+n);
        // for (int i = 0; i < n; ++i)
        //     cout << wv[i].fi << " " << wv[i].se <<endl;
        // cout << endl;
        dp[0] = 0;
       // cout << dp[cost] << endl;
        for (int i = 1; i <= cost; ++i) {
            for (int j = 0; j < n; ++j) {
                if (wv[j].fi > i) break;
                if(dp[i-wv[j].fi] != INT_MAX)
                	dp[i] = min(dp[i], dp[i - wv[j].fi]+wv[j].se);
            }
        }
        // for (int i = 0; i <= cost; ++i)
        // 	cout << dp[i] << " ";
        // cout << endl;
        if(dp[cost] == INT_MAX)
            cout << "This is impossible." << endl;
        else
            cout << "The minimum amount of money in the piggy-bank is " << dp[cost] << "." << endl;
        dp.assign(10001, INT_MAX);
    }

}
