// ui_main.cpp
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QMessageBox>

#include "backend.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    loadFromFile();

    QWidget window;
    window.setWindowTitle("Student Record Management System");
    window.setFixedSize(320, 260);

    QVBoxLayout *layout = new QVBoxLayout();

    QPushButton *addBtn = new QPushButton("Add Student");
    QPushButton *searchBtn = new QPushButton("Search Student");
    QPushButton *exitBtn = new QPushButton("Save & Exit");

    layout->addWidget(addBtn);
    layout->addWidget(searchBtn);
    layout->addWidget(exitBtn);

    // ADD STUDENT
    QObject::connect(addBtn, &QPushButton::clicked, [&]() {
        bool ok;
        int roll = QInputDialog::getInt(&window, "Add Student", "Roll Number:", 0, 0, 9999, 1, &ok);
        if (!ok) return;

        QString name = QInputDialog::getText(&window, "Add Student", "Name:", QLineEdit::Normal, "", &ok);
        if (!ok) return;

        double marks = QInputDialog::getDouble(&window, "Add Student", "Marks:", 0, 0, 100, 1, &ok);
        if (!ok) return;

        addStudentUI(roll, name.toStdString(), marks);
        QMessageBox::information(&window, "Success", "Student added");
    });

    // SEARCH STUDENT
    QObject::connect(searchBtn, &QPushButton::clicked, [&]() {
        bool ok;
        int roll = QInputDialog::getInt(&window, "Search Student", "Roll Number:", 0, 0, 9999, 1, &ok);
        if (!ok) return;

        std::string result = searchStudentUI(roll);
        QMessageBox::information(&window, "Result", QString::fromStdString(result));
    });

    // EXIT
    QObject::connect(exitBtn, &QPushButton::clicked, [&]() {
        saveToFile();
        QApplication::quit();
    });

    window.setLayout(layout);
    window.show();

    return app.exec();
}