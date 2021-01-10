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


vector<vector<pii> > adj(40005);
int par[40005][20] = {};
int depth[40005] = {};
bool visit[40005] = {};
int dist[40005] = {};
void foo(int node, int cost) {
    for(auto x : adj[node]) {
        if(depth[x.fst]) continue;
        depth[x.fst] = depth[node] + 1;
        par[x.fst][0] = node;
        dist[x.fst] = cost + x.snd;
        foo(x.fst, cost + x.snd);
    }
}
signed main() {
    FASTIO();
    sc(N);
    rep(i, N - 1) {
        sc3(a, b, c);
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    depth[1] = 1;
    MEM_1(par);
    foo(1, 0);

    for(int i = 0 ; i < 20 ; i++) {
        for(int j = 1 ; j <= N ; j++) {
            if(par[j][i] != -1) {
                par[j][i + 1] = par[par[j][i]][i];
            }
        }
    }
    sc(M);

    while(M--) {
        sc2(a, b);
        if(depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        int tmpa = a;
        int tmpb = b;
        // cout << "diff : " << diff << endl;
        // cout << "A  : " << a << endl;
        // cout << "b : " << b << endl;
        // cout << "a's parent : " << par[a][0] << endl;
        rep(i, 20) {
            if((1<<i)&diff) a = par[a][i];
        }
        int ans = 0;
        // cout << "a : " << a << endl;
        // cout << "b : " << b << endl;
        if(a == b) { // b가 a의 조상
            ans = abs(dist[tmpa] - dist[b]); 
            // cout << dist[tmpa] << ' ' << dist[b] << endl;
        }
        else if(a != b) {
            for(int i = 19 ; i >= 0 ; i--) {
                if(par[a][i] != -1 && par[a][i] != par[b][i]) {
                    a = par[a][i];
                    b = par[b][i];
                }
            }
            int lca = par[a][0];
            ans += abs(dist[tmpa] - dist[lca]);
            ans += abs(dist[tmpb] - dist[lca]);
        }
        print(ans);
    }
    return 0;
}



