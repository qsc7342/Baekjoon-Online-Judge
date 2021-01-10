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
const ll INF = 987654321;


int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<int> arr;

  for(int i = 0 ; i < N ; i++) {
    int x;
    cin >> x;
    arr.pb(x);
  }

  int left = 0;
  int right = arr.size() - 1;
  while(left < right) {
    swap(arr[left], arr[right]);
    left++;
    right--;
  }


  vector<int> adj;

  for(int i = 0 ; i < arr.size() ; i++) {
    if(adj.size() == 0 || adj.back() < arr[i]) {
      adj.pb(arr[i]);
    }
    else {
      auto it = lower_bound(adj.begin(), adj.end(), arr[i]);
      *it = arr[i];
    }
  }
  cout << N - adj.size() << endl;
} 
