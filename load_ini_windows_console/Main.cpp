#include <iostream>
#include <conio.h>
#include <string>

#include "INILoader.h"

int main()
{

    std::string name = INILoader::GetValFromIniFile("たかし", "name", "./sample.ini");
    int age = INILoader::GetValFromIniFile("たかし", "age", "./sample.ini");
    float height = INILoader::GetValFromIniFile("たかし", "height", "./sample.ini");
    
    // 取得した値確認
    std::cout << name << std::endl;
    std::cout << age << std::endl;
    std::cout << height << std::endl;

    _getch();
    return 0;
}