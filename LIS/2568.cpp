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


int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false); 
  ll N;
  cin >> N;
  vector<pii> adj;

  for(int i = 0 ; i < N ; i++) {
    int x, y;
    cin >> x >> y;
    adj.pb(mp(x, y));
  }
  sort(all(adj));
  vector<int> lis;
  stack<pii> s;

  for(int i = 0 ; i < adj.size() ; i++) {
    if(lis.size() == 0 || lis.back() < adj[i].second) {
      lis.pb(adj[i].second);
      s.push(mp(lis.size() - 1, adj[i].second));
    }
    else {
      int it = lower_bound(lis.begin(), lis.end(), adj[i].second) - lis.begin();
      lis[it] = adj[i].second;
      s.push(mp(it, adj[i].second));
    }
  }

  int st = lis.size() - 1;
  vector<int> res;
  set<int> inlis;

  while(!s.empty()) {
    if(s.top().first == st) {
      res.pb(s.top().second);
      inlis.insert(s.top().second);
      st--;
      s.pop();
    }
    else {
      s.pop();
    }
  }
  reverse(all(res));

  cout << N - res.size() << endl;
  for(int i = 0 ; i < adj.size() ; i++) {
    if(inlis.find(adj[i].second) == inlis.end()) {
      cout << adj[i].first << endl;
    }
  }
} 