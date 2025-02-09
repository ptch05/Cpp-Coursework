#ifndef STATEMENTPRINTER_H
#define STATEMENTPRINTER_H

#include "Person.h"
#include <map>
#include <string>

// Handles formatting and printing of transaction statements
class StatementPrinter {
public:
    void printStatements(const std::map<std::string, Person>& people) const;  // Prints all people’s transactions
};

#endif
