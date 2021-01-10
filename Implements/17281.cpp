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

int N;
vector<int> adj; // 1 ~ 9번 타자
vector<int> man;
int res[10][51] = {};
int ans = 0;

void sett() {
  man.clear();
  man.pb(-1);
  man.pb(adj[0]); // 2
  man.pb(adj[1]); // 3
  man.pb(adj[2]); // 4
  man.pb(1);      // 1
  man.pb(adj[3]); // 5
  man.pb(adj[4]); // 6
  man.pb(adj[5]); // 7
  man.pb(adj[6]); // 8
  man.pb(adj[7]); // 9
  return;
}

void solve(int inning, int start, int score) {
  if(inning == N) {
    ans = max(ans, score);
    return;
  }
  int out = 0;
  queue<int> q;

  int cur = start;
  while(out < 3) {
    while(q.size() >= 4) {
      int tmp = q.front();
      if(tmp) {
        score++;
      }
      q.pop();
    }
    if(res[man[cur]][inning] == 1) {
      q.push(1);
    }
    if(res[man[cur]][inning] == 2) {
      q.push(1);
      q.push(0);
    }  
    if(res[man[cur]][inning] == 3) {
      q.push(1);
      q.push(0);
      q.push(0);
    }
    if(res[man[cur]][inning] == 4) {
      q.push(1);
      q.push(0);
      q.push(0);
      q.push(0);
    }
    if(res[man[cur]][inning] == 0) {
      out++;
    }
    cur++;
    if(cur == 10) cur = 1;  
  }
  solve(inning + 1, cur, score);
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;

  for(int i = 0 ; i < N ; i++) {
    for(int j = 1 ; j <= 9 ; j++) {
      cin >> res[j][i];
    }
  }
  for(int i = 2 ; i <= 9 ; i++) {
    adj.pb(i);
  }

  sort(adj.begin(), adj.end());


  do {
    sett();
    solve(0, 1, 0);
  }while(next_permutation(adj.begin(), adj.end()));
  cout << ans << endl;
} 
