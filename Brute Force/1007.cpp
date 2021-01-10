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

vector<pii> pick;
bool visit[21] = {};
long double ans = INF;
int N;
vector<pii> point;

void solve(int pos, int picked) {
   if(picked == N / 2) {
      vector<pii> npick;
      for(int i = 0  ; i < N ; i++) {
         if(!visit[i]) {
            npick.pb(mp(point[i].fst, point[i].snd));
         }
      }
      int y2,y1,x2,x1;
      y2 = y1 = x2 = x1 = 0;
      for(int i = 0 ; i < pick.size() ; i++) {
         y2 += pick[i].fst;
         x2 += pick[i].snd;
         y1 += npick[i].fst;
         x1 += npick[i].snd;
      }
      long double val = sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
      ans = min(ans, val);
      return;   
   }
   for(int i = pos ; i < point.size() ; i++) {
      int cy  = point[i].fst;
      int cx = point[i].snd;
      pick.pb(mp(cy, cx));
      visit[i] = true;
      solve(i + 1, picked + 1);
      pick.pop_back();
      visit[i] = false;
   }
   return;
}

signed main() {
   FASTIO();
   TC() {
      cin >> N;
      ans = INF;
      pick.clear();
      point.clear();
      memset(visit, false, sizeof(visit));
      int tmp = N;
      while(tmp--) {
         sc(y);
         sc(x);
         point.pb(mp(y, x));
      }
      solve(0, 0);
      cout << fixed;
      cout.precision(10);
      cout << ans << endl;
   }   
}