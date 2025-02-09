#include "FileManager.h"

// Main function to run the program
int main() {
    FileManager manager("payments.txt", "people.txt");  // Initialize the FileManager with input files
    manager.printAllStatements();  // Print all transaction statements
    return 0;
}
