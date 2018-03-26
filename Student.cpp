//
//  Student.cpp
//
#include <iostream>
#include <fstream>
#include "Student.h"
#include "Reader.h"
#include "User.h"
#include <string>
#include <vector>
#include "Copy.h"
#include "Book.h"


Student::Student() {
    
}



Student::Student(string tempusername, string temppassword, int tempnumcopies, list<Copy> tempcopiesborrowed, int tempnumbooks, list<Book> tempbooksreserved, int tempnumpenalties) {
    set_username(tempusername);
    set_password(temppassword);
    setnumbooksreserved(tempnumbooks);
    setnumcopiesborrowed(tempnumcopies);
    setlistcopiesborrowed(tempcopiesborrowed);
    setlistbooksreserved(tempbooksreserved);
    setnumpenalties(tempnumpenalties);
    setmax_copies(2);
    maxlength=10;
}


Student::Student(Reader tempreader) {
    set_username(tempreader.get_username());
    set_password(tempreader.get_password());
    setnumbooksreserved(tempreader.getnumbooksreserved());
    setnumcopiesborrowed(tempreader.getnumcopiesborrowed());
    //setmax_copies(2);
    setnumpenalties(tempreader.getnumpenalties());
    maxlength=10;
    setmax_copies(tempreader.getmaxcopies());
    setlistbooksreserved(tempreader.getlistbooksreserved());
    setlistcopiesborrowed(tempreader.getlistcopiesborrowed());    
}

void Student::printstudent() {
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

void Student::printstudents(list<Student>& mystudents) {
    list<Student>::iterator iters;
    
    for (iters=mystudents.begin(); iters!=mystudents.end(); iters++) {
        Student tempstudent=*iters;
        tempstudent.printstudent();
        cout << endl;
    }
}

bool Student::operator==(const Student& rhs) {
    Student tempstudent = rhs;
    if(get_username()==tempstudent.get_username()) {
        return true;
    }
    else {
        return false;
    }
    
}

void Student::addstudentcopyborrowed(Copy tempborrowcopy) {
    
    list<Copy> currentlist = getlistcopiesborrowed();
    
    currentlist.push_back(tempborrowcopy);
    
    setlistcopiesborrowed(currentlist);
    
    
}








