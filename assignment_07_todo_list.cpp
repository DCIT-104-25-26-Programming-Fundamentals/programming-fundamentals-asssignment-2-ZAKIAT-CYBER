// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function Prototypes
void addTask(vector<string>& tasks);
void viewTasks(const vector<string>& tasks);
void deleteTask(vector<string>& tasks);

int main() {
    vector<string> tasks;
    int choice = 0;

    // Use a loop to keep the menu running until option 4 (Quit) is chosen
    while (choice != 4) {
        cout << "\n=========================\n";
        cout << "      TO-DO LIST MENU      \n";
        cout << "=========================\n";
        cout << "1. Add task\n";
        cout << "2. View tasks\n";
        cout << "3. Delete task\n";
        cout << "4. Quit\n";
        cout << "Enter your choice (1-4): ";
        
        cin >> choice;

        // Handle invalid data types (e.g., if a user types a letter instead of a number)
        if (cin.fail()) {
            cin.clear(); 
            string dummy;
            cin >> dummy; 
            cout << "Invalid choice! Please enter a number between 1 and 4.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please choose a option between 1 and 4.\n";
                break;
        }
    }

    return 0;
}

// 1. Add a Task
void addTask(vector<string>& tasks) {
    string description;
    cout << "Enter task: ";
    cin.ignore(); // Clears out the leftover newline character from cin >> choice
    getline(cin, description); // Captures the full text sentence, spaces included
    
    tasks.push_back(description);
    cout << "Task added: \"" << description << "\"\n";
}

// 2. View All Tasks
void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty!\n";
        return;
    }

    cout << "Your Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << (i + 1) << ". " << tasks[i] << "\n";
    }
}

// 3. Delete a Task
void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to delete.\n";
        return;
    }

    // Display list with numbers first so user can choose
    viewTasks(tasks);

    int taskNumber;
    cout << "Enter task number to delete: ";
    cin >> taskNumber;

    // Validate if the input matches an index item inside the vector boundaries
    if (taskNumber > 0 && taskNumber <= static_cast<int>(tasks.size())) {
        // Convert human-readable 1-based index to 0-based vector index
        int indexToDelete = taskNumber - 1;
        string removedTask = tasks[indexToDelete];
        
        tasks.erase(tasks.begin() + indexToDelete);
        cout << "Task \"" << removedTask << "\" has been removed.\n";
    } else {
        cout << "Error: Invalid task number!\n";
    }
}
