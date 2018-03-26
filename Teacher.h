//
//  Teacher.hpp
//

#ifndef Teacher_h
#define Teacher_h

#include <iostream>
#include "Reader.h"
#include "User.h"
using namespace std;

class Teacher: public Reader {
    public:
            
        // constructors
        Teacher();
        Teacher(string tempusername, string temppassword, int tempnumcopies, list<Copy> tempcopiesborrowed, int tempnumbooks, list<Book> tempbooksreserved, int tempnumpenalties);
        Teacher(Reader);

        // populate teachers based on readers list
        static void populateteachers(list<Reader>& myreaders, list<Teacher>& myteachers);
        
        // print teacher info
        static void printteachers(list<Teacher>& myteachers);
        void printteacher();

        //find teacher based on username
        bool operator==(const Teacher& rhs);

        void addteachercopyborrowed(Copy);
    private:
        int maxlength;
};

#endif /* Teacher_h */
