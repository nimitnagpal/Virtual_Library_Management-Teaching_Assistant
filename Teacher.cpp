//
//  Teacher.cpp
//  ESE224 Final
//
#include <iostream>
#include "Teacher.h"
//#include "Student.h"
#include "User.h"
#include "Reader.h"
using namespace std;

Teacher::Teacher() {
    
}

Teacher::Teacher(string tempusername, string temppassword, int tempnumcopies, list<Copy> tempcopiesborrowed, int tempnumbooks, list<Book> tempbooksreserved, int tempnumpenalties) {

    set_username(tempusername);
    set_password(temppassword);
    setnumbooksreserved(tempnumbooks);
    setnumcopiesborrowed(tempnumcopies);
    setlistcopiesborrowed(tempcopiesborrowed);
    setlistbooksreserved(tempbooksreserved);
    setnumpenalties(tempnumcopies);
    setmax_copies(5);
    maxlength=20;
}

Teacher::Teacher(Reader tempreader) {
    set_username(tempreader.get_username());
    set_password(tempreader.get_password());
    setnumbooksreserved(tempreader.getnumbooksreserved());
    setnumcopiesborrowed(tempreader.getnumcopiesborrowed());
    //setmax_copies(5);
    setnumpenalties(tempreader.getnumpenalties());
    maxlength=20;
    setmax_copies(tempreader.getmaxcopies());
    setlistbooksreserved(tempreader.getlistbooksreserved());
    setlistcopiesborrowed(tempreader.getlistcopiesborrowed());
}

void Teacher::printteacher() {
    print_user();
    cout << "Number of copies borrowed: " << getnumcopiesborrowed() << "\nCopies Borrowed: ";
    printcopiesborrowed();
    cout << "Number of books reserved: " << getnumbooksreserved() << "\nBooks Reserved: ";
    printbooksreserved();
    cout << "Number of penalties: " << getnumpenalties() << "\nMaximum borrow length: ";
    cout << maxlength << "\nMaximum copies allowed: " << getmaxcopies();
    cout << endl;
    cout << "Max borrow length: " << maxlength << endl;
}

void Teacher::printteachers(list<Teacher>& myteachers) {
    list<Teacher>::iterator itert;
    for (itert=myteachers.begin(); itert!=myteachers.end(); itert++) {
        Teacher tempteacher=*itert;
        tempteacher.printteacher();
        cout << endl;
    }
}

void Teacher::populateteachers(list<Reader>& myreaders, list<Teacher>& myteachers) {
    list<Reader>::iterator iterr;
    
    for(iterr=myreaders.begin();iterr!=myreaders.end();iterr++) {
        Reader tempreader = *iterr;
        
        if(tempreader.getreadertype()== 't') {
            Teacher tempteacher(tempreader);
            myteachers.push_back(tempteacher);
        }
    }
}

bool Teacher::operator==(const Teacher& rhs) {
    Teacher tempteacher = rhs;
    
    if (get_username()==tempteacher.get_username()) {
        return true;
    }
    else {
        return false;
    }
}

void Teacher::addteachercopyborrowed(Copy tempborrowcopy) {
    
    list<Copy> currentlist = getlistcopiesborrowed();
    
    currentlist.push_back(tempborrowcopy);
    
    setlistcopiesborrowed(currentlist);
    
    
}







