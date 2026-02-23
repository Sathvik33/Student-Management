#include <bits/stdc++.h>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

map<int, Student> records;
stack<map<int, Student>> undoStack;

void save() {
    undoStack.push(records);
}

void addStudent() {
    save();
    Student s;
    cout << "Enter roll number: ";
    cin >> s.roll;

    cout << "Enter name: ";
    cin >> ws;                 // FIX
    getline(cin, s.name);

    cout << "Enter marks: ";
    cin >> s.marks;

    records[s.roll] = s;
    cout << "Student added\n";
}

void updateStudent() {
    int roll;
    cout << "Enter roll number to update: ";
    cin >> roll;

    if (records.find(roll) == records.end()) {
        cout << "Student not found\n";
        return;
    }

    save();
    cout << "Enter new name: ";
    cin >> ws;                 // FIX
    getline(cin, records[roll].name);

    cout << "Enter new marks: ";
    cin >> records[roll].marks;

    cout << "Updated successfully\n";
}

void deleteStudent() {
    int roll;
    cout << "Enter roll number to delete: ";
    cin >> roll;

    if (records.find(roll) == records.end()) {
        cout << "Student not found\n";
        return;
    }

    save();
    records.erase(roll);
    cout << "Deleted successfully\n";
}

void searchStudent() {
    int ch;
    cout << "1. Search by roll\n2. Search by name\nChoice: ";
    cin >> ch;

    if (ch == 1) {
        int roll;
        cout << "Enter roll number: ";
        cin >> roll;

        if (records.count(roll)) {
            auto s = records[roll];
            cout << s.roll << " " << s.name << " " << s.marks << endl;
        } else {
            cout << "Student not found\n";
        }
    } 
    else {
        string key;
        cout << "Enter name part: ";
        cin >> ws;              // FIX
        getline(cin, key);

        bool found = false;
        for (auto &p : records) {
            if (p.second.name.find(key) != string::npos) {
                cout << p.second.roll << " "
                     << p.second.name << " "
                     << p.second.marks << endl;
                found = true;
            }
        }
        if (!found)
            cout << "No matching student\n";
    }
}

void sortRecords() {
    vector<Student> temp;
    for (auto &p : records)
        temp.push_back(p.second);

    int ch;
    cout << "Sort by:\n1. Marks\n2. Name\nChoice: ";
    cin >> ch;

    if (ch == 1) {
        sort(temp.begin(), temp.end(),
             [](Student a, Student b) {
                 return a.marks > b.marks;
             });
    } else {
        sort(temp.begin(), temp.end(),
             [](Student a, Student b) {
                 return a.name < b.name;
             });
    }

    for (auto s : temp) {
        cout << s.roll << " "
             << s.name << " "
             << s.marks << endl;
    }
}

void showStats() {
    if (records.empty()) {
        cout << "No records found\n";
        return;
    }

    float sum = 0;
    float minMarks = records.begin()->second.marks;
    Student top = records.begin()->second;
    Student bottom = records.begin()->second;

    for (auto &p : records) {
        sum += p.second.marks;
        if (p.second.marks > top.marks)
            top = p.second;
        if (p.second.marks < minMarks) {
            minMarks = p.second.marks;
            bottom = p.second;
        }
    }

    cout << "Average marks: " << sum / records.size() << endl;
    cout << "Topper: " << top.name << " (" << top.marks << ")\n";
    cout << "Lowest marks: " << bottom.name << " (" << minMarks << ")\n";
}

void saveToFile() {
    ofstream file("students.json");
    if (!file.is_open()) {
        cout << "Error: Could not save to file\n";
        return;
    }

    file << "{\n\"students\": [\n";

    bool first = true;
    for (auto &p : records) {
        if (!first) file << ",\n";
        file << "  {\"roll\": " << p.second.roll 
             << ", \"name\": \"" << p.second.name 
             << "\", \"marks\": " << p.second.marks << "}";
        first = false;
    }

    file << "\n]\n}";
    file.close();
    cout << "Records saved successfully\n";
}

void loadFromFile() {
    ifstream file("students.json");
    if (!file.is_open()) return;

    string line, name;
    int roll;
    float marks;
    char nameBuffer[256];

    while (getline(file, line)) {
        if (line.find("\"roll\"") != string::npos) {
            sscanf(line.c_str(), "%*[^:]:%d", &roll);
            getline(file, line);
            sscanf(line.c_str(), "%*[^\"]:\"%255[^\"]", nameBuffer);
            name = nameBuffer;
            getline(file, line);
            sscanf(line.c_str(), "%*[^:]:%f", &marks);
            
            records[roll] = {roll, name, marks};
        }
    }
    file.close();
}

void undo() {
    if (undoStack.empty()) {
        cout << "Nothing to undo\n";
        return;
    }
    records = undoStack.top();
    undoStack.pop();
    cout << "Undo done\n";
}

int main() {
    loadFromFile();
    int choice;
    do {
        cout << "\n---- Student Record System ----\n";
        cout << "1. Add student\n";
        cout << "2. Update student\n";
        cout << "3. Delete student\n";
        cout << "4. Search student\n";
        cout << "5. Sort records\n";
        cout << "6. Show stats\n";
        cout << "7. Undo last change\n";
        cout << "8. Save and Exit\n";
        cout << "0. Exit\n";
        cout << "Choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: updateStudent(); break;
            case 3: deleteStudent(); break;
            case 4: searchStudent(); break;
            case 5: sortRecords(); break;
            case 6: showStats(); break;
            case 7: undo(); break;
            case 8: saveToFile(); cout << "Exiting...\n"; break;
            case 0: cout << "Exiting without saving...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 0 && choice != 8);

    return 0;
}