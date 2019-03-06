#include "Phone.h"
#include <iostream>
using namespace std;

Phone::Phone(){
areaCode = 0;
number = 0;
}
Phone::Phone(const int areaCode, const int number){
this->areaCode = areaCode;
this->number = number;
}
Phone::getAreaCode(){
return areaCode;
}
Phone::getNumber(){
return number;
}

