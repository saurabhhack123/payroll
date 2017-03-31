/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "hourlyemployee.h"


HourlyEmployee::HourlyEmployee(string pid,string pfirstName,string plastName,double phourly_wage):Employee(pid,pfirstName,plastName),hourly_wage(phourly_wage)
{     
};

double HourlyEmployee::calculatePay(double hours){
    return hours*hourly_wage;
}