Maze Builder and Solver :
Project Overview
This C-based Maze Solver is an educational application that allows users to input, visualize, and solve 5x5 mazes using stack-based pathfinding algorithms. The program demonstrates core data structure concepts and provides an interactive way to learn about backtracking and maze-solving techniques.

Key Features
Interactive Menu System: Users can input mazes, display them, and solve them through a simple console interface

Custom Maze Input: Accepts user-defined 5x5 mazes with walls ('1'), paths ('0'), start ('S'), and end ('E') points

Stack-Based Solver: Implements a linked list stack to explore paths and backtrack when needed

Path Visualization: Marks the solution path with asterisks ('*') when found

Input Validation: Ensures mazes contain exactly one start and one end point

Technical Implementation
Data Structures: Uses a linked list implementation of a stack for path tracking

Algorithms: Employs depth-first search with backtracking to navigate the maze

Memory Management: Properly allocates and frees stack nodes using malloc/free

Error Handling: Validates user input for correct maze format and content

Educational Value
This project serves as an excellent demonstration of:

Stack data structure applications

Backtracking algorithms

Dynamic memory management in C

2D array manipulation

User input validation

How to Use
Input a 5x5 maze when prompted (using 0, 1, S, and E characters)

Choose to solve the maze or display it

View the solution path marked with asterisks (if one exists)

Exit when finished
