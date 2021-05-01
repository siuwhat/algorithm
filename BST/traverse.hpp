
#include<vector>
#include<queue>
#include<string>
#include<binaryNode.hpp>
#include<iostream>
using namespace std;
template<typename T>
class traverse {
public:
	using D = T::value_type;
    void print_tree() {
        queue<binaryNode<D>*>q;
        q.push(top);
        while (!q.empty())
        {
            vector<binaryNode<D>*>vec;
            while (!q.empty()) { vec.push_back(q.front()); q.pop(); }
            string line = "                        ";
            for (auto i : vec)
            {
                auto temp = i;
                if (temp)
                {
                    for (auto j = 0; j < inorder_vec.size(); ++j)
                    {
                        if (inorder_vec[j] == temp) { line[j] = temp->data; break; }
                    }
                    if (temp->lson) q.push(temp->lson);
                    if (temp->rson) q.push(temp->rson);
                }
            }
            cout << line << endl;
        }


    }
    traverse(const T& tree) :top(tree.root())
    {
        inorder_traverse(top);
    }
private:
	queue<binaryNode<D>*> q;
	vector<binaryNode<D>*>inorder_vec;
	void inorder_traverse(binaryNode<D>* node)
	{
		if (!node)return;
		inorder_traverse(node->lson);
		inorder_vec.push_back(node);
		inorder_traverse(node->rson);
	}
	binaryNode<D>* top;
	
    

};