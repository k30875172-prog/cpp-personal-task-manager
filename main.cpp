#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string name;
    bool completed;
};

vector<Task> tasks;

// Add new task
void addTask() {
    Task t;

    cout << "Enter task name: ";
    getline(cin, t.name);

    t.completed = false;
    tasks.push_back(t);

    cout << "Task added successfully!\n";
}

// View all tasks
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].name;

        if (tasks[i].completed)
            cout << " [Completed]";
        else
            cout << " [Pending]";

        cout << endl;
    }
}

// Update task
void updateTask() {
    int n;

    viewTasks();

    if (tasks.empty()) return;

    cout << "Enter task number to update: ";
    cin >> n;
    cin.ignore();

    if (n >= 1 && n <= tasks.size()) {
        cout << "Enter new task name: ";
        getline(cin, tasks[n - 1].name);

        cout << "Task updated successfully!\n";
    }
    else {
        cout << "Invalid task number!\n";
    }
}

// Complete task
void completeTask() {
    int n;

    viewTasks();

    if (tasks.empty()) return;

    cout << "Enter task number: ";
    cin >> n;

    if (n >= 1 && n <= tasks.size()) {
        tasks[n - 1].completed = true;
        cout << "Task completed successfully!\n";
    }
    else {
        cout << "Invalid task number!\n";
    }
}

// Delete task
void deleteTask() {
    int n;

    viewTasks();

    if (tasks.empty()) return;

    cout << "Enter task number to delete: ";
    cin >> n;

    if (n >= 1 && n <= tasks.size()) {
        tasks.erase(tasks.begin() + n - 1);
        cout << "Task deleted successfully!\n";
    }
    else {
        cout << "Invalid task number!\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== PERSONAL TASK MANAGER =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Update Task\n";
        cout << "4. Complete Task\n";
        cout << "5. Delete Task\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addTask();
                break;

            case 2:
                viewTasks();
                break;

            case 3:
                updateTask();
                break;

            case 4:
                completeTask();
                break;

            case 5:
                deleteTask();
                break;

            case 6:
                cout << "Thank you for using Task Manager!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
