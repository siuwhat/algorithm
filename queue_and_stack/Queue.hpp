#pragma once
#ifndef HAD_INCLUDED
#define HAD_INCLUDED
#include<Node.hpp>
#include<cassert>
#endif // !HAD_INCLUDED
template<class T>
class Queue {
public:
	Queue() = default;
	Node<T>* head;
	Node<T>* tail;
	constexpr Node<T> begin()const { assert(!is_empty()); return *head; }
	constexpr Node<T>end()const { assert(!is_empty()); return  tail->next == nullptr ? *(tail->next = new Node<T>) : *tail->next; }
	void push(T pushdata) {
		if (is_empty()) {
			tail = new Node<T>(pushdata);
			head = tail;
			tail->next = new Node<T>;
			//防止单个元素的时候for()调用begin()还没有调用end()，返回的tail->next是NULL发生错误
		}
		else {
			if (tail->next != nullptr) {delete tail->next; }//已经存在tail->next就删除，他需要去新的地方。
			auto oldNode = tail;
			tail = new Node<T>(pushdata);
			oldNode->next = tail;
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
