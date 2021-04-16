#pragma once
#ifndef HAD_INCLUDED
#define HAD_INCLUDED
#include<Node.hpp>
#endif // !HAD_INCLUDED
template<class T>
class Stack{
public:
	Stack() = default;
	Node<T>* head;
	Node<T>* tail;
	constexpr Node<T> begin()const { assert(!is_empty()); return *head; }
	constexpr Node<T>end()const { assert(!is_empty()); return   *tail->next; }
	void push(T pushdata) {
		if (is_empty()) {
			head= new Node<T>(pushdata);
			tail = head;
			tail->next = new Node<T>;
			//防止单个元素的时候for()调用begin()还没有调用end()，返回的tail->next是NULL发生错误
		}
		else {
			/*if (tail->next != nullptr) { delete tail->next; }*///已经存在tail->next就删除，他需要去新的地方。
			auto oldNode = head;
			head = new Node<T>(pushdata);
			head->next = oldNode;
			if (size() == 1)
				tail = oldNode;
		}
		SIZE++;
	}
	T pop() {
		assert(!is_empty());
		auto oldNode = *head;
		if (head == tail)delete tail;
		head = head->next;
		SIZE--;
		return oldNode.data;
	}
	constexpr size_t size() const { return SIZE; }
	constexpr bool is_empty() const { return !size(); }
private:
	size_t SIZE = 0;

};
