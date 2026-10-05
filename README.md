# DSA Lab 04: Singly Linked Lists

Data Structures and Algorithms, Department of Computing

| | |
|---|---|
| Name | Farhad Khan |
| CMS ID | 549034 |
| Section | BSCS-15_ E |
| Instructor | Sara Tariq Sheikh |
| Lab Engineer | Urooj Akmal |
| Lab Date | 29 September 2026 |

## About

This lab builds a singly linked list of integers in C++ from scratch. Every node is created with `new` and released with `delete`. No arrays, vectors or `std::list` are used to store the elements. Each task is one standalone `.cpp` file that compiles and runs on its own, and each one has a `List` class with a private `head` pointer.

## Files

| Name | Task | What it does |
|---|---|---|
| q1 | Creating and traversing | Reads three integers, links three nodes in input order, prints the list, clears it. Handles the empty list message. |
| q2 | Appending with a loop | `AddNode()` appends at the end, `CountNodes()` counts. Reads n and appends n integers. Tested with n = 0, 1 and 5. |
| q3 | Searching and second node | `SearchNode()` gives the position of the first match (starting at 1) or "Value not found". `PrintSecondNode()` handles lists with fewer than two nodes. |
| q4 | Inserting at the beginning | `InsertAtBeginning()` in O(1). Final order 10, 20, 30 after two beginning inserts and one append. |
| q5 | Deleting by value | `DeleteNode()` removes only the first match. Covers empty list, first, middle, last, missing value and only node. |
| q6 | Menu application | Menu with all operations from Tasks 1 to 5, invalid choice handling, and cleanup on exit. |

Each one is a single source file (q1 is `q1.cpp`, q2 is `q2.cpp`, and so on).

## How to run

Each file is a complete program on its own, so run them one at a time.

**Using an IDE (easiest)**

1. Open the file, for example `q1.cpp`, in your IDE.
2. Press the compile and run button.
   - Dev-C++: F11
   - Code::Blocks: F9
   - Visual Studio: Ctrl + F5
   - VS Code with a C++ extension: the play button at the top right
3. A console window opens. Type the inputs when it asks, for example `10 20 30` for q1.

**Using the terminal (optional)**

If you have the g++ compiler installed, open a terminal in this folder and run:

```
g++ q1.cpp -o q1
./q1
```

The first line turns the source code into a program, and the second line runs it. On Windows use `q1.exe` for the second line. For the other tasks replace q1 with q2, q3 and so on.

## Sample output

Task 4, insert at beginning then append:

```
Starting with an empty list:
The list is empty.

Insert 20 at the beginning:
20

Insert 10 at the beginning:
10 20

Append 30 at the end:
10 20 30
```

Task 5, duplicates, only the first match is removed:

```
Test 2: list 10 20 20 30, delete 20 once
10 20 20 30
20 deleted
10 20 30
```

## Memory safety

- Every node is allocated with `new` and released with `delete`.
- `ClearList()` saves the next pointer before deleting a node, then sets `head` to `nullptr`, and is called before every program ends.
- Pointers are checked before `->` is used.
- All six programs were built with AddressSanitizer and UndefinedBehaviorSanitizer and ran with no errors or leaks.

## Concepts covered

- **Why a position needs traversal:** each node only knows the address of the next one, so reaching position k means following k links from `head`. There is no direct index.
- **Why search is O(n):** the worst case (missing value or match at the end) visits every node once.
- **Insert at beginning is O(1), append is O(n):** the beginning only needs `head` updated, while appending has to walk to the last node first.
- **Deletion needs a previous pointer:** the list only has forward links, so the node before the target must be tracked to reconnect around it.

## Reference

Goodrich, M. T., Tamassia, R., & Mount, D. M. (2011). *Data Structures and Algorithms in C++* (2nd ed.). Wiley.
