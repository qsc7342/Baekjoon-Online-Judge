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
     
int N, M;
int dp[100001][11] = {};
int happy[100001][11] = {};
int main() {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   cin >> N >> M;

   for(int i = 1 ; i <= M ; i++) {
      for(int j = 1 ; j <= N ; j++) {
         cin >> happy[j][i];
         if(j == 1) {
            dp[1][i] = happy[1][i];
         }
      }
   }

   for(int i = 2 ; i <= N ; i++) {
      for(int j = 1 ; j <= M ; j++) {
         for(int k = 1 ; k <= M ; k++) {
            int cur = happy[i][k];
            if(j == k) {
               cur /= 2;
            }
            dp[i][k] = max(dp[i][k], dp[i - 1][j] + cur);
         }
      }
   }
   int ans = -1;
   for(int i = 1 ; i <= M ; i++) {
      ans = max(ans, dp[N][i]);
   }
   cout << ans << endl;
} 