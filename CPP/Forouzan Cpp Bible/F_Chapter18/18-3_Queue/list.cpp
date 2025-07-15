//list 구현 파일
#ifndef LIST_CPP
#define LIST_CPP
#include "list.h"

//생성자 
template<typename T>
List<T>::List() : begin(0), count(0) {}

//소멸자
template<typename T>
List<T>::~List() {

	Node<T>* del = begin;
	while (begin) {
		begin = begin->next;
		delete del;
		del = begin;
	}
}

//insert 함수 정의 
template<typename T>
void List<T>::insert(int pos, const T& value) {

	if (pos < 0 || pos >count) {
		cout << "범위를 넘는 위치에 노드를 삽입할 수 없습니다. \n";
		return;
	}
	Node<T>* add = makeNode(value);
	if (pos == 0) {
		add->next = begin;
		begin = add;
	}
	else {
		Node<T>* cur = begin;
		for (int i = 1; i < pos; i++) {
			cur = cur->next;
		}
		add->next = cur->next;
		cur->next = add;
	}
	count++;
}

//erase 함수 정의
template<typename T>
void List<T>::erase(int pos) {

	if (pos<0 || pos> count - 1) {
		cout << "범위를 넘는 위치의 노드를 제거할 수 없습니다. \n ";
		return;
	}
	if (pos == 0) {
		Node<T>* del = begin;
		begin = begin->next;
		delete del;
	}
	else {
	
		Node<T>* cur = begin;
		for (int i = 0; i < pos - 1; i++) {
			cur = cur->next;
		}
		Node<T>* del = cur->next;
		cur->next = cur->next->next;
		delete del;
	}
	count--;
}

//get 함수 정의
template<typename T>
T& List<T>::get(int pos) const {
	
	if (pos<0 || pos>count - 1) {
		cout << "범위를 넘는 위치 노드에 접근 할 수 없습니다, 프로그램을 종료합니다 \n";
		assert(false);
	}
	else if (pos == 0) {
		return begin->data;
	}
	else {
		Node<T>* cur = begin;
		for (int i = 0; i < pos; i++) {
			cur = cur->next;
		}
		return cur->data;
	}
}
//print 함수 정의
template<typename T>
void List<T>::print() const {

	if (count == 0) {
		cout << "List가 비었습니다. \n";
		return;
	}
	Node<T>* cur = begin;
	while (cur != 0) {
		cout << cur->data << endl;
		cur = cur->next;
	}
}

//size 함수 정의
template<typename T>
int List<T>::size() const {

	return count;
}
//make noode 함수 정의 (private)
template<typename T>
Node<T>* List<T>::makeNode(const T& value) {

	Node<T>* temp = new Node<T>;
	temp->data = value;
	temp->next = 0;
	return temp;
}
#endif
