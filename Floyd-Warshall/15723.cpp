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
#define PQ(T) priority_queue<T> // 맥스힙
#define GPQ(T) priority_queue<T,vector<T>,greater<T>> // 민힙
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e15;

signed main() {
   FASTIO();
   sc(n);
   int dist[27][27] = {};
   for(int i = 0 ; i <= 26 ; i++) {
    for(int j = 0 ; j <= 26 ; j++) {
      dist[i][j] = INF;
    }
   }
   rep(i, n) {
    char a, b;
    string is;
    cin >> a >> is >> b;
    dist[a - 'a'][b - 'a'] = 1;
   }

   for(int k = 0 ; k <= 26 ; k++) {
    for(int i = 0 ; i <= 26 ; i++) {
      for(int j = 0 ; j <= 26 ; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
   }

   sc(m);
   while(m--) {
    char a, b;
    string is;
    cin >> a >> is >> b;

    if(dist[a - 'a'][b - 'a'] == INF) {
      cout << "F" << endl;
    }
    else {
      cout << "T" << endl;
    }
   }
}