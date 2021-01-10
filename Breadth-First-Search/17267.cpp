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

int arr[1001][1001] = {};
bool visit[1001][1001] = {};
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1}; // i % 2 == 0 왼쪽이동, i % 2 == 1 오른쪽 이동

int N, M;
int L, R;
deque<pair< pair<int, int>, pair<int, int> > > q;

bool isRange(int y, int x) {
  if(y > N || y <= 0 || x > M || x <= 0) return false;
  else return true;
}

int bfs() {
  int cnt = 1; 
  while(!q.empty()) {
    int cur_y = q.back().first.first;
    int cur_x = q.back().first.second;
    int cur_L = q.back().second.first;
    int cur_R = q.back().second.second;
    q.pop_back();
    for(int i = 0 ; i < 4 ; i++) {
      int ny = cur_y + dy[i];
      int nx = cur_x + dx[i];

      if(isRange(ny, nx) && !visit[ny][nx] && arr[ny][nx] != 1) {
        if(i == 2 && cur_L > 0) {
          cnt++;
          visit[ny][nx] = true;
          q.push_front(mp(mp(ny, nx), mp(cur_L - 1, cur_R)));
        }
        else if(i == 3 && cur_R > 0) {
          cnt++;
          visit[ny][nx] = true;
          q.push_front(mp(mp(ny, nx), mp(cur_L, cur_R - 1)));
        }
        else if(i == 1 || i == 0) {
          cnt++;
          visit[ny][nx] = true;
          q.push_back(mp(mp(ny, nx), mp(cur_L, cur_R)));
        }
      }
    }
  }
  return cnt;
}

int main() {
  scanf("%d %d",&N ,&M);

  scanf("%d %d",&L, &R);

  for(int i = 1 ; i <= N ; i++) {
    for(int j = 1 ; j <= M ; j++) {
      scanf("%1d", &arr[i][j]);
      if(arr[i][j] == 2) {
        visit[i][j] = true;
        q.push_back(mp(mp(i, j), mp(L, R)));
      }
    }
  }
  cout << bfs() << endl;

  return 0;
}