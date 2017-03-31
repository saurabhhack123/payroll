/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "employee.h"

Employee::Employee(string pid,string pfirstName,string plastName):id(pid), firstName(pfirstName), lastName(plastName)
{     
};

string Employee::getID(){
    return id;
}

string Employee::getfirstName(){
    return firstName;
}

string Employee::getlastName(){
    return lastName;
}