#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(const string name){
this->name = name;
head = NULL;
phones = 0;
}

Person::Person(const Person &personToCopy){
    name = personToCopy.name;
    if (personToCopy.head == NULL){
      head = NULL;  // original list is empty
        phones = 0;

    }

    else {
      // copy first node
    phones = personToCopy.phones;
      head = new PhoneNode;
      head->p = personToCopy.head->p;
      // copy rest of list
      PhoneNode *newPtr = head;  // new list ptr

      for (PhoneNode *origPtr = personToCopy.head->next;
                     origPtr != NULL;
                     origPtr = origPtr->next){
         newPtr->next = new PhoneNode;
         newPtr = newPtr->next;
         newPtr->p = origPtr->p;
      }
      newPtr->next = NULL;
   }
}
void Person::operator=(const Person &right){

    name = right.name;
    phones = right.phones;
    if (right.head == NULL)
      head = NULL;  // original list is empty
    else {
      // copy first node
      head = new PhoneNode;
      head->p = right.head->p;
      // copy rest of list
      PhoneNode *newPtr = head;  // new list ptr

      for (PhoneNode *origPtr = right.head->next;
                     origPtr != NULL;
                     origPtr = origPtr->next){
         newPtr->next = new PhoneNode;
         newPtr = newPtr->next;
         newPtr->p = origPtr->p;
      }
      newPtr->next = NULL;
   }


}

string Person::getName(){
    return name;
}

int Person::getPhones(){
    return phones;
}

bool Person::findPhonesWithAreaCode(const int areaCode){
        PhoneNode* curr = head;
        bool displayed = false;
        if (curr != NULL)
        {
            while( (curr!=NULL) ){
                if ( (curr->p.getAreaCode() == areaCode)){
                        if(!displayed){
                        cout<<name<<endl;
                        displayed = true;
                        }
                    cout<<"Phone Number: " << curr->p.getAreaCode() << ", " <<curr->p.getNumber()<<endl;

                }
                    curr= curr->next;
                }
//                if(displayed = true)
//                cout<< " " << endl;
        }

    return displayed;
}


bool Person::addPhone(const int areaCode, const int number){

phones++;
if (findPhone(areaCode,number) == NULL){
    Phone ph(areaCode, number);
    PhoneNode* newptr = new PhoneNode;
    newptr->p = ph;
    newptr->next = NULL;


    if(head == NULL){
        head = newptr;
        return true;
    }

    if(head!=NULL){

        PhoneNode* curr = head;
        while(curr->next != NULL){
        curr = curr->next; //reach end of list

        }
        curr->next = newptr;


        curr = NULL;
        delete curr;

        return true;

    }

}
cout<<"Phone Number Enter for " << name <<  " Is Not Unique"<<endl;
return false;
}


bool Person::removePhone(const int areaCode, const int number){

phones--;

if (findPhone(areaCode,number) != NULL){

    PhoneNode* curr = head;

    if((curr->p.getAreaCode() == areaCode) && (curr->p.getNumber() == number) ){

        head = head->next;
        return true;

    }



    while( (curr->next->p.getAreaCode() != areaCode) || (curr->next->p.getNumber() != number) ){
        curr = curr->next;
            }

    if(curr->next->next == NULL){
        curr->next = NULL;
    }
    else{
        curr->next = curr->next->next;
        //curr->next->next = NULL;

    }


    curr = NULL;
    delete curr;


    return true;
}
return false;
}

void Person::displayPhoneNumbers(){

    if(head == NULL)
        cout << "---EMPTY---"<< endl;
    else{

    PhoneNode* curr = head;

    while(curr != NULL){
        cout << "Phone Number: " <<curr->p.getAreaCode() <<", "<<curr->p.getNumber() << endl;
        curr = curr->next;
    }
    delete curr;
    curr = NULL;


    }
}
Person::PhoneNode* Person::findPhone( const int areaCode, const int number ){

PhoneNode* curr = head;
if (curr != NULL)
{
    while( (curr!=NULL) ){
        if ( (curr->p.getAreaCode() == areaCode) && (curr->p.getNumber()== number) )
            return curr;
        else
            curr = curr->next;
        }
        return NULL; //ADD case sensitivity
}
return NULL;
}

Person::~Person(){

delete[] head;
}

