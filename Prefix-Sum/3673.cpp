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
int T;

vector<ll>arr;
ll psum[50001] = {};
ll cnt[1000001] = {};
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> T;

  rep(i, T) {
    cin >> N >> M;

    for(int i = 0 ; i < M ; i++) {
      ll num;
      cin >> num;
      arr.pb(num);
    }
    psum[0] = arr[0];
    for(int i = 1 ; i < M ; i++) {
      psum[i] = psum[i - 1] + arr[i];
    }
    ll ans = 0;

    for(int i = 0 ; i < M ; i++) {
      psum[i] %= N;
    }

    for(int i = 0 ; i < M ; i++) {
      cnt[psum[i]]++;
    }

    for(int i = 0 ; i <= 1000000 ; i++) {
      ans += cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ans + cnt[0] << endl;

    arr.clear();
    memset(psum, 0, sizeof(psum));
    memset(cnt, 0, sizeof(cnt));
  }
  return 0;
}