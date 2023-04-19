# kmp_search
​	使用kmp的字符串查找类。该类对象绑定一个模式串，只要模式串不变，就无需重建该对象。在查找时输入文本串即可。没找到返回-1。

## 接口说明

* search(const char* txt)：查找第一个找到的字符串，返回找到的下标
* search(const char* txt, int startIndex)：查找从startIndex开始的第一个字符串，返回找到的下标
* searchAll(const char* txt)：查找所有找到的字符串，返回特征字符串的下标数组

## 使用案例

```C++
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
```

