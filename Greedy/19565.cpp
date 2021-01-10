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
   sc(N);
   sc(K);
   int cnt = 1;
   int len = 0;
   int cur = 1;
   int ans = 0;
   while(N--) {
    string s = to_string(cur);
    len += s.size();
    if(len >= K) {
      int tmp = len - K;
      while(tmp--) {
        cur /= 10;
      }
      cout << cur % 10 << endl;
      return 0;
    }
    cnt++;
    cur++;
   }
   cout << "-1" << endl;
}