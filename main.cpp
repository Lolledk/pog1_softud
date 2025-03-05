#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Class representing a task
class Task
{
    public:
    std::string _description;
    bool _completed;

     // Constructor to initialize a task with a description
    Task(std::string description){
        _description = description,
        _completed = false;
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
    void editTask(int index, const std::string & description, bool completed) {
        if (index >= 0 && index < todolist.size()) {
            todolist[index]._description = description;
            todolist[index]._completed = completed;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }

    // Method to remove a task from the list
    void markTaskAsCompleted(int index) {
        if (index >= 0 && index < todolist.size()) {
            todolist[index]._completed = true;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }

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
    char choice;

    // Loop to allow the user to add multiple tasks
    while (choice != '6') {
    std::cout << "\nMenu:" << std::endl;

    std::cout << "1. Add a task" << std::endl;
    std::cout << "2. Mark task as completed" << std::endl;
    std::cout << "3. View tasks" << std::endl;
    std::cout << "4. Edit a task" << std::endl;
    std::cout << "5. Delete a task" << std::endl;
    std::cout << "6. Exit" << std::endl;
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
            int taskNumber;
            std::cout << "\nEnter the task number to mark as completed: ";
            std::cin >> taskNumber;
            std::cin.ignore(); // Clears the newline character from input buffer
            todo.markTaskAsCompleted(taskNumber - 1);
            break;

        case '3':
            std::cout << "\nTasks: " << std::endl;
            for (int i = 0; i < todo.todolist.size(); i++) {
                std::cout << i + 1 << ". " << todo.todolist[i]._description;
                if (todo.todolist[i]._completed) {
                    std::cout << " [Completed]";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
            break;

        case '4':
            bool completed;
            std::cout << "\nEnter the task number to edit: ";
            std::cin >> taskNumber;
            std::cin.ignore(); // Clears the newline character from input buffer
            std::cout << "\nEnter new task description: ";
            std::getline(std::cin, taskDescription);
            std::cout << "\nIs the task completed? (y/n): ";
            std::cin >> choice;
            std::cin.ignore(); // Clears the newline character from input buffer
            todo.editTask(taskNumber - 1, taskDescription, completed);
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