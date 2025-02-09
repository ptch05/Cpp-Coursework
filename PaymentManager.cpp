#include "PaymentManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Loads payments and people from files
PaymentManager::PaymentManager(const std::string& paymentsFile, const std::string& peopleFile) {
    std::ifstream paymentsStream(paymentsFile);
    if (!paymentsStream) {
        std::cerr << "Failed to open " << paymentsFile << std::endl;
        return;
    }

    std::ifstream peopleStream(peopleFile);
    if (!peopleStream) {
        std::cerr << "Failed to open " << peopleFile << std::endl;
        return;
    }

    std::string line;

    // Load payments from the payments file
    while (getline(paymentsStream, line)) {
        std::istringstream iss(line);
        std::string person, item;
        double price;

        // Parse person, item, and price from the line
        if (iss >> person >> item >> price) {
            payments[person].emplace_back(item, price);  // Add the transaction to the map
            std::cout << "Loaded payment for " << person << ": " << item << " - " << price << std::endl;
        } else {
            std::cerr << "Error reading payment record: " << line << std::endl;
        }
    }

    // Load people from the people file
    while (getline(peopleStream, line)) {
        people.push_back(line);  // Add each person to the people list
        std::cout << "Loaded person: " << line << std::endl;
    }
}

// Prints statements for all people, including their purchases and totals
void PaymentManager::printStatements() const {
    // Check if any people are loaded
    if (people.empty()) {
        std::cout << "No people found." << std::endl;
        return;
    }

    // Check if any payments are loaded
    if (payments.empty()) {
        std::cout << "No payments found." << std::endl;
        return;
    }

    // Loop through all people
    for (const auto& person : people) {
        auto it = payments.find(person);  // Find the person's transactions
        if (it == payments.end()) {
            // Print "No purchases" if no transactions exist
            std::cout << person << std::endl << "No purchases" << std::endl << "Total: 0" << std::endl;
            continue;
        }

        // Calculate and print the person's transactions and total spent
        double total = 0;
        std::cout << person << std::endl;
        for (const auto& [item, amount] : it->second) {
            std::cout << item << " " << amount << std::endl;
            total += amount;
        }
        std::cout << "Total: " << total << std::endl;
    }
}
