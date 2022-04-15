//
//  main.c
//  Fibonacci
//
//  Created by Kai Chang on 2/5/22.
//

#include <stdio.h>

int fib(int n)
{
    int t0 = 0, t1 = 1, s = 0, i;
    if(n <= 1)
        return n;
    for(i = 2; i<=n;i++){
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int rfib(int n)
{
    if (n <= 1)
        return n;
    return rfib(n - 1) + rfib(n - 2);
}

int f[10];

int mfib(int n)
{
    if(n <= 1)
    {
        f[n] = n;
        return n;
    }
    else{
        if(f[n-1] == -1)
        {
            f[n-1] = mfib(n-1);
        }
        if(f[n-2] == -1)
        {
            f[n-2] = mfib(n-2);
        }
        return  f[n-1] + f[n-2];
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int i;
    for(i = 0; i<=10; i++)
    {
        f[i] = -1;
    }
    printf("%d\n", mfib(5));
    return 0;
}
