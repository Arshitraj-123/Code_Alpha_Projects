#include <iostream>
#include <vector>
#include <iomanip> // For setting precision

using namespace std;

// Function to convert grade to grade points
double getGradePoint(char grade) {
    switch (grade) {
        case 'A': case 'a': return 4.0;
        case 'B': case 'b': return 3.0;
        case 'C': case 'c': return 2.0;
        case 'D': case 'd': return 1.0;
        case 'F': case 'f': return 0.0;
        default: return -1.0; // Invalid grade
    }
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<int> credits(numCourses);
    vector<char> grades(numCourses);
    vector<double> gradePoints(numCourses);

    // Input course details
    for (int i = 0; i < numCourses; ++i) {
        cout << "\nCourse " << i + 1 << ":\n";
        cout << "Enter credits: ";
        cin >> credits[i];
        cout << "Enter grade (A, B, C, D, F): ";
        cin >> grades[i];

        // Convert grade to grade points
        gradePoints[i] = getGradePoint(grades[i]);
        if (gradePoints[i] == -1.0) {
            cout << "Invalid grade entered! Please try again.\n";
            --i; // Retry this course
        }
    }

    // Calculate total credits and total grade points
    int totalCredits = 0;
    double totalGradePoints = 0.0;

    for (int i = 0; i < numCourses; ++i) {
        totalCredits += credits[i];
        totalGradePoints += credits[i] * gradePoints[i];
    }

    // Calculate CGPA
    double cgpa = totalGradePoints / totalCredits;

    // Display results
    cout << "\n\n--- Results ---\n";
    cout << "Course\tCredits\tGrade\tGrade Points\n";
    for (int i = 0; i < numCourses; ++i) {
        cout << i + 1 << "\t" << credits[i] << "\t" << grades[i] << "\t" << gradePoints[i] << "\n";
    }

    cout << "\nTotal Credits: " << totalCredits << "\n";
    cout << "Total Grade Points: " << totalGradePoints << "\n";
    cout << fixed << setprecision(2); // Set precision for CGPA
    cout << "CGPA: " << cgpa << "\n";

    return 0;
}