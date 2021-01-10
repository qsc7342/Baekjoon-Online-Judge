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
   str W, S;
   str ans;
   cin >> W >> S;
   sc(N);
   DQ(char) dq;
   rep(i, S.size()) {
       dq.pb(S[i]);
   } 
    S(char) left;
    S(char) right;
    int success = 0;
    int pi[W.size()] = {};
    int j = 0;
    fup(i, 1, W.size() - 1, 1) {
        while(j > 0 && W[i] != W[j]) j = pi[j - 1];
        if(W[i] == W[j]) pi[i] = ++j;
    }
    while(N--) {
        char c;
        cin >> c;
      //  cout << "size : " << dq.size() << endl;
      /*
        print("=======================");
        cout << "command : " << c << endl;
        cout << "dq : ";
        for(auto x : dq) {
            cout << x;
        }
        cout << endl;
        print("=======================");
        */
        if(c == 'L') {
            int pos = 0;
            while(1) {
                if(dq.empty()) break;
                if(dq[0] == W[pos]) {
                    pos++;
                }
                else {
                    while(pos > 0 && dq[0] != W[pos]) {
                        pos = pi[pos - 1];
                    }
                    if(dq[0] == W[pos]) {
                        pos++;
                    }
                }
                left.push(dq[0]);
                dq.pop_front();
                if(pos == W.size()) {
                    success++;
                    int cnt = W.size();
                    while(cnt--) {
                        left.pop();
                    }
                    cnt = W.size();
                    while(cnt > 0 && !left.empty()) {
                        dq.push_front(left.top());
                        left.pop();
                        cnt--;
                    }
                    break;
                }
            }
        }

        else if(c == 'R') {
            int pos = W.size() - 1;
            while(1) {
                if(dq.empty()) break;
                if(dq.back() == W[pos]) {
                    pos--;
                }
                else {
                    while(pos < W.size() - 1 && dq.back() != W[pos]) {
                        pos = (W.size() - 1) - pi[pos - 1];
                    }
                    if(dq.back() == W[pos]) {
                        pos--;
                    }
                }
                right.push(dq.back());
                dq.pop_back();
                if(pos == -1) {
                    success++;
                    int cnt = W.size();
                    while(cnt--) {
                        right.pop();
                    }
                    cnt = W.size();
                    while(cnt > 0 && !right.empty()) {
                        dq.push_back(right.top());
                        right.pop();
                        cnt--;
                    }
                    break;
                }
            }
        }
    }

    while(!left.empty()) {
        dq.push_front(left.top());
        left.pop();
    }
    while(!right.empty()) {
        dq.push_back(right.top());
        right.pop();
    }
    for(auto x : dq) {
        ans += x;
    }

    bool flag = true;
    j = 0;
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
