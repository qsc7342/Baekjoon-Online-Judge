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

int N, M;
set<pii> pos;
vector<pii> pick;
int board[51][51] = {};
int tmpboard[51][51] = {};
bool visit[51][51] = {};
bool visitb[51][51] = {};
int ans = INF;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int tc = 0;
int blank = 0;
void bfs();

void solve(int picked, int sty, int stx) {
  if(stx > N) {
    stx = 1;
    sty++;
  }
  if(picked == M) {
    tc++;
    memset(visitb, false, sizeof(visitb));
    for(int i = 1 ; i <= N ; i++) {
      for(int j = 1 ; j <= N ; j++) {
        board[i][j] = tmpboard[i][j];
      }
    }
    bfs();
    return;
  }
  bool f = true;
  for(int i = sty ; i <= N ; i++) {
    for(int j = stx ; j <= N ; j++) {
      if(pos.find(mp(i, j)) != pos.end() && visit[i][j] == false) {
        visit[i][j] = true;
        pick.pb(mp(i, j)); 
        solve(picked + 1, i, j + 1);
        visit[i][j] = false;
        pick.pop_back();
      }
    }
    if(f) {
      stx = 1;
      f= false;
    }
  }
  return;
}

void bfs() {
  int mx = INF;
  int fest = 0;
  queue<pair<pair<int, int>, int > > q;
  for(int i = 0 ; i < pick.size() ; i++) {
    q.push(mp(mp(pick[i].first, pick[i].second), 0));
    visitb[pick[i].first][pick[i].second] = true;
    board[pick[i].first][pick[i].second] = 2;
  }
  while(!q.empty()) {
    int cy = q.front().first.first;
    int cx = q.front().first.second;
    int t = q.front().second;
    q.pop();
    if(board[cy][cx] == 0) {
      fest++;
      board[cy][cx] = 2;
    }
    if(fest == blank - M && mx == INF) {
      mx = t;
    }
    for(int i = 0 ; i < 4 ; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if(ny <= 0 || ny > N || nx <= 0 || nx > N || visitb[ny][nx] || board[ny][nx] == 1) continue;
      visitb[ny][nx] = true;
      q.push(mp(mp(ny, nx), t + 1));
    }
  }
  if(mx != INF) {
    ans = min(ans, mx);
  } 
  return;
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;

  for(int i = 1 ; i <= N ; i++) {
    for(int j = 1 ; j <= N ; j++) {
      cin >> board[i][j];
      if(board[i][j] == 2) {
        board[i][j] = 0;
        pos.insert(mp(i, j));
      }
      if(board[i][j] == 0) blank++;
      tmpboard[i][j] = board[i][j];
    }
  }
  solve(0, 1, 1);
  if(ans == INF) {
    cout << "-1" << endl;
    return 0;
  }
  cout << ans << endl;
} 
