/***** String.cpp *****/
#include "String.h"

string::string(const char* s){
    len=(s!=NULL?strlen(s)+1:1);
    str=new char[len];

    if(s!=NULL)
        strcpy(str, s);
}