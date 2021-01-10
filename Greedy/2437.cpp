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

int N;
vector<int>weight;
int cur = 0;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  rep(i, N) {
    int num;
    cin >> num;
    weight.pb(num);
  }
  sort(all(weight));

  for(int i = 0 ; i < weight.size() ; i++) {
    if(weight[i] > cur + 1) {
      cout << cur + 1 << endl;
      return 0;
    }
    else {
      cur += weight[i];
    }
  }
  if(cur == 1) {
    cout << '2' << endl;
  }
  else {
    cout << cur + 1 << endl;
  }
}
