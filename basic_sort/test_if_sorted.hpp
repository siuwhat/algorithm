
#pragma once
#include<functional>
#include<cassert>
template<class T>
class test_if_sort{
public:
	test_if_sort() = default;
	void operator()(T vec) {  for (auto i = 0; i < vec.size() - 1; ++i)assert(vec[i]<=vec[i + 1]); }
};