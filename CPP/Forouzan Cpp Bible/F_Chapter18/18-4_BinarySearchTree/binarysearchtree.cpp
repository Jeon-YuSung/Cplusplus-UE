//이진 탐색 트리 구현 파일
#ifndef BINARYSEARCHTREE_CPP
#define BINARYSEARCHTREE_CPP
#include "binarysearchtree.h"

//생성자 정의 
template<typename T>
Binary_search_tree<T>::Binary_search_tree() : root(0), count(0) {}

//소멸자 정의
template<typename T>
Binary_search_tree<T>::~Binary_search_tree() {
	destory(root);
}

//insert 함수 정의
template<typename T>
void Binary_search_tree<T>::insert(const T& value) {
	insert(value, root);
	count++;
}

//search 함수 정의 
template<typename T>
bool Binary_search_tree<T>::search(const T& value) const {
	return search(value, root);
}

//중위 순회 정의 
template<typename T>
void Binary_search_tree<T>::inorder() const {
	inorder(root);
}

//전위 순회 정의 
template<typename T>
void Binary_search_tree<T>::pre_order() const {
	pre_order(root);
}

//후위 순회 정의 
template<typename T>
void Binary_search_tree<T>::post_order() const {
	post_order(root);
}

//size 함수 정의 
template<typename T>
int Binary_search_tree<T>::size() const {
	return count;
}

//empty 함수 정의 
template<typename T>
bool Binary_search_tree<T>::empty() const {
	return (count == 0);
}


//헬퍼함수들 정의 
//소멸자에서 사용하는 헬퍼 함수 
template<typename T>
void Binary_search_tree<T>::destory(Node<T>* ptr) {

	if (!ptr) {
		return;
	}
	destory(ptr->left);
	destory(ptr->right);
	delete ptr;
}

//insert함수에서 활용하는 헬퍼 함수
template<typename T>
void Binary_search_tree<T>::insert(const T& value, Node<T>*& ptr) {

	if (!ptr) {
		ptr = makeNode(value);
		return;
	}
	else if (value < ptr->data) {
		insert(value, ptr->left);
	}
	else {
		insert(value, ptr->right);
	}
}

//전위 순회에서 사용할 헬퍼 함수 
template<typename T>
void Binary_search_tree<T>::pre_order(Node<T>* ptr) const {

	if (!ptr) {
		return;
	}
	cout << ptr->data << endl;
	pre_order(ptr->left);
	pre_order(ptr->right);
}

// 중위 순회에서 사용할 헬퍼 함수
template<typename T>
void Binary_search_tree<T>::inorder(Node<T>* ptr) const {

	if (!ptr) {
		return;
	}
	inorder(ptr->left);
	cout << ptr->data << endl;
	inorder(ptr->right);
}

// 후위 순회에서 사용할 헬퍼 함수
template<typename T>
void Binary_search_tree<T>::post_order(Node<T>* ptr) const {
	if (!ptr) {
		return;
	}
	post_order(ptr->left);
	post_order(ptr->right);
	cout << ptr->data << endl;
}

//search 함수에서 활용할 헬퍼 함수 
template<typename T>
bool Binary_search_tree<T>::search(const T& value, Node<T>* ptr) const {

	if (!ptr) {
		return false;
	}
	else if (ptr->data == value) {
		return true;
	}
	else if(value < ptr->data) {
		return search(value, ptr->left);
	}
	else {
		return search(value, ptr->right);
	}
}

//makeNode에서 활용할 헬퍼 함수 
template<typename T>
Node<T>* Binary_search_tree<T>::makeNode(const T& value) {

	Node<T>* temp = new Node<T>;
	temp->data = value;
	temp->left = 0;
	temp->right = 0;
	return temp;
}
#endif
