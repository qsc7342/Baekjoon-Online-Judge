#include <stdio.h>
#include <stdlib.h>
int min(int a,int b){
  return (a>b?b:a);
}

int main(int argc, char const *argv[]) {
  int n,m;
  int A,B;
  int A_min=100000,B_min=100000;
  scanf("%d %d",&n,&m);
  if(n == 0 || m == 0) {
    printf("0\n");
    return 0;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &A,&B);
    A_min=min(A_min,A);
    B_min=min(B_min,B);
  }
  if(A_min == 0 || B_min==0){
    printf("0\n");
  }
  else{
    if ((double)A_min/6>B_min) {
      printf("%d\n",B_min*n); //세트가 비싼 경우
    }
    else{
      if(n / 6 * A_min + n % 6 * B_min <= n / 6 * A_min + A_min) {
        printf("%d\n",n/6*A_min+n%6*B_min);//세트+낱
      }
      else{
        if(n / 6 == 0) printf("%d\n",n/6*A_min);
        else printf("%d\n",n/6*A_min+A_min);//세트
      }
    }
  }

  return 0;
}