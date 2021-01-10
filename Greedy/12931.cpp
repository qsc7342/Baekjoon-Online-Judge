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
const int INF = 987654321;

int N;
vector<int>arr;
vector<int>ans;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    int cnt = 0;

    for(int i = 0 ; i < N ; i++) {
      int num;
      cin >> num;
      arr.pb(num);
      ans.pb(0);
    }

    while(arr != ans) {
      for(int i = 0 ; i < N ; i++) {
        if(arr[i] % 2 == 1) {
          arr[i]--;
          cnt++;
        }
        else {
          cont;
        }
      }
      if(arr == ans) {
        cout << cnt << endl;
        return 0;
      }
      for(int i = 0 ; i < N ; i++) {
        if(arr[i] > 1)
          arr[i] /= 2;
      }
      cnt++;
    }
    cout << cnt << endl;
}