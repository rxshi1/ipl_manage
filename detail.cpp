#include<iostream>
#include<string>

using namespace std;

class Student {
    public : 
    int rollN;
    string name;
    float marks;
    Student* next;
};
 Student* head = NULL;

 // now for adding students
 void addStudent()
 {
  Student* newStudent = new Student();
  cout <<  "Enter Roll number : " ;
 cin >> newStudent->rollN ;
 cout << "Enter Name : ";
 getline(cin,newStudent->name);
 cout << " Enter Marks : ";
 cin >> newStudent->marks;

 newStudent->next = head;
 head = newStudent;
 cout << " Student is  added sucessfully.. ";
 }

 void displayAllRecords() {
    Student* temp = head;
    if (!temp) {
        cout << "No student records found!!\n";
        return;
    }

    cout << "\nAll Student Records :\n";
    while (temp) {
        cout << "Roll No: " << temp->rollN << ", Name: " << temp->name << ", Marks: " << temp->marks << "\n";
        temp = temp->next;
    }
}

// search student by roll number
void searchStudent() {
    int roll;
    cout << "Please Enter The Roll Number to Search : ";
    cin >> roll;
    Student* temp = head;

    while (temp) {
        if (temp->rollN == roll) {
            cout << "Found: " << temp->name << ", Marks: " << temp->marks << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Student not found ❌\n";
}

// delete the student by roll number
void deleteStudent() {
    int roll;
    cout << "Enter Roll Number to Delete: ";
    cin >> roll;

    Student* temp = head;
    Student* prev = NULL;

    while (temp) {
        if (temp->rollN == roll) {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;
            delete temp;
            cout << "Student record deleted succesfully \n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Student not found ❌\n";
}

// now for updating the existing record
void updateStudent() {
    int roll;
    cout << "Enter Roll Number to Update: ";
    cin >> roll;
    Student* temp = head;

    while (temp) {
        if (temp->rollN == roll) {
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, temp->name);
            cout << "Enter New Marks: ";
            cin >> temp->marks;
            cout << "Record updated successfully \n";
            return;
        }
        temp = temp->next;
    }
    cout << "Student not found.\n";
}

// now a menu to access all above functionality

int main() {
    int choice;
    do {
        cout << "\n---- Student Record Menu ----\n";
        cout << "1. Add Student\n2. Display All Students\n3. Search Student\n4. Delete Student\n5. Update Student\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAllRecords(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: updateStudent(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}