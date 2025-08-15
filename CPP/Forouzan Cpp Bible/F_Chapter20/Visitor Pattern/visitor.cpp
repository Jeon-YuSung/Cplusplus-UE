#include "visitor.h"

void EngVisitor::visit() {
	std::cout << "Good Morning! \n";
}

void FrenchVisitor::visit() {

	std::cout << "Bon Jour! \n";

}

void KoreanVisitor::visit() {

	std::cout << "안녕하세요 좋은 아침 입니다 \n";
}
