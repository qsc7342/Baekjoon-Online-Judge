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

char board[21][21];
bool visit[21][21];
int R, C;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ans = 0;
bool chk[26];

bool isRange(int y, int x) {
  if(y < 0 || y >= R || x < 0 || x >= C) return false;
  else return true;
}

int solve(int y, int x, char cur, int cnt) {
  chk[cur - 'A'] = true;
  visit[y][x] = true;
  rep(i, 4) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    int nxt = board[ny][nx];
    if(isRange(ny, nx) && chk[nxt - 'A'] == false && visit[ny][nx] == false) {
      chk[nxt - 'A'] = true;
      visit[ny][nx] = true;
      ans = max(ans, solve(ny, nx, board[ny][nx], cnt + 1));
      chk[nxt - 'A'] = false;
      visit[ny][nx] = false;
    }
  }
  return ans = max(ans, cnt);
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> R >> C;

  rep(i, R) {
    rep(j, C) {
      cin >> board[i][j];
    }
  }
  solve(0, 0, board[0][0], 1);
  cout << ans << endl;
  return 0;
}