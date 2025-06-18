#include "TaskManager.h"
#include "Color.h"
#include <fstream>
#include <iostream>
#include <algorithm>

TaskManager::TaskManager(const std::string& filename) 
    : filename(filename), nextId(1) {
    loadTasks();
}

void TaskManager::loadTasks() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        Color::setColor(Color::YELLOW);
        std::cout << "No existing tasks file found. Starting fresh!" << std::endl;
        Color::reset();
        return;
    }

    std::string line;
    tasks.clear();
    while (std::getline(file, line)) {
        if (!line.empty()) {
            Task task = Task::fromFileString(line);
            tasks.push_back(task);
            nextId = std::max(nextId, task.getId() + 1);
        }
    }
    Color::setColor(Color::GREEN);
    std::cout << "Successfully loaded " << tasks.size() << " tasks." << std::endl;
    Color::reset();
}

void TaskManager::saveTasks() {
    std::ofstream file(filename);
    if (!file.is_open()) {
        Color::setColor(Color::RED);
        std::cerr << "Error: Could not save tasks to file!" << std::endl;
        Color::reset();
        return;
    }

    for (const auto& task : tasks) {
        file << task.toFileString() << std::endl;
    }
}

int TaskManager::generateId() {
    return nextId++;
}

void TaskManager::addTask(const std::string& description) {
    Task task(generateId(), description);
    tasks.push_back(task);
    saveTasks();
    Color::setColor(Color::GREEN);
    std::cout << " Task added successfully (ID: " << task.getId() << ")" << std::endl;
    Color::reset();
}

void TaskManager::updateTask(int id, const std::string& description) {
    auto it = std::find_if(tasks.begin(), tasks.end(),
        [id](const Task& task) { return task.getId() == id; });

    if (it != tasks.end()) {
        it->setDescription(description);
        saveTasks();
        Color::setColor(Color::GREEN);
        std::cout << " Task " << id << " updated successfully" << std::endl;
        Color::reset();
    } else {
        Color::setColor(Color::RED);
        std::cerr << " Error: Task " << id << " not found!" << std::endl;
        Color::reset();
    }
}

void TaskManager::deleteTask(int id) {
    auto it = std::remove_if(tasks.begin(), tasks.end(),
        [id](const Task& task) { return task.getId() == id; });

    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        saveTasks();
        Color::setColor(Color::GREEN);
        std::cout << " Task " << id << " deleted successfully" << std::endl;
        Color::reset();
    } else {
        Color::setColor(Color::RED);
        std::cerr << " Error: Task " << id << " not found!" << std::endl;
        Color::reset();
    }
}

void TaskManager::markTaskInProgress(int id) {
    auto it = std::find_if(tasks.begin(), tasks.end(),
        [id](const Task& task) { return task.getId() == id; });

    if (it != tasks.end()) {
        it->setStatus("in-progress");
        saveTasks();
        Color::setColor(Color::BLUE);
        std::cout << " Task " << id << " marked as in-progress" << std::endl;
        Color::reset();
    } else {
        Color::setColor(Color::RED);
        std::cerr << " Error: Task " << id << " not found!" << std::endl;
        Color::reset();
    }
}

void TaskManager::markTaskDone(int id) {
    auto it = std::find_if(tasks.begin(), tasks.end(),
        [id](const Task& task) { return task.getId() == id; });

    if (it != tasks.end()) {
        it->setStatus("done");
        saveTasks();
        Color::setColor(Color::GREEN);
        std::cout << " Task " << id << " marked as done" << std::endl;
        Color::reset();
    } else {
        Color::setColor(Color::RED);
        std::cerr << " Error: Task " << id << " not found!" << std::endl;
        Color::reset();
    }
}

void TaskManager::listAllTasks() const {
    if (tasks.empty()) {
        Color::setColor(Color::YELLOW);
        std::cout << " No tasks found. Add some tasks to get started!" << std::endl;
        Color::reset();
        return;
    }

    Color::setColor(Color::CYAN);
    std::cout << "\n Task List (" << tasks.size() << " tasks):\n" << std::endl;
    Color::reset();

    for (const auto& task : tasks) {
        std::cout << task.toString() << std::endl;
    }
}

void TaskManager::listTasksByStatus(const std::string& status) const {
    bool found = false;
    int count = 0;

    Color::setColor(Color::CYAN);
    std::cout << "\n Tasks with status '" << status << "':\n" << std::endl;
    Color::reset();

    for (const auto& task : tasks) {
        if (task.getStatus() == status) {
            std::cout << task.toString() << std::endl;
            found = true;
            count++;
        }
    }

    if (!found) {
        Color::setColor(Color::YELLOW);
        std::cout << " No tasks found with status: " << status << std::endl;
        Color::reset();
    } else {
        Color::setColor(Color::GREEN);
        std::cout << "Found " << count << " task(s) with status '" << status << "'" << std::endl;
        Color::reset();
    }
}

bool TaskManager::taskExists(int id) const {
    return std::any_of(tasks.begin(), tasks.end(),
        [id](const Task& task) { return task.getId() == id; });
}

void TaskManager::printUsage() const {
    Color::setColor(Color::CYAN);
    std::cout << "\n Task Tracker CLI - Usage Guide:\n" << std::endl;
    Color::reset();
    
    Color::setColor(Color::WHITE);
    std::cout << "  task-cli add \"Task description\"     - Add a new task\n"
              << "  task-cli update <id> \"New desc\"     - Update a task\n"
              << "  task-cli delete <id>                - Delete a task\n"
              << "  task-cli mark-in-progress <id>      - Mark task as in progress\n"
              << "  task-cli mark-done <id>             - Mark task as done\n"
              << "  task-cli list                       - List all tasks\n"
              << "  task-cli list todo                  - List todo tasks\n"
              << "  task-cli list in-progress           - List in-progress tasks\n"
              << "  task-cli list done                  - List done tasks\n"
              << std::endl;
    Color::reset();
}