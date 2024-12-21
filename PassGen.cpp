





// *~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~*


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


string generatePassword(int length) {
    const string characters =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[]{}|;:',.<>?/";
    string password;
    srand(time(0)); 

    for (int i = 0; i < length; ++i) {
        password += characters[rand() % characters.size()];
    }
    return password;
}


void ensureFileExists(const string& filename) {
    ifstream file(filename);
    if (!file) { 
        ofstream createFile(filename);
        createFile.close();
    }
}


void savePasswordToFile(const string& filename, const string& name, const string& password) {
    ensureFileExists(filename);
    ofstream file(filename, ios::app); // 
    if (file.is_open()) {
        file << name << ": " << password << "\n";
        file.close();
    }
    else {
        cerr << "File is not accessible\n";
    }
}

int main() {
    string name;
    int length;
    const string filename = "passlog.txt";

    
    cout << "Enter the name of password: ";
    getline(cin, name);

    cout << "Enter password length: ";
    cin >> length;

    
    string password = generatePassword(length);
    savePasswordToFile(filename, name, password);

    cout << "\n" << "Password generated and saved in " << filename << ".\n";

    return 0;
}






// *~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~**~*
