#pragma once


template<class T>
class Node {
public:
	Node() = default;
	Node(T data) :data(data) {}
	Node<T>* next = nullptr;
	T data;
	T operator*() { return this->data; }
	bool operator!=( Node<T> user) const { return (*user) != this->data; }
	Node<T>& operator++() { *this = *this->next; return *this; }
	
};


