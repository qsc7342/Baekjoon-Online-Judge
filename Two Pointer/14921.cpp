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

const ll INF = 9876543212135;
ll N, M;
vector<int>arr;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;

  for(int i = 0 ; i < N ; i++) {
    int num;
    cin >> num;
    arr.pb(num);
  }

  sort(arr.begin(), arr.end());

  int left = 0;
  int right = arr.size() - 1;
  ll min_diff = INF;

  while(left < right) {
    int cur = arr[right] - arr[left];
    if(cur > min_diff) {
      right--;
    }
    else if(cur <= min_diff) {
      if(cur >= M) {
        min_diff = cur;
      }
      left++;
    }
  }
}
