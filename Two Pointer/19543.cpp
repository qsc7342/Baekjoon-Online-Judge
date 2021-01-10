#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll INF = 987654321;

ll dp[35555][3] = {};

int main() {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   dp[1][0] = 0;
   dp[1][1] = 1;
   dp[1][2] = 1;
   ll mod = 1e9 + 9;

   int N;
   cin >> N;

   for(int i = 2 ; i <= 33333 ; i++) {
    dp[i][0] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][0];
    dp[i][1] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][0];
    dp[i][2] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][0];
    dp[i][0] %= mod;
    dp[i][1] %= mod;
    dp[i][2] %= mod; 
   }

   cout << dp[N][0] << endl;
   return 0;
}