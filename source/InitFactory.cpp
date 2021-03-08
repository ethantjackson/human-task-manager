#include "../header/InitFactory.h"

InitFactory::InitFactory() {

}

InitFactory::~InitFactory() {

}

TaskList* InitFactory::load(string data)
{
    root = new TaskList("root", nullptr);
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

            }
            info += "</tl>,";

            root->appendTaskList(info);
        }
        if (token == "<t>") {
            info = token + ",";
            while (token != "</t>") {
                getline(ss, token, ',');
                info += (token + ",");

            }
            info += "</t>,";

            root->appendTask(info);
        }
    }

    return root;
}
