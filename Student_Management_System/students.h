#ifndef STUDENTS_H
#define STUDENTS_H

struct Student {
    char name[100];
    int id;
    float marks;
    struct Student* left;
    struct Student* right;
};

class StudentManager {
public:
    StudentManager();
    ~StudentManager();

    void addStudent(const char* name, int id, float marks);
    void deleteStudent(int id);
    void searchStudent(int id);
    void displayStudents();
    void saveToFile(const char* filename);
    void loadFromFile(const char* filename);

private:
    struct Student* root;

    struct Student* createStudent(const char* name, int id, float marks);
    void destroyTree(struct Student* node);
    struct Student* insertStudent(struct Student* node, struct Student* newStudent);
    struct Student* deleteNode(struct Student* node, int id);
    struct Student* findMinNode(struct Student* node);
    void inorderTraversal(struct Student* node);
    void saveToFileHelper(struct Student* node, FILE* file);
    struct Student* loadFromFileHelper(FILE* file);
};

#endif

