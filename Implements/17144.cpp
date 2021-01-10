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

int board[51][51] = {};
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1 , 1};
int R, C, T;
vector<pii> air;
bool isRange(int y, int x) {
  if(y <= 0 || y > R || x <= 0 || x > C || (y == air[0].first && x == air[0].second) || (y == air[1].first && x == air[1].second)) return false;
  else return true; 
}

void spread() {
  int tmp[51][51] = {};
  for(int i = 1 ; i <= R ; i++) {
    for(int j = 1 ; j <= C ; j++) {
      tmp[i][j] = board[i][j];
    }
  }
  for(int i = 1 ; i <= R ; i++) {
    for(int j = 1 ; j <= C ; j++) {
      if(tmp[i][j] > 0) {
        int spread = 0;
        for(int k = 0 ; k < 4 ; k++) {
          int ny = i + dy[k];
          int nx = j + dx[k];
          if(isRange(ny, nx)) {
            board[ny][nx] += tmp[i][j] / 5;
            spread += tmp[i][j] / 5;
          }
        }
        board[i][j] -= spread;
      }
    }
  }
}

void up(int y, int x) {
  for(int i = y - 1 ; i >= 2 ; i--) {
    board[i][1] = board[i - 1][1];
  }
  for(int i = x ; i <= C - 1 ; i++) {
    board[1][i] = board[1][i + 1];
  }

  for(int i = 1 ; i <= y - 1 ; i++) {
    board[i][C] = board[i + 1][C];
  }

  for(int i = C ; i >= 3 ; i--) {
    board[y][i] = board[y][i - 1];
  }
  board[y][2] = 0;
}

void down(int y, int x) {
  for(int i = y + 1 ; i <= R - 1 ; i++) {
    board[i][1] = board[i + 1][1];
  }
  for(int i = 1 ; i <= C - 1 ; i++) {
    board[R][i] = board[R][i + 1];
  }
  for(int i = R ; i >= y + 1 ; i--) {
    board[i][C] =  board[i - 1][C];
  }
  for(int i = C ; i >= 3 ; i--) {
    board[y][i] = board[y][i - 1];
  } 
  board[y][2] = 0; 
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> R >> C >> T;
  for(int i = 1 ; i <= R ; i++) {
    for(int j = 1 ; j <= C ; j++) {
      cin >> board[i][j];
      if(board[i][j] == -1) {
        air.pb(mp(i, j));
      }
    }
  }
  while(T--) {
    spread();
    up(air[0].first, air[0].second);
    down(air[1].first, air[1].second);
  }
  ll ans = 0;
  for(int i = 1 ; i <= R ; i++) {
    for(int j = 1 ; j <= C ; j++) {
      ans += max(0, board[i][j]);
    }
  }
  cout << ans << endl;
}