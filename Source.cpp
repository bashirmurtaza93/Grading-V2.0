#include<iostream>
#include<string>
#include<algorithm>
#include<ios>
#include<vector>
#include<iomanip>
#include<iomanip>
#include<algorithm>
#include<iostream>
#include<stdexcept>
#include<string>
#include"grade.h"
#include"Student_info.h"

using std::domain_error;
using std::cout;		using std::sort;
using std::cin;			using std::streamsize;
using std::endl;		using std::string;
using std::string;		using std::vector;
using std::setprecision; using std::max;
int main() {
	
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;    // the length of the longest name

	// read and store all the students data
	// invaraint: students contain all the student records read so far
	// maxlen contains the length of the longest name

	while (read(cin, record)) {
		// find the length of the longest name 
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);

	}

	// alphabetize the studen records
	sort(students.begin(), students.end(), compare);

	// write the names and grades 
	for (vector <Student_info>::size_type i = 0; i != students.size(); ++i) {

		// write the name, padded on the right to maxlen +1 characters 
		cout << students[i].name
			<< string(maxlen + 1 - students[i].name.size(), ' ');


		//compute and write the grade
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();

		}
		cout << endl;

	}
	return 0;

	
	}








