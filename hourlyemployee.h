/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hourlyemployee.h
 * Author: codedoctor
 *
 * Created on 29 March 2017, 02:50
 */

#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H
#include "employee.h"

#include <string>
using namespace std;

class HourlyEmployee : public Employee{
    
    public:
        double hourly_wage;
        HourlyEmployee(string id,string firstName,string lastName,double hourly_wage);
        double calculatePay(double hours);     
};

#endif /* HOURLYEMPLOYEE_H */

