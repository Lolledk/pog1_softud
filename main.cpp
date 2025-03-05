#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Class representing a task
class Task
{
    public:
    std::string _description;
    std::string _deadline;
    bool _completed;

     // Constructor to initialize a task with a description
    Task(std::string description = "", std::string deadline = "") {
        _description = description,
        _deadline = deadline;
        _completed = false;
    }
};

// Class representing a to-do list
class TodoList
{
    public:
    std::vector<Task> todolist;

    // Method to add a task to the list
    void addTask(const std::string & description, const std::string & deadline ="") {
        todolist.push_back(Task(description, deadline));
    }

    // Method to edit a task in the list
    void editTask(int index, const std::string & description, const std::string & deadline, bool completed) {
        if (index >= 0 && index < todolist.size()) {
            todolist[index]._description = description;
            todolist[index]._deadline = deadline;
            todolist[index]._completed = completed;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }

    // Method to mark a task as completed
    void markTaskAsCompleted(int index) {
        if (index >= 0 && index < todolist.size()) {
            todolist[index]._completed = true;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }

    // Method to remove a task from the list
    void deleteTask(int index) {
        if (index >= 0 && index < todolist.size()) {
            todolist.erase(todolist.begin() + index);
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }


    TodoList(){}
};

int main() {
    TodoList todo = TodoList();
    std::string taskDescription;
    std::string taskDeadline;
    char choice;

    // Loop to allow the user to add multiple tasks
    while (choice != '6') {
    std::cout << "\nMenu:" << std::endl;

    std::cout << "1. Add a task" << std::endl;
    std::cout << "2. View tasks" << std::endl;
    std::cout << "3. Edit a task" << std::endl;
    std::cout << "4. Mark task as completed" << std::endl;
    std::cout << "5. Delete a task" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "\nEnter your choice: ";
    std::cin >> choice;
    std::cin.ignore(); // Clears the newline character from input buffer
    
    switch (choice) {
        case '1':
            std::cout << "\nEnter task description: ";
            std::getline(std::cin, taskDescription);
            std::cout << "\nDo you want to add a deadline to this task? (y/n): ";
            std::cin >> choice;
            std::cin.ignore(); // Clears the newline character from input buffer
            if (choice == 'y') {
                std::cout << "\nEnter deadline: ";
                std::getline(std::cin, taskDeadline);
            } else {
                taskDeadline = "";
            }
            todo.addTask(taskDescription, taskDeadline);
            std::cout << "\nDo you want to add another task? (y/n): ";
            std::cin >> choice;
            std::cin.ignore(); // Clears the newline character from input buffer
            if (choice == 'y') {
                continue;
                }
            else if (choice == 'n') {
                break;
            }
            else {
                std::cout << "\nInvalid choice. Returning to main menu." << std::endl;
                break;
            }
            std::cin.ignore();
            break;
        
        case '2':
            std::cout << "\nTasks: " << std::endl;
            if (todo.todolist.size() == 0) {
                std::cout << "No tasks." << std::endl;
            }
            for (int i = 0; i < todo.todolist.size(); i++) {
                std::cout << i + 1 << ". " << todo.todolist[i]._description << " - " << todo.todolist[i]._deadline;
                if (todo.todolist[i]._completed) {
                    std::cout << " [Completed]";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        break;


        case '3':
            bool completed;
            int taskNumber;
            std::cout << "\nEnter the task number to edit: ";
            std::cin >> taskNumber;
            std::cin.ignore(); // Clears the newline character from input buffer
            std::cout << "\nEnter new task description: ";
            std::getline(std::cin, taskDescription);
            std::cout << "\nEnter new task deadline: ";
            std::getline(std::cin, taskDeadline);
            std::cout << "\nIs the task completed? (y/n): ";
            std::cin >> choice;
            std::cin.ignore(); // Clears the newline character from input buffer
            completed = (choice == 'y');
            todo.editTask(taskNumber - 1, taskDescription, taskDeadline, completed);
            break;

        case '4':
            std::cout << "\nEnter the task number to mark as completed: ";
            std::cin >> taskNumber;
            std::cin.ignore(); // Clears the newline character from input buffer
            todo.markTaskAsCompleted(taskNumber - 1);
            break;

        case '5':
            std::cout << "\nEnter the task number to delete: ";
            std::cin >> taskNumber;
            std::cin.ignore(); // Clears the newline character from input buffer
            todo.deleteTask(taskNumber - 1);
            break;
        
        case '6':
            std::cout << "\nExiting..." << std::endl;
            break;
        
        default:
            std::cout << "\nInvalid choice. Please try again." << std::endl;
    }
}
    return 0;
}