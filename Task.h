#ifndef TASK_H
#define TASK_H

#include <string>
#include <ctime>

class Task {
private:
    int id;
    std::string description;
    std::string status;  // "todo", "in-progress", "done"
    std::time_t createdAt;
    std::time_t updatedAt;

public:
    // Constructors
    Task();
    Task(int id, const std::string& description);

    // Getters
    int getId() const;
    std::string getDescription() const;
    std::string getStatus() const;
    std::time_t getCreatedAt() const;
    std::time_t getUpdatedAt() const;

    // Setters
    void setDescription(const std::string& description);
    void setStatus(const std::string& status);
    void setUpdatedAt();

    // File I/O
    std::string toFileString() const;
    static Task fromFileString(const std::string& line);
    
    // Display
    std::string toString() const;
};

#endif // TASK_H