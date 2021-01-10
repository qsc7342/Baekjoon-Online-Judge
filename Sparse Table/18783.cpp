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

signed main() {
   FASTIO();
    sc(N);
    sc(M);
    sc(K);

    int arr[N + 1] = {};
    for(int i = 1 ; i <= N ; i++) {
        arr[i] = i;
    }
    while(M--) {
        sc(a); sc(b);
        reverse(arr + a, arr + b + 1);
    }
    
    int table[N + 1][32] = {};

    for(int i = 1 ; i <= N ; i++) {
        table[i][0] = arr[i];
    }

    for(int i = 1 ; i < 32 ; i++) {
        for(int j = 1 ; j <= N ; j++) {
            table[j][i] = table[table[j][i - 1]][i - 1];
        }
    }
        
    for(int i = 1 ; i <= N ; i++) {
        int cur = i;
        int tmp = K;
        for(int j = 31 ; j >= 0 ; j--) {
            if(tmp >= (int)1 << j) {
                tmp -= 1 << j;
                cur = table[cur][j];
            }
        }
        cout << cur << endl;
    }
}