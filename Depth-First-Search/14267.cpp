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

int n, m;
bool visit[100001] = {};
int ans[100001] = {};
vector<vector<pii> > adj(100001);


void solve(int cur, int val) {
  ans[cur] += val;
  visit[cur] = true;
  for(int i = 0 ; i < adj[cur].size() ; i++) {
    int nxt = adj[cur][i].fst;
    if(!visit[nxt]) {
      visit[nxt] = true;
      solve(nxt, val + adj[nxt][0].snd);
    }
  }
}
signed main() {
   FASTIO();
   cin >> n >> m;

   for(int i = 1 ; i <= n ; i++) {
    sc(x);
    if(i == 1) continue;
    adj[i].pb(mp(x, 0));
    adj[x].pb(mp(i, 0));
   }

   while(m--) {
    int a, b;
    cin >> a >> b;
    adj[a][0].snd += b;
   }

  solve(1, 0);
  for(int i = 1 ; i <= n ; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}