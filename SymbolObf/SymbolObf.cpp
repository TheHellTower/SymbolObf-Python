#include <fstream>
#include <iostream>
#include <Windows.h>

#include "Utils.h"

using namespace std;

Utils utils = Utils();

string templateOutput = R"(#Obfuscated with: https://github.com/TheObfuscators/SymbolObf By TheHellTower

THT_6669=[{TheHellTower}];THT_1=__import__;THT_2=dir;THT_3=THT_1(("s"+"n"+"i"+"t"+"l"+"i"+"u"+"b")[::+-+-(-(+1))]);THT_4=getattr;THT_5=[("s"+"n"+"i"+"t"+"l"+"i"+"u"+"b"),("c"+"e"+"x"+"e")];THT_4(THT_3, THT_2(THT_3)[THT_2(THT_1(THT_5[0][::+-+-(-(+1))])).index(THT_5[1][::+-+-(-(+1))])])("".join([chr(len(i)) for i in THT_6669])))";
string toAdd;
char theChar;

string filePath;
ifstream file;
ofstream outputFile;

int main()
{
    SetConsoleTitleA("Symbol Obfuscator");
    //Need a valid file
    while (!utils.doesFileExist(filePath)) {
        cout << "Python File Path: ";
        getline(cin, filePath);
        system("cls");
    }

    while (theChar == '\0') {
        cout << "Char To Use(Ex: #): ";
        cin >> theChar;
        system("cls");
    }
    

    //Open the file
    file.open(filePath);

    //Iterate through the content
    string fileContent((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    //Sexy iteration
    int i = 0;
    while (i < strlen(fileContent.c_str())) {
        toAdd += "\"" + string((int)fileContent[i], theChar) + "\",";
        i++;
    }

    //To remove the last char from "toAdd" string (',' in this case)
    toAdd.pop_back();

    //Add "toAdd" string to the template
    utils.replace_all(templateOutput, "{TheHellTower}", toAdd);
    
    utils.replace_all(filePath, ".py", "-SymbolObf.py");

    outputFile.open(filePath, ofstream::binary);
    outputFile.write(templateOutput.c_str(), templateOutput.length());
    outputFile.close();
}