#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Person.h"
#include <string>
#include <map>

// Handles loading and processing data from files
class FileManager {
private:
    std::map<std::string, Person> people;  // Maps person names to Person objects

public:
    FileManager(const std::string& paymentsFile, const std::string& peopleFile);  // Initializes the manager

    void loadPayments(const std::string& filename);  // Loads payment data from a file
    void loadPeople(const std::string& filename);  // Loads people data from a file
    void processPaymentLine(const std::string& personName, const std::string& item, double amount);  // Handles valid payment lines
    void printAllStatements() const;  // Prints statements for all people
};

#endif
