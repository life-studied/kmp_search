#include "kmp_search.h"
#include <iostream>
using std::cout;
using std::endl;
int main()
{
	const char* p = "aaab";
	const char* txt = "aaabaaabaaab";
	kmp_search s(p);
	cout << s.search(txt) << endl;
	cout << s.search(txt, 4) << endl;
	vector<int> v = s.searchAll(txt);
	for (const auto& i : v)
		cout << i << endl;
}