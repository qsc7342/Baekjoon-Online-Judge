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


set<string> st;
queue<pair<pii, int> > q;


int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  vector<ll> arr;
  for(int i = 0 ; i < 3 ; i++) {
    ll x;
    cin >> x;
    arr.pb(x);
  }
  sort(arr.begin(), arr.end());
  int a = arr[0];
  int b = arr[1];
  int c = arr[2];
  string f, s, t;
  f += to_string(a);
  s += to_string(b);
  t += to_string(c);
  f += 'a';
  s += 'b';
  t += 'c';
  string tmp = f + s + t;
  st.insert(tmp);
  q.push(mp(mp(a, b), c));

  while(!q.empty()) {
    int v[3];
    v[0] = q.front().first.first;
    v[1] = q.front().first.second;
    v[2] = q.front().second;
    if(v[0] == v[2]) {
      cout << "1" << endl;
      return 0;
    }
    q.pop();

    int c1[3] = {};
    c1[0] = v[1] - v[0];
    c1[1] = v[0] + v[0];
    c1[2] = v[2];
    sort(c1, c1 + 3);
    string f1, s1, t1;
    f1 += to_string(c1[0]);
    s1 += to_string(c1[1]);
    t1 += to_string(c1[2]);
    f1 += 'a';
    s1 += 'b';
    t1 += 'c';
    string tmp2 = f1 + s1 + t1;

    int c2[3] = {};
    c2[0] = v[2] - v[0];
    c2[1] = v[0] + v[0];
    c2[2] = v[1];
    sort(c2, c2 + 3);
    string f2, s2, t2;
    f2 += to_string(c2[0]);
    s2 += to_string(c2[1]);
    t2 += to_string(c2[2]);
    f2 += 'a';
    s2 += 'b';
    t2 += 'c';
    string tmp3 = f2 + s2 + t2;

    int c3[3] = {};
    c3[0] = v[2] - v[1];
    c3[1] = v[1] + v[1];
    c3[2] = v[0];
    sort(c3, c3 + 3);
    string f3, s3, t3;
    f3 += to_string(c3[0]);
    s3 += to_string(c3[1]);
    t3 += to_string(c3[2]);
    f3 += 'a';
    s3 += 'b';
    t3 += 'c';
    string tmp4 = f3 + s3 + t3;

    if(st.find(tmp2) == st.end()) {
      st.insert(tmp2);
      q.push(mp(mp(c1[0], c1[1]), c1[2]));
    }
    if(st.find(tmp3) == st.end()) {
      st.insert(tmp3);
      q.push(mp(mp(c2[0], c2[1]), c2[2]));
    }
    if(st.find(tmp4) == st.end()) {
      st.insert(tmp4);
      q.push(mp(mp(c3[0], c3[1]), c3[2]));
    }
  }
  cout << "0" << endl;
  return 0;
} 
