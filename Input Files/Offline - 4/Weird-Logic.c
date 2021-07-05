/* ************************** */
/*       Output = 2, 2        */
/* ************************** */

int a;
int function(int a){
  return a%2;
}

int main(){
  a = 1;
  int b;
  b = 6;
  int c;
  c = 2;

  if(function(b)==1){
    printf(a);
  }else{
    println(c);
  }
  b = a && 0 + 0 || c + b && a ; 
  printf(b);
}
