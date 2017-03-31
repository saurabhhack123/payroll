/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "salaryemployee.h"

SalaryEmployee::SalaryEmployee(string pid,string pfirstName,string plastName,double pweekly_salary):Employee(pid,pfirstName,plastName),weekly_salary(pweekly_salary)
{     
   
};

double SalaryEmployee::calculatePay(double hours){
    return hours*weekly_salary;
}