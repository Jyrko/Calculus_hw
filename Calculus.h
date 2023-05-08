#ifndef CALCULUS_H
#define CALCULUS_H

#include <string>
#include <vector>
#include <fstream>
#include "Student.h"
#include "json.hpp"

using namespace std;



class Calculus {
    private: 
        vector<Student> students;
        int lastStudentIndex;
        static int exerciseCounter;
        const bool DRY_RUN;

    public: 
      Calculus(vector<Student>& students, const bool isDryRun = false, int lastStudentIndex = 0): students(students), DRY_RUN(isDryRun), lastStudentIndex(lastStudentIndex) {};
      
      void startLesson();
      Student& goToBlackboard(bool last_iter);
      void endLesson();

};

#endif