
#include <iostream>
#include<binaryNode.hpp>
using namespace std;
template<typename T>
class BST {
public:
    BST() { sz = hi = 0; top = NULL; }
    void insert(const T& data);
    void remove(const T& data);
    binaryNode<T>* search(const T& data);
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
   binaryNode<T>* floor(binaryNode<T>*node);
   binaryNode<T>* ceil (binaryNode<T>* node);
   binaryNode<T>* MAX() const{ binaryNode<T>* temp = root(); while (temp->rson)temp = rson; return temp; }
   binaryNode<T>* MIN() const{ binaryNode<T>* temp = root(); while (temp->lson)temp = lson; return temp; }
    constexpr int SIZE() const{ return sz; }
    constexpr int HEIGHT() const { return hi; }
    ~BST() { if(top)delete top; }

private:
    constexpr bool is_exist(const binaryNode<T>* node) const { return node->lson || node->rson; }
    int checksz(const binaryNode<T>*node) const
    {
        if (!node)return 0;
        return checksz(node->lson) + checksz(node->rson) + 1;
    }
    int checkhi(const binaryNode<T>* node) const
    {
        if(!node)return 0;
        return  max(checkhi(node->lson),checkhi(node->rson)) + 1;
    }
    int sz;
    int hi;
    binaryNode<T>*  top;
};

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

}

template<typename T> binaryNode<T>* BST<T>::search(const T& data) {
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
    test.insert('H');
    test.insert('S');
    test.insert('Z');
    test.insert('A');
    test.insert('G');
    cout << test.MAX()->data<<test.MIN()->data;
}

