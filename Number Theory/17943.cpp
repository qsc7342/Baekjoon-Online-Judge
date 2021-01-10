#include <bits/stdc++.h>
#define endl '\n';

using namespace std;
int N, Q;
int arr[200001] = {};
int pxor[200001] = {};
int main() {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   cin >> N >> Q;

   for(int i = 1 ; i < N ; i++) {
      cin >> arr[i];
   }
   for(int i = 1 ; i < N ; i++) {
      pxor[i] = pxor[i - 1] ^ arr[i];
   }
   while(Q--) {
      int q;
      cin >> q;
      if(q == 0) {
         int x, y;
         cin >> x >> y;
         cout << (pxor[y - 1] ^ pxor[x - 1]) << endl;
      }
      if(q == 1) {
         int x, y, d;
         cin >> x >> y >> d;
         cout << (d ^ (pxor[y - 1] ^ pxor[x - 1])) << endl;
      }
   }
} 