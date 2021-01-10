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
#define all(x) (x).begin(), (x).end()
#define PQ(T) priority_queue<T> // 맥스힙
#define GPQ(T) priority_queue<T,vector<T>,greater<T>> // 민힙
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e15;

signed main() {
   FASTIO();
   sc(T);
   sc(n);
   vector<int> a;
   vector<int> b;
   rep(i, n) {
    sc(x);
    a.pb(x);
   }
   sc(m);
   rep(i, m) {
    sc(x);
    b.pb(x);
   }

   map<int, int> chk;

   for(int i = 0 ; i < a.size() ; i++) {
    int cur = 0;
    for(int j = i ; j < a.size() ; j++) {
      cur += a[j];
      chk[cur]++;
    }
   }
   int ans = 0;
   for(int i = 0 ; i < b.size() ; i++) {
    int cur = 0;
    for(int j = i ; j < b.size() ; j++) {
      cur += b[j];
      if(chk[T - cur] > 0) {
        ans += chk[T - cur];
      }
    }
   }
   cout << ans << endl;
}