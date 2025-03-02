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
	TodoList(){}
};

int main() {
    
	char choice;

	// Loop to allow the user to add multiple tasks
<<<<<<< HEAD
	while (choice != '3') {
	std::cout << "Menu: \n" << std::endl;
=======
	do {
	std::cout << "Menu: " << std::endl;
>>>>>>> parent of eee1bdb (Menu Ficed GUI)
	std::cout << "1. Add a task" << std::endl;
	std::cout << "2. View tasks" << std::endl;
	std::cout << "3. Exit" << std::endl;
	std::cout << "Enter your choice: ";
	std::cin >> choice;
	std::cin.ignore(); // Clears the newline character from input buffer
	
	switch (choice) {
		case '1':
			std::cout << "Enter task description: ";
			std::getline(std::cin, taskDescription);
			todo.addTask(taskDescription);
			std::cout << "Do you want to add another task? (y/n): ";
			std::cin >> choice;
			std::cin.ignore(); // Clears the newline character from input buffer
		        switch (choice) {
					case 'y' || case 'Y':
						std::cout << "Enter task description: ";
						std::getline(std::cin, taskDescription);
						todo.addTask(taskDescription);
						break;
					case 'n' || case 'N':
						break;
				}
	std::cin.ignore();
			break;
		case '2':
			std::cout << "Tasks: " << std::endl;
			for (int i = 0; i < todo.todolist.size(); i++) {
				std::cout << i + 1 << ". " << todo.todolist[i]._description << std::endl;
			}
			std::cout << std::endl;
			
			break;
		case '3':
			std::cout << "Exiting..." << std::endl;
			break;
		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
	}

    return 0;
}
