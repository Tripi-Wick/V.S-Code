#include <stdio.h>
#include <math.h>
int count(int);


int main() {
	
    int n;
    printf("Enter a number:");
    scanf("%d", &n);
    int a,c;
    static int sum;

    int x=count(n);
    printf("%d\n",x);

    while(n>0){
        c=n/(pow(10,x));
        a=n%((int)pow(10,x));
        sum=+c;
        c=a;
        x--;
    }

    
    printf("%d\n",sum);
    return 0;
}

int count(int n){
    int x=0;
        while(n!=0){
            n=n/10;
            x++;
        }
    return x;
}