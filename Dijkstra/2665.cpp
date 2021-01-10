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

int T;
int N;
int board[51][51] = {};
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool isRange(int y, int x) {
  if(y <= 0 || y > N || x <= 0 || x > N) return false;
  else return true;
}
int main() {
  // cin.tie(NULL);
  // ios_base::sync_with_stdio(false);

  cin >> N;

  for(int i = 1 ; i <= N ; i++) {
    for(int j = 1 ; j <= N ; j++) {
      scanf("%1d" , &board[i][j]);
    }
  }

  int tmp[51][51] = {};

  for(int i = 1 ; i <= N ; i++) {
    for(int j = 1 ; j <= N ; j++) {
      tmp[i][j] = INF;
    }
  }
  queue<pair<pii, int> > q;
  q.push(mp(mp(1, 1), 0));

  while(!q.empty()) {
    int cury = q.front().first.first;
    int curx = q.front().first.second;
    int curd = q.front().second;
    q.pop();
    if(curd >= tmp[cury][curx]) continue;
    else tmp[cury][curx] = curd;
    for(int i = 0 ; i < 4 ; i++) {
      int ny = cury + dy[i];
      int nx = curx + dx[i];
      if(!isRange(ny, nx)) continue;
      int nxt = curd;
      if(board[ny][nx] == 0) nxt++;
      if(tmp[ny][nx] > nxt) {
        q.push(mp(mp(ny, nx), nxt));
      }
    }
  }
  cout << tmp[N][N] << endl;
} 
