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

int N;
char board[51][51] = {};
int maxcnt = 0;
int ans = 0;
bool visit[51] = {};

void solve(int per) {
  int cnt = 0;

  queue<pii> q;
  visit[per] = true;
  q.push(mp(per, 0));
  while(!q.empty()) {
    int curper = q.front().first;
    int curd = q.front().second;
    q.pop();
    if(curd > 1) break;
    for(int i = 1 ; i <= N ; i++) {
      if(!visit[i] && board[curper][i] == 'Y') {
        visit[i] = true;
        cnt++;
        q.push(mp(i, curd + 1));
      }
    }
  }
  ans = max(ans, cnt);
  return;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;

  for(int i = 1 ; i <= N ; i++) {
    for(int j = 1 ; j <= N ; j++) {
      cin >> board[i][j];
    }
  }

  for(int i = 1 ; i <= N ; i++) {
    memset(visit, false, sizeof(visit));
    solve(i);
  }
  cout << ans << endl;
}