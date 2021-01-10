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
#define PQ(T) priority_queue<T>
#define GPQ(T) priority_queue<T,vector<T>,greater<T>>
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e15;

const int mod = 9901;
signed main() {
   FASTIO();
   sc(N);

   int dp[N + 1][3] = {}; // all blank, left, right;
   dp[1][0] = 1;
   dp[1][1] = 1;
   dp[1][2] = 1;

   for(int i = 2 ; i <= N ; i++) {
       dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
       dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
       dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
   }

   cout << (dp[N][0] + dp[N][1] + dp[N][2]) % mod << endl;
}