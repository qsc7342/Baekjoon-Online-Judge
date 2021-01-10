#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue  
#define MOD 998244353
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll INF = 10000000000000001;
const double pi = 3.141592653589793;

vector<int> diff;
int dp[101][1001] = {};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int N, S, M;
  cin >> N >> S >> M; 
  // M : maximum volume
  // S : start volume
  diff.pb(987654321);
  for(int i = 0 ; i < N ; i++) {
    int x;
    cin >> x;
    diff.pb(x);
  }
  dp[0][S] = 1;

  for(int i = 1 ; i < diff.size() ; i++) {
    int cur = diff[i];

    for(int j = 0 ; j <= 1000 ; j++) {
      if(dp[i - 1][j] == 1) {
//        cout << " j : " << j << endl;
        if(j + cur <= M) {
          dp[i][j + cur] = 1;
 //         cout << "dp" << i << ' ' << j + cur << ' ' << endl;
        }
        if(j - cur >= 0) {
          dp[i][j - cur] = 1;
          // cout << "dp" << i << ' ' << j - cur << ' ' << endl;
        }
      }
    }
  }
  ll ans = -1;
  for(int i = 0 ; i <= 1000 ; i++) {
    if(dp[N][i] == 1) {
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}