#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 987654321;
     
int N, M;
int sub[1001] = {}; 
int dist[1001][1001] = {};
pii ans[1001] = {};

int main() {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   cin >> N >> M;
   fill(ans, ans + 1001, mp(INF, INF));

   for(int i = 0 ; i < N ; i++) {
      cin >> sub[i];
   }

   for(int i = 0 ; i < N ; i++) {
      for(int j = 0 ; j < N ; j++) {
         cin >> dist[i][j];
      }
   }

   queue<pair<int, pii> > q;
   q.push(mp(0, mp(0, 0)));

   while(!q.empty()) {
      int cur = q.front().first;
      int moved = q.front().second.first;
      int cost = q.front().second.second;
      q.pop();
      if(ans[cur].first < moved) continue;
      if(ans[cur].first == moved && ans[cur].second <= cost) continue;
      ans[cur].first = moved;
      ans[cur].second = cost;

      for(int i = 0 ; i < N ; i++) {
         if(dist[cur][i] != 0) {
            int nxt = i;
            int nxt_cost = cost + dist[cur][i];
            int nxtmove = moved;
            if(sub[cur] != sub[nxt]) nxtmove++;
            if(ans[nxt].first >= nxtmove && ans[nxt].second > nxt_cost) {
               q.push(mp(nxt, mp(nxtmove, nxt_cost)));
            } 
         }
      }
   }
   cout << ans[M].first << ' ' << ans[M].second << endl;
} 