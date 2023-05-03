#include <iostream>
#include "Student.h"

using namespace std;

ostream& operator<<(ostream& out, const Student& stud) {
        out << stud.name << endl;
        return out;
}