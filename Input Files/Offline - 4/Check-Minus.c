/* ************************** */
/*    Output = 13, 12, 11     */
/* ************************** */

int main(){
    int a,b,c,i;
    b=0;
    c=1;
    for(i=0;i<4;i++){
        a=3;
        while(a--){
            b++;
        }
    }
    a = b-a;
    println(a);
    println(b);
    c = c + 10;
    println(c);
}
