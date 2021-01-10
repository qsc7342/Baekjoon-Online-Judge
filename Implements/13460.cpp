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

char board[11][11] = {};
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int ans = INF;
int pos_ry, pos_rx, pos_by, pos_bx, pos_hy, pos_hx;
int N, M;

bool isRange(int y, int x) {
    if(y < 0 || y >= N || x < 0 || x >= M) return false;
    else return true;
}

int solve(int pos_ry, int pos_rx, int pos_by, int pos_bx, int step) {
    if(pos_by == pos_hy && pos_bx == pos_hx) return INF;
    if(pos_ry == pos_hy && pos_rx == pos_hx) return step;

    rep(i, 4) {
        int npos_ry, npos_rx, npos_by, npos_bx;
        bool bluein = false;
        bool redin = false;
        npos_ry = pos_ry;
        npos_rx = pos_rx;
        npos_by = pos_by;
        npos_bx = pos_bx;
        int moveblue = 0;
        int movered = 0;
        while(board[npos_by + dy[i]][npos_bx + dx[i]] != '#') {
            npos_by = npos_by + dy[i];
            npos_bx = npos_bx + dx[i];
            if(npos_by == pos_hy && npos_bx == pos_hx) {
                bluein = true;
            }
            moveblue++;
        }
        while(board[npos_ry + dy[i]][npos_rx + dx[i]] != '#') {
            npos_ry = npos_ry + dy[i];
            npos_rx = npos_rx + dx[i];
            if(npos_ry == pos_hy && npos_rx == pos_hx) {
                redin = true;
            }
            movered++;
        }
        if(bluein && redin) {
            continue;
        }
        else if(bluein)  {
            continue; 
        }
        else if(redin) {
            ans = min(ans, step + 1);
            continue; 
        }
        else {
            if( (npos_by == npos_ry) && (npos_bx == npos_rx)) {
                if(movered > moveblue) {
                    npos_ry -= dy[i];
                    npos_rx -= dx[i];
                }
                else if(movered < moveblue) {
                    npos_by -= dy[i];
                    npos_bx -= dx[i];
                }
            }
            ans = min(ans, solve(npos_ry, npos_rx, npos_by, npos_bx, step + 1));
        }
    }
    return ans;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    rep(i, N) {
        rep(j, M) {
            cin >> board[i][j];
            if(board[i][j] == 'B') {
                pos_by = i;
                pos_bx = j;
            }

            if(board[i][j] == 'R') {
                pos_ry = i;
                pos_rx = j;
            }

            if(board[i][j] == 'O') {
                pos_hy = i;
                pos_hx = j;
            }
        }
    }
    int ret = solve(pos_ry, pos_rx, pos_by, pos_bx, 0);
    if(ret == INF) {
        cout << "-1" << endl;
    }
    else {
        cout << ret << endl;
    }
    return 0;
}