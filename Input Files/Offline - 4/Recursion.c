/* ************************** */
/*        Output = 121        */
/* ************************** */

int a;
int function(int a){
  if(a==1){
    return 1;
  }
  return a*function(a-1);
}

int main(){
  a = 1;
  int b;
  b = 6;

  a = a+function(b);
  printf(a);
}
