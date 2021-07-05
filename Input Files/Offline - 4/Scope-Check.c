/* ************************** */
/*         Output = 71        */
/* ************************** */

int a;
int function(int a){
  return 70*a;
}

int main(){
  a = 1;
  int b;
  b = 1;

  a = a+function(b);
  printf(a);
}
