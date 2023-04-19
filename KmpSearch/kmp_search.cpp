#include "kmp_search.h"

kmp_search::kmp_search(const char* _pat) : dp(nullptr), pat(_pat), patSize(0)
{
    //create dp memory
    while (pat[patSize++]);
    dp = new int[patSize][256];

    //init dp
    int maxPrefix = 0;          
    dp[0][pat[0]] = 1;
    for (int i = 1; i < patSize; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            if (pat[i] == j)            //ahead
                dp[i][j] = j + 1;
            else                        //refind
                dp[i][j] = dp[maxPrefix][j];
        }
        maxPrefix = dp[maxPrefix][i];           //update the maxPrefix
    }
}

int kmp_search::search(const char* txt)
{
    int txtSize = 0;
    while (txt[txtSize++]);
    int patIndex = 0;
    for (int txtIndex = 0; txtIndex < txtSize; txtIndex++)
    {
        patIndex = dp[patIndex][txt[txtIndex]];
        if (patIndex == patSize) return txtIndex - patIndex + 1;
    }
    return -1;
}
