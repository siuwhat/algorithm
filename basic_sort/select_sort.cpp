
#include <iostream>
#include<vector>
#include<test_if_sorted.hpp>
using namespace std;

template<class T>
class select_sort {
public:
	select_sort(const initializer_list<T>& data_list):vec(data_list) {}
	void operator()() {
		
		for (size_t i = 0,min=i; i <= vec.size() - 1; ++i)
		{
			min = i;
			for (size_t j = i+1; j <= vec.size()-1; ++j) {
				if (vec[min] > vec[j])min = j;
			}
			swap(vec[i], vec[min]);
		traverse();
		}
		test(vec);
		
	}
	
private:
	vector<T>vec;
	test_if_sort<decltype(vec)>test;
	void traverse() { for (auto i : vec)cout << i << ends; cout << endl; }
};

int main()
{
	select_sort<char>s({ 'S','O','R','T','E','X','A','M','P','L','E' });
	s();

}

