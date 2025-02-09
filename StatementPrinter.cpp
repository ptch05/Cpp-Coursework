#include "StatementPrinter.h"
#include <iostream>
#include <iomanip>

// Prints formatted statements for all people
void StatementPrinter::printStatements(const std::map<std::string, Person>& people) const {
    for (const auto& pair : people) {
        const Person& person = pair.second;
        std::cout << person.getName() << std::endl;
        for (const auto& transaction : person.getTransactions()) {
            std::cout << transaction.first << " "
                      << std::fixed << std::setprecision(1) << transaction.second << std::endl;
        }
        std::cout << "Total: " << std::fixed << std::setprecision(1) << person.getTotalSpent() << std::endl;
    }
}
