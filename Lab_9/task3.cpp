#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct Employee{
    std::string position;
    std::string fullName;
    std::string gender;
    std::string birthDate;
    std::string workDate;
    std::string education;
    std::string specialty;
    std::string maritalStatus;
    std::string department;
};
Employee Parse(const std::string& str)
{
    std::stringstream ss(str);
    std::string name1,name2,name3;
    Employee temp;
    ss>>temp.position;
    ss>>name1>>name2>>name3;
    temp.fullName=name1+' '+name2+' '+name3;
    name1=name2=name3="";
    ss>>temp.gender>>temp.birthDate>>temp.workDate>>temp.education>>temp.specialty;
    ss>>name1;
    if (name1=="Не"||name1=="не")
    {
        ss>>name2;
         temp.maritalStatus=name1+" "+name2;
    }
    else
         temp.maritalStatus=name1;
    while (ss >> name1) {
       temp.department+=' '+name1;
        }
    return temp;
}

std::vector<Employee> SortEmployee(const std::vector<Employee>& employees, const std::string& filtr,bool (*sortfunct)(const Employee&, const std::string&))
{
    std::vector<Employee> result;
    for (const auto& employee : employees) {
        if (sortfunct(employee, filtr)) {
            result.push_back(employee);
        }
    }
    return result;
}

bool isSingleMan(const Employee& employee, const std::string& maritalStatus) {
    return ((employee.gender =="м") && (employee.maritalStatus == maritalStatus));
}

bool isSingleHigherEducation(const Employee& employee, const std::string& education) {
    return isSingleMan(employee, "Не женат") && employee.education == education;
}

bool isSingleWoman(const Employee& employee, const std::string& maritalStatus) {
    return employee.gender=="ж" && employee.maritalStatus == maritalStatus;
}

int task3()
{
    std::vector<Employee> employees;
    std::string line;
    std::ifstream in("baza.info");
    if(in.fail()) {
        std::cerr << "Open file failed."<<'\n';
        return 1;
    }
    while(1) {
        std::getline(in, line);
        if(in.eof())
            break;
        employees.push_back(Parse(line));
    }
    in.close();
    std::vector<Employee> singleMen=SortEmployee(employees,"Не женат",isSingleMan);
    std::vector<Employee> singlehighereducation=SortEmployee(employees,"В/О",isSingleHigherEducation);
    std::vector<Employee> singlewoman=SortEmployee(employees,"Не замужем",isSingleWoman);
    for(auto var:singleMen)
    {
        printf("Не женатых мужчин:\n");
        printf("            %s\n",var.fullName.c_str());
    }
    for(auto var:singlehighereducation)
    {
        printf("Не женатых мужчин с В/О:\n");
        printf("            %s\n",var.fullName.c_str());
    }
    for(auto var:singlewoman)
    {
        printf("Конкуренток:\n");
        printf("            %s\n",var.fullName.c_str());
    }
    return 0;
}
