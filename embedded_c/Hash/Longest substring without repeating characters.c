#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256


int lengthOfLongestSubstring(const char *s)
{
    int n = strlen(s);
    int lastIndex[MAX_CHAR]; // ASCII character map
    for(int i = 0; i < MAX_CHAR; i++)
    {
        lastIndex[i] = -1;
    }
    int maxLen = 0;
    int start = 0;  // start of current substring
    for(int end = 0; end < n; end++)
    {
        char ch = s[end];
        // if character was seen and is inside current window
        if(lastIndex[(unsigned char)ch] >= start)
        {
            start = lastIndex[(unsigned char)ch] + 1;
        }
        lastIndex[(unsigned char)ch] = end;
        int currLen = end - start + 1;
        if(currLen > maxLen)
        {
            maxLen = currLen;
        }
    }
    return maxLen;
}


int main() {
    const char *testStr = "abcabcbb";
    int len = lengthOfLongestSubstring(testStr);
    printf("Length of longest substring without repeating characters: %d\n", len);
    return 0;
}