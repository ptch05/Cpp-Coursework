#ifndef PAYMENTMANAGER_H
#define PAYMENTMANAGER_H

#include <string>
#include <vector>
#include <map>

// Manages payments and people data
class PaymentManager {
private:
    std::map<std::string, std::vector<std::pair<std::string, double>>> payments;  // Maps names to transactions
    std::vector<std::string> people;  // List of people

public:
    PaymentManager(const std::string& paymentsFile, const std::string& peopleFile);  // Loads data from files
    void processFiles();  // Processes loaded data (not currently used)
    void printStatements() const;  // Prints all people and their transactions
};

#endif
