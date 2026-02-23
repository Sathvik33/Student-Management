#include "backend.h"
#include <sstream>

// IMPORTANT: reuse your existing backend exactly
#include "pro.cpp"

// ADD
void addStudentUI(int roll, const std::string& name, float marks) {
    Student s{roll, name, marks};
    records[roll] = s;
}

// UPDATE
bool updateStudentUI(int roll, const std::string& name, float marks) {
    if (records.find(roll) == records.end())
        return false;

    records[roll].name = name;
    records[roll].marks = marks;
    return true;
}

// DELETE
bool deleteStudentUI(int roll) {
    if (records.find(roll) == records.end())
        return false;

    records.erase(roll);
    return true;
}

// SEARCH
std::string searchStudentUI(int roll) {
    if (!records.count(roll))
        return "Student not found";

    auto &s = records[roll];
    return "Roll: " + std::to_string(s.roll) +
           "\nName: " + s.name +
           "\nMarks: " + std::to_string(s.marks);
}

// STATS
std::string statsUI() {
    if (records.empty())
        return "No records available";

    float sum = 0;
    Student top = records.begin()->second;
    Student low = records.begin()->second;

    for (auto &p : records) {
        sum += p.second.marks;
        if (p.second.marks > top.marks) top = p.second;
        if (p.second.marks < low.marks) low = p.second;
    }

    std::ostringstream out;
    out << "Total Students: " << records.size() << "\n"
        << "Average Marks: " << sum / records.size() << "\n"
        << "Topper: " << top.name << " (" << top.marks << ")\n"
        << "Lowest: " << low.name << " (" << low.marks << ")";

    return out.str();
}