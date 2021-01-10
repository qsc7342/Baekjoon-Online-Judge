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
const int INF = 2147483646;
const double pi = 3.141592653589793;

int N, M, K;
int r, c, s;
int board[51][51] = {};

void foo() {
	bool visit[51][51] = {};
	int mny = r - s;
	int mnx = c - s;
	int mxy = r + s;
	int mxx = c + s;

	while(1) {
		deque<int> chk;
		bool flag = true;
		for(int i = mnx ; i <= mxx ; i++) {
			if(visit[mny][i] == true) flag = false;
			chk.pb(board[mny][i]);
			visit[mny][i] = true;
		}
		for(int i = mny + 1 ; i <= mxy ; i++) {
			if(visit[i][mxx] == true) flag = false;
			chk.pb(board[i][mxx]);
			visit[i][mxx] = true;
		}
		for(int i = mxx - 1 ; i >= mnx ; i--) {
			if(visit[mxy][i] == true) flag = false;
			chk.pb(board[mxy][i]);
			visit[mxy][i] = true;
		}
		for(int i = mxy - 1 ; i >= mnx + 1 ; i--) {
			if(visit[i][mnx] == true) flag = false;
			chk.pb(board[i][mnx]);
			visit[i][mnx] = true;
		}
		if(!flag) return;
		for(int i = mnx ; i <= mxx ; i++) {
			if(i == mnx) {
				board[mny][i] = chk.back();
				chk.pop_back();
			}
			else {
				board[mny][i] = chk.front();
				chk.pop_front();
			}
		}
		for(int i = mny + 1 ; i <= mxy ; i++) {
			board[i][mxx] = chk.front();
			chk.pop_front();
		}
		for(int i = mxx - 1 ; i >= mnx ; i--) {
			board[mxy][i] = chk.front();
			chk.pop_front();
		}
		for(int i = mxy - 1 ; i >= mnx + 1 ; i--) {
			board[i][mnx] = chk.front();
			chk.pop_front();
		}
		mny++;
		mnx++;
		mxy--;
		mxx--;
	}
}

int main() {
 cin.tie(NULL);
 ios_base::sync_with_stdio(false);

 cin >> N >> M >> K;

 for(int i = 1 ; i <= N ; i++) {
 	for(int j = 1 ; j <= M ; j++) {
 		cin >> board[i][j];
 	}
 }

 while(K--) {
 	cin >> r >> c >> s;
 	// 왼쪽위 (r - s, c - s)
 	// 오른쪽 아래 (r + s, c + s)

 }

} 
