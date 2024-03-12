#pragma once
#include "std_lib_facilities.h"


class CourseCatalog{
private:
map<string, string> courses;

public:
CourseCatalog();
void addCourse(string courseCode, string courseName);
void removeCourse(string courseCode);
void getCourse(string courseCode);
void loadData(string filename);
void storeData();
friend ostream& operator<<(ostream&,const CourseCatalog&);
};
