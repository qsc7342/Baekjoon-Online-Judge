#include <bits/stdc++.h>
#define FASTIO() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define fst first
#define snd second
#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define sc(x) int x; cin >> x;
#define sz(x) x.size()
#define all(x) (x).begin(), (x).end()
#define PQ(T) priority_queue<T> // 맥스힙
#define GPQ(T) priority_queue<T,vector<T>,greater<T>> // 민힙
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e15;

int mod = 1e9 + 7;
int pow2(int x, int y) {
  if(y == 0) {
    return 1;
  }
  if(y == 1) {
    return x % mod;
  }
  if(y % 2 == 1) {
    return (((pow2(x, y / 2) % mod) * (pow2(x, y / 2) % mod) % mod) * x) % mod;
  }
  else {
    return ((pow2(x, y / 2) % mod) * (pow2(x, y / 2) % mod) % mod) % mod;
  }
}
signed main() {
  FASTIO();
  sc(N);
  vector<int> v;
  rep(i, N) {
    sc(x);
    v.pb(x);
  }

  sort(all(v));
  int ans = 0;
  rep(i, v.size()) {
    ans += ((v[i] % mod) * pow2(2, i) % mod) % mod;
    ans %= mod;
    ans -= ((v[i] % mod) * pow2(2, sz(v) - i - 1) % mod) % mod; 
    ans += mod;
    ans %= mod;
  }  
  cout << ans % mod << endl;
  return 0;
}