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

deque<int> dq[51] = {};
int N, M, T;
int sum = 0;
int cnt = 0;
int x, d, k;

void solve(int m, int dir, int re) {
	bool flag = false;

	for(int i = m ; i <= N ; i += m) {
		int move = re % M;
		for(int j = 0 ; j < move ; j++) {
			if(dir == 0) {
				int tmp = dq[i].back();
				dq[i].pop_back();
				dq[i].push_front(tmp);
			}
			else if(dir == 1) {
				int tmp = dq[i].front();
				dq[i].pop_front();
				dq[i].push_back(tmp);
			}
		}
	}
	vector<pii> adj;

	for(int i = 1 ; i <= N ; i++) {
		for(int j = 0 ; j < M ; j++) {
			if(dq[i][j] != 0) {
				bool f = false;

				if(j == 0) {
					if(dq[i][j] == dq[i][1]) {
						adj.pb(mp(i, 1));
						f = true;
					}
					if(dq[i][j] == dq[i][M - 1]) {
						adj.pb(mp(i, M - 1));
						f = true;
					}
				}
				else if(j == M - 1) {
					if(dq[i][j] == dq[i][M - 2]) {
						adj.pb(mp(i, M - 2));
						f = true;
					}
					if(dq[i][j] == dq[i][0]) {
						adj.pb(mp(i, 0));
						f = true;
					}
				}
				else {
					if(dq[i][j] == dq[i][j - 1]) {
						adj.pb(mp(i, j - 1));
						f = true;
					}
					if(dq[i][j] == dq[i][j + 1]) {
						adj.pb(mp(i, j + 1));
						f = true;
					}
				}

				if(i == 1) {
					if(dq[i + 1][j] == dq[i][j]) {
						adj.pb(mp(i + 1, j));
						f = true;
					}
				}
				else if(i == N) {
					if(dq[i - 1][j] == dq[i][j]) {
						adj.pb(mp(i - 1, j));
						f = true;
					}
				}
				else {
					if(dq[i][j] == dq[i - 1][j]) {
						adj.pb(mp(i - 1, j));
						f = true;
					}
					if(dq[i + 1][j] == dq[i][j]) {
						adj.pb(mp(i + 1, j));
						f = true;
					}
				}
				if(f) {
					flag = true;
					adj.pb(mp(i, j));
				}
			}
		}
	}
	if(flag) {
		sort(adj.begin(), adj.end());
		adj.erase(unique(adj.begin(), adj.end()), adj.end());

		for(auto x : adj) {
			int f = x.first;
			int s = x.second;
			cnt--;
			sum -= dq[f][s];
			dq[f][s] = 0;
		}
	}
	else {
		double mean = (double)sum / (double)cnt;

		for(int i = 1 ; i <= N ; i++) {
			for(int j = 0 ; j < M ; j++) {
				if(dq[i][j] != 0) {
					if(dq[i][j] > mean) {
						dq[i][j]--;
						sum--;
					}
					else if(dq[i][j] < mean) {
						dq[i][j]++;
						sum++;
					}
				}
			}
		}
	}
}
int main() {
 cin.tie(NULL);
 ios_base::sync_with_stdio(false);

 cin >> N >> M >> T;

 for(int i = 1 ; i <= N ; i++) {
 	for(int j = 0 ; j < M ; j++) {
 		int x;
 		cin >> x;
 		dq[i].push_back(x);
 		sum += x;
 		cnt++;
 	}
 }
 while(T--) {
 	cin >> x >> d >> k;
 	solve(x, d, k);
 }
 cout << sum << endl;
} 
