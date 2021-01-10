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
const int INF = 987654321;

int N, M;
vector< vector<pair<int, int> > >adj(100001);

adj[0].pb 
adj[0][0]
adj[0].pb(mp(다음노드, 비용))
adj[0][1]
bool visit[100001];


bool bfs(int start, int dest, int mid) {
  queue<int>q;
  q.push(start);
  visit[start] = true;

  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    if(cur == dest) return true;
    for(int i = 0 ; i < adj[cur].size() ; i++) {
      int cost = adj[cur][i].second;
      int next = adj[cur][i].first;
      if(cost < mid) continue;

      else {
        if(!visit[next]) {
          visit[next] = true;
          q.push(next);
        }
      }
    }
  }
  return false;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;

    rep(i, M) {
      int a, b, cost;
      cin >> a >> b >> cost;
      adj[a].pb(mp(b,cost));
      adj[b].pb(mp(a,cost));
    }
    int st, de;
    cin >> st >> de;

    ll lo = 1;
    ll hi = 1000000001;

    while(lo + 1 < hi) {
      int mid = (lo + hi) / 2;
      memset(visit, false, sizeof(visit));

      if(bfs(st, de, mid) == true) {
        lo = mid;
      }
      else {
        hi = mid;
      }
    }
    cout << lo << endl;
}