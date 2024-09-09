/*
Build a simple console-based to-do list manager that allows users to add, view, and delete tasks.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string FILENAME = "todo_list.txt";

void add_task() {
    ofstream file;
    file.open(FILENAME, ios::app);  // Open the file in append mode

    if (file.is_open()) {
        string task;
        cout << "Enter a new task: ";
        cin.ignore();  // Clear the input buffer
        getline(cin, task);

        file << task << endl;
        file.close();
        cout << "Task added successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}

void view_tasks() {
    ifstream file;
    file.open(FILENAME);  // Open the file in read mode

    if (file.is_open()) {
        string task;
        int task_number = 1;

        cout << "\nTo-Do List:" << endl;
        while (getline(file, task)) {
            cout << task_number << ". " << task << endl;
            task_number++;
        }
        file.close();

        if (task_number == 1) {
            cout << "No tasks found." << endl;
        }
    } else {
        cout << "Error opening file!" << endl;
    }
}

void delete_task() {
    ifstream file;
    file.open(FILENAME);  // Open the file in read mode

    if (file.is_open()) {
        string task;
        int task_number = 1, delete_num;
        string tasks[100];
        int count = 0;

        while (getline(file, task)) {
            tasks[count] = task;
            count++;
        }
        file.close();

        if (count == 0) {
            cout << "No tasks to delete!" << endl;
            return;
        }

        cout << "\nTo-Do List:" << endl;
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }

        cout << "Enter the task number to delete: ";
        cin >> delete_num;

        if (delete_num < 1 || delete_num > count) {
            cout << "Invalid task number!" << endl;
            return;
        }

        ofstream temp_file;
        temp_file.open("temp.txt");

        for (int i = 0; i < count; i++) {
            if (i != delete_num - 1) {
                temp_file << tasks[i] << endl;
            }
        }
        temp_file.close();

        remove(FILENAME.c_str());
        rename("temp.txt", FILENAME.c_str());

        cout << "Task deleted successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                view_tasks();
                break;
            case 3:
                delete_task();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
