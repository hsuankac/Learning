//
//  main.c
//  ncr
//
//  Created by Kai Chang on 2/5/22.
//

#include <stdio.h>

int NCR(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }
    return NCR(n-1, r-1) + NCR(n-1, r);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n", NCR(5, 1));
    return 0;
}
