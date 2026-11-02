#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

struct Student {
    int roll;
    string name;
    double marks;
};

// Comparator for Max Heap (ranks by highest marks)
struct Compare {
    bool operator()(const Student& a, const Student& b) {
        return a.marks < b.marks;
    }
};

int main() {
    // Hash Table: Key = Roll Number, Value = Student
    unordered_map<int, Student> db;
    int choice;

    // Sample initial records
    db[101] = {101, "Alice", 88.5};
    db[102] = {102, "Bob", 92.0};
    db[103] = {103, "Charlie", 95.5};

    while (true) {
        cout << "\n--- Student Ranking System ---\n";
        cout << "1. Add/Update Student\n";
        cout << "2. Search Student\n";
        cout << "3. Display Top 10\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            cout << "Enter Roll No: ";
            cin >> s.roll;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, s.name);
            cout << "Enter Marks: ";
            cin >> s.marks;
            
            db[s.roll] = s;
            cout << "Record saved successfully!\n";
        } 
        else if (choice == 2) {
            int roll;
            cout << "Enter Roll No to search: ";
            cin >> roll;
            
            if (db.find(roll) != db.end()) {
                cout << "Found: " << db[roll].name << " | Marks: " << db[roll].marks << "\n";
            } else {
                cout << "Student not found!\n";
            }
        } 
        else if (choice == 3) {
            if (db.empty()) {
                cout << "No records available!\n";
                continue;
            }

            // Max Heap to extract top performers
            priority_queue<Student, vector<Student>, Compare> heap;
            for (auto const& [roll, s] : db) {
                heap.push(s);
            }

            cout << "\n--- Top Students ---\n";
            int rank = 1;
            while (!heap.empty() && rank <= 10) {
                Student top = heap.top();
                heap.pop();
                cout << rank++ << ". Roll: " << top.roll << " | " << top.name << " | Marks: " << top.marks << "\n";
            }
        } 
        else if (choice == 4) {
            cout << "Exiting system.\n";
            break;
        } 
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}