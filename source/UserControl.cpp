#include "../header/UserControl.h"

UserControl::UserControl() {
	init = new InitFactory();
	homeList = new TaskList("Home List", nullptr);
	ifstream sfile;

	sfile.open("Users`.txt");
	if (sfile.is_open()) {
		string username;
		string password;
		while (getline(sfile, username, '`')) {
			getline(sfile, password, '`');
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
			delete homeList;
			homeList = init->load(data);
		}
		sfile.close();
	}
	curr = homeList;
	log();
}

UserControl::~UserControl() {
    delete init;
    delete homeList;
}

void UserControl::navigate() {
	char choice;
	cout << "Would you like to (1) move back one list, (2) move to sub-tasklist, or (3) stay: ";
	cin >> choice;
	while (choice != '3') {
		if (choice == '1') {
			if (curr->getParent() == nullptr) {
				cout << "Already at Home List..." << endl << endl;
			}
			else {
				navigateBack();
        			curr->display();
        			cout << endl;
			}
		}
		else if (choice == '2') {
			string task;
			cout << "Specify which sub-tasklist to move to: ";
			cin.ignore();
			getline(cin, task);
      			cout << endl;
			curr = curr->navigate(task);
			cout << endl;
      			curr->display();
      			cout << endl;
		}
		else {
			cout << "Invalid Choice" << endl;
		}
		cout << "Would you like to (1) move back one list, (2) move to subtask, or (3) stay: ";
		cin >> choice;
		cout << endl;
	}
}

void UserControl::save()
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

void UserControl::saveUsers() {
	 ofstream sfile;

        sfile.open("Users`.txt");
        if (sfile.is_open()) {
                for (auto p : users) {
                        sfile << p.first << "`" << p.second << "`";
                }
                sfile.close();
        }
}

void UserControl::reset()
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
			delete homeList;;
			homeList = init->load(data);
		}
   		sfile.close();
	}			
	curr = homeList;
	while(!saves.empty()) saves.pop();
	log();
}

void UserControl::login()
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
		while((name.find("<")!=string::npos) || (name.find(">")!=string::npos) || (name.find("`")!=string::npos))
                {
			incorrect = true;
			cout << "The use of the characters \"<\", \">\", and \"`\" are not permitted...1" << endl;
			cout << "Enter username: ";
			cin >> name;
			cout << endl;
		}
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
				if((pass.find("<")!=string::npos) || (pass.find(">")!=string::npos) || (pass.find("`")!=string::npos))
                		{
                			cout << "The use of the characters \"<\", \">\", and \"`\" are not permitted..." << endl;
               	 		}
				else {
					cout << endl;
					users.push_back(make_pair(name, pass));
					this->username = name;
				}
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

void UserControl::log() {
	string logData = homeList->save();
	saves.push(make_pair(logData,curr->getRootPath()));
	while (!redos.empty()) redos.pop();
}

void UserControl::undo() {
	if (saves.size() > 1) {
		redos.push(saves.top());
		saves.pop();
		delete homeList;
		homeList = init->load(saves.top().first);
		curr = findPrevCurr(saves.top().second); // find curr
	}
	else {
		cout << "Cannot Undo Further." << endl;
	}
}
void UserControl::redo() {
	if (redos.size() > 0) {
		saves.push(redos.top());
		redos.pop();
		delete homeList;
		homeList = init->load(saves.top().first);
		curr = findPrevCurr(saves.top().second); // find curr
	}
	else {
		cout << "Cannot Redo Further." << endl;
	}
}

TaskList* UserControl::findPrevCurr(vector<string> path) {
	TaskList* curr = homeList;
	for (auto s : path) {
		curr = static_cast<TaskList*>(curr->getChild(s));
	}
	return curr;
}
