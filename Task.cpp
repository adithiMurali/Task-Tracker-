#include "Task.h"
#include "Color.h"
#include <sstream>
#include <iomanip>

Task::Task() : id(0), status("todo") {
    createdAt = std::time(nullptr);
    updatedAt = createdAt;
}

Task::Task(int id, const std::string& description) 
    : id(id), description(description), status("todo") {
    createdAt = std::time(nullptr);
    updatedAt = createdAt;
}

int Task::getId() const {
    return id;
}

std::string Task::getDescription() const {
    return description;
}

std::string Task::getStatus() const {
    return status;
}

std::time_t Task::getCreatedAt() const {
    return createdAt;
}

std::time_t Task::getUpdatedAt() const {
    return updatedAt;
}

void Task::setDescription(const std::string& newDescription) {
    description = newDescription;
    setUpdatedAt();
}

void Task::setStatus(const std::string& newStatus) {
    status = newStatus;
    setUpdatedAt();
}

void Task::setUpdatedAt() {
    updatedAt = std::time(nullptr);
}

std::string Task::toFileString() const {
    std::stringstream ss;
    ss << id << "|" 
       << description << "|"
       << status << "|"
       << createdAt << "|"
       << updatedAt;
    return ss.str();
}

Task Task::fromFileString(const std::string& line) {
    std::stringstream ss(line);
    std::string item;
    Task task;
    
    // Parse ID
    std::getline(ss, item, '|');
    task.id = std::stoi(item);
    
    // Parse description
    std::getline(ss, task.description, '|');
    
    // Parse status
    std::getline(ss, task.status, '|');
    
    // Parse timestamps
    std::getline(ss, item, '|');
    task.createdAt = std::stoll(item);
    
    std::getline(ss, item, '|');
    task.updatedAt = std::stoll(item);
    
    return task;
}

std::string Task::toString() const {
    std::stringstream ss;
    
    // ID in cyan
    Color::setColor(Color::CYAN);
    ss << "ID: " << id << "\n";
    
    // Description in white
    Color::setColor(Color::WHITE);
    ss << "Description: " << description << "\n";
    
    // Status in appropriate color
    Color::setColor(Color::getStatusColor(status));
    ss << "Status: " << status << "\n";
    
    // Timestamps in gray
    Color::setColor(Color::GRAY);
    ss << "Created: " << std::put_time(std::localtime(&createdAt), "%Y-%m-%d %H:%M:%S") << "\n"
       << "Updated: " << std::put_time(std::localtime(&updatedAt), "%Y-%m-%d %H:%M:%S") << "\n";
    
    // Separator in gray
    ss << "---\n";
    
    // Reset color
    Color::reset();
    
    return ss.str();
}