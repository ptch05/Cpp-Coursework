#include "Person.h"

// Initializes a person with a given name
Person::Person(const std::string& name) : name(name) {}

// Sets the person's name
void Person::setName(const std::string& newName) {
    name = newName;
}

// Adds a new transaction for the person
void Person::addTransaction(const std::string& item, double amount) {
    transactions.emplace_back(item, amount);
}

// Retrieves all transactions for the person
std::vector<std::pair<std::string, double>> Person::getTransactions() const {
    return transactions;
}

// Returns the person's name
std::string Person::getName() const {
    return name;
}

// Calculates the total amount spent across all transactions
double Person::getTotalSpent() const {
    double total = 0.0;
    for (const auto& transaction : transactions) {
        total += transaction.second;
    }
    return total;
}
