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

    TodoList todo = TodoList();
	std::string taskDescription;
	char choice;

	// Loop to allow the user to add multiple tasks
	do {std::cout << "Enter task description: ";

		std::getline(std::cin, taskDescription);

		todo.addTask(taskDescription);

		std::cout << "Do you want to add another task? (y/n): ";

		std::cin >> choice;

		std::cin.ignore();
		
	} while (choice == 'y' || choice == 'Y');

    return 0;
}
