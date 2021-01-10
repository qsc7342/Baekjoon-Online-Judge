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

int R, C;
int board[105][105] = {};
bool visit[105][105] = {}; 
int cheese = 0;
int prv = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<pii> melt;

bool isRange(int y, int x){
  if(y < 0 || y > R || x < 0 || x > C) return false;
  else return true;
}

void bfs() {
  queue<pii> q;
  q.push(mp(0, 0));
  visit[0][0] = true;
  while(!q.empty()) {
    int cury = q.front().first;
    int curx = q.front().second;
    q.pop();
    if(board[cury][curx] == 1) {
      melt.pb(mp(cury, curx));
      continue;
    }

    for(int i = 0 ; i < 4 ; i++) {
      int ny = cury + dy[i];
      int nx = curx + dx[i];
      if(!isRange(ny, nx)) continue;
      if(!visit[ny][nx]) {
        visit[ny][nx] = true;
        q.push(mp(ny, nx));
      }
    }
  }
  return;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> R >> C;
  for(int i = 1 ; i <= R ; i++) {
    for(int j = 1 ; j <= C ; j++) {
      cin >> board[i][j];
      if(board[i][j] == 1) cheese++;
    }
  }
  int t = 0;
  while(cheese != 0) {
    memset(visit, false, sizeof(visit));
    prv = cheese;
    t++;
    bfs();

    for(auto x : melt) {
      board[x.first][x.second] = 0;
      cheese--;
    }
    melt.clear();
  }
  cout << t << endl << prv << endl;
} 
