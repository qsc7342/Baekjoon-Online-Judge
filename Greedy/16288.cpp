#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 987654321;

int N, K;
vector<int>adj;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> K;
  int cnt = 0;

  rep(i, N) {
    int num;
    cin >> num;
    adj.pb(num);
  }

  for(int i = 0 ; i < adj.size() ; i++) {
    int tmp = INF;
    if(adj[i] !=0) tmp = adj[i];
    if(adj[i] != 0) {
      cnt++;
      // cout << "adj[i] : " << adj[i] << endl;
    }
    adj[i] = 0;
    for(int j = i ; j < adj.size() ; j++) {
      if(adj[j] > tmp)  {
        // cout << adj[j] << ' ';
        tmp = adj[j];
        adj[j] = 0;
      }
    }
    // cout << endl;
  }
  if(cnt > K) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}
