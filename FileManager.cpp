#include "FileManager.h"
#include "StatementPrinter.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Initializes the FileManager and loads the data
FileManager::FileManager(const std::string& paymentsFile, const std::string& peopleFile) {
    loadPeople(peopleFile);
    loadPayments(paymentsFile);
}

// Loads payments data and validates each line
void FileManager::loadPayments(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "[Error] Unable to open payments file: " << filename << std::endl;
        return;
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "[Error] The payments file is empty: " << filename << std::endl;
        return;
    }

    std::string line, personName, item;
    double amount;
    int lineNumber = 0;

    while (std::getline(file, line)) {
        ++lineNumber;
        std::istringstream iss(line);
        if (iss >> personName >> item >> amount) {
            if (personName.empty() || item.empty() || amount <= 0) {
                std::cerr << "[Validation Error] Invalid data on line " << lineNumber << ": " << line << std::endl;
                continue;
            }
            processPaymentLine(personName, item, amount);
        } else {
            std::cerr << "[Validation Error] Malformed line (" << lineNumber << "): " << line << std::endl;
        }
    }
}

// Loads people data and validates the input
void FileManager::loadPeople(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "[Error] Unable to open people file: " << filename << std::endl;
        return;
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "[Error] The people file is empty: " << filename << std::endl;
        return;
    }

    std::string name;
    int lineNumber = 0;

    while (std::getline(file, name)) {
        ++lineNumber;
        if (name.empty()) {
            std::cerr << "[Validation Error] Empty name on line " << lineNumber << std::endl;
            continue;
        }
        people[name] = Person(name);
    }
}

// Adds a valid transaction to the corresponding person
void FileManager::processPaymentLine(const std::string& personName, const std::string& item, double amount) {
    auto it = people.find(personName);
    if (it != people.end()) {
        it->second.addTransaction(item, amount);
    }
}

// Prints transaction statements for all people
void FileManager::printAllStatements() const {
    StatementPrinter printer;
    printer.printStatements(people);
}
