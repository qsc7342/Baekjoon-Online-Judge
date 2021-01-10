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

int T;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false); 

  ll N;
  cin >> N;
  ll arr[N + 1] = {};
  ll good[N + 1] = {};
  ll degree[N + 1] = {};
  vector<vector<ll> > adj(N + 1);  
  for(int i = 0 ; i < N ; i++) {
    ll t;
    cin >> t;
    arr[i] = t;
    ll m;
    cin >> m;

    for(int j = 0 ; j < m ; j++) {
      int x;
      cin >> x;
      adj[x - 1].pb(i);
      degree[i]++;
    }
  }

  queue<pii> q;
  ll ans = 0;
  for(int i = 0 ; i < N ; i++) {
    if(degree[i] == 0) {
      q.push(mp(i, arr[i]));
      ans = max(ans, arr[i]);
      good[i] = arr[i];
    }
  } 

  while(!q.empty()) {
    int work = q.front().first;
    ll c = q.front().second;
    q.pop();
    ans = max(ans, good[work]);
    for(int i = 0 ; i < adj[work].size() ; i++) {
      int nxt = adj[work][i];
      degree[nxt]--;
      good[nxt] = max(good[nxt], good[work] + arr[nxt]);
      if(degree[nxt] == 0) {
        q.push(mp(nxt, good[nxt]));
      }
    }
  }
  cout << ans << endl;
} 