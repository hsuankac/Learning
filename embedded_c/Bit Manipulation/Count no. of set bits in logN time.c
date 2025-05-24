#include <stdio.h>

int hammingWeight(int n)
{  
  int count = 0;
  while (n > 0)
  {
    n = n & (n - 1);
    count++;
  }
  return count;
}

int main()
{
    // Worst time complexity is O(log(N)) when all bits are set
    int count = hammingWeight(13);
    printf("No. of 1 bits is: %d\n", count); 
    return 0;
}