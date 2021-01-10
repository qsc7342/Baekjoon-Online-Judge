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


int lis[1001] = {};
int lds[1001] = {};
int arr[1001] = {};
int N;
int getLis2() {
  vector<int>chk;
  chk.pb(-INF);

  for(int i = 1 ; i <= N ; i++) {
    if(chk.back() < arr[i]) {
      chk.pb(arr[i]);
    }
    else {
      int pos = lower_bound(chk.begin(), chk.end(), arr[i]) - chk.begin();
      chk[pos] = arr[i];
    }
  }
  return chk.size() - 1;
}

int getLds2() {
  vector<int>chk;
  chk.pb(-INF);

  for(int i = N ; i >= 1 ; i--) {
    if(chk.back() < arr[i]) {
      chk.pb(arr[i]);
    }
    else {
      int pos = lower_bound(chk.begin(), chk.end(), arr[i]) - chk.begin();
      chk[pos] = arr[i];
    }
  }
  return chk.size() - 1;
}

void getLis(int st) {
  vector<int>chk;
  chk.pb(-INF);

  for(int i = 1 ; i <= st ; i++) {
    if(chk.back() < arr[i]) {
      chk.pb(arr[i]);
    }
    else {
      int pos = lower_bound(chk.begin(), chk.end(), arr[i]) - chk.begin();
      chk[pos] = arr[i];
    }
  }
  lis[st] = chk.size() - 1; 
  return;
}

void getLds(int st) {
  vector<int>chk;
  chk.pb(-INF);

  for(int i = N ; i >= st ; i--) {
    if(chk.back() < arr[i]) {
      chk.pb(arr[i]);
    }
    else {
      int pos = lower_bound(chk.begin(), chk.end(), arr[i]) - chk.begin();
      chk[pos] = arr[i];
    }
  }
  lds[st] = chk.size() - 1; 
  return;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;

  for(int i = 1 ; i <= N ; i++) {
    cin >> arr[i];
  }

  int max_len = 1;

  for(int i = 1 ; i <= N ; i++) {
    getLis(i);
    getLds(i);
  }

  for(int i = 1 ; i <= N ; i++) {
    max_len = max(max_len, lis[i]);
    max_len = max(max_len, lds[i]);
  }
  for(int i = 1 ; i <= N ; i++) {
    if(lis[i] > 1 && lds[i] > 1) {
      max_len = max(max_len, lis[i] + lds[i] - 1);
    }
  }
  max_len = max(max_len, getLis2());
  max_len = max(max_len, getLds2());
  cout << max_len << endl;  
  return 0;
}
