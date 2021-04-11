#include <iostream>
#include<vector>
using namespace std;

 class Union {
public:
	Union(size_t size = 10) :SIZE(size) { parent = vector<int>(SIZE); for (auto i = 0; i < SIZE; ++i)parent[i]=i; }	
	void union_element(int source, int destination);
	bool if_connected(int first,int second);
	size_t count() { return SIZE; }
	int find();
	void traverse() { for (auto i = 0; i < SIZE; ++i) cout << parent[i] << ends; cout << endl; }
private:
	size_t SIZE;
	vector<int>parent;
};
 void Union::union_element(int destination, int source) {
	 if (!if_connected(destination, source)) {
		 while (parent[source] != source)source = parent[source];
		 while (parent[destination] != destination)destination = parent[destination];
		 parent[destination] = source;
	 }
	 traverse();
 }
 bool Union::if_connected(int first, int second) {
	 while (parent[first] != first) { first = parent[first]; }
	 while (parent[second] != second) { second = parent[second]; }
	 return first==second?true:false; }
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
	a.union_element(7, 3);

	

	
}

