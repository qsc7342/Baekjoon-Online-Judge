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
int n, m;
int dist[401][401] = {};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  cin >> m;


  for(int i = 1 ; i <= n ; i++) {
    for(int j = 1 ; j <= n; j++) {
      if(i == j) dist[i][j] == 0;
      else {
        dist[i][j] = INF;
      }
    }
  }
  for(int i = 0 ; i < m ; i++) {
    int a, b;
    cin >> a >> b;
    dist[a][b] = min(dist[a][b], 1);
  }

  for(int k = 1 ; k <= n ; k++) {
    for(int i = 1 ; i <= n ; i++) {
      for(int j = 1 ; j <= n ; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int t;
  cin >> t;

  for(int i = 0 ; i < t ; i++) {
    int a, b;
    cin >> a >> b;
    if(dist[a][b] == INF && dist[b][a] == INF) {
      cout << '0' << endl;
    }
    else {
      if(dist[a][b] != INF) {
        cout << "-1" << endl;
      }
      else {
        cout << '1' << endl;
      }
    }
  }
  return 0;
}


