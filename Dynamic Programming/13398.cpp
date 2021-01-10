#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue  
#define MOD 998244353
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll INF = 1e17;
const double pi = 3.141592653589793;

int T;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  ll N, M;
  cin >> N >> M;
  ll max_val = 0;
  vector<ll> cost;
  for(int i = 0 ; i < N ; i++) {
    ll x;
    cin >> x;
    cost.pb(x);
    max_val = max(max_val, x);
  }

  ll lo = max_val - 1;
  ll hi = 1e12;
  ll ans = 1e12;
  while(lo + 1 < hi) {
   // cout << "l o : " << lo << " hi : " << hi << endl;
    ll mid = (lo + hi) / 2;
    ll cur_money = 0;
    ll cnt = 0;
    for(int i = 0 ; i < N ; i++) {
      // cout << "cur_money : " << cur_money << endl; 
      if(cost[i] > cur_money) {
        cnt++;
        cur_money = mid;
      }
      cur_money -= cost[i];
    }
    if(cnt > M) { // 인출 많이했으니 더 큰금액
 //     cout << "cnt : " << cnt << endl;
      lo = mid;
    }
    else {
      hi = mid;
    }
  }
  cout << hi << endl;
  return 0;
}