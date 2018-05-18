#include <stdio.h>

int change(int n){

  int p,min;
  int OPT[n+1];
  OPT[0]=0;
  for(p=1;p<=n;p++){
    min=32766;
    if(25<=p&&1+OPT[p-25]<min)
      min=1+OPT[p-25];
    if(10<=p&&1+OPT[p-10]<min)
      min=1+OPT[p-10];
    if(1<=p&&1+OPT[p-1]<min)
      min=1+OPT[p-1];
    OPT[p]=min;
  }
  return OPT[n];
}

int main(){
  int money=30;
  int num=change(money);
  printf("The fewest number of coins to make change of %d cents is %d coins.\n",money,num);
  return 0;
}
