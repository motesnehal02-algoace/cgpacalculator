#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of courses: ";
    cin >> n;

    string subject[n];
    char grade[n];
    int credit[n];

    float gradePoint[n];
    float totalCredits = 0;
    float totalGradePoints = 0;

    cout << "\nEnter details of each course:";

    for(int i = 0; i < n; i++)
    {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter Course Name: ";
        cin >> subject[i];

        cout << "Enter Grade (O/A/B/C/D/F): ";
        cin >> grade[i];

        cout << "Enter Credit Hours: ";
        cin >> credit[i];

        switch(grade[i])
        {
            case 'O':
            case 'o':
                gradePoint[i] = 10;
                break;

            case 'A':
            case 'a':
                gradePoint[i] = 9;
                break;

            case 'B':
            case 'b':
                gradePoint[i] = 8;
                break;

            case 'C':
            case 'c':
                gradePoint[i] = 7;
                break;

            case 'D':
            case 'd':
                gradePoint[i] = 6;
                break;

            case 'F':
            case 'f':
                gradePoint[i] = 0;
                break;

            default:
                cout << "Invalid Grade! Assuming 0 Grade Point.\n";
                gradePoint[i] = 0;
        }

        totalCredits = totalCredits + credit[i];
        totalGradePoints = totalGradePoints + (gradePoint[i] * credit[i]);
    }

    float gpa = totalGradePoints / totalCredits;

    float previousCGPA;
    int previousCredits;

    cout << "\nEnter Previous CGPA (Enter 0 if first semester): ";
    cin >> previousCGPA;

    cout << "Enter Total Previous Credits: ";
    cin >> previousCredits;

    float cgpa;

    if(previousCredits == 0)
    {
        cgpa = gpa;
    }
    else
    {
        cgpa = ((previousCGPA * previousCredits) + totalGradePoints) / (previousCredits + totalCredits);
    }

    cout << "\n-------------------------------------------";
    cout << "\nCourse Details";

    cout << fixed << setprecision(2);

    for(int i = 0; i < n; i++)
    {
        cout << "\nCourse : " << subject[i];
        cout << "\nGrade  : " << grade[i];
        cout << "\nCredits: " << credit[i];
        cout << "\nGrade Point: " << gradePoint[i];
        cout << "\n------------------------------";
    }

    cout << "\nTotal Credits      : " << totalCredits;
    cout << "\nSemester GPA       : " << gpa;
    cout << "\nOverall CGPA       : " << cgpa;

    return 0;
}