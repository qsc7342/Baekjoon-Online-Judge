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


int N;
vector<int>arr;

int getLis() {
  vector<int>adj;

  for(int i = 0 ; i < N ; i++) {
    if(adj.size() == 0 || adj.back() < arr[i]) {
      adj.pb(arr[i]);
    }
    else {
      int chk = lower_bound(adj.begin(), adj.end(), arr[i]) - adj.begin();
      adj[chk] = arr[i];
    }
  }
  return adj.size();
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;

  for(int i = 0 ; i < N ; i++) {
    int num;
    cin >> num;
    arr.pb(num);
  }
  cout << N - getLis() << endl;
}
