#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 987654321;

ll N, M, K;
vector< vector<ll> > route(1000001);
vector<ll>one;

ll adj[1000001];
bool x[1000001][2] = {}; // left : 0 , right : 1
ll needs = 0;
int start;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M >> K;

  for(int i = 1 ; i <= N ; i++) {
    cin >> adj[i];
  }

  for(int j = 0 ; j < M ; j++) {
    int a , b;
    cin >> a >> b;
    if(a > b) swap(a,b);
    if(b == N && a  == 1) {
      swap(a, b);
    }
    x[a][0] = true;
    x[b][1] = true;
  }

  for(int i = 1 ; i <= N ; i++) {
    int nxt = i + 1;
    if(nxt > N) nxt = 1;

    if(x[i][0] && x[nxt][1]) {
      start = i + 1;
      break;
    }

    if(x[i][1] && x[nxt][0]) {
      start = i;
      break;
    }
  }

  if(start > N) start = 1;
  int tmp = start;
  // cout << "init start : " << start << endl;
  while(1) {
    ll cur = INF;
    int nxt = start + 1;
    if(nxt > N) nxt = 1;
    while(x[start][0] == false && x[nxt][1] == false) {
      if(cur > adj[start]) {
        cur = min(cur, adj[start]);
      }
      // cout << "start :" << start << "cur : " << cur << endl;
      start++;
      if(start > N) start = 1;
      if(start == tmp) break;
      nxt = start + 1;
      if(nxt > N) nxt = 1;
    }
    if(cur > adj[start]) {
      cur = min(cur, adj[start]);
    }
    // cout << "start :" << start << "cur : " << cur << endl;
    start++;
    if(start > N) start = 1;
    nxt = start + 1;
    if(nxt > N) nxt = 1;
    // cout << "select is : " << cur << endl;
    needs += cur;

    if(start == tmp) break;
  }
  if(needs > K) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}
