#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

// Simulate the behavior of IsDebuggerPresent
bool IsDebuggerPresent() {
    return false;  // Simulate that no debugger is present
}

// Decrypt and print the flag (Mock function)
void decrypt_and_print_flag() {
    std::cout << "Flag: Stack{FlagDecrypted123}" << std::endl;
}

int main() {
    char secret[520];

    // Simulate the debugger check being bypassed by returning false
    if (IsDebuggerPresent()) {
        std::cout << "Debugger detected! Exiting..." << std::endl;
        exit(1);  // Simulate the exit behavior if debugger was present
    }

    std::cout << "Enter secret: ";
    fgets(secret, sizeof(secret), stdin);  // Safe reading of user input

    // Remove trailing newline if present from fgets
    size_t len = strlen(secret);
    if (len > 0 && secret[len - 1] == '\n') {
        secret[len - 1] = '\0';  // Remove the newline character
    }

    // Compare part of the input with the string "flag{sta"
    if (strncmp(secret + 5, "flag{sta", 8) == 0) {
        decrypt_and_print_flag();  // Proceed to flag decryption
    }
    else {
        std::cout << "Invalid secret!" << std::endl;
    }

    return 0;
}
