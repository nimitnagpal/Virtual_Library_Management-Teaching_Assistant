//
//  Student.hpp
//

#ifndef Student_h
#define Student_h

#include <iostream>
#include <string>
#include "User.h"
#include "Reader.h"
#include "Copy.h"
#include "Book.h"
#include <vector>
#include <list>
#include <string>
using namespace std;

class Student: public Reader {
    public:
        // constructors
        Student();
        Student(string tempusername, string temppassword, int tempnumcopies, list<Copy> tempcopiesborrowed, int tempnumbooks, list<Book> tempbooksreserved, int tempnumpenalties);
        Student(Reader);

        // print student info
        void printstudent();
        static void printstudents(list<Student>& mystudents);
        
        // find student based on username
        bool operator==(const Student& rhs);

        // add copy to user's list of copies
        void addstudentcopyborrowed(Copy);
    private:
        int maxlength;
    
};

#endif /* Student_h */
