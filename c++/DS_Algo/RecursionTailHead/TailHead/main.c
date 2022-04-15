//
//  main.c
//  TailHead
//
//  Created by Kai Chang on 2/3/22.
//

#include <stdio.h>

void fun_tail(int n)
{
    if (n > 0)
    {
        printf("%d", n);
        fun_tail(n - 1);
    }
}


void fun_head(int n)
{
    if (n > 0)
    {
        fun_head(n - 1);
        printf("%d", n);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int x = 3;
    fun_head(x);
    return 0;
}
