#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Company {
    string name;
    string owner;
    string phone;
    string address;
    string business;
};

class Directory {
private:
    vector<Company> companies;
    const string filename = "directory.txt";

    void loadFromFile() {
        ifstream file(filename);
        if (!file) return;
        Company c;
        while (getline(file, c.name) && getline(file, c.owner) && getline(file, c.phone) && getline(file, c.address) && getline(file, c.business)) {
            companies.push_back(c);
        }
        file.close();
    }

    void saveToFile() {
        ofstream file(filename);
        for (const auto &c : companies) {
            file << c.name << "\n" << c.owner << "\n" << c.phone << "\n" << c.address << "\n" << c.business << "\n";
        }
        file.close();
    }

public:
    Directory() { loadFromFile(); }
    ~Directory() { saveToFile(); }

    void addCompany(const Company &c) {
        companies.push_back(c);
    }

    void searchByName(const string &query) {
        for (const auto &c : companies) {
            if (c.name == query) {
                printCompany(c);
            }
        }
    }

    void searchByOwner(const string &query) {
        for (const auto &c : companies) {
            if (c.owner == query) {
                printCompany(c);
            }
        }
    }

    void searchByPhone(const string &query) {
        for (const auto &c : companies) {
            if (c.phone == query) {
                printCompany(c);
            }
        }
    }

    void searchByBusiness(const string &query) {
        for (const auto &c : companies) {
            if (c.business == query) {
                printCompany(c);
            }
        }
    }

    void printAll() {
        for (const auto &c : companies) {
            printCompany(c);
        }
    }

private:
    void printCompany(const Company &c) {
        cout << "название фирмы: " << c.name << "\nвладелец: " << c.owner << "\nтелефон: " << c.phone << "\nадрес: " << c.address << "\nрод деятельности: " << c.business << "\n---\n";
    }
};

int main() {
    Directory dir;
    int choice;
    do {
        cout << "1. добавить фирму\n2. поиск по названию\n3. поиск по владельцу\n4. поиск по телефону\n5. поиск по роду деятельности\n6. вывести все записи\n0. выход\nваш выбор: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            Company c;
            cout << "название фирмы: "; getline(cin, c.name);
            cout << "владелец: "; getline(cin, c.owner);
            cout << "телефон: "; getline(cin, c.phone);
            cout << "адрес: "; getline(cin, c.address);
            cout << "род деятельности: "; getline(cin, c.business);
            dir.addCompany(c);
        } else if (choice >= 2 && choice <= 5) {
            string query;
            cout << "введите запрос: "; getline(cin, query);
            if (choice == 2) dir.searchByName(query);
            if (choice == 3) dir.searchByOwner(query);
            if (choice == 4) dir.searchByPhone(query);
            if (choice == 5) dir.searchByBusiness(query);
        } else if (choice == 6) {
            dir.printAll();
        }
    } while (choice != 0);
    return 0;
}
