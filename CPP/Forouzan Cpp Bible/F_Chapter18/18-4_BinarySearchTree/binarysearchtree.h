#pragma once
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <cassert>
using namespace std;


//node 구조체 정의
template<typename T>
struct Node {

	T data;
	Node<T>* left;
	Node<T>* right;

};

//이진 탐색 트리 클래스 정의
template <typename T>
class Binary_search_tree {

private:
	Node<T>* root;
	int count;
	Node<T>* makeNode(const T& value);

	//헬퍼 함수 선언 
	void destory(Node<T>* ptr); 
	void insert(const T& value, Node<T>*& ptr);
	void inorder(Node<T>* ptr) const;
	void pre_order(Node<T>* ptr) const;
	void post_order(Node<T>* ptr) const;
	bool search(const T& value, Node<T>* ptr) const;

public:
	Binary_search_tree();
	~Binary_search_tree();
	void insert(const T& value);
	void erase(const T& value);
	bool search(const T& value) const;
	void inorder() const;
	void pre_order() const;
	void post_order() const;
	int size() const;
	bool empty() const;

};
#endif
