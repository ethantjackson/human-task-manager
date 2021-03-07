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
        cout << "    u: undo to last save" << endl;
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
		}
    
		else if (answer == "s") {
			user->save();
		}

		else if (answer == "u") {
			user->reset();
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
	cout << "Enter whether you want info for (1)current or (2)child: " << endl;
	cin >> opt;
	if(opt == '1') {
	    user->getCurr()->info();
	}
	else if(opt == '2') {
	    string targetName;
	    cout << "Enter the name of the task you want to find the info for: " << endl;
	    cin.ignore();
	    getline(cin, targetName);
	    Component* target = user->getCurr()->getChild(targetName);
	    	if(target) {
		    target->info();
	    	}
	    	else {
		    cout << "Invalid name of task" << endl;
	        }	
	}
	else {
	    cout << "Invalid Choice" << endl;
	}
    }

    else if (answer == "sd") {
        char choice;
	char opt;
        cout << "Enter whether you want to set done for (1)current or (2)child:  " << endl;
        cin >> choice;
        cout << endl;
        if (choice == '1') {
	    cout << "Is this current list done? (y/n) " << endl;
	    cin >> opt;
	    if (opt == 'y') {
                user->getCurr()->setDone(true);
		cout << "Current task has been set to done" << endl;
            }
	    else if (opt == 'n') {
		user->getCurr()->setDone(false);
		cout << "Current task has been set to not done" << endl;
	    }
	    else {
		cout << "Invalid option" << endl;
	    }
	}
	else if (choice == '2') {
	    cout << "Is this child list done? (y/n) " << endl;
	    cin >> opt;
	    if (opt == 'y') {
		string targetName;
		cout << "Enter the name of the child list you want to have set done: " << endl;
		cin.ignore();
		getline(cin, targetName);
		Component* target = user->getCurr()->getChild(targetName);
		    if(target) {
			target->setDone(true);
			cout << "Child list has been set to done" << endl;
		    }
		    else {
			cout << "Invalid name of child list" << endl;
		    }
	    }
	    else if (opt == 'n') {
		string targetName;
		cout << "Enter the name of the child list you want to have set as not done: " << endl;
		cin.ignore();
		getline(cin, targetName);
		Component* target = user->getCurr()->getChild(targetName);
		    if(target) {
			target->setDone(false);
			cout << "Child list has been set to not done" << endl;
	    	    }
		    else {
			cout << "Invalid name of child list" << endl;
		    }
	    }
	}		
        else {
            cout << "Invalid Choice" << endl;
        }
    }

    else if (answer == "d") {
	cout << endl;
        user->getCurr()->display();
    }

    else if (answer == "cd") {
        string newDescription;
        cout << "Enter new description: " << endl;
        cin.ignore();
        getline(cin, newDescription);
        user->getCurr()->setDescription(newDescription);
    }

    else if (answer == "due") {
        string newDueDate;
        cout << "Enter new due date " << endl;
        cin.ignore();
        getline(cin, newDueDate);
        user->getCurr()->setDueDate(newDueDate);
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
          //cout << "data: \"" << data << "\"\n";
          user->getCurr()->appendTaskList(data);
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
          //cout << "data: \"" << data << "\"\n";
          user->getCurr()->appendTask(data);
          break;
          
        default:
          cout << "Invalid Choice...\n";
          break;
        }
    }

    else if (answer == "r") {
        string target;
        char choice;
        cout << "Would you like to (1) remove a subtask/list or (2) remove all contents? ";
        cin >> choice;
        if (choice == '1') {
          cout << "Specify the subtask/list to remove: ";
          cin.ignore();
          getline(cin, target);
          cout << "Removing...\n";
	  user->getCurr()->remove(target);
        }
        else if (choice == '2') {
	  cout << "Clearing Contents...\n";
          user->getCurr()->removeAll();
        }
    }

    else if (answer == "re") {
        string newName;
        cout << "Enter new title: " << endl;
        cin.ignore();
        getline(cin, newName);
        user->getCurr()->rename(newName);
    }

    else{
        cout << "Invalid Action" << endl;
    }

	  cout << endl;
	  cout << "Enter action: (enter h for help)" << endl;
	  cin >> answer;
	}
	
  cout << "\nSaving..." << endl;
	user->save();

	return 0;
}
