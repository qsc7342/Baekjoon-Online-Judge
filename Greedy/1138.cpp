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
vector<int> person;
int cnt[11] = {};
bool solve() {
  for(int i = 0 ; i < person.size() ; i++) {
    int cur = person[i];
    int cnt2 = 0;
    for(int j = 0 ; j < i ; j++) {
      if(person[j] > cur) cnt2++;
    }
    if(cnt[cur] != cnt2) {
      return false;
    }
  }
  return true;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for(int i = 1 ; i <= N ; i++) {
    cin >> cnt[i];
  }
  for(int i = 1 ; i <= N ; i++) {
    person.pb(i);
  }

  do {
    if(solve() == true) {
      for(auto x : person) {
        cout << x << ' ';
      }
      cout << endl;
      return 0;
    }
  }while(next_permutation(person.begin(), person.end()));
}