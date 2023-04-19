#include "kmp_search.h"
#include <cstring>
kmp_search::kmp_search(const char* _pat) : dp(nullptr), pat(_pat), patSize(0)
{
    //create dp memory
    while (pat[patSize++]); --patSize;
    dp = new int[patSize][256];
    for(int i = 0;i<patSize;i++)
        memset(dp[i], 0, 256*sizeof(int));

    //init dp
    int maxPrefix = 0;          
    dp[0][pat[0]] = 1;
    for (int i = 1; i < patSize; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            if (pat[i] == j)            //ahead
                dp[i][j] = i + 1;
            else                        //refind
                dp[i][j] = dp[maxPrefix][j];
        }
        maxPrefix = dp[maxPrefix][i];           //update the maxPrefix
    }
}

int kmp_search::search(const char* txt)
{
    return search(txt, 0);
}

int kmp_search::search(const char* txt, int startIndex)
{
    int txtSize = 0;
    while (txt[txtSize++]); --txtSize;
    if (startIndex > txtSize)  return -1;
    int patIndex = 0;
    for (int txtIndex = startIndex; txtIndex < txtSize; txtIndex++)
    {
        patIndex = dp[patIndex][txt[txtIndex]];
        if (patIndex == patSize) return txtIndex - patIndex + 1;
    }
    return -1;
}

vector<int> kmp_search::searchAll(const char* txt)
{
    int index = 0;
    vector<int> res;
    while ((index = search(txt, index)) != -1)
    {
        res.push_back(index);
        index += patSize;
    }
    return std::move(res);
}
