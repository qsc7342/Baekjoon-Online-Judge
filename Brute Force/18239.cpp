#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define MAX 10000000
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 987654321;

int R, C, Q;

int arr[1001][1001] = {};
int psum[1001][1001] = {};


int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> R >> C >> Q;

  for(int i = 1 ; i <= R ; i++) {
    for(int j = 1 ; j <= C ; j++) {
      cin >> arr[i][j];
    }
  }

  for(int i = 1 ; i <= R ; i++) {
    for(int j = 1 ; j <= C ; j++){
      psum[i][j] = psum[i - 1][j] + psum[i][j - 1] + arr[i][j] - psum[i - 1][j - 1];
    }
  }


  for(int i = 0 ; i < Q ; i++) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int cur = psum[r2][c2] - psum[r2 - 1][c1 - 1] - psum[r1 - 1][c2 - 1] + psum[r1 - 1][c1 - 1];
    int cnt = (c2 - c1 + 1) * (r2 - r1 + 1);
    cout << cur / cnt << endl;
  }
}
