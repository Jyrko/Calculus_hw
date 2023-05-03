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

    public: 
      Calculus(vector<Student>& students, int lastStudentIndex = 0): students(students), lastStudentIndex(lastStudentIndex) {};
      
      void startLesson();
      Student& goToBlackboard(bool last_iter);
      void endLesson();

};

#endif