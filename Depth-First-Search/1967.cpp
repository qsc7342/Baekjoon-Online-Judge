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
#define all(x) (x).begin(), (x).end()
#define PQ(T) priority_queue<T> // 맥스힙
#define GPQ(T) priority_queue<T,vector<T>,greater<T>> // 민힙
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e15;

int n;
vector<vector<pii> > adj(10001);
int ans = 0;
void solve(int cur) {
  queue<pair<pii, int> > q;

  q.push(mp(mp(cur, 0), -1));

  while(!q.empty()) {
    int cnode = q.front().fst.fst;
    int cdist = q.front().fst.snd;
    int prv = q.front().snd;
    q.pop();
    ans = max(ans, cdist);
    for(int i = 0 ; i < adj[cnode].size() ; i++) {
      int nxt = adj[cnode][i].fst;
      if(prv != nxt) {
        q.push(mp(mp(nxt, cdist + adj[cnode][i].snd), cnode));
      }
    }
  }
}
signed main() {
  FASTIO();
  cin >> n;
  int tmp = n - 1;
  while(tmp--) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].pb(mp(b, c));
    adj[b].pb(mp(a, c));
  }
  for(int i = 1 ; i <= n ; i++) {
    solve(i);
  }
  cout << ans << endl;
  return 0;
}