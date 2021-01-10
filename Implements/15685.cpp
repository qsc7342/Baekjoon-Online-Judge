#include <bits/stdc++.h>

using namespace std;

int N;
int board[105][105] = {}; 
stack<char> cur;
stack<char> tmp;
int x, y, d, g;

void solve(int cy, int cx, int cg) {
	if(cg == g) return;
	tmp = cur;
	int ly = cy;
	int lx = cx;
	while(!tmp.empty()) {
		char dir = tmp.top();
		tmp.pop();
		if(dir == 'u') {
			lx--;
			board[ly][lx] = 1;
			cur.push('l');
		}

		else if(dir == 'r') {
			ly--;
			board[ly][lx] = 1;
			cur.push('u');
		}

		else if(dir == 'd') {
			lx++;
			board[ly][lx] = 1;
			cur.push('r');
		}

		else if(dir == 'l') {
			ly++;
			board[ly][lx] = 1;
			cur.push('d');
		}
	}
	solve(ly, lx, cg + 1);
	return;
}


int main() {
 cin >> N;
 while(N--) {
	while(!cur.empty()) cur.pop();
	while(!tmp.empty()) tmp.pop(); 	
	cin >> x >> y >> d >> g;
 	board[y][x] = 1;
 	if(d == 0) {
 		board[y][x + 1] = 1;
 		cur.push('r');
 		solve(y, x + 1, 0);
 	}
 	else if(d == 1) {
 		board[y - 1][x] = 1;
 		cur.push('u');
 		solve(y - 1, x, 0);
 	}
 	else if(d == 2) {
 		board[y][x - 1] = 1;
 		cur.push('l');
 		solve(y, x - 1, 0);
 	} 
 	else {
 		board[y + 1][x] = 1;
 		cur.push('d');
 		solve(y + 1, x, 0);
 	}
 }
 int ans = 0;
 for(int i = 0 ; i <= 100 ; i++) {
 	for(int j = 0 ; j <= 100 ; j++) {
 		if(board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 1][j + 1] == 1 && board[i][j + 1] == 1) {
 			ans++;
 		}
 	}
 }
 cout << ans << endl;
} 
