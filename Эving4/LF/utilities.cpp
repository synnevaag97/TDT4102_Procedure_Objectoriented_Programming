#include "utilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes)
{
	for (int i = 0; i < numTimes; i++)
		startValue += increment;

	return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes)
{
	for (int i = 0; i < numTimes; i++)
		startValue += increment;
}

void swapNumbers(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
// I swapNumbers må vi bruke referanseparametere (pass by reference)
// siden vi ønsker å endre på parameterne

string randomizeString(int n, char lower, char upper)
{
	string str;
	for (int i = 0; i < n; ++i)
		str += lower + (rand() % (upper - lower));

	return str;
}

string readInputToString(unsigned int n, char lower, char upper)
{
	string str;
	//Variabelen ch er introdusert i for-lokkens scope. Generelt er et mindre scope bedre,
	// saa lenge er mulig.
	// I hver iterasjon, sjekk at n ikke er lik 0, og les tegne til ch

	// Grensene konverteres også til store bokstaver for avgrensingen
	lower = toupper(lower);
	upper = toupper(upper);
	
	for (char ch; str.size() < n && cin >> ch; ) {
		// hopp over tegn som ikke er alfanumerisk
		if (isalnum(ch)) {
			ch = toupper(ch); // endre til stor bokstav
			if (lower <= ch && ch <= upper) {
				str += ch;
			}
		}
	}

	// forkast overflowing input paa samme linje
	cin.clear();
	cin.ignore(255, '\n');

	return str;
}

int countChar(string str, char ch)
{
	int n = 0;
	for (char c : str) {
		if (c == ch) {
			++n;
		}
	}

	return n;

	// STL algorithm
	// return count(str.begin(), str.end(), ch);
}

void printStudent(const Student& student){
	cout<< "Name: " <<student.name << ", age: " << student.age <<", studyprogram: " 
	<< student.studyProgram <<'\n'; 
}

bool isInProgram(const Student& student, const string& program) {
	return student.studyProgram == program;
}
