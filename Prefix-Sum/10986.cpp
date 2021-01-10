#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

// 
int N, M;
vector<ll>arr;
ll psum[1000002] = {};
ll cnt[1001] = {};
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;

  for(int i = 0 ; i < N ; i++) {
    ll num;
    cin >> num;
    arr.pb(num);
  }
  psum[0] = arr[0];
  for(int i = 1 ; i < N ; i++) {
    psum[i] = psum[i - 1] + arr[i];
  }
  ll ans = 0;

  for(int i = 0 ; i < N ; i++) {
    psum[i] %= M;
  }

  for(int i = 0 ; i < N ; i++) {
    cnt[psum[i]]++;
  }

  for(int i = 0 ; i <= 1000 ; i++) {
    ans += cnt[i] * (cnt[i] - 1) / 2;
  }
  cout << ans + cnt[0] << endl;
  return 0;
}