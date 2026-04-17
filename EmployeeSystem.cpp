#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
public:
    string name;
    double baseSalary;

    virtual double totalSalary() = 0;
    virtual string getRole() = 0;
};

class Developer : public Employee {
public:
    int projects;

    double totalSalary() override {
        return baseSalary + projects * 5000;
    }
    string getRole() override {
        return "Developer";
    }
};
class Manager : public Employee {
public:
    double saleAmount;

    double totalSalary() override {
        return baseSalary + saleAmount * 0.1;
    }
    string getRole() override {
        return "Manager";
    }
};

class Intern : public Employee {
public:
    double totalSalary() override {
        return baseSalary;
    }
    string getRole() override {
        return "Intern";
    }
};

int main()
{
    vector<Employee*> staff;
    int choice;

    while (true) {
        cout << "\n==== EmployeeSystem ====" << endl;
        cout << "1. Add Developer" << endl;
        cout << "2. Add Manager" << endl;
        cout << "3. Add Intern" << endl;
        cout << "4. Show all" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (choice == 1) {
            Developer* d = new Developer();
            cout << "Name: ";
            cin.ignore();
            getline(cin, d->name);
            cout << "Base salary: ";
            cin >> d->baseSalary;
            cout << "Projects: ";
            cin >> d->projects;
            staff.push_back(d);
            cout << "Developer added!" << endl;
        }
        else if (choice == 2) {
            Manager* m = new Manager();
            cout << "Name: ";
            cin.ignore();
            getline(cin, m->name);
            cout << "Base salary: ";
            cin >> m->baseSalary;
            cout << "Sale amount: ";
            cin >> m->saleAmount;
            staff.push_back(m);
            cout << "Manager added!" << endl;
        }
        else if (choice == 3) {
            Intern* i = new Intern();
            cout << "Name: ";
            cin.ignore();
            getline(cin, i->name);
            cout << "Base salary: ";
            cin >> i->baseSalary;
            staff.push_back(i);
            cout << "Intern added!" << endl;
        }
        else if (choice == 4) {
            if (staff.empty()) {
                cout << "No employee yet." << endl;
            }
            else {
                for (int i = 0; i < staff.size(); i++) {
                    cout << i + 1 << ". " << staff[i]->name
                        << " | " << staff[i]->getRole()
                        << " | Salary: " << staff[i]->totalSalary() << endl;
                }
            }
        }
        else if (choice == 0) {
            cout << "Bye!" << endl;
            break;
        }
    }
    for (int i = 0; i < staff.size(); i++) delete staff[i];
    return 0;

}

