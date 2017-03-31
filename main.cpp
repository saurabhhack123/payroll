/******************************
   Name
   Date
   File Name template.cpp
   Description
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <limits>
using namespace std;

#include "employee.h"
#include "hourlyemployee.h"
#include "salaryemployee.h"

void loadEmployees(vector<HourlyEmployee> &hourlyemployees,vector<SalaryEmployee> &salaryemployees, string fileName)
{
  string line;
  string id,firstName,lastName;
  string type;
  double hourly_worked;
  ifstream myfile(fileName);
  if (myfile.is_open())
  {
   
    while ( getline (myfile,line) )
    {
      std::vector<std::string> result;
      std::istringstream iss(line);
      for(std::string s; iss >> s;)
      result.push_back(s);
      
      type=result[0];
      id=result[1];
      firstName=result[2];
      lastName=result[3];   
      hourly_worked= atof(result[4].c_str());
      if(type.compare("H") == 0)
          hourlyemployees.push_back(HourlyEmployee(id,firstName,lastName,hourly_worked));
      else
          salaryemployees.push_back(SalaryEmployee(id,firstName,lastName,hourly_worked));
    }
    myfile.close();
  }else {
    cout << "Unable to open file"; 
  }
      
   
  return;

}
struct EmployeeTime
{
	string id;				// ID of employee
	double hours;						// Hours worked for week
};

int main(){

  std::vector<HourlyEmployee> hourlyemployees;
  std::vector<SalaryEmployee> salaryemployees;
  loadEmployees(hourlyemployees,salaryemployees,"employees.dat");
  
     
  string id;
  string line;
  string time;
  vector<EmployeeTime> empTime;
  
  ifstream myfile("emp_time.dat");
  ofstream payroll;
  payroll.open ("payroll.txt");
  
  if (myfile.is_open())
  { int i=0;
    while ( getline (myfile,line) )
    {
      std::vector<std::string> result;
      std::istringstream iss(line);
      for(std::string s; iss >> s;)
      result.push_back(s);
      
      empTime.push_back(EmployeeTime());
      empTime[i].id=result[0];
      empTime[i].hours= atof(result[1].c_str());
      i=i+1;
    }
  }
  
  vector<EmployeeTime>::iterator it3;
  vector<HourlyEmployee>::iterator it1;
  vector<SalaryEmployee>::iterator it2;
  
  
      
  for (it3 = empTime.begin(); it3 != empTime.end(); ++it3)
  {    for (it1 = hourlyemployees.begin(); it1 != hourlyemployees.end(); ++it1)
       { if( it1->id == it3->id)
         { 
           cout << it1->id << " " << it1->lastName << "," << it1->firstName << " " << std::fixed << std::setprecision(2) << it3->hours << " " << it3->hours * it1->hourly_wage << "\n";
           payroll << it1->id << " " << it1->lastName << "," << it1->firstName << " " << std::fixed << std::setprecision(2) << it3->hours << " " << it3->hours * it1->hourly_wage << "\n";
         }
       }
  
      for (it2 = salaryemployees.begin(); it2 != salaryemployees.end(); ++it2)
       { if( it2->id == it3->id)
         { 
           cout << it2->id << " " << it2->lastName << "," << it2->firstName << " " << std::fixed << std::setprecision(2) << it3->hours << " " << it3->hours * it2->weekly_salary << "\n";
           payroll << it2->id << " " << it2->lastName << "," << it2->firstName << " " << std::fixed << std::setprecision(2) << it3->hours << " " << it3->hours * it2->weekly_salary << "\n";
         
         }
       }
  }
  payroll.close();
  return 0;
}