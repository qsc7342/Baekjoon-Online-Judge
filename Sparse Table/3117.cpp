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

int table[100001][31] = {};
signed main() {
   FASTIO();
    sc(N); sc(K); sc(M);
    int move[N + 1] = {};    
    rep(i, N) {
        cin >> move[i + 1];
    }
    rep(i, K) {
        cin >> table[i + 1][0];
    }
    for(int i = 1 ; i < 31 ; i++) {
        for(int j = 1 ; j <= K ; j++) {
            table[j][i] = table[table[j][i - 1]][i - 1];
        }
    }
    for(int i = 1 ; i <= N ; i++) {
        int ans = move[i];
        int tmp = M - 1;
        for(int j = 30 ; j >= 0 ; j--) {
            if(tmp >= 1 << j) {
                tmp -= 1 << j;
                ans = table[ans][j];
            }
        }
        cout << ans << ' ';
    }
    cout << endl;
}