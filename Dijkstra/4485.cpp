#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue  
#define MOD 1000000007
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
const int INF = 2147483646;
const double pi = 3.141592653589793;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  ll asc[1001][1000];
  ll dsc[1001][1000];


  for(int i = 1 ; i <= 1000 ; i++) {
    asc[i][1] = 1;
    dsc[i][1] = 1;
  }


  ll n, m;
  cin >> n >> m;

  for(int i = 2 ; i <= m ; i++) {
    for(int j = 1 ; j <= n ; j++) {
      for(int k = 1 ; k <= j ; k++) {
        asc[j][i] += asc[k][i - 1] % MOD;
        asc[j][i] %= MOD;
      }
    }
  }
  for(int i = 2 ; i <= m ; i++) {
    for(int j = 1 ; j <= n ; j++) {
      for(int k = n ; k >= j ; k--) {
        dsc[j][i] += dsc[k][i - 1] % MOD;
        dsc[j][i] %= MOD;
      }
    }
  }

  ll ans = 0;

  for(int i = 1 ; i <= n ; i++) {
    ans += asc[i][m];
    ans %= MOD;
    ans += dsc[i][m];
    ans %= MOD;
  }
  cout << ans % MOD << endl;
  return 0;
}