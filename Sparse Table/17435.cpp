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
   sc(m);
   int arr[m + 1][19] = {};

   for(int i = 1 ; i <= m ; i++) {
       cin >> arr[i][0];
   }

   for(int i = 1 ; i < 19 ; i++) {
       for(int j = 1 ; j <= m ; j++) {
           arr[j][i] = arr[arr[j][i - 1]][i - 1];
       }
   }
   sc(Q);
   while(Q--) {
       sc(n); sc(x);
        for(int i = 18 ; i >= 0 ; i--) {
            if(n >= 1 << i) {
                n -= 1<<i;
                x = arr[x][i];
            }
        }
        cout << x << endl;
   }
}