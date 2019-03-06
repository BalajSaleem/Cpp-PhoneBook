#ifndef __PERSON_H
#define __PERSON_H
#include <string>
using namespace std;
#include "Phone.h"
class Person{
public:
 Person( const string name = "" );
 ~Person();
 Person( const Person& personToCopy );
 void operator=( const Person &right );
 string getName();
 int getPhones();
 bool findPhonesWithAreaCode(const int areaCode);
 bool addPhone( const int areaCode, const int number );
 bool removePhone( const int areaCode, const int number );
 void displayPhoneNumbers();
private:
 struct PhoneNode {
 Phone p;
 PhoneNode* next;
 };
 PhoneNode *head;
 string name;
 int phones;
 PhoneNode* findPhone( const int areaCode, const int number );
};
#endif
