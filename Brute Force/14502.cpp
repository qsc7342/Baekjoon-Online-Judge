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
const int INF = 987654321;

int N, M;
int mat[9][9];
int cnt = 0;
int ans = 0;
vector<pii>blank;
vector<pii>wall;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool visit[9][9] = {};
int numofzero = 0;

bool isRange(int y, int x) {
  if(y < 0 || y >= N || x < 0 || x >= M) return false;
  else return true;
}

void getvirus(int y, int x) {
  if(visit[y][x]) return;
  visit[y][x] = true;
  for(int i = 0 ; i < 4 ; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(mat[ny][nx] == 0 && !visit[ny][nx] && isRange(ny, nx)) {
      cnt++;
      getvirus(ny, nx);
    }
  }
  return;
}

void solve(int start, int picked) {
  if(picked == 3) {
    for(int i = 0 ; i < wall.size() ; i++) {
      mat[wall[i].first][wall[i].second] = 1;
    }
    for(int i = 0 ; i < N ; i++) {
      for(int j = 0 ; j < M ; j++) {
        if(!visit[i][j] && mat[i][j] == 2) {
          getvirus(i, j);
        }
      }
    }
    for(int i = 0 ; i < wall.size() ; i++) {
      mat[wall[i].first][wall[i].second] = 0;
    }
    ans = max(ans, numofzero - cnt);
    memset(visit, false, sizeof(visit));
    cnt = 0;
    return;
  }

  for(int i = start ; i < blank.size() ; i++) {
    int f = blank[i].first;
    int s = blank[i].second;
    wall.pb(mp(f, s));
    solve(i + 1, picked + 1);
    wall.pop_back();
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  numofzero = N * M;

  rep(i, N) {
    rep(j, M){
      cin >> mat[i][j];
      if(mat[i][j] == 0) {
        blank.pb(mp(i, j));
      }
      else {
        numofzero--;
      }
    }
  }
  numofzero -= 3;

  solve(0, 0);
  // cout << numofzero << endl;
  cout << ans << endl;
}