#include <stdio.h>

void change(int n,int* x,int* y, int* z){
  int k,min;
  int out[3];
  int OPT_COINS[n+1][3];
  OPT_COINS[0][0]=0;
  OPT_COINS[0][1]=0;
  OPT_COINS[0][2]=0;
  for(k=1;k<=n;k++){
    min=32766;
    if(25<=k&&(1+OPT_COINS[k-25][0]+OPT_COINS[k-25][1]+OPT_COINS[k-25][2])<min){
      min=1+OPT_COINS[k-25][0]+OPT_COINS[k-25][1]+OPT_COINS[k-25][2];
      out[0]=OPT_COINS[k-25][0];
      out[1]=OPT_COINS[k-25][1];
      out[2]=OPT_COINS[k-25][2]+1;
    }
    if(10<=k&&(1+OPT_COINS[k-10][0]+OPT_COINS[k-10][1]+OPT_COINS[k-10][2])<min){
      min=1+OPT_COINS[k-10][0]+OPT_COINS[k-10][1]+OPT_COINS[k-10][2];
      out[0]=OPT_COINS[k-10][0];
      out[1]=OPT_COINS[k-10][1]+1;
      out[2]=OPT_COINS[k-10][2];
    }
    if(1<=k&&(1+OPT_COINS[k-1][0]+OPT_COINS[k-1][1]+OPT_COINS[k-1][2])<min){
      min=1+OPT_COINS[k-1][0]+OPT_COINS[k-1][1]+OPT_COINS[k-1][2];
      out[0]=OPT_COINS[k-1][0]+1;
      out[1]=OPT_COINS[k-1][1];
      out[2]=OPT_COINS[k-1][2];
    }
    OPT_COINS[k][0]=out[0];
    OPT_COINS[k][1]=out[1];
    OPT_COINS[k][2]=out[2];
  }//endfor
  *x=OPT_COINS[n][0];
  *y=OPT_COINS[n][1];
  *z=OPT_COINS[n][2];
  return;
}

int main(){
  int money=30;
  int *x=NULL,*y=NULL,*z=NULL;
  change(money,x,y,z);
  printf("Changing %d cents needs %d pennies, %d dimes and %d quarters.\n",money,*x,*y,*z);
  return 0;
}
