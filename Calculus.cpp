#include "Calculus.h"
#include <iostream>

int Calculus::exerciseCounter = 0;


void saveStudentsToFile(vector<Student>& studs) {
    ofstream outfile;
    outfile.open("students.json", ios::out | ios::trunc);
    // outfile << 
    nlohmann::json js;
    for (Student& stud: studs) {
        js.push_back({stud.name, stud.isPresent, stud.status});
    }
    string output = js.dump();
    outfile << output;
    outfile.close();
}


vector<Student>& readStudentsFromFile() {
    ifstream outfile;
    nlohmann::json js;
    string tmp;
    outfile.open("students.json", ios::in);
    outfile >> tmp;
    cout << tmp;
    
    outfile.close();
}

void Calculus::startLesson() {
    ifstream outfile("students.json");
    string tmp;
    nlohmann::json js = nlohmann::json::parse(outfile);

    for (int i = 0; i < js.size(); i++) {
        Student stud(js[i][0], static_cast<STATUS>(js[i][2]), js[i][1]);
        students.push_back(stud);
    }
    outfile >> tmp;
    cout << tmp;
    
}

Student& Calculus::goToBlackboard(bool last_iter) {
    int offset = 0;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getStatus() == STATUS::LAST_COWBOY) {
            offset = i;
            students[i].setStatus(STATUS::PREVIOUS);
        }
    }

    lastStudentIndex = (offset + lastStudentIndex + 6) % students.size(); 

    while (true) {
        if (students[lastStudentIndex].getStatus() == STATUS::NOTHING) break;

        lastStudentIndex = (lastStudentIndex + 1) % students.size();
    }

    if (!DRY_RUN) {
        if (last_iter) {
            students[lastStudentIndex].setStatus(STATUS::LAST_COWBOY);
        } else {
            students[lastStudentIndex].incrementStatus();
        }
    }
    return students[lastStudentIndex];
}


void Calculus::endLesson() {
    if (!DRY_RUN) {
        for (Student& stud: students) {
            if (stud.getStatus() != STATUS::NOTHING && stud.getStatus() != STATUS::LAST_COWBOY ) {
                stud.incrementStatus();
            }
        }
    }
    saveStudentsToFile(students);
}