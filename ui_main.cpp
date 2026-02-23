#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QMessageBox>
#include <QLineEdit>

#include "backend.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    loadFromFile();

    QWidget window;
    window.setWindowTitle("Student Record Management System");
    window.setFixedSize(360, 420);

    QVBoxLayout *layout = new QVBoxLayout();

    QPushButton *addBtn    = new QPushButton("Add Student");
    QPushButton *updateBtn = new QPushButton("Update Student");
    QPushButton *deleteBtn = new QPushButton("Delete Student");
    QPushButton *searchBtn = new QPushButton("Search Student");
    QPushButton *statsBtn  = new QPushButton("Show Statistics");
    QPushButton *exitBtn   = new QPushButton("Save & Exit");

    layout->addWidget(addBtn);
    layout->addWidget(updateBtn);
    layout->addWidget(deleteBtn);
    layout->addWidget(searchBtn);
    layout->addWidget(statsBtn);
    layout->addWidget(exitBtn);

    // ADD
    QObject::connect(addBtn, &QPushButton::clicked, [&]() {
        bool ok;
        int roll = QInputDialog::getInt(&window, "Add", "Roll:", 0, 0, 9999, 1, &ok);
        if (!ok) return;

        QString name = QInputDialog::getText(&window, "Add", "Name:", QLineEdit::Normal, "", &ok);
        if (!ok) return;

        double marks = QInputDialog::getDouble(&window, "Add", "Marks:", 0, 0, 100, 1, &ok);
        if (!ok) return;

        addStudentUI(roll, name.toStdString(), marks);
        QMessageBox::information(&window, "Success", "Student added");
    });

    // UPDATE
    QObject::connect(updateBtn, &QPushButton::clicked, [&]() {
        bool ok;
        int roll = QInputDialog::getInt(&window, "Update", "Roll:", 0, 0, 9999, 1, &ok);
        if (!ok) return;

        QString name = QInputDialog::getText(&window, "Update", "New Name:", QLineEdit::Normal, "", &ok);
        if (!ok) return;

        double marks = QInputDialog::getDouble(&window, "Update", "New Marks:", 0, 0, 100, 1, &ok);
        if (!ok) return;

        if (updateStudentUI(roll, name.toStdString(), marks))
            QMessageBox::information(&window, "Updated", "Student updated");
        else
            QMessageBox::warning(&window, "Error", "Student not found");
    });

    // DELETE
    QObject::connect(deleteBtn, &QPushButton::clicked, [&]() {
        bool ok;
        int roll = QInputDialog::getInt(&window, "Delete", "Roll:", 0, 0, 9999, 1, &ok);
        if (!ok) return;

        if (deleteStudentUI(roll))
            QMessageBox::information(&window, "Deleted", "Student deleted");
        else
            QMessageBox::warning(&window, "Error", "Student not found");
    });

    // SEARCH
    QObject::connect(searchBtn, &QPushButton::clicked, [&]() {
        bool ok;
        int roll = QInputDialog::getInt(&window, "Search", "Roll:", 0, 0, 9999, 1, &ok);
        if (!ok) return;

        QMessageBox::information(&window, "Result",
            QString::fromStdString(searchStudentUI(roll)));
    });

    // STATS
    QObject::connect(statsBtn, &QPushButton::clicked, [&]() {
        QMessageBox::information(&window, "Statistics",
            QString::fromStdString(statsUI()));
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