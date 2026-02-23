#pragma once
#include <string>

// lifecycle
void loadFromFile();
void saveToFile();

// CRUD used by UI
void addStudentUI(int roll, const std::string& name, float marks);
bool updateStudentUI(int roll, const std::string& name, float marks);
bool deleteStudentUI(int roll);
std::string searchStudentUI(int roll);

// stats
std::string statsUI();