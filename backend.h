#pragma once
#include <string>

void loadFromFile();
void saveToFile();

// backend operations
void addStudentUI(int roll, const std::string& name, float marks);
std::string searchStudentUI(int roll);