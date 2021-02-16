#include "SingletonUser.h"

SingletonUser::SingletonUser() {
	homeList = new TaskList("Home List", nullptr);
	ifstream sfile;

	sfile.open("Users.txt");
	if (sfile.is_open()) {
		string username;
		string password;
		while (getline(sfile, username, ',')) {
			getline(sfile, password, ',');
			users.push_back(make_pair(username, password));
		}
		sfile.close();
	}

	login();

	sfile.open(username + ".txt");
	if (sfile.is_open()) {
		string data;
		string title;
		while (getline(sfile, title)) {
			data += title;
		}
		if (data != "") {
			homeList->load(data);
		}
		sfile.close();
	}
	curr = homeList;
}
