#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Function to reverse the contents of a file
void reverseFileContents(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath);
    if(!inputFile) {
        std::cerr << "Error opening input file: " << inputFilePath << std::endl;
        return;
    
}

// Read the content of the file into a string
std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
inputFile.close();

// Reverse the string
std::reverse(content.begin(), content.end());

// Write the reversed string to the output file
std::ofstream outputFile(outputFilePath);
if (!outputFile) {
    std::cerr << "Error opening output file: " << outputFilePath << std::endl;
    return;
}

outputFile << content;
outputFile.close();
}

int main () {
    std::string filePath = "CSC450_CT5_mod5.txt";
    std::ofstream file;

    // Open the file in append mode
    file.open(filePath, std::ios::app);
    if(!file) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return 1;
    }

// Get input from the user
std::string userInput;
std::cout << "Enter text to append to the file: ";
std::getline(std::cin, userInput);

// Append user input to the file
file << userInput << std::endl;
file.close();

// Reverse the content of the file and save it to another file 
reverseFileContents(filePath, "CSC450_mod5_reverse.txt");

std::cout << "User input has been appended and the file contents have been reversed and storeed in CSC450_mod5_reverse.txt" << std::endl;

return 0;
}