
#include <iostream>
#include<vector>
#include<test_if_sorted.hpp>
using namespace std;

template<class T>
class insert_sort {
public:
	insert_sort(const initializer_list<T>& data_list) :vec(data_list) {}
	void operator()() {

		for (size_t i = 0; i <= vec.size() - 1; ++i)
		{
			for (size_t j = i; j>0;) {
				if (vec[j] < vec[j - 1]) { swap(vec[j-1], vec[j]); --j; }
				else break;//时间复杂度在O(N ^ (1 - 2))
			}
			traverse();
		}
		
		test(vec);

	}

private:
	test_if_sort<vector<T>, T>test;
	vector<T>vec;
	void traverse() { for (auto i : vec)cout << i << ends; cout << endl; }
};

int main()
{
	insert_sort<int>s({7,10,5,3,8,4,2,9,6 });
	s();

}

