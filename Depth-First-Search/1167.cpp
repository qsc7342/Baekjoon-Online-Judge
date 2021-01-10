#include <bits/stdc++.h>
#define FASTIO() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define fst first
#define snd second
#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define sc(x) int x; cin >> x;
#define s(x) cin >> x;
#define all(x) (x).begin(), (x).end()
#define V(T) vector<T>
#define PQ(T) priority_queue<T>
#define GPQ(T) priority_queue<T,vector<T>,greater<T>>
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e15;

vector<vector<pii> > adj(100001);
int V;
bool visit[100001] = {};
int start = 0;
int dist = 0;

void dfs(int cur, int d) {
  if(dist < d) {
    start = cur;
    dist = d;
  }

  visit[cur] = true;

  for(int i = 0 ; i < adj[cur].size() ; i++) {
    int nxt = adj[cur][i].fst;
    if(!visit[nxt]) {
      dfs(nxt, d + adj[cur][i].snd);
    }
  }
  return;
}

signed main() {
  FASTIO();
  s(V);
  rep(i, V) {
    sc(x);
    int a = 0;
    while(1) {
    s(a);
    if(a == -1) break;
    sc(b);
    adj[x].pb(mp(a, b));
    }
  }
  dfs(1, 0);
  memset(visit, false, sizeof(visit));
  dist = 0;
  dfs(start, 0);
  cout << dist << endl;
  return 0;
}