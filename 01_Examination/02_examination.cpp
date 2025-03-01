#include <iostream>
using namespace std;

class Examination {
private:
    int duration;
    int credit_Hours;
    string course_Title;
    int month, date, year;
    string time;

public:
    // Constructor
    Examination(int duration, int credit_Hours, string title, int month, int date, int year, string time);

    // Setters
    void setDuration(int duration);
    void setCreditHours(int credit_Hours);
    void setCourseTitle(string course_Title);
    void setDate(int date, int month, int year);
    void setTime(string time);

    // Getters
    int getDuration();
    int getCreditHours();
    string getCourseTitle();
    string getDate();
    string getTime();

    // Function to display details
    void showDetails();
};

// Constructor definition
Examination::Examination(int duration, int credit_Hours, string title, int month, int date, int year, string time) {
    setDuration(duration);
    setCreditHours(credit_Hours);
    setCourseTitle(title);
    setDate(date, month, year);
    setTime(time);
}

// Setters
void Examination::setDuration(int duration) { this->duration = duration; }
void Examination::setCreditHours(int credit_Hours) { this->credit_Hours = credit_Hours; }
void Examination::setCourseTitle(string course_Title) { this->course_Title = course_Title; }
void Examination::setDate(int date, int month, int year) { this->date = date; this->month = month; this->year = year; }
void Examination::setTime(string time) { this->time = time; }

// Getters
int Examination::getDuration() { return duration; }
int Examination::getCreditHours() { return credit_Hours; }
string Examination::getCourseTitle() { return course_Title; }
string Examination::getDate() { return to_string(month) + "-" + to_string(date) + "-" + to_string(year); }
string Examination::getTime() { return time; }

// Function to display examination details
void Examination::showDetails() {
    cout << "Course Title: " << getCourseTitle() << endl;
    cout << "Duration: " << getDuration() << " minutes" << endl;
    cout << "Credit Hours: " << getCreditHours() << endl;
    cout << "Date: " << getDate() << endl;
    cout << "Time: " << getTime() << endl;
}

// Main function
int main() {
    Examination exam(90, 3, "Computer Science", 5, 12, 2025, "10:00 AM");
    exam.showDetails();
    return 0;
}
