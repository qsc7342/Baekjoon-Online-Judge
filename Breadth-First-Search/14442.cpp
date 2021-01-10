#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define MAX 10000000
#define INF 987654321
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int N, M, K;
int arr[1001][1001] = {};
bool visit[1001][1001][11] = {}; // 0 안뚫고 visit, 1 뚫고 visit
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool isRange(int y, int x) {
  if(y > N || y <= 0 || x > M || x <= 0) return false;
  else return true;
}

int bfs() {
  queue<pair< pii, pii > >q; // {y좌표, x좌표} , {벽뚫었는지 check, 이동 수}
  q.push(mp(mp(1, 1), mp(0, 1)));
  int ans = INF;
  visit[1][1][0] = true;

  while(!q.empty()) {
    int cur_y = q.front().first.first;
    int cur_x = q.front().first.second;
    int wall = q.front().second.first;
    int moved = q.front().second.second;

//    cout << "y ,x , wall, moved " << cur_y << ' ' << cur_x << ' ' << wall << ' ' << moved << endl; 
    q.pop();
    if(cur_y == N && cur_x == M) {
      // destination
      ans = min(ans, moved);
    }
    else {
      for(int i = 0 ; i < 4 ; i++) {
        int ny = cur_y + dy[i];
        int nx = cur_x + dx[i];
        if(isRange(ny, nx)) {
          if(arr[ny][nx] == 1) { // 벽일 경우
            if(wall + 1 <= K && !visit[ny][nx][wall + 1]) {
              if(moved % 2 == 1) {
                visit[ny][nx][wall + 1] = true;
                q.push(mp(mp(ny, nx), mp(wall + 1, moved + 1)));
              }
              else {
                q.push(mp(mp(cur_y, cur_x), mp(wall, moved + 1)));
              }
            }
          }

          else if(arr[ny][nx] == 0) {
            if(!visit[ny][nx][wall]) {
              visit[ny][nx][wall] = true;
              q.push(mp(mp(ny, nx), mp(wall, moved + 1)));
            }
          }
        }
      }
    }
  }
  if(ans == INF) ans = -1;
  return ans;
}

int main() {
  // cin.tie(NULL);
  // ios_base::sync_with_stdio(false);
  
  scanf("%d %d %d", &N ,&M, &K);

  for(int i = 1 ; i <= N ; i++) {
    for(int j = 1 ; j <= M ; j++) {
      scanf("%1d", &arr[i][j]);
    }
  }
  +
  printf("%d\n", bfs());

  return 0;
}
