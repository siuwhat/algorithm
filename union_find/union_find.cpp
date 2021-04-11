#include <iostream>
#include<vector>
using namespace std;

 class Union {
public:
	Union(size_t size = 10) :SIZE(size) { parent = vector<int>(SIZE); weight = vector<int>(SIZE); for (auto i = 0; i < SIZE; ++i) { parent[i] = i; weight[i] = 0; } }
	void union_element(int source, int destination);
	bool if_connected(int first,int second);
	size_t count() { return SIZE; }
	int find();
	void traverse() { for (auto i = 0; i < SIZE; ++i) cout << parent[i] << ends; cout << endl; }
	vector<int>weight;
private:
	size_t SIZE;
	vector<int>parent;
	
};
 void Union::union_element(int destination, int source) {
	 if (!if_connected(destination, source)) {
		 while (parent[source] != source)source = parent[source];
		 while (parent[destination] != destination)destination = parent[destination];
		 if (weight[source] >= weight[destination])
		 {
			 parent[destination] = source;	
			 weight[source]++;
			 weight[source]+=weight[destination];
		 }
		 else
		 {
			 parent[source] = destination;
			 weight[destination]++;
			 weight[destination]+=weight[source];
		 }
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
	a.union_element(3,4);
	a.union_element(3, 8);
	a.union_element(5, 6);
	a.union_element(9, 4);
	a.union_element(1, 2);
	a.union_element(0, 5);
	a.union_element(7, 2);
	a.union_element(1, 6);
	a.union_element(7, 3);
	
	

	
}

