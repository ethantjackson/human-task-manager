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

void SingletonUser::navigate() {
	char choice;
	cout << "Would you like to (1) move back one list, (2) move to subtask, or (3) stay: ";
	cin >> choice;
	while (choice != '3') {
		if (choice == '1') {
			if (curr->getParent() == nullptr) {
				cout << "Already at Home List..." << endl;
				return;
			}
			else {
				navigateBack();
			}
		}
		else if (choice == '2') {
			string task;
			cout << "Specify which subtask to move to: " << endl;
			cin.ignore();
			getline(cin, task);
			curr = curr->navigate(task);
		}
		else {
			cout << "Invalid Choice" << endl;
		}
		cout << "Would you like to (1) move back one list, (2) move to subtask, or (3) stay: ";
		cin >> choice;
		cout << endl;
	}
}

void SingletonUser::save()
{
	saveUsers();

	ofstream sfile;
	sfile.open(username + ".txt");
	if (sfile.is_open()) {
		sfile << homeList->save();
		sfile.close();
	}
	else {
		cout << "Failed to open: " << username << ".txt" << endl;
		exit(1);
	}
}

void SingletonUser::saveUsers() {
	 ofstream sfile;

        sfile.open("Users.txt");
        if (sfile.is_open()) {
                for (auto p : users) {
                        sfile << p.first << "," << p.second << ",";
                }
                sfile.close();
        }
}

void SingletonUser::reset()
{
	delete homeList;
	homeList = new TaskList("Home List", nullptr);
	ifstream sfile;
	sfile.open(username + ".txt");
	if (sfile.is_open()) {
		string data;
		string token;
		while (getline(sfile, token)) {
			data += token;
		}
		if (data != "") {
			homeList->load(data);
		}
   		sfile.close();
	}
	curr = homeList;
}
