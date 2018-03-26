//
//  Librarian.cpp
//

#include "Librarian.h"
#include "User.h"
#include <iostream>
#include <list>
#include <string>
#include <fstream>

Librarian::Librarian() {
    
}

Librarian::Librarian(string tempusername, string temppassword) {
    set_username(tempusername);
    set_password(temppassword);
}


void Librarian::printlibrarian() {
    print_user();
}

void Librarian::printlibrarians(list<Librarian>& mylibrarians) {
    list<Librarian>::iterator iterl;

    for (iterl=mylibrarians.begin(); iterl!=mylibrarians.end(); iterl++) {
        Librarian templibrarian=*iterl;
        templibrarian.printlibrarian();
        cout << endl;
    }
}

// overload operator to input librarian
void Librarian::operator>>(list<Librarian>& mylibrarians) {
    ifstream input;
    string tempusername, blankline, temppassword;
    
    input.open("librarianfinal.dat");
    if(input.fail()){
        cerr << "Error opening librarianfinal.dat for input...\n" << endl;
    }
    
    while(input >> tempusername) {
        getline(input, blankline);
        getline(input, temppassword);
        Librarian templibrarian = Librarian(tempusername, temppassword);
        mylibrarians.push_back(templibrarian);
    }
    input.close();
}

void Librarian::operator<<(list<Librarian>& mylibrarians) {
    ofstream output;
    list<Librarian>::iterator iterl;
    
    output.open("librarianfinal.dat");
    if(output.fail()) {
        cerr << "Error opening librarianfinal.dat for output...\n" << endl;
    }
    
    for(iterl=mylibrarians.begin();iterl!=mylibrarians.end();iterl++) {
        Librarian templibrarian = *iterl;
        output << templibrarian.get_username() << endl << templibrarian.get_password() << endl << endl;
    }
    output.close();
}

bool Librarian::operator==(const Librarian& rhs) {
    Librarian templibrarian = rhs;
    if(get_username()==templibrarian.get_username()){
        return true;
    }
    else {
        return false;
    }
}
