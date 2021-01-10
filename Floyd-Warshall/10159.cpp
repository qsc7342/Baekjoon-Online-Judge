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
#define all(x) (x).begin(), (x).end()
#define PQ(T) priority_queue<T> // 맥스힙
#define GPQ(T) priority_queue<T,vector<T>,greater<T>> // 민힙
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e15;

signed main() {
  FASTIO();
  int dist[101][101] = {};
  for(int i = 1 ; i <= 100 ; i++) {
    for(int j = 1 ; j <= 100 ; j++) {
      dist[i][j] = INF;
    }
  }

  sc(N);
  sc(M);

  rep(i, M) {
    int a, b;
    cin >> a >> b;
    dist[a][b] = 1;
  }

  for(int k = 1 ; k <= N ; k++) {
    for(int i = 1 ; i <= N ; i++) {
      for(int j = 1 ; j <= N ; j++) {
        if(i == j) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  int ans[101] = {};
  for(int i = 1 ; i <= N ; i++) {
    for(int j = 1 ; j <= N ; j++) {
      if(i != j) {
        if(dist[i][j] == INF && dist[j][i] == INF) {
          ans[i]++;
        }
      }
    }
    cout << ans[i] << endl;
  }
  return 0;
}