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


int dp[100005]  = {};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int C, N;
  cin >> C >> N;

  fill(dp, dp + 100005, INF);

  vector<pii> ad;

  for(int i = 0 ; i < N ; i++) {
    int x, y;
    cin >> x >> y;
    ad.pb(mp(x, y));
  }
  dp[0] = 0;
  for(int i = 0 ; i < ad.size() ; i++) {
    int cost = ad[i].first;
    int plus = ad[i].second;
    for(int j = plus ; j <= 100004 ; j++) {
      dp[j] = min(dp[j - plus] + cost, dp[j]);
    }
  }
  ll ans = INF;
  for(int i = C ; i <= 100004 ; i++) {
    ans = min(ans, (ll)dp[i]);
  }
  cout << ans << endl;
} 
