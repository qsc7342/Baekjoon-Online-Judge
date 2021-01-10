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

int board[9][9] = {};
bool check_col[9][10] = {};
bool check_row[9][10] = {};
bool check_box[9][10] = {};

int calc_box(int col, int row) {
  return (col / 3) * 3 + (row / 3);
}

bool solve(int pos) {
  if(pos == 81) {
    rep(i, 9) {
      rep(j, 9) {
        cout << board[i][j] << ' ';
      }
      cout << endl;
    }
    return true;
  }
  int row = pos % 9;
  int col = pos / 9;
  if(board[col][row] != 0) {
    return solve(pos + 1);
  }
  else {
    for(int i = 1 ; i <= 9 ; i++) {
      if(check_row[row][i] == false && check_col[col][i] == false && check_box[calc_box(col, row)][i] == false) {
        check_row[row][i] = check_col[col][i] = check_box[calc_box(col, row)][i] = true;
        board[col][row] = i;
        if(solve(pos + 1) == true) {
          return true;
        }
        board[col][row] = 0;
        check_row[row][i] = check_col[col][i] = check_box[calc_box(col, row)][i] = false;   
      }
    }
  }
  return false;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  rep(i, 9) {
    rep(j, 9) {
      cin >> board[i][j];
      check_col[i][board[i][j]] = true;
      check_row[j][board[i][j]] = true;
      check_box[calc_box(i, j)][board[i][j]] = true;
    }
  }
  solve(0);
}