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

int N, M, D;
int board[17][17] = {};
bool visit[17][17] = {};
vector<int> arch;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int ans = 0;
int ret = 0;
int tmpboard[17][17] = {};
bool isRange(int y, int x) {
  if(y < 0 || y >= N || x < 0 || x >= M) return false;
  else return true;
} 

bool compare(pii a, pii b) {
  return a.second < b.second;
}

void attack() {
  set<pii> att;
  for(int i = 0 ; i < arch.size() ; i++) {
    if(arch[i] == 1) {
      memset(visit, false, sizeof(visit));
      queue<pair<pair<int, int>, int > > q;
      q.push(mp(mp(N, i), 0));
      vector<pii> enemy;
      int mind = INF;
      while(!q.empty()) {
        int cury = q.front().first.first;
        int curx = q.front().first.second;
        int curd = q.front().second;
        visit[cury][curx] = true;
        q.pop();
        if(curd > D) continue;
        if(board[cury][curx] == 1 && curd < mind && curd <= D) {
          enemy.clear();
          enemy.pb(mp(cury, curx));
          mind = curd;
        }
        else if(board[cury][curx] == 1 && curd == mind && curd <= D) {
          enemy.pb(mp(cury, curx));
        }
        for(int j = 0 ; j < 4 ; j++) {
          int ny = cury + dy[j];
          int nx = curx + dx[j];
          if(!isRange(ny, nx) || visit[ny][nx]) continue;
          visit[ny][nx] = true;
          q.push(mp(mp(ny, nx), curd + 1));
        }
      }
      if(enemy.size() == 0) continue;
      sort(enemy.begin(), enemy.end(), compare);
      att.insert(mp(enemy[0].first, enemy[0].second));
    }
  }
  for(auto x : att) {
    if(board[x.first][x.second] == 1) {
      ans++;
      board[x.first][x.second] = 0;
    }
  }
  return;
}

bool check() {
  for(int i = 0 ; i < N ; i++) {
    for(int j = 0 ; j < M ; j++) {
      if(board[i][j] == 1) return false;
    }
  }
  return true;
}

void move() {
  int newboard[17][17] = {};
  for(int i = 1 ; i < N ; i++) {
    for(int j = 0 ; j < M ; j++) {
      newboard[i][j] = board[i - 1][j];
    }
  }

  for(int i = 0 ; i < N ; i++) {
    for(int j = 0 ; j < M ; j++) {
      board[i][j] = newboard[i][j];
    }
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int mons = 0;
  cin >> N >> M >> D;
  for(int i = 0 ; i < N ; i++) {
    for(int j = 0 ; j < M ; j++) {
      cin >> board[i][j];
    }
  }

  for(int i = 0 ; i < N ; i++) {
    for(int j = 0 ; j < M ; j++) {
      tmpboard[i][j] = board[i][j];
    }
  }
  arch.resize(M);
  arch[0] = 1;
  arch[1] = 1;
  arch[2] = 1;
  sort(arch.begin(), arch.end());

  do {
    for(int i = 0 ; i < N ; i++) {
      for(int j = 0 ; j < M ; j++) {
        board[i][j] = tmpboard[i][j];
      }
    }
    rep:
    attack();
    move();
    if(!check()) {
      ret = max(ans, ret);
      goto rep;
    }
    else {
      ret = max(ans, ret);
      ans = 0;
    }
  }while(next_permutation(arch.begin(), arch.end()));

  cout << ret << endl;
} 
