#include <iostream>
using namespace std;
struct Student{
    int Roll_No;
    string Name;
    float SGPA;
};
void quicksort(Student students[], int low, int high);
int partition(Student students[], int low, int high);
int main(){
    cout << "Enter the number of students to add : ";
    int n;
    cin >> n;
    Student students[n];
// Input..
    for (int i = 0; i < n; i++){
        cout << "Enter Roll No of Student: ";
        cin >> students[i].Roll_No;
        cout << "Enter Name of Student: ";
        cin >> students[i].Name;
        cout << "Enter SGPA of Student: ";
        cin >> students[i].SGPA;
        cout << endl;
        }
        
// Roll call list (by Bubble Sort)
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if (students[j].Roll_No > students[j + 1].Roll_No){
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
                }
            }
    }
    
// Output by Roll Number
    cout << endl << "Sorting by Roll Number" << endl;
    for (int i = 0; i < n; i++){
        cout << "Student" << i + 1 << " Information:- ";
        cout << "Roll No: " << students[i].Roll_No << ", Name: " <<
        students[i].Name << ", SGPA: " << students[i].SGPA << endl;
    }
// Sort by Name (Insertion Sort)
    for (int i = 1; i < n; i++){
        Student to_sort = students[i];
        int j = i - 1;
            while (j >= 0 && students[j].Name.compare(to_sort.Name) > 0){
                students[j + 1] = students[j];
                j = j - 1;
            }
        students[j + 1] = to_sort;
    }
    
// Output by Alphabetical order
    cout << endl << "Sorting by Alphabetical order" << endl;
    for (int i = 0; i < n; i++){
        cout << "Student " << i + 1 << " Information:- ";
        cout << " Roll No: " << students[i].Roll_No << ", Name: " <<
        students[i].Name << ", SGPA: " << students[i].SGPA << endl;
    }
    
// Quicksort by SGPA
    quicksort(students, 0, n - 1);
// Output SGPA order
    cout << endl << "SGPA order" << endl;
    for (int i = n - 1; i >= 0; i--){
        cout << "Student details:" << endl;
        cout << "Roll No: " << students[i].Roll_No << ", Name: " <<
        students[i].Name << ", SGPA: " << students[i].SGPA << endl;
    }
// Linear search

    cout << endl << "Enter SGPA (Linear): ";
    float searchl;
    cin >> searchl;
    int num = 0;
    for (int i = 0; i < n; i++){
        if (students[i].SGPA == searchl){
            cout << "Roll No: " << students[i].Roll_No << ", Name: " <<
            students[i].Name << ", SGPA: " << students[i].SGPA << endl;
            num++;
        }
    }
    if (num == 0){
        cout << "Enter a valid SGPA ";
    }
// Binary search

    cout << endl << "Enter SGPA (Binary): ";
    float searchb;
    cin >> searchb;
    int high = n - 1;
    int low = 0;
    int found = 0;
    while (low <= high){
        int mid = (high + low) / 2;
        if (students[mid].SGPA == searchb){
            cout << "Roll No: " << students[mid].Roll_No << ", Name: "
            << students[mid].Name << ", SGPA: " << students[mid].SGPA << endl;
            found++;
            break;
        }
        else if (students[mid].SGPA < searchb){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    if (found == 0){
        cout << "No Students Found" << endl;
    }
}
// Quicksort function
int partition(Student students[], int low, int high){
    Student pivot = students[high];
    int i = low - 1;
    for (int j = low; j < high; j++){
        if (students[j].SGPA < pivot.SGPA){
            i++;
            Student temp1 = students[i];
            students[i] = students[j];
            students[j] = temp1;
        }
    }
    Student temp2 = students[i + 1];
    students[i + 1] = students[high];
    students[high] = temp2;
    return i + 1;
}
void quicksort(Student students[], int low, int high){
    if (low < high){
        int pivot_index = partition(students, low, high);
        quicksort(students, low, pivot_index - 1);
        quicksort(students, pivot_index + 1, high);
    }
}
