#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define MAX 10000000
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 987654321;

int parent[4100000] = {};
int RANK[4100000] = {};
int board[2001][2001] = {};
bool visit[2001][2001] = {};
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int cnt2[1000001] = {};
int year = 0;
queue<pii>q, q2;

int N, K;
int cnt = 0;
int find(int n) {
  if(parent[n] < 0) return n;
  return parent[n] = find(parent[n]);
}

bool merge(int a, int b) {
  a = find(a);
  b = find(b);

  if(a == b) return false;
  parent[a] += parent[b];
  parent[b] = a;
  return true;
}

bool isRange(int y, int x) {
  if(x <= 0 || x > N || y <= 0 || y > N) return false;
  else return true;
}


void Union() {
  while(!q.empty()) {
    int cur_y = q.front().first;
    int cur_x = q.front().second;
    q2.push(mp(cur_y, cur_x));
    q.pop();

    for(int i = 0 ; i < 4 ; i++) {
      int ny = cur_y + dy[i];
      int nx = cur_x + dx[i];

      if(isRange(ny, nx)) {
        if(board[ny][nx] > 0 && board[cur_y][cur_x] != board[ny][nx]) {
          if(merge(board[ny][nx], board[cur_y][cur_x])) K--;
        }
      }
    }
  }
}

void Spread() {
  while(!q2.empty()) {
    int cur_y = q2.front().first;
    int cur_x = q2.front().second;
    q2.pop();

    for(int i = 0 ; i < 4 ; i++) {
      int ny = cur_y + dy[i];
      int nx = cur_x + dx[i];

      if(isRange(ny, nx)) {
        if(board[ny][nx] == 0) {
          board[ny][nx] = board[cur_y][cur_x];
          q.push(mp(ny, nx));
        }
      }
    }
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  memset(parent, -1, sizeof(parent));
  memset(visit, false, sizeof(visit));
  memset(RANK, -1, sizeof(RANK));

  cin >> N >> K;

  if(K == 1) {
    cout << "0" << endl;
    return 0;
  }

  for(int i = 1 ; i <= K ; i++) {
    int y, x;
    cin >> y >> x;
    board[y][x] = i;
    q.push(mp(y, x));
  }

  while(K > 1) {
    Union();
    if(K == 1) break;
    Spread();
    year++;
 //   cout << K << endl;
  }

  cout << year << endl;
}
