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

int arr[101][101] = {};
bool visit[101][101] = {};
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1 ,1};
int N, M;
int max_height = 0;
int sum = 0;

bool isRange(int ny, int nx) {
  if(ny < 0 || ny > N || nx < 0 || nx > M) return false;
  else return true;
}
int bfs(int y, int x, int height) {
  int cnt = 1; // 시작 포함해야하니 1로 시작
  bool flag = false;
  queue<pii> q;
  q.push(mp(y, x));
  visit[y][x] = true;

  while(!q.empty()) {
    int cur_y = q.front().first;
    int cur_x = q.front().second;
    q.pop();
    if(cur_y <= 1 || cur_y >= N || cur_x <= 1 || cur_x >= M) { 
      flag = true;
    }
    for(int i = 0 ; i < 4 ; i++) {
      int ny = cur_y + dy[i];
      int nx = cur_x + dx[i];
      if(isRange(ny, nx) && height >= arr[ny][nx] && !visit[ny][nx]) { // 벽이 아니고 미방문 시
        visit[ny][nx] = true;
        cnt++; // 갈수있는 갯수 증가
        q.push(mp(ny, nx));
      }
    }
  }
  if(flag) return 0;
  else return cnt;
}


int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  // For fast IO

  memset(visit, false, sizeof(visit));

  cin >> N >> M;

  for(int i = 1 ; i <= N ; i++) {
    for(int j = 1 ; j <= M ; j++) {
      cin >> arr[i][j];
      max_height = max(max_height, arr[i][j]);
    }
  } // 입력 및 최대높이 구하기


  for(int i = 0 ; i <= max_height ; i++) {
    for(int j = 1 ; j <= N ; j++) {
      for(int k = 1 ; k <= M ; k++) {
        if(!visit[j][k] && i >= arr[j][k]) { // 미방문 + 벽이 아닐 경우
          sum += bfs(j, k, i);
        }
      }
    }
    memset(visit, false, sizeof(visit));
  }
  cout << sum << endl;
}