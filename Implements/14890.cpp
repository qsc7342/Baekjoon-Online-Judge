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
   sc(N);
   sc(L);
   int ans = 0;
   int board[101][101] = {};

   for(int i = 1 ; i <= N ; i++) {
    for(int j = 1 ; j <= N ; j++) {
      cin >> board[i][j];
    }
   }
   for(int i = 1 ; i <= N ; i++) {
    bool flag = true;
    for(int j = 2 ; j <= N ; j++) {
      if(abs(board[i][j] - board[i][j - 1]) > 1) flag = false;
    }
    if(!flag) continue;
    for(int j = 1 ; j <= 10 ; j++) {
      bool start = false;
      int cur = 1;
      int stx, destx;
      bool fi = false;
      stx = destx = -1;
      for(int k = 1 ; k <= N ; k++) {
        if(board[i][k] == j) {
          if(start == false) {
            start = true;
            stx = k;
            cur = 1;
          }
          else if(start == true) {
            cur++;
          }
        }
        if(board[i][k] != j || k == N) {
          if(start == true || k == N) {
            destx = k;
            if(k == N && board[i][k] == j) fi = true;
          }
        }
        if(stx != -1 && destx != -1) {
          if((board[i][stx] < board[i][max((int)1, stx - 1)] && abs(board[i][max((int)1, stx - 1)] - board[i][stx]) == 1) && (fi == false && (abs(board[i][max((int)1, destx - 1)] - board[i][destx]) == 1 && board[i][max((int)1, destx - 1)] < board[i][destx]))) {
            if(cur < 2 * L) {
              flag = false;
            }
            else {
              stx = -1;
              destx = -1;
              start = false;
              fi = false;
            }
          }
          else if((board[i][stx] < board[i][max((int)1, stx - 1)] && abs(board[i][max((int)1, stx - 1)] - board[i][stx]) == 1) || (fi == false && (abs(board[i][max((int)1, destx - 1)] - board[i][destx]) == 1 && board[i][max((int)1, destx - 1)] < board[i][destx]))) {
            if(cur < L) {
              flag = false;
            }
            else {
              stx = -1;
              destx = -1;
              start = false;
              fi = false;
            }  
          }
          else {
              stx = -1;
              destx = -1;
              start = false;
              fi = false;
          }
        }
      }
      if(!flag) break;
    }
    if(flag) {
      ans++;
    }
   }


   for(int i = 1 ; i <= N ; i++) {
    bool flag = true;
    for(int j = 2 ; j <= N ; j++) {
      if(abs(board[j][i] - board[j - 1][i]) > 1) flag = false;
    }
    if(!flag) continue;
    for(int j = 1 ; j <= 10 ; j++) {
      bool start = false;
      int cur = 1;
      int stx, destx;
      bool fi = false;
      stx = destx = -1;
      for(int k = 1 ; k <= N ; k++) {
        if(board[k][i] == j) {
          if(start == false) {
            start = true;
            stx = k;
            cur = 1;
          }
          else if(start == true) {
            cur++;
          }
        }
        if(board[k][i] != j || k == N) {
          if(start == true || k == N) {
            destx = k;
            if(k == N && board[k][i] == j) fi = true;
          }
        }
        if(stx != -1 && destx != -1) {
          if((board[stx][i] < board[max((int)1, stx - 1)][i] && abs(board[max((int)1, stx - 1)][i] - board[stx][i]) == 1) && (fi == false && (abs(board[max((int)1, destx - 1)][i] - board[destx][i]) == 1 && board[max((int)1, destx - 1)][i] < board[destx][i]))) {
            if(cur < 2 * L) {
              flag = false;
            }
            else {
              stx = -1;
              destx = -1;
              start = false;
              fi = false;
            }
          }
          else if((board[stx][i] < board[max((int)1, stx - 1)][i] && abs(board[max((int)1, stx - 1)][i] - board[stx][i]) == 1) || (fi == false && (abs(board[max((int)1, destx - 1)][i] - board[destx][i]) == 1 && board[max((int)1, destx - 1)][i] < board[destx][i]))) {
            if(cur < L) {
              flag = false;
            }
            else {
              stx = -1;
              destx = -1;
              start = false;
              fi = false;
            }  
          }
          else {
              stx = -1;
              destx = -1;
              start = false;
              fi = false;
          }
        }
      }
      if(!flag) break;
    }
    if(flag) {
      ans++;
    }
   }
   cout << ans << endl;
}