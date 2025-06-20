# 📝 Task Tracker CLI — The Procrastinator’s Power Tool 🚀

Welcome to **Task Tracker CLI**: the C++ command-line task tracker that’s so simple, you might actually use it (and so quirky, your tasks might run away in fear).

---

## 🌳 Project Structure

Here’s what you’ll find in your **task-tracker** directory:

```
task-tracker/
├── CMakeLists.txt       # Build instructions for CMake (like a recipe, but for code)
├── Color.h              # Makes your terminal shine with colorful output
├── main.cpp             # Where the magic (main function) happens
├── package.json         # (Curious? Maybe for future npm integration or just a rebel file)
├── task-cli.exe         # The mighty Windows executable (double-click or run in terminal!)
├── Task.cpp             # Defines what a task can do (spoiler: a lot)
├── Task.h               # Declarations for your task objects
├── TaskManager.cpp      # The puppet master for all your tasks
├── TaskManager.h        # TaskManager’s declarations—like a rulebook
├── tasks.txt            # Your to-dos, hopes & dreams (saved here)
```

---

## ✨ Features

- **Add, list, update, and delete tasks**—no mouse required!
- **Colorful terminal output** (because your tasks deserve some flair)
- **All tasks saved in a plain text file** (`tasks.txt`)
- **C++ speed:** Blink and you’ll miss it
- **Runs offline:** No clouds, just code
- **Executable included:** For instant tracking action

---

## 🛠️ Installation

### Option 1: Build from Source

1. Make sure you have [CMake](https://cmake.org/) and a C++ compiler installed.
2. In your terminal:
    ```bash
    git clone https://github.com/adithiMurali/Task-Tracker-.git
    cd Task-Tracker-
    cmake .
    make
    ```
3. Run the program:
    ```bash
    ./task-cli   # Linux/Mac
    task-cli.exe # Windows
    ```

### Option 2: Use the Provided Executable (Windows)

Just double-click `task-cli.exe`  
_or_  
Open a terminal in this directory and run:
```bash
task-cli.exe
```
No install, no fuss, just tasks.

---

## 🚦 How to Use

Once you’re in the CLI, a menu will appear—just follow the prompts!  
Typical actions include:

- **Add a task:**  
  _Because future-you will thank you._

- **View tasks:**  
  _See what you’ve been putting off._

- **Mark as complete:**  
  _The dopamine hit you deserve._

- **Delete a task:**  
  _Because not every idea is a good one._

All your tasks are saved in `tasks.txt`. You can even open that file for a peek (or to edit manually, if you’re brave).

---

## 🧙 Example Workflow (CLI Style)

```
Welcome to Task Tracker!
1. Add Task
2. View Tasks
3. Mark Task as Complete
4. Delete Task
5. Exit
Enter your choice: 1

Enter task description: Finish README
Task added!
```

---

## 🦄 Contributing

Got a feature idea? Found a bug? Want to add ASCII art or support for rainbow colors?  
- Fork the repo
- Make your changes (bonus points for puns in comments)
- Open a pull request

All productivity hackers and procrastinators welcome!

---

## 📃 License

MIT. Use it, break it, improve it, share it.

---

## 🤔 FAQ

**Q: What’s with `package.json` in a C++ project?**  
A: It’s a mystery. Maybe the dev is planning something wild. Or just likes to live dangerously.

**Q: Can I edit `tasks.txt` by hand?**  
A: Yes, but don’t blame us if you break the space-time continuum.

**Q: Why C++?**  
A: Because tracking tasks should be as fast as your ability to forget them.

**Q: Will this work on Mac/Linux?**  
A: Yes, if you build from source. The provided `.exe` is for Windows users who love clicking things.

**Q: Where’s the GUI?**  
A: In your imagination. Or maybe in a future release.

---

May your tasks be few and your completions many!  
**Happy tracking!** 📝🚀
