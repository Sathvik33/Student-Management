#include "backend.h"

// REMOVED: #include "pro.cpp" 

void addStudentUI(int roll, const std::string& name, float marks) {
    Student s;
    s.roll = roll;
    s.name = name;
    s.marks = marks;
    records[roll] = s;
}

std::string searchStudentUI(int roll) {
    if (records.count(roll)) {
        auto s = records[roll];
        return "Roll: " + std::to_string(s.roll) +
               "\nName: " + s.name +
               "\nMarks: " + std::to_string(s.marks);
    }
    return "Student not found";
}