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
int ans = INF;
void getval() {
	for(int i = 1 ; i <= N ; i++) {
		int cur = 0;
		for(int j = 1 ; j <= M ; j++) {
			cur += board[i][j];
		}
		ans = min(ans, cur);
	}
}
void foo() {
	int mny = r - s;
	int mnx = c - s;
	int mxy = r + s;
	int mxx = c + s;

	while(1) {
		deque<int> chk;
		bool flag = true;
		for(int i = mnx ; i <= mxx ; i++) {
			chk.pb(board[mny][i]);
		}
		for(int i = mny + 1 ; i <= mxy ; i++) {
			chk.pb(board[i][mxx]);
		}
		for(int i = mxx - 1 ; i >= mnx ; i--) {
			chk.pb(board[mxy][i]);
		}
		for(int i = mxy - 1 ; i >= mny + 1 ; i--) {
			chk.pb(board[i][mnx]);
		}
		if(mnx > mxx || mny > mxy) return;
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
		for(int i = mxy - 1 ; i >= mny + 1 ; i--) {
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
 int tmpboard[51][51] = {};
 for(int i = 1 ; i <= N ; i++) {
 	for(int j = 1 ; j <= M ; j++) {
 		cin >> board[i][j];
 		tmpboard[i][j] = board[i][j];
 	}
 }
 vector<pair < pair<int, int> , int> > adj;
 while(K--) {
 	cin >> r >> c >> s;
 	adj.pb(mp(mp(r, c), s));
 }
 sort(adj.begin(), adj.end());

 do {
 	for(int i = 1 ; i <= N ; i++) {
 		for(int j = 1 ; j <= M ; j++) {
 			board[i][j] = tmpboard[i][j];
 		}
 	}
 	for(int i = 0 ; i < adj.size() ; i++) {
 		r = adj[i].first.first;
 		c = adj[i].first.second;
 		s = adj[i].second;
 		foo();
 	}
 	getval();
 }while(next_permutation(adj.begin(), adj.end()));

 cout << ans << endl;
} 
