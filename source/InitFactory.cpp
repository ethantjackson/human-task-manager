#include "InitFactory.h"

InitFactory::InitFactory() {
    root = new TaskList("Home List", nullptr);
}

TaskList* InitFactory::load(string data)
{
    stringstream ss(data);
    string info;
    string token;
    int endListCount;

    getline(ss, token, ','); // ignore first <tl>

    getline(ss, token, ',');
    root->rename(token);
    getline(ss, token, ',');
    root->setDueDate(token);
    getline(ss, token, ',');
    root->setDescription(token);
    getline(ss, token, ',');
    if (token == "1") root->setDone(true);
    else root->setDone(false);
    
    while (getline(ss, token, ',')) {
        if (token == "<tl>") {
            //append new task list
            endListCount = 1;
            info = token + ",";
            while (endListCount != 0) {
                getline(ss, token, ',');
                info += (token + ",");
                if (token == "</tl>") --endListCount;
                else if (token == "<tl>") ++endListCount;
                //cout << "tl token: \"" << token << "\"\n";
            }
            info += "</tl>,";
            //cout << "tl info: \"" << info << "\"\n";
            root->appendTaskList(info);
        }
        if (token == "<t>") {
            info = token + ",";
            while (token != "</t>") {
                getline(ss, token, ',');
                info += (token + ",");
                //cout << "t token: \"" << token << "\"\n";
            }
            info += "</t>,";
            //cout << "t info: \"" << info << "\"\n";
            root->appendTask(info);
        }
    }

    return root;
}
