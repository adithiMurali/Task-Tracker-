#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <string>
#include "Task.h"

class TaskManager {
private:
    std::vector<Task> tasks;
    std::string filename;
    int nextId;

    void loadTasks();
    void saveTasks();
    int generateId();

public:
    TaskManager(const std::string& filename = "tasks.txt");
    
    void addTask(const std::string& description);
    void updateTask(int id, const std::string& description);
    void deleteTask(int id);
    void markTaskInProgress(int id);
    void markTaskDone(int id);
    void listAllTasks() const;
    void listTasksByStatus(const std::string& status) const;
    bool taskExists(int id) const;
    void printUsage() const;
};

#endif // TASK_MANAGER_H