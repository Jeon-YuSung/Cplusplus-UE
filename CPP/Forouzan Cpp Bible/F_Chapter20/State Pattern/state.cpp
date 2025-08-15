#include "state.h"

void Light::setState(State* st) {
	state = st;
}

void Light::delState() {
	delete state;
}

void Light::turnSwitch() {
	state->handle(this);
}

void OffState::handle(Light* light) {

	std::cout << "불을 켭니다 \n";
	light->delState();
	light->setState(new OnState);

}

void OnState::handle(Light* light) {

	std::cout << "불을 끕니다 \n";
	light->delState();
	light->setState(new OffState);
}
