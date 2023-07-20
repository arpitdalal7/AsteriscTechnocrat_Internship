#include <iostream>
#include <vector>

using namespace std;


struct Employee {
    int employeeID;
    string name;
    double basicSalary;
    double overtimeHours;
    
};


class PayrollManagementSystem {
private:
    vector<Employee> employees;

public:
    void insertEmployee() {
        Employee employee;
        cout << "Enter employee ID: ";
        cin >> employee.employeeID;
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, employee.name);
        cout << "Enter employee basic salary: ";
        cin >> employee.basicSalary;

        employees.push_back(employee);
        cout << "Employee inserted successfully!\n";
    }

    double calculateSalary(const Employee& employee) {
        double totalSalary = employee.basicSalary;

        
        

        return totalSalary;
    }

    void generatePayslip(const Employee& employee) {
        double netSalary = calculateSalary(employee);

        cout << "Payslip for Employee ID: " << employee.employeeID << endl;
        cout << "Name: " << employee.name << endl;
        cout << "Basic Salary: " << employee.basicSalary << endl;
        cout << "Overtime Pay: " << endl;
        cout << "Bonuses: " << endl;
        cout << "Deductions: " << endl;
        cout << "Net Salary: " << netSalary << endl;
    }
};

int main() {
    PayrollManagementSystem pms;
    int choice;

    do {
        cout << "Payroll Management System\n";
        cout << "1. Insert Employee\n";
        cout << "2. Calculate Salary\n";
        cout << "3. Generate Payslip\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                pms.insertEmployee();
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                cout << "Exiting Management System...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}
