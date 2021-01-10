#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
ll P, T;
ll lasturn = 0;
ll geturn(ll n) {
   ll curturn = 0;
   ll c = 1;
   bool plus = true;
   for(int i = 1 ; i <= n ; i++) {
      curturn += c;
      if(plus) {
         c++;
      }
      else {
         c--;
      }
      if(c == 2 * N) {
         plus = false;
      }
      if(c == 1) plus = true; 
   }
   lasturn = c;
   return curturn;
}

int main() {
   cin >> N;
   cin >> P >> T;
   ll pt = 1;
   ll tmp = 2*N;
   ll cnt[1001] = {};
   ll prevturn = geturn(T - 1);
   ll curturn = lasturn;
   ll pos = prevturn % (2 * N);
   pos--;
   if(pos == -1) {
      pos = 2 * N - 1;
   }
   set<int> s;
   set<int> st[1001];
   while(curturn--) {
      pos++;
      if(pos == 2 * N) {
         pos = 0;
      }
      s.insert(pos);
   } 
   int tt = 0;
   while(tmp--) {
      st[pt].insert(tt);
      tt++;
      if(tt == 2 * N) tt = 0;
      if(pt == N) {
         cnt[pt]++;
         if(cnt[N] == 2) pt = 1; 
      }
      else {
         cnt[pt]++;
         if(cnt[pt] == 2) pt++;
      } 
      if(tt == 2 * N) {
         tt = 0;
      }
   }
   bool flag = false;
   for(auto x : s) {
      if(st[P].find(x) != st[P].end()) {
         flag = true;
      }
   }
   if(flag) {
      cout << "Dehet YeonJwaJe ^~^" << endl;
   }
   else {
      cout << "Hing...NoJam" << endl;
   }
} 