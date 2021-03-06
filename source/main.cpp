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
        cout << "    r: remove task" << endl;
        cout << "    re: rename task" << endl;
        cout << "    n: navigate" << endl;
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
        user->getCurr()->info();
    }

    else if (answer == "sd") {
        char choice;
        cout << "Is this task list done?(y/n) ";
        cin >> choice;
        cout << endl;
        if (choice == 'y') {
            user->getCurr()->setDone(true);
        }
        else if (choice == 'n') {
            user->getCurr()->setDone(false);
        }
        else {
            cout << "Invalid Choice" << endl;
        }
    }

    else if (answer == "d") {
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
        user->getCurr()->remove();
    }

    else if (answer == "re") {
        string newName;
        cout << "Enter new title: " << endl;
        cin.ignore();
        getline(cin, newName);
        user->getCurr()->rename(newName);
    }

    else if (answer != "q" && answer != "n" && answer != "s" && answer != "u" && answer != "l") {
        cout << "Invalid Action" << endl;
    }

	  cout << endl;
	  cout << "Enter action: (enter h for help)" << endl;
	  cin >> answer;
	}
	
	user->getCurr()->save();

	return 0;
}
