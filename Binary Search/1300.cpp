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

ll N, k;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> k;

  ll lo = 0;
  ll hi = min((ll)1e9, (ll)pow(N, 2));
  while(lo + 1 < hi) {
    ll mid = (lo + hi) / 2;
    ll cur = 0;
    for(int i = 1 ; i <= N ; i++) {
      cur += mi (N,mid / i);
    }
    if(cur >= k) {
      hi = mid;
    }
    else {
      lo = mid;
    }
  }
  cout << hi << endl;
  return 0;
}
