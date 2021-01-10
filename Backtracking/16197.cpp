#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 987654321;

int N, M;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ans = INF;
char board[25][25] = {};

int solve(int step, int y1, int x1, int y2, int x2) {
  if(step > 10) return INF;
  if((y1 > N || x1 > M) && (y2 > N || x2 > M)) return INF;
  if((y1 <= 0 || x1 <= 0) && (y2 <= 0 || x2 <= 0)) return INF;
  else if((y1 > N || x1 > M) || (y2 > N || x2 > M)) return step;
  else if((y1 <= 0 || x1 <= 0) || (y2 <= 0 || x2 <= 0)) return step;

  for(int i = 0 ; i < 4 ; i++) {
    int ny1, ny2, nx1, nx2;
    ny1 = y1 + dy[i];
    nx1 = x1 + dx[i];
    ny2 = y2 + dy[i];
    nx2 = x2 + dx[i];
    if(board[ny1][nx1] != '#' && board[ny2][nx2] != '#') { // no wall
      ans = min(ans, solve(step + 1, ny1, nx1, ny2, nx2));
    }
    if(board[ny1][nx1] == '#' && board[ny2][nx2] != '#') { // no wall
      ans = min(ans, solve(step + 1, y1, x1, ny2, nx2));
    }
    if(board[ny1][nx1] != '#' && board[ny2][nx2] == '#') { // no wall
      ans = min(ans, solve(step + 1, ny1, nx1, y2, x2));
    }
    if(board[ny1][nx1] == '#' && board[ny2][nx2] == '#') { // no wall
      ans = min(ans, solve(step + 1, y1, x1, y2, x2));
    }
  }
  return ans;
}

int main() {
  // cin.tie(NULL);
  // ios_base::sync_with_stdio(false);

  cin >> N >> M;
  int y1,x1,y2,x2;
  y1 = 0;
  x1 = 0;
  y2 = 0;
  x2 = 0;
  for(int i = 1 ; i <= N ; i++) {
    for(int j = 1 ; j <= M ; j++) {
      cin >> board[i][j];
      if(board[i][j] == 'o') {
        if(y1 == 0 && x1 == 0) {
          y1 = i;
          x1 = j;
        }
        else if(y2 == 0 && x2 == 0) {
          y2 = i;
          x2 = j;
        }
      }
    }
  }
  solve(0, y1, x1, y2, x2);
  if(ans == INF) {
    cout << "-1" << endl;
    return 0;
  }
  cout << ans << endl;
}