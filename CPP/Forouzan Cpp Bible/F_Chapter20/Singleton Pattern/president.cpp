#include "president.h"

President* President::ptr = 0;

// ������ ���� 
President::President(string nm) : name(nm) {
	cout << "��ǥ�� ���� �Ǿ����ϴ�.\n";
}

// create ���� �Լ� ����
President* President::create(string name) {

	if (!ptr) {
		ptr = new President(name);
	}
	else {
		cout << "��ǥ�� �̹� ������ �����մϴ�! \n";
	}
	return ptr;
}

//������ �Լ� 
string President::getName() const {
	return name;
}