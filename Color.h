#ifndef COLOR_H
#define COLOR_H

#include <windows.h>
#include <string>

class Color {
public:
    static void setColor(int color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

    static void reset() {
        setColor(7); // Default white color
    }

    // Predefined colors
    static const int RED = 12;
    static const int GREEN = 10;
    static const int BLUE = 9;
    static const int YELLOW = 14;
    static const int PURPLE = 13;
    static const int CYAN = 11;
    static const int WHITE = 15;
    static const int GRAY = 8;

    // Color a string
    static std::string colorize(const std::string& text, int color) {
        setColor(color);
        return text;
    }

    // Status-specific colors
    static int getStatusColor(const std::string& status) {
        if (status == "todo") return YELLOW;
        if (status == "in-progress") return BLUE;
        if (status == "done") return GREEN;
        return WHITE;
    }

    // Priority-specific colors
    static int getPriorityColor(int priority) {
        switch (priority) {
            case 1: return GREEN;  // Low
            case 2: return CYAN;   // Medium-Low
            case 3: return YELLOW; // Medium
            case 4: return RED;    // High
            case 5: return PURPLE; // Urgent
            default: return WHITE;
        }
    }
};

#endif // COLOR_H