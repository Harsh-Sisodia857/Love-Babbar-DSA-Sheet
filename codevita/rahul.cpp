#include <iostream>
#include <bitset>

int main()
{
    // Input binary strings
    std::string rahulBinary1 = "10101";
    std::string rahulBinary2 = "1";

    // Ensure both binary strings have the same length by padding with leading zeros
    size_t maxLength = std::max(rahulBinary1.length(), rahulBinary2.length());
    rahulBinary1 = std::string(maxLength - rahulBinary1.length(), '0') + rahulBinary1;
    rahulBinary2 = std::string(maxLength - rahulBinary2.length(), '0') + rahulBinary2;

    // Perform XOR operation on each corresponding bit
    std::string resultBinary;
    for (size_t i = 0; i < maxLength; ++i)
    {
        resultBinary += (rahulBinary1[i] == rahulBinary2[i]) ? '0' : '1';
    }

    // Output the results
    std::cout << "Rahul binary 1: " << rahulBinary1 << std::endl;
    std::cout << "Rahul binary 2: " << rahulBinary2 << std::endl;
    std::cout << "XOR of binary 1 and 2 is: " << resultBinary << std::endl;

    return 0;
}
