#include <iostream>
#include <conio.h>
#include <string>

#include "INILoader.h"

int main()
{

    std::string name = INILoader::GetValFromIniFile("������", "name", "./sample.ini");
    int age = INILoader::GetValFromIniFile("������", "age", "./sample.ini");
    float height = INILoader::GetValFromIniFile("������", "height", "./sample.ini");
    
    // �擾�����l�m�F
    std::cout << name << std::endl;
    std::cout << age << std::endl;
    std::cout << height << std::endl;

    _getch();
    return 0;
}