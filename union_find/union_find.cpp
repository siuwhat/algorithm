#include <iostream>
#include<vector>
using namespace std;

 class Union {
public:
	Union(size_t size = 10) :SIZE(size) { parent = vector<int>(SIZE); for (auto i = 0; i < SIZE; ++i)parent[i]=i; }
	vector<int>parent;
	void union_element(int source, int destination);
	bool if_connected(int first,int second);
	size_t count() { return SIZE; }
	int find();
	void traverse() { for (auto i = 0; i < SIZE; ++i) cout << parent[i] << ends; }
private:
	size_t SIZE;
};
 void Union::union_element(int destination, int source) {
	 int temp = parent[destination];
	 if(!if_connected(destination,source))parent[destination] = parent[source];
	 for (auto i = 0; i < SIZE; ++i)if (parent[i] == temp)parent[i] = parent[source];
 }
 bool Union::if_connected(int first, int second) { if (parent[first] == parent[second])return true; else return false; }
int main()
{
	Union a;
	a.union_element(4,3);
	a.union_element(3, 8);
	a.union_element(6, 5);
	a.union_element(9, 4);
	a.union_element(2, 1);
	a.union_element(5, 0);
	a.union_element(7, 2);
	a.union_element(6, 1);
	a.traverse();

	
}

