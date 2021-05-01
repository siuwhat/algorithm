#pragma once
#ifndef NODE
#define NODE


template<class T>struct binaryNode {
	binaryNode(T data, binaryNode<T>* father = NULL, binaryNode<T>* lson = NULL, binaryNode<T>* rson = NULL) :
		father(father), lson(lson), rson(rson), data(data) {}
	binaryNode<T>* father;
	binaryNode<T>* lson;
	binaryNode<T>* rson;
	T data;
	//auto insertls(T data) {
	//	return lson = new binaryNode<T>(data, this);
	//}
	//auto insertrs(T data) {
	//	return rson = new binaryNode<T>(data, this);
	//}
	//auto remove() {
	//	delete rson;
	//	delete lson;
	//	delete this;
	//}
	/*bool operator<(const binaryNode<T>* node) { return node->data < data; }
	bool operator>(const binaryNode<T>* node) { return !(node < this); }
	bool operator==(const binaryNode<T>* node) { return data == node->data; }*/

};

#endif 