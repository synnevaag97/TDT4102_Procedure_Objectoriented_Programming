#include "maps.h"

CourseCatalog::CourseCatalog(){}

void CourseCatalog::addCourse(string courseCode, string courseName){
    courses[courseCode] = courseName; // This function adds and also override. 
    //courses.insert({courseCode,courseName}); // Insert function does not override.
}
void CourseCatalog::removeCourse(string courseCode){
    courses.erase(courseCode);

}
void CourseCatalog::getCourse(string courseCode){
    cout << courseCode << ": " << courses[courseCode] << endl;
}

ostream& operator<<(ostream& os, const CourseCatalog& cc){
	for (const auto& [code, name] : cc.courses)
	{
		os << code << ", " << name << '\n';
	}
    return os;
}

void CourseCatalog::storeData(){
    ofstream coursesFile("NTNUcourses.txt");
    for(const auto& c: courses){
        coursesFile << c.first << ":" << c.second << "\n";
    } 
}

void CourseCatalog::loadData(string filename){
    courses.clear();
    ifstream coursesFile(filename);
    string line;
    while(getline(coursesFile,line)){
        stringstream ss(line);
        string courseCode;
        string courseName;
        getline(ss,courseCode,':');
        getline(ss,courseName,':');

        courses[courseCode] = courseName;
    }
}
