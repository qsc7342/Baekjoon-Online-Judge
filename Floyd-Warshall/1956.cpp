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
int board[2001][2001] = {};
bool visit[2001][2001] = {};
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

queue< pair<pair<int, int>, move> > q;

int N, K;
int cnt = 0;

int find(int n) {
  if(parent[n] < 0) return n;
  return parent[n] = find(parent[n]);
}

int merge(int a, int b) {
  a = find(a);
  b = find(b);

  if(a == b) return false;
  else {
    parent[a] += parent[b];
    parent[b] = a;
  }
  return abs(parent[a]);
}

bool isRange(int y, int x) {
  return x > 0 && x <= N && y > 0 && y <= N;
}
int bfs() {
  while(!q.empty()) {
    int cur_y = q.first.first;
    int cur_x = q.first.second;
    int year = q.second;
    int cur_num = N * (cur_y - 1) + cur_x;
    cnt++;
    for(int i = 0 ; i < 4 ; i++) {
      int ny = cur_y + dy[i];
      int nx = cur_x + dx[i];
      int next_num = N * (ny - 1) + nx;

      if(isRange(ny, nx) && !visit[ny][nx]) {
        visit[ny][nx] = true;
        q.push(mp(mp(ny, nx), year + 1));
        merge(cur_num, next_num);
      }
    }
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  memset(parent, -1, sizeof(parent));
  memset(visit, false, sizeof(visit));

  cin >> N >> K;

  for(int i = 0 ; i < K ; i++) {
    int y, x;
    cin >> y >> x;
    board[y][x] = 1;
    q.push(mp(mp(y, x), 0));
    visit[y][x] = true;
  }
  for(int i = 1 ; i <= N ; i++) {
    for(int j = 1 ; j <= N ; j++) {
      int num = N * (i - 1) + j;
      if(board[i][j] == 1) {
        for(int k = 0 ; k < 4 ; k++) {
          int ny = i + dy[i];
          int nx = j + dx[i];
          int n_num = N * (ny - 1) + nx;
          if(board[ny][nx] == 1) {
            if(num > n_num) swap(num, n_num);

            merge(num, n_num);
          }
        }
      } 
    }
  }
}
