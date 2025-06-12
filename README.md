# ft_list

This repository contains the implementation of various list-based utility functions in C. These functions provide foundational operations on linked lists, useful in a variety of applications.

## Table of Contents

1. [Project Overview](#project-overview)
2. [Directory Structure](#directory-structure)
3. [How It Works](#how-it-works)
4. [Usage](#usage)
5. [Flowcharts for Functions](#flowcharts-for-functions)
6. [Contributing](#contributing)

---

## Project Overview

The **ft_list** project focuses on creating and manipulating linked lists in C. It provides functionalities for basic list operations such as creation, addition, deletion, and traversal.

### Features

- Creation and initialisation of linked lists.
- Adding elements to the head or tail of the list.
- Traversing and modifying list elements.
- Deleting elements from the list.

---

## Directory Structure

```plaintext
ft_list/
├── srcs/
│   ├── ft_list.c        # Core logic of linked list operations
│   ├── ft_list_utils.c  # Helper functions
│   └── Makefile         # Build script
├── includes/
│   └── ft_list.h        # Header file with function prototypes
└── tests/
    └── test_list.c      # Test cases for linked list functions
```

---

## How It Works

The **ft_list** functions work with a custom `t_list` structure that represents each node in the linked list. Each node contains data and a pointer to the next node in the list.

### Key Steps:

1. **Initialisation**: Create a new list or node.
2. **Adding Elements**: Append or prepend elements to the list.
3. **Traversing**: Iterate through the list to perform operations.
4. **Deletion**: Remove nodes from the list, freeing memory.

---

## Usage

1. Include `ft_list.h` in your project:
   ```c
   #include "ft_list.h"
   ```
2. Use the provided functions:
```c
void	ft_lstiter(t_list *lst, void (*f)(void*));
```
```c
void	ft_lstadd_back(t_list **lst, t_list *new);
```
```c
void	ft_lstadd_front(t_list **lst, t_list *new);
```
```c
void	ft_lstclear(t_list **lst, void (*del)(void*));
```
```c
void	ft_lstdelone(t_list *lst, void (*del)(void*));
```
```c
t_list	*ft_lstlast(t_list *lst);
```
```c
t_list	*ft_lstnew(void *content);
```
```c
t_list *ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));
```c
t_list *list = ft_list_create_node(data);
```
```c
ft_list_add_front(&list, new_data);
```
```c
ft_list_traverse(list, print_function);
```
```c
ft_list_clear(&list);
```
3. Compile using the provided Makefile:
   ```bash
   make
   ```

---

## Flowcharts for Functions

### 1. `ft_lstiter`

```mermaid
graph TD
    A[Start] --> B[Check if list and function are valid]
    B --> C{Current node exists?}
    C -- Yes --> D[Apply function to node's data]
    D --> E[Move to next node]
    E --> C
    C -- No --> F[End]
```

### 2. `ft_lstadd_back`

```mermaid
graph TD
    A[Start] --> B[Check if list pointer is valid]
    B --> C{List exists?}
    C -- No --> D[Set new node as list]
    C -- Yes --> E[Traverse to last node]
    E --> F[Set last node's next to new node]
    F --> G[End]
```

### 3. `ft_lstadd_front`

```mermaid
graph TD
    A[Start] --> B[Check if list pointer is valid]
    B --> C[Set new node's next to current list]
    C --> D[Update list pointer to new node]
    D --> E[End]
```

### 4. `ft_lstclear`

```mermaid
graph TD
    A[Start] --> B[Check if list is valid]
    B --> C{Current node exists?}
    C -- Yes --> D[Store reference to next node]
    D --> E[Free current node's memory]
    E --> F[Move to next node]
    F --> C
    C -- No --> G[Set list pointer to NULL]
    G --> H[End]
```

### 5. `ft_lstdelone`

```mermaid
graph TD
    A[Start] --> B[Check if node is valid]
    B --> C[Apply delete function to node's data]
    C --> D[Free node memory]
    D --> E[End]
```

### 6. `ft_lstlast`

```mermaid
graph TD
    A[Start] --> B[Check if list exists]
    B --> C{Current node's next exists?}
    C -- Yes --> D[Move to next node]
    D --> C
    C -- No --> E[Return current node]
```

### 7. `ft_lstnew`

```mermaid
graph TD
    A[Start] --> B[Allocate memory for new node]
    B --> C{Memory allocation successful?}
    C -- Yes --> D[Initialize node with content and NULL]
    C -- No --> E[Return NULL]
    D --> F[Return new node]
    E --> F
```

### 8. `ft_lstmap`

```mermaid
graph TD
    A[Start] --> B[Check if list and function are valid]
    B --> C[Initialize new list]
    C --> D{Current node exists?}
    D -- Yes --> E[Apply function to node's data]
    E --> F[Create new node with result]
    F --> G[Append new node to new list]
    G --> H[Move to next node]
    H --> D
    D -- No --> I[Return new list]
```

---

## Contributing

Contributions to this project are welcome. If you'd like to contribute:

1. Fork the repository.
2. Clone your forked repository:
   ```bash
   git clone https://github.com/your-username/ft_list.git
   ```
3. Create a new branch:
   ```bash
   git checkout -b feature-name
   ```
4. Commit your changes:
   ```bash
   git commit -m "Add new feature"
   ```
5. Push your changes:
   ```bash
   git push origin feature-name
   ```
6. Open a pull request on GitHub.

---

**License:** This project is licensed under the MIT License.

