#pragma once
#include <string>
#include <map>

// 1. Move the Student struct here so both backend and pro can use it
struct Student {
    int roll;
    std::string name;
    float marks;
};

// 2. Declare the records map as extern so backend.cpp can access it
extern std::map<int, Student> records;

void loadFromFile();
void saveToFile();

// backend operations
void addStudentUI(int roll, const std::string& name, float marks);
std::string searchStudentUI(int roll);