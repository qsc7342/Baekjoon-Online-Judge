#include <iostream>
#include <algorithm>
#include <memory.h>
#include <random>
#include <unordered_map>
#include <math.h>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
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
#define str string
#define lb lower_bound
#define ub upper_bound
#define V(T) vector<T>
#define Q(T) queue<T>
#define S(T) stack<T>
#define DQ(T) deque<T>   
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define sc(x) int x; cin >> x;
#define sc2(x,y)     int x,y;cin>>x>>y
#define sc3(x,y,z)   int x,y,z;cin>>x>>y>>z
#define sc4(x,y,z,w) int x,y,z,w;cin>>x>>y>>z>>w
#define print(x) cout << x << endl 
#define all(x) (x).begin(), (x).end()
#define PQ(T) priority_queue<T>
#define GPQ(T) priority_queue<T,vector<T>,greater<T>>
#define getprime(sz)vector<int> prime; bool isprime[sz + 1]  = {}; memset(isprime, true, sizeof(isprime)); isprime[1] = false; fup(i, 2, (int)sqrt(sz), 1) {\
        if(isprime[i]) prime.pb(i); fup(j, i * i, sz, i) { isprime[j] = false; } }
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e15;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[4] = {-1, 1, 0, 0}; int dy[4] = {0, 0, -1, 1};

// print("===================================");
// printf("dp[%lld][0] : %lld\n", i, dp[i][0]);
// printf("dp[%lld][1] : %lld\n", i, dp[i][1]);
// print("===================================");
signed main() {
   FASTIO();
    sc(N);
    V(pii) adj;
    while(N--) {
        sc2(a, b);
        adj.pb(mp(a, b));
    }
    int dp[100001][2] = {};
    bool flag = true;
    int chk = -1;
    dp[0][0] = adj[0].snd;
    dp[0][1] = 0;
    int mx = adj[0].snd;
    fup(i, 1, adj.size() - 1, 1) {
        int lim = adj[i].fst;
        int val = adj[i].snd;
        // print("lim and val");
        // cout << lim << ' ' << val << endl;
        dp[i][0] = dp[i - 1][0];
        if(dp[i][0] - mx > lim && dp[i][0] < INF) { // 무조건 이거 패스
            chk = i;
            break;
        }
        else {
            dp[i][1] = dp[i][0] - mx;
        }
        if(dp[i][1] > lim) flag = false;
        mx = max(mx, val);
        dp[i][0] += val;
        dp[i][1] += val;
    }
    if(chk != -1) {
        dp[0][0] = adj[0].snd;
        fup(i, 1, adj.size() - 1, 1) {
            if(i == chk) continue;
            int lim = adj[i].fst;
            int val = adj[i].snd;
            dp[i][0] = dp[i - 1][0];
            if(dp[i][0] > lim) flag = false;
            mx = max(mx, val);
            dp[i][0] += val;
        }
    }
    if(flag) print("Kkeo-eok");
    else print("Zzz");
}
