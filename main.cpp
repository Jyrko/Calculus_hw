#include <iostream>
#include "Student.h"
#include "Calculus.h"

using namespace std;


int main(void) {
    vector<Student> students = {
        // Student("Mateusz", STATUS::PREVIOUS),
        // Student("Ksenia", STATUS::PREVIOUS),
        // Student("Sasha"),
        // Student("Ola Bobrova"),
        // Student("Andrei M"),
        // Student("Yurii D")
    };
    
    Calculus calc = Calculus(students);

    calc.startLesson();
    const int END_RANGE = 4;
    for (int i = 0; i < END_RANGE; i++) {
        cout << calc.goToBlackboard(false);
        if ((i + 1) == END_RANGE) {
            cout << "Our last hero:" << endl;
            cout << calc.goToBlackboard(true);
        }
    }

    calc.endLesson();
    cout << "Finished..." << endl;
    return 0;
}