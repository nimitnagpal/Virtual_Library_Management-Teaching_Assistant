//
//  functions.h
//

#ifndef functions_h
#define functions_h

#include <iostream>
#include <list>
#include "Librarian.h"

void outputlists(list<Book>&, list<Copy>&, list<Reader>&, list<Librarian>&);

int checkusertype();
void loginlibrarian(list<Librarian>& mylibrarians, string& tempusername);
void loginreader(list<Reader>& myreaders, char& readertype, string& tempusername);

int optionselectlibrarian();
int optionselectreader();
list<Book> searchbooks(string&, list<Book>&);
bool isonlydigits(string&);
void searchfunction(list<Book>& mybooks, list<Copy>& mycopies);

void addnewbook(list<Book>& mybooks, list<Copy>& mycopies);
void addexistingbookcopy(list<Book>& mybooks, list<Copy>& mycopies);

void deletecopy(list<Book>& mybooks, list<Copy>& mycopies, list<Reader>&, int& optionselect);

void searchusers(list<Reader>&, list<Librarian>&);
void addnewuser(list<Reader>&, list<Librarian>&, list<Teacher>&, list<Student>&);
bool usernameinuse(list<Reader>&, list<Librarian>&, string&);

void deleteuser(list<Reader>&, list<Librarian>&, list<Student>&, list<Teacher>&, list<Book>&);
bool whoisthisuser(list<Reader>&, list<Librarian>&, string&, char&);

void borrowbookstudent(list<Book>& mybooks, list<Copy>& mycopies, list<Reader>& myreaders, string& username, int& currentdate);
void borrowbookstudent2(list<Book>&, list<Copy>&, list<Reader>&, string& username, int& currentdate, int& borrowid);
void borrowbookstudent3(list<Book>&, list<Copy>&, list<Reader>&, string& username, int& currentdate, int& borrowid);

void borrowbookteacher(list<Book>& mybooks, list<Copy>& mycopies, list<Reader>& myreaders, string& username, int& currentdate);
void borrowbookteacher2(list<Book>&, list<Copy>&, list<Reader>&, string& username, int& currentdate, int& borrowid);
void borrowbookteacher3(list<Book>&, list<Copy>&, list<Reader>&, string& username, int& currentdate, int& borrowid);


bool overduecopies(list<Copy>& mycopies, string& username, int& currentdate);
bool maxcopiesreached(list<Reader>& myreaders, string& username);

void returnbooks(list<Copy>& mycopies, list<Reader>& myreaders, string& username, int& currentdate, char& readertype);

void reservebooks(list<Book>& mybooks, list<Copy>& mycopies, list<Reader>&, string& username, int& currentdate, char& readertype);

void cancelreservation(list<Book>& mybooks, list<Copy>& mycopies, list<Reader>& myreaders, string& username, int& currentdate);



#endif /* functions_h */
