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

int arr[4000001] = {};
int N, M, K;
int sz = (int)sqrt(4000000) + 1;
int chk[4000001] = {};
int cnt[(int)sqrt(4000000) + 1] = {};
int x;
V(V(int)) root(sz);

void foo(int x) {
    int cur = x / sz;
    for(auto c : root[cur]) {
        if(chk[c] == -1 && c > x) {
            chk[c] = 0;
            print(c);
            cnt[cur]--;
            return;
        }
    }
    cur++;
    while(cnt[cur] == 0) cur++;
    for(auto c : root[cur]) {
        if(chk[c] == -1 && c > x) {
            chk[c] = 0;
            print(c);
            cnt[cur]--;
            return;
        }
    }
}

signed main() {
    FASTIO();
    cin >> N >> M >> K;
    fup(i, 1, M, 1) {
        sc(tt);
        chk[tt] = -1;
        cnt[tt/sz]++;
    }

    fup(i, 1, N, 1) {
        root[i/sz].pb(i);
    }

    while(K--) {
        cin >> x;
        foo(x);
    }
}
