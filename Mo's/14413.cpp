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

int n, t;
vector<pair<pii, int> > adj;
int arr[500001] = {};
int sz = (int)sqrt(500001);
int ans[500001] = {};
int cnt[500001] = {};
bool compare(pair<pii, int> a, pair<pii, int> b) {
    if(a.fst.fst/sz != b.fst.fst/sz) return a.fst.fst/sz < b.fst.fst/sz;
    return a.fst.snd < b.fst.snd;
}

signed main() {
    FASTIO();
    cin >> n >> t;
    fup(i, 1, n, 1) {
        cin >> arr[i];
    }
    rep(i, t) {
        sc2(l, r);
        adj.pb(mp(mp(l, r), i));
    }
    sort(all(adj), compare);
    int st = adj[0].fst.fst;
    int en = adj[0].fst.snd;
    int idx = adj[0].snd;
    int cur = 0;
    fup(i, st, en, 1) {
        if(cnt[arr[i]] == 1) cur++;
        if(cnt[arr[i]] == 2) cur--;
        cnt[arr[i]]++;
    }
    ans[idx] = cur;

    fup(i, 1, t - 1, 1) {
        int nen = adj[i].fst.snd;
        int nst = adj[i].fst.fst;
        int nidx = adj[i].snd;
        while(nen > en) {
            ++en;
            if(cnt[arr[en]] == 1) cur++;
            if(cnt[arr[en]] == 2) cur--;
            cnt[arr[en]]++;
        }
        while(nst < st) {
            --st;
            if(cnt[arr[st]] == 1) cur++;
            if(cnt[arr[st]] == 2) cur--;
            cnt[arr[st]]++;
        }
        while(en > nen) {
            if(cnt[arr[en]] == 2) cur--;
            if(cnt[arr[en]] == 3) cur++;
            cnt[arr[en]]--;
            en--;
        }
        while(st < nst) {
            if(cnt[arr[st]] == 2) cur--;
            if(cnt[arr[st]] == 3) cur++;
            cnt[arr[st]]--;
            st++;
        }
        ans[nidx] = cur;
    }
    
    rep(i, t) {
        print(ans[i]);
    }
}
