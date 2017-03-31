/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   employee.h
 * Author: codedoctor
 *
 * Created on 29 March 2017, 02:50
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee{        
public:
    string id;				// Id of employee
    string firstName;	// Employee's first name
    string lastName; // Employee's last name
    Employee(string id,string firstName,string lastName);
    string getID();
    string getfirstName();
    string getlastName();
    bool operator==(const Employee& emp);
    virtual double calculatePay(double hours)=0; // making abstract 
};

#endif /* EMPLOYEE_H */

