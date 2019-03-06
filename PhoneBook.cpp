#include "PhoneBook.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

PhoneBook::PhoneBook(){

head = NULL;
numberOfPeople = 0;

}

void PhoneBook::operator=(const PhoneBook& right)
{
    if (right.head == NULL)
      head = NULL;  // original list is empty
    else {
      // copy first node
      head = new Node;
      head->t = right.head->t;
      // copy rest of list
      Node *newPtr = head;  // new list ptr

      for (Node *origPtr = right.head->next;
                     origPtr != NULL;
                     origPtr = origPtr->next){
         newPtr->next = new Node;
         newPtr = newPtr->next;
         newPtr->t = origPtr->t;
      }
      newPtr->next = NULL;
   }
}

PhoneBook::PhoneBook(const PhoneBook& phoneBookToCopy){
    if (phoneBookToCopy.head == NULL)
      head = NULL;  // original list is empty
    else {
      // copy first node
      head = new Node;
      head->t = phoneBookToCopy.head->t;
      // copy rest of list
      Node *newPtr = head;  // new list ptr

      for (Node *origPtr = phoneBookToCopy.head->next;
                     origPtr != NULL;
                     origPtr = origPtr->next){
         newPtr->next = new Node;
         newPtr = newPtr->next;
         newPtr->t = origPtr->t;
      }
      newPtr->next = NULL;
   }



}


bool PhoneBook::addPerson(string name){

if (findPerson(name) == NULL){
    Person p(name);
    Node* newptr = new Node;
    newptr->t = p;
    newptr->next = NULL;

    if(head == NULL){
        head = newptr;
        numberOfPeople++;
        return true;
    }

    if(head!=NULL){

        Node* curr = head;
        for(int i = 1;i < numberOfPeople;i++){
        curr = curr->next; //reach end of list

        }
        curr->next = newptr;
        numberOfPeople++;

        curr = NULL;
        delete curr;
        return true;

    }


}
cout<<"The Person By the Name of ' " << name  << " ' Already Exists"<<endl;
return false;



}


bool PhoneBook::removePerson(const string name){

if (findPerson(name) != NULL)
{
    string str1 = name;
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);

    Node* curr = head;
    string str = curr->t.getName();
    transform(str.begin(), str.end(), str.begin(), ::toupper);

        if((str == str1)){
        head = head->next;
        return true;

    }

        string str2 = "";

    while(str2 != str1){
    str2 = curr->next->t.getName();
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

        if(str2!= str1)
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

void PhoneBook::displayPeople(){



    if(head == NULL)
        cout << "---EMPTY---"<< endl;
    else{

    Node* curr = head;

    while(curr != NULL){
        cout << curr->t.getName()<<" - Number of Phones : " << curr->t.getPhones() << endl;
        curr = curr->next;
    }
    delete curr;
    curr = NULL;


    }
}


void PhoneBook::displayAreaCode(int areaCode){

    bool emp = true;
    cout<<areaCode<<endl;
    Node* curr = head;
    while (curr != NULL){
        if(curr->t.findPhonesWithAreaCode(areaCode))
            emp = false;
        curr=curr->next;
    }
    if (emp)
        cout<<"--EMPTY--"<<endl;
}


bool PhoneBook::addPhone(string personName, int areaCode, int number){

    Node* p  = findPerson(personName);
    if (p == NULL){
        cout<<"A person by the entered name " << personName << " does not exist" <<endl;
        return false;
    }
    else
    {
        p->t.addPhone(areaCode,number);
        return true;
    }
}

bool PhoneBook::removePhone(string personName, int areaCode, int number){

    Node* p  = findPerson(personName);
    if (p == NULL){
        cout<<"A person by the entered name " << personName << " does not exist" <<endl;
        return false;
    }
    else
    {
        p->t.removePhone(areaCode,number);
        return true;
    }
}

void PhoneBook::displayPerson(string personName){

Node* p  = findPerson(personName);
if (p == NULL){
        cout<<"----EMPTY----"<<endl;
        cout<<"A person by the entered name " << personName << " does not exist" <<endl;
}
else{

    cout<< personName << endl;
    p->t.displayPhoneNumbers();
}

}

PhoneBook::Node* PhoneBook::findPerson(string name){

Node* curr = head;
if (curr != NULL)
{
    while( (curr!=NULL) ){


       string str1 = name;
       string str2 = curr->t.getName();
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

        if (str1 == str2)
            return curr;
        else

            curr = curr->next;
        }
        return NULL; //ADD case sensitivity
}

return NULL;
}

PhoneBook::~PhoneBook(){
delete head;
}
