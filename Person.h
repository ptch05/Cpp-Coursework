#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <utility>

// Represents a person and their list of transactions
class Person {
private:
    std::string name;  // Person's name
    std::vector<std::pair<std::string, double>> transactions;  // Transactions as item-price pairs

public:
    Person() : name("") {}  // Default constructor for an unnamed person
    Person(const std::string& name);  // Constructor to initialize a person's name

    void setName(const std::string& newName);  // Sets or updates the person's name
    void addTransaction(const std::string& item, double amount);  // Adds a transaction to the person
    std::vector<std::pair<std::string, double>> getTransactions() const;  // Returns all transactions
    std::string getName() const;  // Retrieves the person's name
    double getTotalSpent() const;  // Calculates the total amount spent by the person
};

#endif
