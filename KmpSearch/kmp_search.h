#pragma once
#include <vector>
using std::vector;
class kmp_search
{
	int(*dp)[256];
	const char* pat;
	int patSize;

public:
	kmp_search(const char* _pat);
	int search(const char* txt);
	int search(const char* txt, int startIndex);
	vector<int> searchAll(const char* txt);
	
};

