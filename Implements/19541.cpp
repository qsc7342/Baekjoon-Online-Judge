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

int N, M;
vector< vector<int> > adj(100001);
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for(int i = 1 ; i <= M ; i++) {
    int x;
    cin >> x;
    for(int j = 0 ; j < x ; j++) {
      int t;
      cin >> t;
      adj[i].pb(t);
    }
  }
  int arr[100001] = {};
  int aft[100001] = {};
  int bef[100001] = {};
  for(int i = 1 ; i <= N ; i++) {
    cin >> arr[i];
    bef[i] = arr[i];
  }


  for(int i = M ; i >= 1 ; i--) {
    vector<int> infest;
    bool ni = false;
    for(int j = 0 ; j < adj[i].size() ; j++) {
      int cur = adj[i][j];
      if(arr[cur] == 1) {
        infest.pb(cur);
      }
      else if(arr[cur] == 0) {
        ni = true;
      }
    }
    if(ni) {
      for(auto x : infest) {
        arr[x] = 0;
      }
    }
  }

  for(int i = 1 ; i <= N ; i++) {
    aft[i] = arr[i];
  } 
  for(int i = 1 ; i <= M ; i++) {
    vector<int> cur;
    bool inf = false;
    for(int j = 0 ; j < adj[i].size() ; j++) {
      int cc = adj[i][j];
      cur.pb(cc);
      if(arr[cc] == 1) {
        inf = true;
      }
    }
    if(inf) {
      for(auto x : cur) {
        arr[x] = 1;
      }
    }
  }
  for(int i = 1 ; i <= N ; i++) {
    if(bef[i] != arr[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  for(int i = 1 ; i <= N ; i++) {
    cout << aft[i] << ' ';
  }
  cout << endl;
} 
