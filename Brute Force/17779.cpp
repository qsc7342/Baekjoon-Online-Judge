#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
int tmp[21][21] = {};
bool visit[21][21] = {};
int cy, cx, ty, tx;
ll ans = 987654321;

void solve(int y, int x, int d1, int d2) {
	int board[21][21] = {};
	if(y + d1 + d2 > N || x - d1 <= 0 || x + d2 > N) return;
	int cnt[21] = {};
	vector<int> adj(5, 0);
	cy = y;
	cx = x;
	ty = y;
	tx = x;
	int k = d1 + 1;
	while(k--) {
		board[cy][cx] = 5;
		cy++;
		cx--;
	}
	cy = ty;
	cx = tx;
	k = d2 + 1;
	while(k--) {
		board[cy][cx] = 5;
		cy++;
		cx++;
	}
	k = d2 + 1;
	cy = ty + d1;
	cx = tx - d1;
	while(k--) {
		board[cy][cx] = 5;
		cy++;
		cx++;
	}
	cy = ty + d2;
	cx = tx + d2;
	k = d1 + 1;
	while(k--) {
		board[cy][cx] = 5;
		cy++;
		cx--;
	}

	for(int i = 1 ; i <= N ; i++) {
		for(int j = 1 ; j <= N ; j++) {
			if(board[i][j] == 5) {
				cnt[i]++;
			}
		}
	}

	for(int i = 1 ; i <= N ; i++) {
		bool flag = false;
		for(int j = 1 ; j <= N ; j++) {
			if(cnt[i] == 2 && board[i][j] == 5 && !flag) {
				flag = true;
				continue;
			}
			if(flag) {
				if(board[i][j] == 0) {
					board[i][j] = 5;
				}
				else if(board[i][j] == 5) {
					flag = false;
					break;
				}
			}
		}
	}

	for(int i = 1 ; i < y + d1 ; i++) {
		for(int j = 1 ; j <= x ; j++) {
			if(board[i][j] == 0) {
				board[i][j] = 1;
			}
		}
	}

	for(int i = 1 ; i <= y + d2 ; i++) {
		for(int j = x + 1 ; j <= N ; j++) {
			if(board[i][j] == 0) {
				board[i][j] = 2;
			}
		}
	}

	for(int i = y + d1 ; i <= N ; i++) {
		for(int j = 1 ; j < x - d1 + d2 ; j++) {
			if(board[i][j] == 0) {
				board[i][j] = 3;
			}
		}
	}

	for(int i = y + d2 + 1 ; i <= N ; i++) {
		for(int j = x - d1 + d2 ; j <= N ; j++) {
			if(board[i][j] == 0) {
				board[i][j] = 4;
			}
		}
	}

	for(int i = 1 ; i <= N ; i++) {
		for(int j = 1 ; j <= N ; j++) {
			adj[board[i][j] - 1] += tmp[i][j];
		}
	}

	sort(adj.begin(), adj.end());

	ll cur = abs(adj[4] - adj[0]);
	ans = min(ans, cur);
	return;
}	

int main() {
 cin >> N;

 for(int i = 1 ; i <= N ; i++) {
 	for(int j = 1 ; j <= N ; j++) {
 		cin >> tmp[i][j];
 	}
 }
 for(int i = 1 ; i <= N ; i++) {
 	for(int j = 1 ; j <= N ; j++) {
 		for(int k = 1 ; k <= N ; k++) {
 			for(int l = 1 ; l <= N ; l++) {
 				solve(i, j, k, l);
 			}
 		}
 	}
 }
 cout << ans << endl;
} 
