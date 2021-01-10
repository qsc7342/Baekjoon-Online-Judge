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


signed main() {
    FASTIO();
    sc2(N, P);
    int sink = 2;
    int source = 1;
    V(V(int)) adj(401);
    int c[401][401] = {};
    int f[401][401] = {};
    while(P--) {
        sc2(a, b);
        c[a][b] = 1;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int ans = 0;
    while(1) {
        Q(int) q;
        int parent[401] = {};
        MEM_1(parent);
        parent[source] = source;
        q.push(source);

        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(auto x : adj[cur]) {
                if(c[cur][x] - f[cur][x] > 0 && parent[x] == -1) {
                    parent[x] = cur;
                    q.push(x);
                    if(x == sink) break;
                }
            }
        }
        if(parent[sink] == -1) break;
        int flow = INF;
        for(int i = sink ; i != source ; i = parent[i]) {
            flow = min(flow, c[parent[i]][i] - f[parent[i]][i]);
        }
        for(int i = sink ; i != source ; i = parent[i]) {
            f[parent[i]][i] += flow;
            f[i][parent[i]] -= flow;
        }
        ans += flow;
    }

    print(ans);
}
