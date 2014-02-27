#include "INILoader.h"
#include <fstream>
#include <iostream>
#include <sstream>

const LPCTSTR INILoader::kDefaultStr = "�L�[��������܂���ł���";//�L�[���������̕�����̖߂�l
const UINT INILoader::kDefaultInt = 999;                              //�L�[����������int�^�̖߂�l
const float INILoader::kDefaultFloat = 999.0f;                        //�L�[����������float�^�̖߂�l

// int�^�Ŏ擾
int INILoader::TempObject::GetTypeInteger(LPCTSTR section_name, LPCTSTR key_name, LPCTSTR ini_file_path)
{
    int ret = GetPrivateProfileInt(section_name, key_name, kDefaultInt, ini_file_path);
    return ret;
}

// float�^�Ŏ擾
float INILoader::TempObject::GetTypeFloat(LPCTSTR section_name, LPCTSTR key_name, LPCTSTR ini_file_path)
{
    std::string str = INILoader::TempObject::GetTypeString(section_name, key_name, ini_file_path);//������ōŏ��Ɏ擾���Ă���
    if(str == INILoader::kDefaultStr){//������Ȃ������Ƃ�
        return kDefaultFloat;
    }
    float ret = ToFloat(str);//float�^�ɕϊ�
    return ret;
}

// string�^�Ŏ擾
std::string	INILoader::TempObject::GetTypeString(LPCTSTR section_name, LPCTSTR key_name, LPCTSTR ini_file_path)
{
    const int kMaxString=256;//�ő啶����
    char buffa[kMaxString];//�ꎞ�o�b�t�@
    GetPrivateProfileString( section_name, key_name, kDefaultStr, buffa, kMaxString, ini_file_path);
    std::string ret(buffa);
    return ret;
}

bool INILoader::IsFoundFile(const char* file_name)
{
    
    std::ifstream ifs(file_name);
    if (ifs.fail()) {
        return false;//�ǂݍ��ݎ��s
    }else {
        return true;//�ǂݍ��ݐ���
    }
    
    return true;

}

float INILoader::ToFloat(const std::string str)
{
    std::stringstream ss;
    ss << str;
    float ret;
    ss >> ret;//float�^�ɕϊ�
    return ret;
}

// INI�t�@�C������l���擾����
INILoader::TempObject INILoader::GetValFromIniFile(LPCTSTR section_name, LPCTSTR key_name, LPCTSTR ini_file_path) {
    std::string file_path(ini_file_path);
    if( !IsFoundFile(ini_file_path) ) {
        std::cout << "INI�t�@�C���ǂݍ��ݎ��s���܂���" << std::endl;
    }
    return TempObject(section_name, key_name, ini_file_path);
}