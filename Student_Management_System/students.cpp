#include <iostream>
#include <cstring>
#include <cstdio>
#include "students.h"
using	namespace	std;
StudentManager::StudentManager() {
    root = NULL;
}

StudentManager::~StudentManager() {
    destroyTree(root);
}

void StudentManager::addStudent(const char* name, int id, float marks) {
    struct Student* newStudent = createStudent(name, id, marks);
    root = insertStudent(root, newStudent);
}

void StudentManager::deleteStudent(int id) {
    root = deleteNode(root, id);
}

void StudentManager::searchStudent(int id) {
    struct Student* node = root;
    while (node != NULL && node->id != id) {
        if (id < node->id)
            node = node->left;
        else
            node = node->right;
    }

    if (node != NULL)
        std::cout << "Student found: Name - " << node->name << ", ID - " << node->id << ", Marks - " << node->marks << std::endl;
    else
        std::cout << "Student not found." << std::endl;
}

void StudentManager::displayStudents() {
    inorderTraversal(root);
}

void StudentManager::saveToFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file != NULL) {
        saveToFileHelper(root, file);
        fclose(file);
        std::cout << "Data saved to file successfully." << std::endl;
    }
    else {
        std::cout << "Failed to open file for writing." << std::endl;
    }
}

void StudentManager::loadFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        destroyTree(root);
        root = loadFromFileHelper(file);
        fclose(file);
        std::cout << "Data loaded from file successfully." << std::endl;
    }
    else {
        std::cout << "Failed to open file for reading." << std::endl;
    }
}

struct Student* StudentManager::createStudent(const char* name, int id, float marks) {
    struct Student* newStudent = new Student;
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->marks = marks;
    newStudent->left = NULL;
    newStudent->right = NULL;
    return newStudent;
}

void StudentManager::destroyTree(struct Student* node) {
    if (node != NULL) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

struct Student* StudentManager::insertStudent(struct Student* node, struct Student* newStudent) {
    if (node == NULL) {
        return newStudent;
    }

    if (newStudent->id < node->id) {
        node->left = insertStudent(node->left, newStudent);
    }
    else if (newStudent->id > node->id) {
        node->right = insertStudent(node->right, newStudent);
    }

    return node;
}

struct Student* StudentManager::deleteNode(struct Student* node, int id) {
    if (node == NULL) {
        return NULL;
    }

    if (id < node->id) {
        node->left = deleteNode(node->left, id);
    }
    else if (id > node->id) {
        node->right = deleteNode(node->right, id);
    }
    else {
        if (node->left == NULL) {
            struct Student* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL) {
            struct Student* temp = node->left;
            delete node;
            return temp;
        }

        struct Student* minNode = findMinNode(node->right);
        strcpy(node->name, minNode->name);
        node->id = minNode->id;
        node->marks = minNode->marks;
        node->right = deleteNode(node->right, minNode->id);
    }

    return node;
}

struct Student* StudentManager::findMinNode(struct Student* node) {
    struct Student* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

void StudentManager::inorderTraversal(struct Student* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        std::cout << "Name: " << node->name << ", ID: " << node->id << ", Marks: " << node->marks << std::endl;
        inorderTraversal(node->right);
    }
}

void StudentManager::saveToFileHelper(struct Student* node, FILE* file) {
    if (node != NULL) {
        saveToFileHelper(node->left, file);
        fprintf(file, "%s %d %.2f\n", node->name, node->id, node->marks);
        saveToFileHelper(node->right, file);
    }
}

struct Student* StudentManager::loadFromFileHelper(FILE* file) {
    struct Student* node = NULL;
    char name[100];
    int id;
    float marks;
    while (fscanf(file, "%s %d %f", name, &id, &marks) != EOF) {
        struct Student* newStudent = createStudent(name, id, marks);
        node = insertStudent(node, newStudent);
    }
    return node;
}

int main() {
    StudentManager manager;

    // Add students
    manager.addStudent("John Doe", 1, 85.5);
    manager.addStudent("Jane Smith", 2, 92.3);
    manager.addStudent("Bob Johnson", 3, 77.8);

    // Display students
    std::cout << "Students:" << std::endl;
    manager.displayStudents();

    // Search student
    manager.searchStudent(2);

    // Delete student
    manager.deleteStudent(1);

    // Display students after deletion
    std::cout << "Students after deletion:" << std::endl;
    manager.displayStudents();

    // Save to file
    manager.saveToFile("students.txt");

    // Load from file
    manager.loadFromFile("students.txt");

    // Display students loaded from file
    std::cout << "Students loaded from file:" << std::endl;
    manager.displayStudents();

    return 0;
}

