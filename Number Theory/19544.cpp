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

int N, S, D;
vector<vector<int> > adj(100001);
bool visit[100001] = {};
int ans = 0;

int solve(int cur, int depth) {
  int mxdist = 0;
  bool flag = false;
  visit[cur] = true;
  for(int i = 0 ; i < adj[cur].size() ; i++) {
    int nxt = adj[cur][i];
    if(!visit[nxt]) {
      visit[nxt] = true;
      mxdist = max(mxdist, solve(nxt, depth + 1));
    }
  }
  if(max(0, mxdist - depth) >= D) {
    ans++;
  }
  return max(mxdist, depth);
}

int main() {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   cin >> N >> S >> D;
   for(int i = 1 ; i < N ; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
   }
   solve(S, 0);
  cout << max((ans - 1) * 2, 0) << endl;
  return 0;
}