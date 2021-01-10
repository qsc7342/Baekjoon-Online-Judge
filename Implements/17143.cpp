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

int r, c, k;
int tc = 0;
int board[1001][1001] = {};
int curr, curc;

void R() {
	int tmpboard[1001][1001] = {};
	int mxsz = 0;

	for(int i = 1 ; i <= curr ; i++) {
		int cnt[101] = {};
		for(int j = 1 ; j <= curc ; j++) {
			cnt[board[i][j]]++;
		}
		vector<pii> adj;
		for(int j = 1 ; j <= 100 ; j++) {
			if(cnt[j] > 0) {
				adj.pb(mp(cnt[j], j));
			}
		}
		sort(adj.begin(), adj.end());
		
	}
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> r >> c >> k;
  curr = 3;
  curc = 3;
  for(int i = 1 ; i <= 3 ; i++) {
  	for(int j = 1 ; j <= 3 ; j++) {
  		cin >> board[i][j];
  	}
  }
  while(board[r][c] != k) {
  	if(curr >= curc) {
  		R();
  	}
  	else {
  		C();
  	}
  }
} 
