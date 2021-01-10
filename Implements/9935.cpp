#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define MAX 10000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 2147483646;

vector<int> child;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  for(int i = 0 ; i < N ; i++) {
    int num;
    cin >> num;
    child.pb(num);
  }

  vector<int>adj;
  for(int i = 0 ; i < child.size() ; i++) {
    if(adj.size() == 0 || adj.back() < child[i]) {
      adj.pb(child[i]);
    }
    else {
      auto it = lower_bound(adj.begin(), adj.end(), child[i]);
      *it = child[i];
    }
  }

  cout << N - adj.size() << endl;

} 