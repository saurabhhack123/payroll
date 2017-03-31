
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   salaryemployee..h
 * Author: codedoctor
 *
 * Created on 29 March 2017, 02:51
 */

#ifndef SALARYEMPLOYEE__H
#define SALARYEMPLOYEE__H

#include <string>
#include "employee.h"
using namespace std;


class SalaryEmployee : public Employee{
       
    public:
        double weekly_salary;
        SalaryEmployee(string id,string firstName,string lastName,double weekly_salary);
        double calculatePay(double hours);     
};
#endif /* SALARYEMPLOYEE__H */

