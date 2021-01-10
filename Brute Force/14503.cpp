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

int T;
int py, px, dir;
int r, c;
int board[51][51] = {};
bool visited[51][51] = {};

void turn() {
   if(dir == 0) dir = 3;
   else if(dir == 1) dir = 0;
   else if(dir == 2) dir = 1;
   else if(dir == 3) dir = 2;
   return;
}
int main() {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   cin >> r >> c;
   cin >> py >> px >> dir;

   for(int i = 0 ; i < r ; i++) {
      for(int j = 0 ; j < c ; j++) {
         cin >> board[i][j];
      }
   }
   // 0north, 1east , 2south , 3west
   int ans = 0;
   int cc = 0;
   int dy[4] = {-1, 1, 0, 0};
   int dx[4] = {0, 0, -1 ,1};
   while(1) {
      if(visited[py][px] == false) {
         visited[py][px] = true;
         ans++;
      }
      bool allclean = true;
      bool allwall = true;
      for(int i = 0 ; i < 4 ; i++) {
         int ny = py + dy[i];
         int nx = px + dx[i];
         if(board[ny][nx] == 0) {
          //  cout << "not wall : " << ny << ' ' << nx << endl;
            allwall = false;
         }
         if(board[ny][nx] == 0 && visited[ny][nx] == 0) {
            allclean = false;
         }
      }
      if(allwall) {
         cout << ans << endl;
         return 0;
      }
      if(allclean) {
         if(dir == 0) {
            if(board[py + 1][px] == 1) {
               cout << ans << endl;
               return 0;
            }
            else {
               py++;
               continue;
            }
         }

         else if(dir == 1) {
            if(board[py][px - 1] == 1) {
               cout << ans << endl;
               return 0;
            }
            else {
               px--;
               continue;
            }
         }
         else if(dir == 2) {
            if(board[py - 1][px] == 1) {
               cout << ans << endl;
               return 0;
            }
            else {
               py--;
               continue;
            }
         }

         else if(dir == 3) {
            if(board[py][px + 1] == 1) {
               cout << ans << endl;
               return 0;
            }
            else {
               px++;
               continue;
            }
         }
      }
      if(dir == 0) {
         bool f = false;
         int i = px - 1;
         if(board[py][i] == 0 && visited[py][i] == false) {
            f = true;
         }
         turn();
         if(!f) {
            cc++;
            continue;
         }
         if(f) {
            px--;
         }
      }
      else if(dir == 1) {
         bool f = false;
         int i = py - 1;
         if(board[i][px] == 0 && visited[i][px] == false) {
            f = true;
         }
         turn();
         if(!f) {
            cc++;
            continue;
         }
         if(f) {
            py--;
         }
      }
      else if(dir == 2) {
         bool f = false;
         int i = px + 1;
         if(board[py][i] == 0 && visited[py][i] == false) {
            f = true;
         }
         turn();
         if(!f) {
            cc++;
            continue;
         }
         if(f) {
            px++;
         }
      }
      else if(dir == 3) {
         bool f = false;
         int i = py + 1;
         if(board[i][px] == 0 && visited[i][px] == false) {
            f = true;
         }
         turn();
         if(!f) {
            cc++;
            continue;
         }
         if(f) {
            py++;
         }
      }
   }
} 