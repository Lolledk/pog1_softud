#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Class representing a task
class Task
{
    public:
    std::string _description;

     // Constructor to initialize a task with a description
    Task(std::string description){
        _description = description;
    }
};

// Class representing a to-do list
class TodoList
{
    
    public:
    std::vector<Task> todolist;

    // Method to add a task to the list
    void addTask(const std::string & description) {
        todolist.push_back(Task(description));
    }

    // Method to edit a task in the list
    void editTask(int index, const std::string & description) {
        if (index >= 0 && index < todolist.size()) {
            todolist[index]._description = description;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }

    TodoList(){}
};

int main() {
    TodoList todo = TodoList();
    std::string taskDescription;
    char choice;

    // Loop to allow the user to add multiple tasks
    while (choice != '4') {
    std::cout << "\nMenu: \n" << std::endl;

    std::cout << "1. Add a task" << std::endl;
    std::cout << "2. View tasks" << std::endl;
    std::cout << "3. Edit a task" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "\nEnter your choice: ";
    std::cin >> choice;
    std::cin.ignore(); // Clears the newline character from input buffer
    
    switch (choice) {
        case '1':
            std::cout << "\nEnter task description: ";
            std::getline(std::cin, taskDescription);
            todo.addTask(taskDescription);
            std::cout << "\nDo you want to add another task? (y/n): ";
            std::cin >> choice;
            std::cin.ignore(); // Clears the newline character from input buffer
            if (choice == 'y') {
                    std::cout << "\nEnter task description: ";
                    std::getline(std::cin, taskDescription);
                    todo.addTask(taskDescription);
                    break;
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
            for (int i = 0; i < todo.todolist.size(); i++) {
                std::cout << i + 1 << ". " << todo.todolist[i]._description << std::endl;
            }
            std::cout << std::endl;
            
            break;
        case '3':
            int taskNumber;
            std::cout << "\nEnter the task number to edit: ";
            std::cin >> taskNumber;
            std::cin.ignore(); // Clears the newline character from input buffer
            std::cout << "\nEnter new task description: ";
            std::getline(std::cin, taskDescription);
            todo.editTask(taskNumber - 1, taskDescription);
            break;
        case '4':
            std::cout << "\nExiting..." << std::endl;
            break;
        default:
            std::cout << "\nInvalid choice. Please try again." << std::endl;
    }
}
    return 0;
}