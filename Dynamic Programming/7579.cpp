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

int N, M;
vector<ll>memory;
vector<ll>cost;

ll dp[101][10001] = {};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;

  for(int i = 0 ; i < N ; i++) {
    ll num;
    cin >> num;
    memory.pb(num);
  }

  for(int i = 0 ; i < N ; i++) {
    ll num;
    cin >> num;
    cost.pb(num);
  }

  for(int i = 0 ; i < N ; i++) {
    if(i == 0) dp[i][cost[i]] = memory[i];
    else dp[i][cost[i]] = max(dp[i - 1][cost[i]], memory[i]);
    for(int j = 0 ; j <= 10000 ; j++) {
      if(j >= cost[i] && i >= 1)
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);
      else if(i >= 1) {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  for(int i = 0 ; i <= 10000 ; i++) {
    if(dp[N - 1][i] >= M) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}