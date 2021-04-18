
#include <iostream>
#include<vector>
#include<test_if_sorted.hpp>
using namespace std;

template<class T>
class shell_sort {
public:
	shell_sort(const initializer_list<T>& data_list) :vec(data_list) {}
	void operator()() {
		int span = 0;
		int N = static_cast<int>(vec.size() - 1);
		while (vec.size() > incre[span])span++;
		while (--span!=-1) {
			for (auto i = 0; i + incre[span] <= N; ++i) {
				for (auto j = i + incre[span]; j - incre[span] >= 0; j -= incre[span]) {
					if (vec[j] < vec[j - incre[span]])swap(vec[j], vec[j - incre[span]]);
					else break;
				}
				traverse();
		}
}
	
		test(vec);

	}

private:
	vector<T>vec;
	test_if_sort<decltype(vec)>test;
	void traverse() { for (auto i : vec)cout << i << ends; cout << endl; }
	//vector<size_t>incre = { 1,5,19,41,109,209,505,929,2161,3905,8929,16001,36289,64769,146305,260609 };
	vector<int>incre = { 1,3,7,15,31,63, };//2*N-1,可以自己生成
};

int main()
{
	shell_sort<char>s({ 'S','O','R','T','E','X','A','M','P','L','E' });
	s();

}

