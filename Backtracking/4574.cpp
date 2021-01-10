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
bool use[10][10] = {};
bool check_col[9][10] = {};
bool check_row[9][10] = {};
bool check_box[9][10] = {};
int N;
int dx[2] = {1, 0};
int dy[2] = {0, 1};
int cnt = 1;

bool isRange(int y, int x) {
  if(y >= 9 || y < 0 || x >= 9 || x < 0) return false;
  else return true;
}

pii getpos(string pos) {
  return mp(pos[0] - 'A', pos[1] - '1');
}

int calc_box(int col, int row) {
  return (col / 3) * 3 + (row / 3);
}

bool solve(int pos) {
  if(pos == 81) {
    rep(i, 9) {
      rep(j, 9) {
        cout << board[i][j];
      }
      cout << endl;
    }
    return true;
  }
  int col = pos / 9;
  int row = pos % 9;

  if(board[col][row] != 0) {
    return solve(pos + 1);
  }
  else {
    for(int k = 0 ; k < 2 ; k++) {
      int n_col = col + dy[k];
      int n_row = row + dx[k];
      if(!isRange(n_col, n_row)) {
        continue;
      }
    if(board[n_col][n_row] != 0) continue;
      for(int i = 1 ; i <= 9 ; i++) {
        for(int j = 1 ; j <= 9 ; j++) {
          if(i == j) continue;
          if(use[i][j]) continue;
          if(check_row[row][i] == false && check_col[col][i] == false && check_box[calc_box(col, row)][i] == false && check_col[n_col][j] == false && check_row[n_row][j] == false && check_box[calc_box(n_col, n_row)][j] == false) {
            check_row[row][i] = check_col[col][i] = check_box[calc_box(col, row)][i] = true;
            check_col[n_col][j] = check_row[n_row][j] = check_box[calc_box(n_col, n_row)][j] = true;
            use[i][j] = use[j][i] = true;
            board[col][row] = i;
            board[n_col][n_row] = j;
            if(solve(pos + 1) == true) {
              return true;
            }
            check_row[row][i] = check_col[col][i] = check_box[calc_box(col, row)][i] = false;
            check_col[n_col][j] = check_row[n_row][j] = check_box[calc_box(n_col, n_row)][j] = false;
            use[i][j] = use[j][i] = false;
            board[col][row] = 0;
            board[n_col][n_row] = 0;
          }
        }
      }
    }
  }
  return false;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;

  while(N != 0) {
    memset(check_row, false, sizeof(check_row));
    memset(check_col, false, sizeof(check_col));
    memset(check_box, false, sizeof(check_box));
    memset(board, 0, sizeof(board));
    memset(use, false, sizeof(use));
    rep(i, N) {
      int num1, num2;
      string pos1, pos2;
      cin >> num1 >> pos1 >> num2 >> pos2;
      int col1, row1, col2, row2;
      col1 = getpos(pos1).first;
      row1 = getpos(pos1).second;
      col2 = getpos(pos2).first;
      row2 = getpos(pos2).second;
      check_row[row1][num1] = true;
      check_col[col1][num1] = true;
      check_row[row2][num2] = true;
      check_col[col2][num2] = true;
      check_box[calc_box(col1, row1)][num1] = true;
      check_box[calc_box(col2, row2)][num2] = true;
      use[num1][num2] = true;
      use[num2][num1] = true;
      board[col1][row1] = num1;
      board[col2][row2] = num2; 
    }
    for(int j = 1 ; j <= 9 ; j++) {
        string pos3;
        cin >> pos3;
        int col3, row3;
        col3 = getpos(pos3).first;
        row3 = getpos(pos3).second;
        check_row[row3][j] = true;
        check_col[col3][j] = true;
        check_box[calc_box(col3, row3)][j] = true;
        board[col3][row3] = j;
    }
    cout << "Puzzle " << cnt++ << endl;
    solve(0);
    cin >> N;
  }
}