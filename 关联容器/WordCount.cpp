// 关联容器.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
使用关联数组实现的单词计数器
*/
#include<iostream>
#include<map>
#include<string>
#include<stdlib.h>
using namespace std;

void WordCount()
{
	map<string, size_t> word_count;
	string word;
	while (cin >> word&&word!="exit")
		++word_count[word];
	for (const auto &w : word_count)
		cout << w.first << "occurs " << w.second
		<< ((w.second > 1) ? "times" : " time") << endl;
}

