#include "../header/InitFactory.h"
#include "../header/UserControl.h"

using namespace std;

void help()
{
        cout << "    i: info" << endl;
        cout << "    sd: set to done" << endl;
        cout << "    d: display" << endl;
        cout << "    cd: change description" << endl;
        cout << "    due: set due date" << endl;
        cout << "    a: add task/task list" << endl;
        cout << "    r: remove task/task list" << endl;
        cout << "    re: rename task/task list" << endl;
        cout << "    n: navigate task lists" << endl;
        cout << "    q: quit" << endl;
        cout << "    s: save" << endl;
        cout << "    u: undo last action" << endl;
		cout << "    z: redo" << endl;
        cout << "    l: login to new user" << endl;
}

int main() {
	UserControl* user = new UserControl();
	string answer;
	cout << "Enter action: (enter h for help)" << endl;
	cin >> answer; 
	while (answer != "q") {
		if (answer == "n") {
			user->navigate();
			user->log();
		}
		else if (answer == "s") {
			user->save();
		}
		else if (answer == "u") {
			cout << "Undoing...\n";
			user->undo();
		}
		else if (answer == "z") {
			cout << "Redoing...\n";
			user->redo();
		}
		else if (answer == "l") {
			user->save();
			user->login();
			user->reset();
    	}
		else if (answer == "h") {
			help();
		}
		else if (answer == "i") {
			char opt;
			cout << "View info for (1) the current list or (2) a subtask/list? " << endl;
			cin >> opt;
			if(opt == '1') {
				user->getCurr()->info();
			}
			else if(opt == '2') {
				string targetName;
				cout << "Enter the name of the task you want to find the info for: " << endl;
				cin.ignore();
				getline(cin, targetName);
				cout << endl;
				Component* target = user->getCurr()->getChild(targetName);
				if(target) {
					target->info();
				}
				else {
					cout << "Task/list Not Found..." << endl;
				}	
			}
			else {
				cout << "Invalid Choice..." << endl;
			}
		}

		else if (answer == "sd") {
			char choice;
			char opt;
			cout << "Set done/not done for (1) the current list or (2) a subtask/list?  " << endl;
			cin >> choice;
			cout << endl;
			if (choice == '1') {
				cout << "Is this current list done? (y/n) " << endl;
				cin >> opt;
				if (opt == 'y') {
					user->getCurr()->setDone(true);
					cout << "Current task list is done!" << endl;
					user->log();
				}
				else if (opt == 'n') {
					user->getCurr()->setDone(false);
					cout << "Current task list is not done." << endl;
					user->log();
				}
				else {
					cout << "Invalid Option..." << endl;
				}
			}
			else if (choice == '2') {
				string targetName;
				cout << "Enter the name of the subtask/list to be modified: " << endl;
				cin.ignore();
				getline(cin, targetName);
				Component* target = user->getCurr()->getChild(targetName);
				if(target) {
					cout << "Is this subtask/list done? (y/n) " << endl;
					cin >> opt;
					if (opt == 'y') {
						user->getCurr()->getChild(targetName)->setDone(true);
						cout << "Subtask/list is done!" << endl;
						user->log();
					}
					else if (opt == 'n') {
						user->getCurr()->getChild(targetName)->setDone(false);
						cout << "Subtask/list is not done." << endl;
						user->log();
					}
					else {
						cout << "Invalid Option..." << endl;
					}
				}
				else {
					cout << "Task/list Not Found..." << endl;
				}	
			}		
			else {
				cout << "Invalid Choice..." << endl;
			}
		}

		else if (answer == "d") {
			cout << endl;
			user->getCurr()->display();
		}

		else if (answer == "cd") {
			string newDescription;
			char choice;
			cout << "Change description for (1) the current list or (2) a subtask/list?" << endl;
			cin >> choice;
			if(choice == '1') {
				cout << "Enter new description: " << endl;
				cin.ignore();
				getline(cin, newDescription);
				user->getCurr()->setDescription(newDescription);
				cout << "Description updated." << endl;
				user->log();
			}
			else if(choice == '2') {
				string targetName;
				cout << "Enter the name of the subtask/list to be modified: " << endl;
				cin.ignore();
				getline(cin, targetName);
				Component* target = user->getCurr()->getChild(targetName);
				if(target) {
					cout << "Enter new description: " << endl;
					getline(cin, newDescription);
					target->setDescription(newDescription);
					cout << "Description updated." << endl;
					user->log();
				}
				else {
					cout << "Task/list Not Found..." << endl;
				}
			}
			else {
				cout << "Invalid Choice..." << endl;
			}
		}

		else if (answer == "due") {
			string newDueDate;
			char choice;
			cout << "Change due date for (1) the current list or (2) a subtask/list?" << endl;
			cin >> choice;
			if(choice == '1') {
				cout << "Enter new due date: " << endl;
				cin.ignore();
				getline(cin, newDueDate);
				user->getCurr()->setDueDate(newDueDate);
				cout << "Due date updated." << endl;
				user->log();
			}
			else if(choice == '2') {
				string targetName;
				cout << "Enter the name of the subtask/list to be modified: " << endl;
				cin.ignore();
				getline(cin, targetName);
				Component* target = user->getCurr()->getChild(targetName);
				if(target) {
					cout << "Enter new due date: " << endl;
					getline(cin, newDueDate);
					target->setDueDate(newDueDate);
					cout << "Due date updated." << endl;
					user->log();
				}
				else {
					cout << "Task/list Not Found..." << endl;
				}
			}
			else {
				cout << "Invalid Choice" << endl;
			}
		}

		else if (answer == "a") {
			string data;
			string tmp;
			char choice;
			cout << "Would you like to add a: (1) TaskList or (2) Task? ";
			cin >> choice; 
			cout << endl;
			switch (choice)
			{
			case '1':
				data+="<tl>,";
				cout << "Enter New TaskList Name: ";
				cin.ignore();
				getline(cin, tmp);
				data+=(tmp+',');
				cout << "Enter New TaskList Due Date (press ENTER if none): ";
				getline(cin, tmp);
				data+=(tmp+',');
				cout << "Enter New TaskList Description (press ENTER if none): ";
				getline(cin, tmp);
				data+=(tmp+',');
				data+="0,</tl>,";
				user->getCurr()->appendTaskList(data);
				cout << "Adding TaskList...\n";
				user->log();
			break;
			
			case '2':
				data+="<t>,";
				cout << "Enter New Task Name: ";
				cin.ignore();
				getline(cin, tmp);
				data+=(tmp+',');
				cout << "Enter New Task Due Date (press ENTER if none): ";
				getline(cin, tmp);
				data+=(tmp+',');
				cout << "Enter New Task Description (press ENTER if none): ";
				getline(cin, tmp);
				data+=(tmp+',');
				data+="0,</t>,";
				user->getCurr()->appendTask(data);
				cout << "Adding Task...\n";
				user->log();
			break;

			default:
				cout << "Invalid Choice...\n";
			break;
			}
		}

		else if (answer == "r") {
			string target;
			char choice;
			cout << "Would you like to (1) remove a subtask/list or (2) remove all contents?" << endl;
			cin >> choice;
			if (choice == '1') {
				cout << "Specify the subtask/list to remove: ";
				cin.ignore();
				getline(cin, target);
				Component* targetChild = user->getCurr()->getChild(target);
				if (targetChild) {
					cout << "Removing...\n";
					user->getCurr()->remove(target);
					user->log();
				}
				else cout << "Task/list not found...\n";
			}
			else if (choice == '2') {
				cout << "Clearing Contents...\n";
				user->getCurr()->removeAll();
				user->log();
			}
			else {
				cout << "Invalid Choice..." << endl;
			}
		}

		else if (answer == "re") {
			string newName;
			char choice;
			cout << "Would you like to rename (1) the current list or (2) a subtask/list?" << endl;
			cin >> choice;
			if (choice == '1') {
				cout << "Enter new title: " << endl;
				cin.ignore();
				getline(cin, newName);
				user->getCurr()->rename(newName);
				cout << "Current list has been renamed." << endl;
				user->log();
			}
			else if (choice == '2') {
				string targetName;
				cout << "Enter name of subtask/list to be renamed: " << endl;
				cin.ignore();
				getline(cin, targetName);
				Component* target = user->getCurr()->getChild(targetName);
				if(target) {
					cout << "Enter new title: " << endl;
					getline(cin, newName);
					target->rename(newName);
					cout << "Subtasklist has been renamed." << endl;
					user->log();
				}
				else {
					cout << "Task/list not found..." << endl;
				}
			}
			else {
				cout << "Invalid Choice" << endl;	
			}
		}

		else {
			cout << "Invalid Action" << endl;
		}

		cout << endl;
		cout << "Enter action: (enter h for help)" << endl;
		cin >> answer;
	}
		
	cout << "\nSaving...\n\n";
	user->save();

	delete user;	

	return 0;
}
