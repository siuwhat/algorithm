

#include <iostream>
using namespace std;
template<class T>
class Node{
public:
    Node() = default;
    Node(T data):data(data){}
    Node<T>* next = NULL;
   T operator*() { return this->data; }
   bool operator!=(Node<T> user) const { return (*user) != this->data; }
   Node<T>& operator++() { *this = *this->next; return *this; }
    T data;
};
//实现c++11 range-based for做准备，需要operator*,operator! operator++和类的begin(),end()
template<class T>
class bag {
public:
    bag() = default;
    Node<T>* head=new Node<T>;
    Node<T>* tail;
     Node<T> begin()  { return *head; }
     Node<T> end() {
         tail=tail->next = new Node<T>;
         return *tail;

     }
     void add(T data) {
         if (is_empty()) { head->data = data; }
         else {
             
             auto oldNode = head;
             head = new Node<T>(data);
             head->next = oldNode;
             if (size() == 1) 
                 tail = oldNode; 
         }
         SIZE++;
     }
     bool is_empty()const { return size()==0; };
    size_t size() const{ return SIZE; }
private:
     size_t SIZE=0;
};

int main()
{
    bag<int> a;
    a.add(100);
    a.add(200);
    a.add(300);
    a.add(400);
    for (auto i : a)
        cout << i << endl;
}

