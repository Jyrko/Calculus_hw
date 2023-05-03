#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

enum class STATUS {
    NOTHING = 0,
    TODAY = 1,
    PREVIOUS = 2,
    LAST_COWBOY = 3
};

class Student {
    private:
        string name;
        bool isPresent;
        STATUS status;

    public: 
        Student(): name("none"), isPresent(false), status(STATUS::NOTHING) {};
        Student(string n, STATUS stat = STATUS::NOTHING, bool present = true): name(n), isPresent(present), status(stat) {};

        STATUS getStatus() const { return status; }
        void setStatus(STATUS stat) { status = stat; }
        void incrementStatus() { 
            // status = (static_cast<int>(status) + 1) % 3;
            if (status == STATUS::NOTHING) status = STATUS::TODAY;
            else if (status == STATUS::TODAY) status = STATUS::PREVIOUS;
            else if (status == STATUS::PREVIOUS) status = STATUS::NOTHING;
            else status = STATUS::NOTHING;
        }
        void presence() { isPresent = !isPresent; }
        
    friend ostream& operator<<(ostream& out, const Student& stud);
    friend void saveStudentsToFile(vector<Student>& studs);
};
#endif