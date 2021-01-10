#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

vector<string>s;
vector<char>letters;
vector<int>num;

int arr[27] = {};
int N;
int alpha[256] = {};
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;

  for(int i = 0 ; i < N ; i++) {
    string str;
    cin >> str;
    s.pb(str);
    for(char x : s[i]) {
      letters.push_back(x);
    }
  }
  sort(letters.begin(), letters.end());
  letters.erase(unique(letters.begin(), letters.end()), letters.end());

  for(int i = 0 ; i < letters.size() ; i++) {
    num.pb(9 - i);
  }
  ll ans = -1;

  do {
    ll sum = 0;
    for(int i = 0 ; i < letters.size() ; i++) {
        alpha[letters[i]] = num[i]; 
    }
    for(string str : s) {
      int pos = 0;
      ll cur = 0;
      for(char c : str) {
        cur = cur * 10 + alpha[c];
      }
      sum += cur;
    }
    if(sum > ans) ans = sum;
  }while(prev_permutation(num.begin(), num.end()));

  cout << ans;
}