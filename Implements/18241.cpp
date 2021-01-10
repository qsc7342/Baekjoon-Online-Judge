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

DQ(char) dq;
DQ(char) left2;
DQ(char) right2;

void printleft2() {
    print("this is left2");
    for(auto x : left2) cout << x;
    
    cout << endl;
    cout << endl;
}
void printright2() {
    print("this is right2");
    for(auto x : right2) cout << x;
    
    cout << endl;
    cout << endl;
}
void printdq() {
    print("this is dq");
    for(auto x : dq) cout << x;
    
    cout << endl;
    cout << endl;
}
signed main() {
   FASTIO();
   str W, S;
   str ans;
   cin >> W >> S;
   str revW = W;
   reverse(all(revW));
   int sz = W.size();
   sc(N);
   rep(i, S.size()) {
       dq.pb(S[i]);
   } 
    int pi[W.size()] = {};
    int j = 0;
    int failure = 0;
    int success = 0;
    fup(i, 1, W.size() - 1, 1) {
        while(j > 0 && W[i] != W[j]) j = pi[j - 1];
        if(W[i] == W[j]) pi[i] = ++j;
    }
    
    while(N--) {
        char c;
        cin >> c;
        if(c == 'L') {
            while(1) {
                if(dq.empty()) {
                    failure++;
                    break;
                }
                left2.pb(dq[0]);
                dq.pop_front();
                if(left2.size() >= sz) {
                    str tmp;
                    int tmp2 = left2.size();
                    fdn(i, tmp2 - 1, tmp2 - sz, 1) {
                        tmp += left2[i];
                    }
                    if(tmp == revW) {
                        success++;
                        int k = sz;
                        while(k--) {
                            left2.pop_back();
                        }
                        break;
                    }
                }
            }
        }
        else if(c == 'R') {
            while(1) {
                if(dq.empty()) {
                    failure++;
                    break;
                }
                right2.pb(dq.back());
                dq.pop_back();
                if(right2.size() >= sz) {
                    str tmp;
                    int tmp2 = right2.size();
                    fdn(i, tmp2 - 1, tmp2 - sz, 1) {
                        tmp += right2[i];
                    }
                    if(tmp == W) {
                        success++;
                        int k = sz;
                        while(k--) {
                            right2.pop_back();
                        }
                        break;
                    }
                }
            }
        }
    }
    for(auto x : dq) {
        left2.pb(x);
    }
    reverse(all(right2));
    while(!left2.empty()) {
        if(right2.size() >= sz) {
            while(1) {
                bool chk = false;
                str tmp;
                rep(i, sz) {
                    tmp += right2[i];
                }
                if(tmp == W && failure > 0) {
                    chk = true;
                    failure--;
                    success++;
                    int k = sz;
                    while(k--) {
                        right2.pop_front();
                    }
                }
                if(!chk) break;
            }
        }
        right2.push_front(left2.back());
        left2.pop_back();
    }

    for(auto x : right2) {
        ans += x;
    }
    j = 0;
    bool flag = true;
    rep(i, ans.size()) {
        while(j > 0 && ans[i] != W[j]) j = pi[j - 1];
        if(ans[i] == W[j]) {
            if(j == W.size() - 1) {
                flag = false;
                break;
            }
            j++;
        }
    }
     print(success);
     print(ans);
     if(flag) {
         print("Perfect!");
     }
     else {
         print("You Lose!");
    }
}
