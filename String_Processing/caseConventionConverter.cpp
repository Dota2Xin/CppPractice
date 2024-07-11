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

bool isVarCharacter(char c) {
    int charNum=static_cast<int>(c);
    if ((charNum>=97 && charNum<= 122) || (charNum>=65 && charNum<=90) || (charNum==95)) {
        return true;
    }
    return false;
}
int getNextWordPosition(string str) {
    int countTill=2;
    int currentElement=1;
    int previousElement=0;
    while(countTill>0 && currentElement<str.length()) {
        if(isVarCharacter(str[currentElement])!=isVarCharacter(str[previousElement])) {
            countTill--;
        }
        currentElement+=1;
        previousElement+=1;
    }
    if(currentElement==str.length()) {
        return -1;
    }
    return currentElement;
}

bool isCamelCased(string word) {
    int wordNum;
    wordNum=static_cast<int>(word[0]);
    if(!(wordNum>=97 && wordNum<=122)) {
        return false;
    }
    bool hasCapital=false;
    for(int i=0; i<word.length(); i++) {
        wordNum= static_cast<int>(word[i]);
        if(wordNum==95) {
            return false;
        }
        if(wordNum>=65 && wordNum<=90) {
            hasCapital=true;
        }
    }
    return hasCapital;
}
string updateWord(string word) {
    string newWord="";
    int currentIndex=0;
    while(!isVarCharacter(word[currentIndex])) {
        currentIndex++;
        newWord+=word[currentIndex];
    }
    string trueWord=word.substr(currentIndex);
    if(isCamelCased(trueWord)) {
        int currentPos=1;
        int previousPos=0;
        while(currentPos<trueWord.length()) {
            int currentNum=static_cast<int>(trueWord[currentPos]);
            int previousNum=static_cast<int>(trueWord[previousPos]);
            //TODO HANDLE ACTUAL CONVERSION FROM CAMEL TO SNAKE CASE
        }
        return newWord;
    }
    return word;
}

string processLine(string originalLine) {
    string usefulLine=removeStartingWhitespace(originalLine);
    string specialLineStarts[12]={"using", "#include", "#define","#undef", "#ifdef","#ifndef","#if","#else","#elif","#endif","#error","#pragma"};
    if(originalLine.length()==0) {
        return originalLine;
    }
    for(int i=0; i<12; i++) {
        string currentString=specialLineStarts[i];
        if(areStringsEqual(usefulLine.substr(0,currentString.length()), currentString)) {
            return originalLine;
        }
    }
    string currentString=originalLine.substr(0);
    string newLine="";
    string currentWord="";
    int nextWord=0;
    while(getNextWordPosition(currentString)!=-1) {
        nextWord=getNextWordPosition(currentString);
        currentWord=currentString.substr(0,nextWord);
        currentWord=updateWord(currentWord);
        newLine+=currentWord;
        currentString=currentString.substr(nextWord);
    }
    //TODO=HANDLE -1 CASE
    return newLine;
}

/*
Takes a .cpp file and attempts to convert it from camelcase to snake case. I don't want to build the C++ compiler so we'll do something
slightly different. We assume that the file is made with standard spacing and linebreaks and that variable and function names consist
entirely of english letters, underscores and numbers. Then we just convert every label type thing into snakecase. I'm going to assume
you never start a line with a variable or function name, which I think is legit for basically all the code I see. Something is camelcased
if it starts with a lowercase letter and then has an uppercase later in the string without containing an underscore. 
*/
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