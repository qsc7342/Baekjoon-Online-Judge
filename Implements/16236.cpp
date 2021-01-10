#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 987654321;

int N;
int board[25][25] = {}; 
queue<pair<pii, int> > q;
int ans = 0;
int big = 2;
int eat = 0;
bool visit[25][25] = {};
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int last_y = 0;
int last_x = 0;

bool isRange(int y, int x) {
	if(y <= 0 || y > N || x <= 0 || x > N) return false;
	else return true;
}

bool compare(pii a, pii b) {
	if(a.first != b.first) {
		return a.first < b.first;
	}
	else{
		return a.second < b.second;
	}
}

bool bfs(int ly, int lx) {
	vector<pii> caneat;
	int min_d = INF;
	q.push(mp(mp(ly, lx), 0));
	while(!q.empty()) {
		int cur_y = q.front().first.first;
		int cur_x = q.front().first.second;
		int cur_d = q.front().second;
		visit[cur_y][cur_x] = true;
		q.pop();
		if(min_d > cur_d && board[cur_y][cur_x] < big && board[cur_y][cur_x] != 0 && board[cur_y][cur_x] != 9) {
			caneat.clear();
			caneat.pb(mp(cur_y, cur_x)); 
			min_d = cur_d;
		}
		else if(min_d == cur_d && board[cur_y][cur_x] < big && board[cur_y][cur_x] != 0 && board[cur_y][cur_x] != 9) {
			caneat.pb(mp(cur_y, cur_x));
		}

		for(int i = 0 ; i < 4 ; i++) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];

			if(!isRange(ny, nx)) continue;
			else {
				if(!visit[ny][nx] && board[ny][nx] <= big) {
					visit[ny][nx] = true;
					q.push(mp(mp(ny, nx), cur_d + 1));
				}
			}
		}
	}
	sort(caneat.begin(), caneat.end(), compare);

	if(caneat.size() > 0) {
		eat++;
		if(eat == big) {
			big++;
			eat = 0;
		}
		last_y = caneat[0].first;
		last_x = caneat[0].second;
		board[last_y][last_x] = 0;
		ans += min_d;
		return true;
	}
	else {
		return false;
	}
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> N;
  for(int i = 1 ; i <= N ; i++) {
    for(int j = 1 ; j <= N ; j++) {
      cin >> board[i][j];
      if(board[i][j] == 9) {
      	last_y = i;
      	last_x = j;
      }
    }
  }
  board[last_y][last_x] = 0;
  while(1) {
  	memset(visit, false, sizeof(visit));
  	if(bfs(last_y, last_x) == false) {
  		break;
  	}
  }
  cout << ans << endl;
}