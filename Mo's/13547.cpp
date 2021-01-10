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

int arr[100005] = {};
int sz;
int sz2 = (int)sqrt(1000000);
int cnt[1000005] = {};
int root[1005] = {};
int ans[100005] = {};
vector<pair<pii, int> > q;

bool compare(pair<pii, int> a, pair<pii, int> b) {
    if(a.fst.fst/sz != b.fst.fst/sz) return a.fst.fst/sz < b.fst.fst/sz;
    return a.fst.snd < b.fst.snd;
}

void in(int x) {
    if(cnt[arr[x]] == 0) root[arr[x] / sz2]++;
    cnt[arr[x]]++;
}

void out(int x) {
    if(cnt[arr[x]] == 1) root[arr[x] / sz2]--;
    cnt[arr[x]]--;
}

int solve() {
    int sum = 0;
    rep(i, 1001) sum += root[i];
    return sum;
}

signed main() {
    FASTIO();

    sc(N);

    fup(i, 1, N, 1) {
        cin >> arr[i];
    }

    sz = (int)sqrt(N);

    sc(Q);

    fup(i, 0, Q - 1, 1) {
        sc2(a, b);
        q.pb(mp(mp(a, b), i));
    }

    sort(all(q), compare);

    int x = q[0].fst.fst;
    int y = q[0].fst.snd;

    fup(i, x, y, 1) in(i);
    ans[q[0].snd] = solve();
    fup(i, 1, Q - 1, 1) {
        while(q[i].fst.snd > y) in(++y);
        while(q[i].fst.fst < x) in(--x);
        while(q[i].fst.snd < y) out(y--);
        while(q[i].fst.fst > x) out(x++);
        ans[q[i].snd] = solve();
    }
    fup(i, 0, Q - 1, 1) {
        print(ans[i]);
    }
}
