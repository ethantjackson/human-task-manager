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

void SingletonUser::login()
{
	this->username = "none";
	string name;
	string pass;
   	char choice;
	bool incorrect;
	while (this->username == "none") {	
		incorrect = false;
		cout << "Enter username: ";
		cin >> name;
		cout << endl;
		for (auto p : users) {
			if (name == p.first) {
				cout << "Enter password: ";
				cin >> pass;
				cout << endl;
				if (pass == p.second) {
					cout << "Would you like to (1) login or (2) remove user: ";
					cin >> choice;
					cout << endl;
					if (choice == '1') {
						this->username = name;
						return;
					}
					else if (choice == '2') {
						vector<pair<string,string>> removedUser;
						for (unsigned i = 0; i < users.size(); ++i) {
							if (users.at(i).first != name) {
								removedUser.push_back(users.at(i));
							}
						}
						users = removedUser;
						string tmp = name + ".txt";
						remove(tmp.c_str());
						saveUsers();
					}
					else {
						cout << "Invalid Choice" << endl;
					}
				}
				else {
					cout << "Incorrect password" << endl;
				}
				incorrect = true;
			}
		}
		if (!incorrect) {
			cout << "User not found: " << endl;
			cout << "    (1) Add new user?" << endl;
			cout << "    (2) Display users?" << endl;
			cout << "    (3) Try again?" << endl;
			cin >> choice;
			if (choice == '1') {
				cout << endl << "Enter password: ";
				cin >> pass;
				cout << endl;
				users.push_back(make_pair(name, pass));
				this->username = name;
			}
			else if (choice == '2') {
				if (users.empty()) {
					cout << "No users yet..." << endl;
				}
				for (auto p : users) cout << p.first << endl;
			}
			else if (choice != '3') {
				cout << "Invalid Choice" << endl;
			}
		}
	}
}
