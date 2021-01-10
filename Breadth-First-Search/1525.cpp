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
set<string> st;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};

bool isRange(int y, int x) {
   if(y < 0 || y >= 3 || x < 0 || x >= 3) return false;
   else return true;
}

int main() {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   string s;
   for(int i = 0 ; i < 9 ; i++) {
      char c;
      cin >> c;
      s += c;
   }
   if(s == "123456780") {
      cout << "0" << endl;
      return 0;
   }

   queue<pair<string,int> > q;
   q.push(mp(s, 0));
   int ans = -1;
   while(!q.empty()) {
      string cur = q.front().first;
      int move = q.front().second;
      q.pop();
      if(st.find(cur) != st.end()) continue;
      st.insert(cur);
      if(cur == "123456780") {
         ans = move;
         break;
      }
      char board[3][3] = {};
      int x = 0;
      int y = 0;
      pii pos;
      for(int i = 0 ; i < cur.size() ; i++) {
         if(cur[i] == '0') {
            pos.first = y;
            pos.second = x;
         }
         board[y][x] = cur[i];
         x++;
         if(x == 3) {
            x = 0;
            y++;
         }
      }

      for(int i = 0 ; i < 4 ; i++) {
         int ny = pos.first + dy[i];
         int nx = pos.second + dx[i];
         if(isRange(ny, nx)) {
            swap(board[ny][nx], board[pos.first][pos.second]);
            string tmp;
            for(int i = 0 ; i < 3 ; i++) {
               for(int j = 0 ; j < 3; j++) {
                  tmp += board[i][j];
               }
            }
            q.push(mp(tmp, move + 1));
            swap(board[ny][nx], board[pos.first][pos.second]);
         }
      }
   }
   cout << ans << endl;
}