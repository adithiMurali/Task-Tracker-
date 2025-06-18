#include "TaskManager.h"
#include "Color.h"
#include <iostream>
#include <string>

void printWelcome() {
    Color::setColor(Color::CYAN);
    std::cout << "\n Welcome to Task Tracker CLI!\n" << std::endl;
    Color::reset();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        TaskManager manager;
        printWelcome();
        manager.printUsage();
        return 1;
    }

    std::string command = argv[1];
    TaskManager manager;

    try {
        if (command == "add" && argc >= 3) {
            manager.addTask(argv[2]);
        }
        else if (command == "update" && argc >= 4) {
            int id = std::stoi(argv[2]);
            manager.updateTask(id, argv[3]);
        }
        else if (command == "delete" && argc >= 3) {
            int id = std::stoi(argv[2]);
            manager.deleteTask(id);
        }
        else if (command == "mark-in-progress" && argc >= 3) {
            int id = std::stoi(argv[2]);
            manager.markTaskInProgress(id);
        }
        else if (command == "mark-done" && argc >= 3) {
            int id = std::stoi(argv[2]);
            manager.markTaskDone(id);
        }
        else if (command == "list") {
            if (argc >= 3) {
                std::string status = argv[2];
                manager.listTasksByStatus(status);
            } else {
                manager.listAllTasks();
            }
        }
        else {
            printWelcome();
            manager.printUsage();
            return 1;
        }
    }
    catch (const std::exception& e) {
        Color::setColor(Color::RED);
        std::cerr << " Error: " << e.what() << std::endl;
        Color::reset();
        return 1;
    }

    return 0;
}