#include <fstream> 
#include <iostream>
#include <cctype> 
#include <string> 
#include <filesystem>

using namespace std;

bool areStringsEqual(string str1, string str2) {
    if(str1.length() ==str2.length()) {
        for(int i=0; i<str1.length(); i++) {
            if(str1[i] != str2[i]) {
                return false;
            }
        }
    }
    else {
        return false;
    }
    return true;
}

string removeStartingWhitespace(string str) {
    int startIndex=0;
    while (isspace(str[startIndex])) {
        startIndex++;
    }
    return str.substr(startIndex);
}

string processLine(string originalLine) {
    string usefulLine=removeStartingWhitespace(originalLine);
    string specialLineStarts[12]={"using", "#include", "#define","#undef", "#ifdef","#ifndef","#if","#else","#elif","#endif","#error","#pragma"};

    for(int i=0; i<12; i++) {
        string currentString=specialLineStarts[i];
        if(areStringsEqual(usefulLine.substr(0,currentString.length()), currentString)) {
            return originalLine;
        }
    }

    
    return originalLine;
}

int camelcaseToSnakecase(string filePath) {
    int checkOpen=0;    
    string newFilePath;
    size_t fileType=filePath.find_last_of(".");
    newFilePath=filePath.substr(0,fileType)+"_to_snakecase"+filePath.substr(fileType);

    filesystem::path originalPath(filePath);
    filesystem::path newPath(newFilePath);

    ifstream readFile(originalPath);
    ofstream writeFile(newPath);
    
    string line;
    string newLine;

    while(getline(readFile, line)) {
        newLine=processLine(line);
        writeFile<< newLine <<std::endl;
    }

    readFile.close();
    writeFile.close();
    return 0;
}