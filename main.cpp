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
	Task(std::string description) : _description(description), _completed(false) {}
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

	void markTaskCompleted(int index) {
		if (index >= 0 && index < todolist.size()) {
			todolist[index]._completed = true;
		} else {
			std::cout << "Invalid task number. Please try again." << std::endl;
		}
	}

	TodoList(){}
};

int main() {
    
	TodoList todo;
	char choice;
	std::string taskDescription;

	// Loop to allow the user to add multiple tasks
	while (choice != '4') {
		std::cout << "\n Menu:" << std::endl;
		std::cout << "1. Add a task" << std::endl;
		std::cout << "2. Mark as completed" << std::endl;
		std::cout << "3. View tasks" << std::endl;
		std::cout << "4. Exit" << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		std::cin.ignore(); // Clears the newline character from input buffer

		switch (choice) {
			case '1':
				std::cout << "Enter task description: ";
				std::getline(std::cin, taskDescription);
				todo.addTask(taskDescription);
				break;

			case '2':
				std::cout << "Tasks: " << std::endl;
				for (int i = 0; i < todo.todolist.size(); i++) {
					std::cout << i + 1 << ". " << todo.todolist[i]._description << std::endl;
				}
				std::cout << "Enter the task number to mark as completed: ";
				int taskNumber;
				std::cin >> taskNumber;
				todo.markTaskCompleted(taskNumber - 1);
				break;

			case '3':
				std::cout << "Tasks: " << std::endl;
				for (int i = 0; i < todo.todolist.size(); i++) {
					std::cout << i + 1 << ". " << todo.todolist[i]._description;
					if (todo.todolist[i]._completed) {
						std::cout << " (Completed)";
					}
					std::cout << std::endl;
				}
				break;

			case '4':
				std::cout << "Exiting..." << std::endl;
				break;

			default:
				std::cout << "Invalid choice. Please try again." << std::endl;
		}
	}

    return 0;
}
