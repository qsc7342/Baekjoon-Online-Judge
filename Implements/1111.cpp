#include <bits/stdc++.h>
#define FASTIO() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define fst first
#define snd second
#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define sc(x) int x; cin >> x;
#define s(x) cin >> x;
#define all(x) (x).begin(), (x).end()
#define V(T) vector<T>
#define PQ(T) priority_queue<T>
#define GPQ(T) priority_queue<T,vector<T>,greater<T>>
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e15;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

signed main() {
  FASTIO();
  sc(N);
  sc(M);
  int arr[51][51] = {};
  bool visit[51][51] = {};
  int move[51][51] = {};
  queue<pair<pii, int> > q;
  for(int i = 1 ; i <= N ; i++) {
    for(int j = 1 ; j <= M ; j++) {
      cin >> arr[i][j];
      if(arr[i][j]) {
        q.push(mp(mp(i, j), 0));
        visit[i][j] = true;
      }
    }
  }

  while(!q.empty()) {
    int cury = q.front().fst.fst;
    int curx = q.front().fst.snd;
    int dist = q.front().snd;
    move[cury][curx] = dist;
    visit[cury][curx] = true;
    for(int i = 0 ; i < 8 ; i++) {
      int ny = cury + dy[i];
      int nx = curx + dx[i];
      if(ny <= 0 || ny > N || nx <= 0 || nx > M) continue;

      if(!visit[ny][nx]) {
        q.push(mp(mp(ny, nx), dist + 1));
      }
    }
  }
  int ans = 0;
  for(int i = 1 ; i <= N ; i++) {
    for(int j = 1;  j <= M ; j++) {
      ans = max(ans, move[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}