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
#define MOD 1000000
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

int mul[3][3] = {};
int ans[3][3] = {};
int chk[3][3] = {};
void foo(int N, int a[3][3], int b[3][3]) {
    MEM0(chk);
    fup(i, 1, 2, 1) {
        fup(j, 1, 2, 1) {
            fup(k, 1, 2, 1) {
                chk[i][j] += (a[i][k] % MOD) * (b[k][j] % MOD);
            }
            chk[i][j] %= MOD;
        }
    }

    fup(i, 1, 2, 1) {
        fup(j, 1, 2, 1) {
            a[i][j] = chk[i][j];
        }
    }
    return;
}
signed main() {
    FASTIO();
    sc(N);
    mul[1][1] = 1;
    mul[1][2] = 1;
    mul[2][1] = 1;
    mul[2][2] = 0;
    fup(i, 1, 2, 1) ans[i][i] = 1;

    if(N == 0) {
        print("0");
        return 0;
    }
    else if(N == 1) {
        print("1");
        return 0;
    }
    else if(N == 2) {
        print("1");
        return 0;
    }
    else {
        int p = N - 2;
        while(p > 0) {
            if(p % 2 == 1) {
                foo(N, ans, mul);
            }
            foo(N, mul, mul);
            p /= 2; 
        }
        int ret = 0;
        ret += (ans[1][1] * 1) % MOD + (ans[1][2] * 1) % MOD;
        print(ret % MOD);
    }
}
