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

int N;
int board[105][105] = {};
int moved[105][105] = {};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visit[105][105] = {};
int ans = INF;
bool visit2[105][105] = {};
vector< vector<pii> > island(100001);
int cnt = 2;
int stt = 0;
bool isRange(int y, int x) {
   if(y <= 0 || y > N || x <= 0 || x > N) return false;
   else return true;
}
void dfs(int y, int x) {
   island[stt].pb(mp(y, x));
   visit2[y][x] = true;
   board[y][x] = cnt;
   for(int i = 0 ; i < 4 ; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(isRange(ny, nx) && board[ny][nx] == 1 && visit2[ny][nx] == false) {
         visit2[y][x] = true;
         dfs(ny, nx);
      }
   }
}
int main() {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   cin >> N;
   for(int i = 1 ; i <= N ; i++) {
      for(int j = 1 ; j <= N ; j++) {
         cin >> board[i][j];
         moved[i][j] = INF;
      }
   }
   queue<pair<pii, int> > q;
   for(int i = 1 ; i <= N ; i++) {
      for(int j = 1 ; j <= N ; j++) {
         if(board[i][j] == 1 && visit2[i][j] == false) {
            dfs(i, j);
            cnt++;
            stt++;
         }
      }
   }

   for(int i = 0 ; i < island.size() ; i++) {
      for(int j = 0 ; j < island[i].size() ; j++) {
         queue<pair<pii, int> > q;
         memset(visit, false, sizeof(visit));
         int st = board[island[i][j].first][island[i][j].second];
         q.push(mp(mp(island[i][j].first, island[i][j].second), 0));
         bool flag = false;
         while(!q.empty()) {
            int cury = q.front().first.first;
            int curx = q.front().first.second;
            int move = q.front().second;
            if(island[i][j].first == 3 && island[i][j].second == 9) {
            }
            q.pop();
            visit[cury][curx] = true;
            if(board[cury][curx] == st) {
               move = 0;
            }
            else if(board[cury][curx] != 0 && board[cury][curx] != st) {
               if(move > 0) {
                  if(ans > move) {
                  }
                  ans = min(ans, move);
                  continue;
               } 
            }
            for(int i = 0 ; i < 4 ; i++) {
               int ny = cury + dy[i];
               int nx = curx + dx[i];
               if(!isRange(ny, nx)) continue;
               if(visit[ny][nx]) continue;
               visit[ny][nx] = true;
               if(board[ny][nx] == 0) q.push(mp(mp(ny, nx), move + 1));
               else q.push(mp(mp(ny, nx), move));
            }
         }
      }
      // cout << "cur start : " << island[i].first << ' ' << island[i].second << endl;
      // cout << "ans : " << ans << endl;
   }
   cout << ans << endl;
}  