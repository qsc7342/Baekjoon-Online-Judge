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
const int INF = 1000000001;

int dp[1001][1001] = {};
int arr[1001][1001] = {};
int N, M;
int ans = 0;
int main() {
    // cin.tie(NULL);
    // ios_base::sync_with_stdio(false);
    
    cin >> N >> M;

    for(int i = 1 ; i <= N ; i++) {
      for(int j = 1 ; j <= M ; j++) {
        scanf("%1d", &arr[i][j]);
      }
    }

    for(int i = 1 ; i <= N ; i++) {
      for(int j = 1 ; j <= M ; j++) {
        if(arr[i][j] == 1) {
//          if(arr[i - 1][j] == 1 && arr[i][j - 1] == 1 && arr[i - 1][j - 1] == 1) {
            int can = min(min(dp[i - 1][j], dp[i][j - 1]),dp[i -1][j - 1]);
            if(can == 0) {
              dp[i][j] = 1;
            }
            else {
              int num = sqrt(can) + 1;
              dp[i][j] = (int)pow(num, 2);
            }
//          }
        }
        if(dp[i][j] > ans) {
          ans = dp[i][j];
        }
      }
    }

    // for(int i = 1 ; i <= N ; i++) {
    //   for(int j = 1 ; j <= M ; j++) {
    //     cout << dp[i][j] << ' ';
    //   }
    //   cout << endl;
    // }
    cout << ans << endl;
}