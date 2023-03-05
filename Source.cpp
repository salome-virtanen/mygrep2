#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char* argv[]) {

    if (argc >= 2) {
        std::string search_string = argv[1];
        std::string filename = argv[2];

        std::ifstream file(filename);

        if (!file.is_open()) {
            std::cout << "Can't open file. File is already open: " << filename << "\n";
            return 1;
        }

        std::string line;
        while (getline(file, line)) {
            if (line.find(search_string) != std::string::npos) {
                std::cout << line << '\n';
            }
        }

        file.close();
    }


    else {
        std::string str;
        std::cout << "Give a string from which to search for: ";
        std::getline(std::cin, str);
        std::string substr;
        std::cout << "Give search string: ";
        std::getline(std::cin, substr);
        std::cout << "\n";
        size_t pos = str.find(substr);
        if (pos != std::string::npos) {
            std::cout << "\"" << substr << "\" found in \"" << str << "\" in position " << pos << std::endl;
        }
        else {
            std::cout << "\"" << substr << "\" NOT found in \"" << str << "\"" << std::endl;
        }
        return 0;
    }

}
