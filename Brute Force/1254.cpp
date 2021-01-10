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

bool ispalin(string s) {
  int left = 0;
  int right = s.size() - 1;

  while(left < right) {
    if(s[left] != s[right]) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;

  if(ispalin(s)) {
    cout << s.size() << endl;
    return 0;
  }

  for(int i = 0 ; i < s.size() - 1 ; i++) {
    string s2;
    s2 = s;
    for(int j = i ; j >= 0 ; j--) {
      s2 += s[j];
    }
    if(ispalin(s2)) {
      cout << s2.size() << endl;
      return 0;
    }
  }
  return 0;
}
