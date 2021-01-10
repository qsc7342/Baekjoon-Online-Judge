#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 987654321;

int N;
ll MOD = 1e9;
ll ans = 0;
ll dp[101][10][2049] = {};
int main() {
 //  cin.tie(NULL);
//   ios_base::sync_with_stdio(false);
   cin >> N;
   for(int i = 1 ; i <= 9 ; i++) {
      dp[1][i][(1 << i)] = 1;
   }
   for(int i = 2 ; i <= N ; i++) {
      for(int j = 0 ; j <= 9 ; j++) {
         for(int k = 0 ; k <= 2047 ; k++) {
            if(j == 0) {
               dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k] % MOD;
            }
            else if(j == 9) {
               dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k] % MOD;
            } 
            else dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k] % MOD + dp[i - 1][j - 1][k] % MOD;
            dp[i][j][k|(1 << j)] %= MOD;
         }
      }
   }
   ll ans = 0;
   for(int i = 0 ; i <= 9 ; i++) {
      ans += dp[N][i][1023] % MOD;
      ans %= MOD;
   }
   cout << ans << endl;
}  