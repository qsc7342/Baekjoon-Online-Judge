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

int par[10001] = {};
vector<pii> cost;

int foo(int n) {
  if(par[n] == -1) return n;
  else {
    return par[n] = foo(par[n]);
  } 
} 

void merge(int a, int b) {
  if(a > b) swap(a, b);
  a = foo(a);
  b = foo(b);
  if(a == b) return;
  else {
    par[a] = b;
    return;
  }
}
signed main() {
   FASTIO();
   memset(par, -1, sizeof(par));
   sc(N);

   vector<int> arr;

   rep(i, N) {
    sc(x);
    arr.pb(x);
   }

   int cnt[1000001] = {};

   rep(i, arr.size()) {
    cnt[arr[i]]++;
   }

   stack<pii> s;
   vector<int> ans;
   for(int i = arr.size() - 1 ; i >= 0 ; i--) {
    while(!s.empty() && s.top().snd <= cnt[arr[i]]) {
      s.pop();
    }
    if(s.empty()) {
      ans.pb(-1);
    }
    else {
      ans.pb(s.top().fst);
    }
    ans.push(mp(arr[i] ,cnt[arr[i]]));
   }
   reverse(all(ans));

   for(auto x : ans) {
    cout << x << ' ';
   }
   cout << endl;

}