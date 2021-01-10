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
const int INF = 2147483646;
const double pi = 3.141592653589793;

bool visit[11] = {};
bool visit2[11] = {};
vector<vector<int> > adj(11);
int N;
int person[11] = {};
int ans = INF;
vector<int> c;

void dfs(int n) {
  visit2[n] = true;
  for(int i = 0 ; i < adj[n].size() ; i++) {
    int nxt = adj[n][i];
    if(!visit2[nxt]) {
      visit2[nxt] = true;
      dfs(nxt);
    }
  }
}

void solve(int cur, vector<int> pick) {
  bool flag = true;
  if(pick.size() != 0 && pick.size() != N) {
    int f = 0;
    int s = 0;
    memset(visit2, false, sizeof(visit2));
    for(int i = 1 ; i <= N ; i++) {
      if(visit[i] == false) visit2[i] = true; 
    }
    dfs(pick[0]);
    for(int i = 1 ; i <= N ; i++) {
      if(visit[i] == true) f += person[i];
      if(visit[i] == false) s += person[i];
      if(visit[i] == true && visit2[i] == false) {
        flag = false;
      }
    }
    memset(visit2, false, sizeof(visit2));
    for(int i = 1 ; i <= N ; i++) {
      if(visit[i]) visit2[i] = true;
    }
    for(int i = 1 ; i <= N ; i++) {
      if(visit[i] == false) {
        dfs(i);
        break;
      } 
    }
    for(int i = 1 ; i <= N ; i++) {
      if(visit2[i] == false && visit[i] == false) {
        flag = false;
      }
    }

    if(flag) {
      ans = min(abs(f - s), ans);
    }
  } 

  if(cur > N) return;

  visit[cur] = true;
  pick.pb(cur);
  solve(cur + 1, pick);
  visit[cur] = false;
  pick.pop_back();
  solve(cur + 1, pick);
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;

  for(int i = 1 ; i <= N ; i++) {
    cin >> person[i];
  }

  for(int i = 1 ; i <= N ; i++) {
    int x;
    cin >> x;
    for(int j = 0 ; j < x ; j++) {
      int t;
      cin >> t;
      adj[i].pb(t);
    }
  }
  solve(1, c);
  if(ans == INF) {
    cout << "-1" << endl;
    return 0;
  }
  cout << ans << endl;
} 
