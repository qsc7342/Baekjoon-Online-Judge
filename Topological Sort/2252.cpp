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
const int INF = 987654321;

int N, M, T;
int degree[32001] = {};
vector<vector<int> > adj(32001);

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> N >> M;

  for(int i = 0 ; i < M ; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    degree[b]++;
  }
  queue<int> q;
  vector<int> ans;

  for(int i = 1 ; i <= N ; i++) {
    if(degree[i] == 0) q.push(i);
  }

  for(int i = 0 ; i < N ; i++) {
    int cur = q.front();
    ans.pb(cur);
    q.pop();
    for(int j = 0 ; j < adj[cur].size() ; j++) {
      int nxt = adj[cur][j];
      degree[nxt]--;
      if(degree[nxt] == 0) q.push(nxt);
    }
  }

  for(auto x : ans) {
    cout << x << ' ';
  }
  cout << endl;
}