#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Company {
private:
    string name;
    string address;
    string directorName;
    int numberOfEmployee;

public:
    Company() {
        name = "";
        address = "";
        directorName = "";
        numberOfEmployee = 0;
    }

    Company(string name, string address, string directorName, int numberOfEmployee) {
        this->name = name;
        this->address = address;
        this->directorName = directorName;
        this->numberOfEmployee = numberOfEmployee;
    }

    ~Company() {

    }

    string getCompanyName() const {
        return name;
    }

    string getCompanyAddress() const {
        return address;
    }

    string getDirectorName() const {
        return directorName;
    }

    int getNumberOfEmployee() const {
        return numberOfEmployee;
    }

    void showInfo() const {
        cout << "Company name: " << name << endl;
        cout << "Address of company: " << address << endl;
        cout << "Name of CEO: " << directorName << endl;
        cout << "Number of employee: " << numberOfEmployee << endl;
        cout << "===================" << endl << endl;
    }

    void inputData() {
        cout << "Enter the name company: " << endl;
        cin >> name;
        cout << "Enter the address of company: " << endl;
        cin >> address;
        cout << "Enter the name of CEO: " << endl;
        cin >> directorName;
        cout << "Enter the number of employee: " << endl;
        cin >> numberOfEmployee;
    }

    bool emptyName() const {
        return name.empty();
    }
};

// Используем sort для сортировки
void bubbleSort(vector<Company>& companies) {
    sort(companies.begin(), companies.end(), [](const Company& a, const Company& b) {
        return a.getNumberOfEmployee() < b.getNumberOfEmployee();
        });
}

int main() {
    vector<Company> companies;
    int choice;

    do {
        cout << "Menu: " << endl;
        cout << "1. Display companies: " << endl;
        cout << "2. Create a new company: " << endl;
        cout << "3. Sort by company name: " << endl;
        cout << "4. Display companies by known name: " << endl;
        cout << "5. Add a new element to position 1: " << endl;
        cout << "6. Remove element by number of employees: " << endl;
        cout << "7. Save companies to file: " << endl;
        cout << "0. Exit." << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Display companies data: " << endl;
            for (const auto& company : companies) {
                company.showInfo();
            }
            break;

        case 2: {
            cout << "Create a new company: " << endl;
            Company newCompany;
            newCompany.inputData();
            companies.push_back(newCompany);
            break;
        }

        case 3: {
            cout << "Sorting companies names with sort: " << endl;
            bubbleSort(companies);

            cout << "Sorted by companies names: \n";
            for (const auto& company : companies) {
                company.showInfo();
            }
            break;
        }

        case 4: {
            cout << "Display companies by known name: " << endl;
            for (const auto& company : companies) {
                if (!company.emptyName()) {
                    company.showInfo();
                }
            }
            break;
        }

        case 5: {
            cout << "Add new element at position 1" << endl;
            Company newCompany;
            newCompany.inputData();
            companies.insert(companies.begin(), newCompany);
            break;
        }

        case 6: {
            cout << "Remove element by number of employees" << endl;
            int employeesToRemove;
            cout << "Enter number of employees to remove: ";
            cin >> employeesToRemove;

            auto it = find_if(companies.begin(), companies.end(), [employeesToRemove](const Company& company) {
                return company.getNumberOfEmployee() == employeesToRemove;
                });

            if (it != companies.end()) {
                companies.erase(it);
                cout << "Element removed successfully." << endl;
            }
            else {
                cout << "No element found with the specified number of employees." << endl;
            }
            break;
        }

        case 7: {

            // Открытие файла в режиме записи
            ofstream outFile("companies.txt");

            // Проверка открытия файла
            if (outFile.is_open()) {
                // Запись информации о каждой компании в файл
                for (const auto& company : companies) {
                    outFile << company.getCompanyName() << endl;
                    outFile << company.getCompanyAddress() << endl;
                    outFile << company.getDirectorName() << endl;
                    outFile << company.getNumberOfEmployee() << endl;
                    outFile << "===================" << endl << endl;
                }

                // Закрытие файла
                outFile.close();

                cout << "Companies data saved to file successfully!" << endl;
            }
            else {
                cout << "Error opening file for writing." << endl;
            }
            break;
        }
        case 0:
            cout << "Exit" << endl;
            break;

        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}