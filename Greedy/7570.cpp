#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define MAX 10000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 2147483646;

vector<int> child;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  int len = 0;

  int dp[1000001] = {};

  for(int i = 0 ; i < N ; i++) {
    int num;
    cin >> num;
    dp[num] = dp[num - 1] + 1;
  }

  int max_len = 0;

  for(int i = 1 ; i <= N ; i++) {
    max_len = max(max_len, dp[i]);
  }
  cout << N - max_len << endl;
} 