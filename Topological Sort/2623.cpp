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
int tim[1001] = {};
int buildtime[1001] = {}; 
int degree[1001] = {};
vector<vector<int> > adj(1001);

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> T;

  while(T--) {
    int N, K, want;
    cin >> N >> K;
    memset(tim, 0, sizeof(tim));
    memset(buildtime, 0, sizeof(buildtime));
    memset(degree, 0, sizeof(degree));
    adj = vector<vector<int> >(1001);
    queue<int> q;

    for(int i = 1 ; i <= N ; i++) {
      cin >> buildtime[i];
    }
    for(int i = 0 ; i < K ; i++) {
      int a, b;
      cin >> a >> b;
      adj[a].pb(b);
      degree[b]++;
    }

    for(int i = 1 ; i<= N ; i++) {
      if(degree[i] == 0) q.push(i);
    }
    cin >> want;
    vector<vector<int> > tmp(1001);

    for(int i = 1 ; i <= N ; i++) {
      int cur = q.front();
      q.pop();
      tim[cur] = buildtime[cur];
      for(int j = 0 ; j < tmp[cur].size() ; j++) {
        tim[cur] = max(tim[cur], tim[tmp[cur][j]] + buildtime[cur]);
      }
      for(int j = 0 ; j < adj[cur].size() ; j++) {
        int nxt = adj[cur][j];
        tmp[nxt].pb(cur);
        degree[nxt]--;
        if(degree[nxt] == 0) {
          q.push(nxt);
        }
      }
    }

    cout << tim[want] << endl;
  }
}