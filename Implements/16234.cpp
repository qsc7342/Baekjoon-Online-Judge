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

int arr[51][51] = {};
bool visit[51][51] = {};
bool flag = false;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
ll N, L, R;

bool isRange(int y, int x) {
  if(y <= 0 || y > N || x <= 0 || x > N) {
    return false;
  }
  return true;
}

void bfs(int y, int x) {
  vector<pii> visited;
  queue<pii> q;
  ll sum = 0;
  q.push(mp(y, x));
  visited.pb(mp(y, x));
  sum += arr[y][x];
  visit[y][x] = true;
  while(!q.empty()) {
    int cury = q.front().first;
    int curx = q.front().second;
    q.pop();
    for(int i = 0 ; i < 4 ; i++) {
      int ny = cury + dy[i];
      int nx = curx + dx[i];
      if(!isRange(ny, nx)) continue;
      ll diff = abs(arr[cury][curx] - arr[ny][nx]);
      if(!visit[ny][nx] && diff >= L && diff <= R) {
        flag = true;
        q.push(mp(ny, nx));
        visit[ny][nx] = true;
        visited.pb(mp(ny, nx));
        sum += arr[ny][nx];
      }
    }
  }
  ll tmp = visited.size();
  ll res = sum / tmp;

  for(int i = 0 ; i < visited.size() ; i++) {
    arr[visited[i].first][visited[i].second] = res;
  }
  return;
}


int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> L >> R;

  for(int i = 1 ; i <= N ; i++) {
    for(int j = 1;  j <= N ; j++) {
      cin >> arr[i][j];
    }
  }
  ll ans = 0;

  while(1) {
    flag = false;
    memset(visit, false, sizeof(visit));
    for(int i = 1 ; i <= N ; i++) {
      for(int j = 1 ; j <= N ; j++) {
        if(!visit[i][j]) {
          bfs(i, j);
        }
      }
    }
    if(!flag) break;
    else ans++;
  }
  cout << ans << endl;
} 
