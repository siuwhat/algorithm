#include<string>
#include<queue>
#include<binaryNode.hpp>
#include<traverse.hpp>
#include<iostream>
using namespace std;
template<typename T>
class BST {
public:
    BST() { sz = hi = 0; top = NULL; }//初始化
    using value_type = T;
    void insert(const T& data);
    void insert(const initializer_list<T>& data_list) { for (auto i : data_list)insert(i); }
    void remove(const T& data);
    void remove(binaryNode<T>*node);
    constexpr binaryNode<T>* root() const { return top; }
    void inorder_traverse  (const binaryNode<T>* node/*=root()*/)   //中序遍历了解结构，这里不能用默认参数root()
    {
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
   binaryNode<T>* floor(const T& data);//小于等于data的元素
   binaryNode<T>* ceil (const T& data);//大于等于data的元素
   binaryNode<T>* max(binaryNode<T>*node) const{  while (node->rson)node = node->rson; return node; }//一个节点当做个子树看,最大的元素
   binaryNode<T>* min(binaryNode<T>*node) const{  while (node->lson)node = node->lson; return node; }//一个节点当做个子树看,最小的元素
    constexpr int size() const{ return sz; }
    constexpr int height() const { return hi; }
    binaryNode<T>* find(const T&data) 
    {
        if (auto node = find_it(data))return node; else { cout << "we can't find it!"; abort(); }
    }
    //通过find_it(data)获得准确的节点在哪，如果为空，程序截止
   
    ~BST() 
    {
        traverse(top);
    }//遍历删除元素
private:
    void traverse(binaryNode<T>* node) { if (node) { traverse(node->lson); traverse(node->rson); delete node; } }
    binaryNode<T>* find_it(const T& data);
    binaryNode<T>* search(const T& data);
    void swap(binaryNode<T>* left, binaryNode<T>* right) { auto t = left->data; left->data = right->data; right->data = t; }//只交换元素不交换指针
    constexpr bool is_exist(const binaryNode<T>* node) const { return node->lson || node->rson; }//判断双节点是否存在不存在返回false；
    int checksz(const binaryNode<T>*node) const
    {
        if (!node)return 0;
        return checksz(node->lson) + checksz(node->rson) + 1;
    }//遍历检查各个子树的size
    int checkhi(const binaryNode<T>* node) const
    {
        if(!node)return 0;
        return  std::max(checkhi(node->lson),checkhi(node->rson)) + 1;
    }//遍历检查各个子树的height

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
    }//删除叶子节点，如果是top，则置为空树。
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
    }//删除一个节点，该节点只有一个子树，该节点的父亲指向节点之子
    void remove_both(binaryNode<T>* node)
    {
        binaryNode<T>* temp = min(node->rson);
        BST<T>::swap(temp, node);
        remove(temp);
    }//不写交换而要考虑很多情况，所以为了方便。只转移数据

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

template<typename T> void BST<T>::insert(const T& data) {//利用BST的性质找到该插入的地方插入
    if (!top)top = new binaryNode<T>(data);
    else
    {   binaryNode<T>* temp = search(data);
    if(!temp||temp->data==data) 
    {
        cout << "you have inserted same data in BST!" << endl; abort();
    }
    else{
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
        if (temp->data == data)
            return nullptr;
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
    test.insert({ 'E','B','F','A','D','C','H','G','I','K','J' });
    traverse<decltype(test)>it(test);
    it.print_tree();
    /*test.insert({ 's','a','f','k','d','p','c','g'});
    test.insert('z');
    cout << " BST高度: " << test.height() << " BST元素个数: " << test.size() << endl;
    test.inorder_traverse(test.root());
    cout << endl;
    test.remove('k');
    cout << " BST高度: " << test.height() << " BST元素个数: " << test.size() << endl;
    test.inorder_traverse(test.root());
    cout << endl;
    test.remove('a');
    cout << " BST高度: " << test.height() << " BST元素个数: " << test.size() << endl;
    test.inorder_traverse(test.root());
    cout << endl;
    test.remove('d');
    cout << " BST高度: " << test.height() << " BST元素个数: " << test.size() << endl;
    test.inorder_traverse(test.root());
    cout << endl;
    test.remove('p');
    cout << " BST高度: " << test.height() << " BST元素个数: " << test.size() << endl;
    test.inorder_traverse(test.root());
    cout << endl;
    test.remove('s');
    cout << " BST高度: " << test.height() << " BST元素个数: " << test.size() << endl;
    test.inorder_traverse(test.root());
    cout << endl;
    test.remove('f');
    cout << " BST高度: " << test.height() << " BST元素个数: " << test.size() << endl;
    test.inorder_traverse(test.root());
    cout << endl;
    test.remove('g');
    cout << " BST高度: " << test.height() << " BST元素个数: " << test.size() << endl;
    test.inorder_traverse(test.root());
    cout << endl;
    test.remove('c');
    cout << " BST高度: " << test.height() << " BST元素个数: " << test.size() << endl;
    test.inorder_traverse(test.root());
    cout << endl;
  */
}

