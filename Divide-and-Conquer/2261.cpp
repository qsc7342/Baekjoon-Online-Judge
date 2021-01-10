#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define INF 987654321
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int N;
struct Point {
	int x, y;
};

bool cmp_x(const Point &u, const Point &v) {
 return make_pair(u.x, u.y) < make_pair(v.x, v.y);
}

bool cmp_y(const Point &u, const Point &v) {
 return make_pair(u.y, u.x) < make_pair(v.y, v.x);
}

int dist(Point p1, Point p2) {
 return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

int getdist(vector<Point> &a, int start, int end) {
	int ans = -1;

	for(int i = start ; i < end ; i++) {
		for(int j = i + 1 ; j <= end ; j++) {
			int d = dist(a[i], a[j]);
			if(ans == -1 || ans > d) {
				ans = d;
			}
		}
	}
	return ans;
}

int solve(vector<Point> &a, int start, int end) {
	int n = end - start + 1;
	if(n <= 3) {
		return getdist(a, start, end);
	}

	int mid = (start + end) / 2;
	int left = solve(a, start, mid);
	int right = solve(a, mid + 1, end);

	int ans = min(left, right);

	vector<Point> b;

	for(int i = start ; i <= end ; i++) {
		int d = a[i].x - a[mid].x;
		if(d * d < ans) {
			b.pb(a[i]);
		}
	}
	sort(b.begin(), b.end(), cmp_y);
	int SIZE = b.size();

	for(int i = 0 ; i < SIZE - 1 ; i++) {
		for(int j = i + 1 ; j < SIZE ; j++) {
			int y = b[j].y - b[i].y;
			if(y * y < ans) {
				int d = dist(b[i], b[j]);
				if(d < ans) {
					ans = d;
				}
			}
			else {
				break;
			}
		}
	}
	return ans;
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;

  vector<Point> a(N);

  for(int i = 0 ; i < N ; i++) {
  	int x, y;
  	cin >> x >> y;
  	a[i] = {x, y};
  }
  sort(a.begin(), a.end(), cmp_x);
  cout << solve(a, 0, N - 1) << endl;
  return 0;
}
