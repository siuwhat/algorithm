
#include <iostream>
#include<string>
#include<binaryNode.hpp>
using namespace std;
template<typename T>
class BST {
public:
    BST() { sz = hi = 0; top = NULL; }
    void insert(const T& data);
    void insert(const initializer_list<T>& data_list) { for (auto i : data_list)insert(i); }
    void remove(const T& data);
    void remove(binaryNode<T>*node);
    constexpr binaryNode<T>* root() const { return top; }
    void inorder_traverse  (const binaryNode<T>* node)   {
        if (!node)return;
        inorder_traverse(node->lson);
        cout << node->data << " ";
        inorder_traverse(node->rson);
    }
    /*
问：一个类中，为什么不能将数据成员做为成员函数的默认参数？
答：标准规定这么一个限制条件是有其理由的，
非静态成员如果在成员函数被调用前没有被初始化，
此时编译器无法确认函数参数的默认值是多少。
而标准这样做就把错误的发现提前到编译期。
 */
   binaryNode<T>* floor(const T& data);
   binaryNode<T>* ceil (const T& data);
   binaryNode<T>* max(binaryNode<T>*node) const{  while (node->rson)node = node->rson; return node; }
   binaryNode<T>* min(binaryNode<T>*node) const{  while (node->lson)node = node->lson; return node; }
    constexpr int size() const{ return sz; }
    constexpr int height() const { return hi; }
    binaryNode<T>* find(const T&data) 
    {
        if (auto node = find_it(data))return node; else { cout << "we can't find it!"; abort(); }
    }
    ~BST() 
    {
        traverse(top);
    }
private:
    void traverse(binaryNode<T>* node) { if (node) { traverse(node->lson); traverse(node->rson); delete node; } }
    binaryNode<T>* find_it(const T& data);
    binaryNode<T>* search(const T& data);
    void swap(binaryNode<T>* left, binaryNode<T>* right) { auto t = left->data; left->data = right->data; right->data = t; }
    constexpr bool is_exist(const binaryNode<T>* node) const { return node->lson || node->rson; }
    int checksz(const binaryNode<T>*node) const
    {
        if (!node)return 0;
        return checksz(node->lson) + checksz(node->rson) + 1;
    }
    int checkhi(const binaryNode<T>* node) const
    {
        if(!node)return 0;
        return  std::max(checkhi(node->lson),checkhi(node->rson)) + 1;
    }

    void remove_leaf(binaryNode<T>* node)
    {
        if (node != top) {
            if (node->father->lson == node)
                node->father->lson = NULL;
            else
                node->father->rson = NULL;
        }
        else top = NULL;
        delete node;
    }
    void remove_one(binaryNode<T>* node)
    {
        if (node != top) {
            if (!node->lson)
            {
                if (node->father->lson == node)
                {
                    node->father->lson = node->rson;
                    node->rson->father = node->father;
                }
                else
                {
                    node->father->rson = node->rson;
                    node->rson->father = node->father;
                }
            }
            else
            {
                if (node->father->lson == node)
                {
                    node->father->lson = node->lson;
                    node->lson->father = node->father;
                }
                else
                {
                    node->father->rson = node->lson;
                    node->lson->father = node->father;
                }
            }
        }
        else {
            if (!node->lson) top = node->rson;
            else top = node->lson;
            
        }
        delete node;
    }
    void remove_both(binaryNode<T>* node)
    {
        binaryNode<T>* temp = min(node->rson);
        BST<T>::swap(temp, node);
        remove(temp);
    }

    int sz;
    int hi;
    binaryNode<T>*  top;
};
template<typename T> binaryNode<T>* BST<T>::find_it(const T& data)
{
    binaryNode<T>* temp = root();
    while (is_exist(temp)||temp->data==data)
    {
        if (temp->data == data)return temp;
        else if (data > temp->data) {
            if (temp->rson)
                temp = temp->rson;
            else break;
        }
        else {
            if (temp->lson)
                temp = temp->lson;
            else break;
        }
    }
    return nullptr;
}


template<typename T> binaryNode<T>* BST<T>::floor(const T& data)
{
    binaryNode<T>* close = top;
    while (is_exist(close))
    {
        if (data == close->data)return close;
        if (data > close->data)
        {
            if (close->rson)
                close = close->rson;
            else break;
        }
        else
        {
            if (close->lson)
                close = close->lson;
            else break;
        }
    }
    while (data<close->data)
    { binaryNode<T>* temp = close;
    close = close->father;
    if (temp != close->lson)
        return close;
    }
    return close;
}


template<typename T> binaryNode<T>* BST<T>::ceil(const T& data)
{
    binaryNode<T>* close = top;
    while (is_exist(close))
    {
        if (data == close->data)return close;
        if (data > close->data)
        {
            if (close->rson)
                close = close->rson;
            else break;
        }
        else
        {
            if (close->lson)
                close = close->lson;
            else break;
        }
    }
    while (data > close->data)
    {
        binaryNode<T>* temp = close;
        close = close->father;
        if (temp != close->rson)
            return close;
    }
    return close;
}

template<typename T> void BST<T>::insert(const T& data) {
    if (!top)top = new binaryNode<T>(data);
    else
    {   binaryNode<T>* temp = search(data);
        if (temp) {
            if (data > temp->data) 
            {
                temp->rson = new binaryNode<T>(data);
                temp->rson->father = temp;
            }
            else
            {
                temp->lson = new binaryNode<T>(data);
                temp->lson->father = temp;
            }

    }
    
    }
    sz = checksz(top);
    hi = checkhi(top);
}

template<typename T> void BST<T>::remove(const T& data) {
    if (!top) { cout << "top is not exist!" << endl; abort(); }
    binaryNode<T>* temp = find_it(data);
    if (!temp) { cout << "we can't find it that you want to remove!" << endl; abort(); }
    remove(temp);
    sz = checksz(top);
    hi = checkhi(top);
}
template<typename T> void BST<T>::remove(binaryNode<T>*node) {
    if (is_exist(node))
    {
        if (node->lson && node->rson)
            remove_both(node);//最棘手的两个
        else
            remove_one(node);//处理单个子树节点
    }
    else
        remove_leaf(node);//表示是个孤单的叶子结点
}

template<typename T> binaryNode<T>* BST<T>::search(const T& data) {
    if (top->data == data)return top;
    binaryNode<T>* temp = root();
    while (is_exist(temp)) {
        if (temp->data == data)return nullptr;
        if (data > temp->data)
            if (temp->rson)
                temp = temp->rson;
            else break;
        else if (data < temp->data)
            if (temp->lson)
                temp = temp->lson;
            else break;
}
    return temp;
}

int main()
{
    BST<char>test;
    test.insert({ 'S','E','X','A','C','R','V','Y'});
   /* cout << test.MAX()->data<<test.MIN()->data;
    cout << test.size() << test.height();
     test.inorder_traverse(test.root());*/
    test.inorder_traverse(test.root());
    cout << endl;
    test.remove('E');
    test.inorder_traverse(test.root());
    cout << endl;
    test.remove('S');
    test.inorder_traverse(test.root());
    cout << endl;
    test.remove('V');
    test.inorder_traverse(test.root());
    cout << endl;
    test.remove('X');
    test.inorder_traverse(test.root());
    cout << endl;
    test.remove('Y');
    test.inorder_traverse(test.root());
    cout << endl;
    test.remove('R');
    test.inorder_traverse(test.root());
    cout << endl;
    test.remove('A');
    test.inorder_traverse(test.root());
    cout << endl;
    test.remove('C');
    test.inorder_traverse(test.root());
    cout << endl;

}

