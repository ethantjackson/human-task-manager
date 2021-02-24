#include "../header/SingletonUser.hpp"

SingletonUser* SingletonUser::instance = 0;

int main() {
	SingletonUser* user = user->getInstance();
	char action = user->getCurr()->run();
	while (action != 'q') {
		if (action == 'n') {
			user->navigate();
		}
		else if (action == 's') {
			user->save();
		}
		else if (action == 'u') {
			user->reset();
		}
		else if (action == 'l') {
			user->save();
			user->login();
			user->reset();
		}
		action = user->getCurr()->run();
	}
	user->save();
	return 0;
}
