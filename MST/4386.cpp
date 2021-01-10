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

int parent[200001];

int find(int n) {
  if(parent[n] == -1) return n;
  return parent[n] = find(parent[n]);
}

bool merge(int a, int b) {
  a = find(a);
  b = find(b);
  if(a == b) return false;

  parent[b] = a;
  return true;
}

vector<pair<int, int> >star;
vector<pair<double, pair<int, int> > > adj;

double getdist(double x2, double x1, double y2, double y1) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  memset(parent, -1, sizeof(parent));

  int n;
  cin >> n;

  for(int i = 0 ; i < n ; i++) {
    double x, y;
    cin >> x >> y;
    star.pb(mp(x,y));
  }

  for(int i = 0 ; i < star.size() ; i++) {
    for(int j = i + 1 ; j < star.size() ; j++) {
      double x2, x1, y2, y1;
      x2 = star[i].first;
      x1 = star[j].first;
      y2 = star[i].second;
      y1 = star[j].second;

      adj.pb(mp(getdist(x2, x1, y2, y1), mp(i, j)));
    }
  }
    sort(adj.begin(), adj.end());

    int cnt = 0;
    double sum = 0;
    for(int i = 0 ; i < adj.size() ; i++) {
      double val = adj[i].first;
      int a, b;
      a = adj[i].second.first;
      b = adj[i].second.second;

      if(find(a) == find(b)) continue;
      else {
        merge(a, b);
        cnt ++;
        sum += val;
      }
      if(cnt == n - 1) break;
    }
  cout.precision(3);
  cout << sum;
  cout << endl;
  return 0;
}