//
//  main.c
//  TowerOfHanoi
//
//  Created by Kai Chang on 2/5/22.
//

#include <stdio.h>

void TOH(int n, int a, int b, int c)
{
    if(n > 0)
    {
        TOH(n-1, a, c, b);
        printf("(%d, %d)\n", a, c);
        TOH(n-1, b, a, c);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    TOH(3, 1, 2, 3);
    return 0;
}
