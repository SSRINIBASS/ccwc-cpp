#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int countBytes(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return -1;
    }

    file.seekg(0, std::ios::end);
    int size = file.tellg();
    file.close();
    return size;
}

int countLines(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return -1;
    }

    int lines = 0;
    std::string line;
    while (std::getline(file, line)) {
        ++lines;
    }

    file.close();
    return lines;
}

int countWords(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return -1;
    }

    int words = 0;
    std::string word;
    while (file >> word) {
        ++words;
    }

    file.close();
    return words;
}

int countChars(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return -1;
    }

    int chars = 0;
    char ch;
    while (file.get(ch)) {
        ++chars;
    }

    file.close();
    return chars;
}



int countLinesFromString(const std::string& input) {
    std::istringstream iss(input);
    int lines = 0;
    std::string line;
    while (std::getline(iss, line)) {
        ++lines;
    }
    return lines;
}

int countWordsFromString(const std::string& input) {
    std::istringstream iss(input);
    int words = 0;
    std::string word;
    while (iss >> word) {
        ++words;
    }
    return words;
}

int countBytesFromString(const std::string& input) {
    return input.size();  // in bytes
}

int countCharsFromString(const std::string& input) {
    return input.length();  // in chars (assumes ASCII)
}

int main(int argc, char* argv[]) {
    if (argc == 3) {
        std::string flag = argv[1];
        std::string filename = argv[2];

        if (flag == "-c") {
            int bytes = countBytes(filename);
            if (bytes != -1)
                std::cout << bytes << " " << filename << "\n";
        }
        else if (flag == "-l") {
            int lines = countLines(filename);
            if (lines != -1)
                std::cout << lines << " " << filename << "\n";
        }
        else if (flag == "-w") {
            int words = countWords(filename);
            if (words != -1)
                std::cout << words << " " << filename << "\n";
        }
        else if (flag == "-m") {
            int chars = countChars(filename);
            if (chars != -1)
                std::cout << chars << " " << filename << "\n";
        }
        else {
            std::cerr << "Unknown flag: " << flag << "\n";
            return 1;
        }
    }
    else if (argc == 2) {
        std::string flag = argv[1];

        // Read stdin into a string
        std::ostringstream oss;
        oss << std::cin.rdbuf();
        std::string input = oss.str();

        if (flag == "-c") {
            std::cout << countBytesFromString(input) << "\n";
        }
        else if (flag == "-l") {
            std::cout << countLinesFromString(input) << "\n";
        }
        else if (flag == "-w") {
            std::cout << countWordsFromString(input) << "\n";
        }
        else if (flag == "-m") {
            std::cout << countCharsFromString(input) << "\n";
        }
        else {
            std::cerr << "Unknown flag: " << flag << "\n";
            return 1;
        }
    }
    else if (argc == 1) {
        // No args: read from stdin and print all 3 (like default `wc`)
        std::ostringstream oss;
        oss << std::cin.rdbuf();
        std::string input = oss.str();

        int lines = countLinesFromString(input);
        int words = countWordsFromString(input);
        int bytes = countBytesFromString(input);

        std::cout << lines << " " << words << " " << bytes << "\n";
    }
    else {
        std::cerr << "Usage: ccwc [-c|-l|-w|-m] [filename]\n";
        return 1;
    }

    return 0;
}
