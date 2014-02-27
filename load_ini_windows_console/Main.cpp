#include <iostream>
#include <conio.h>
#include <string>

#include "INILoader.h"

int main()
{

    std::string name = INILoader::GetValFromIniFile("‚½‚©‚µ", "name", "./sample.ini");
    int age = INILoader::GetValFromIniFile("‚½‚©‚µ", "age", "./sample.ini");
    float height = INILoader::GetValFromIniFile("‚½‚©‚µ", "height", "./sample.ini");
    
    // Žæ“¾‚µ‚½’lŠm”F
    std::cout << name << std::endl;
    std::cout << age << std::endl;
    std::cout << height << std::endl;

    _getch();
    return 0;
}