#include "INILoader.h"
#include <fstream>
#include <iostream>
#include <sstream>

const LPCTSTR INILoader::kDefaultStr = "キーが見つかりませんでした";//キー未発見時の文字列の戻り値
const UINT INILoader::kDefaultInt = 999;                              //キー未発見時のint型の戻り値
const float INILoader::kDefaultFloat = 999.0f;                        //キー未発見時のfloat型の戻り値

// int型で取得
int INILoader::TempObject::GetTypeInteger(LPCTSTR section_name, LPCTSTR key_name, LPCTSTR ini_file_path)
{
    int ret = GetPrivateProfileInt(section_name, key_name, kDefaultInt, ini_file_path);
    return ret;
}

// float型で取得
float INILoader::TempObject::GetTypeFloat(LPCTSTR section_name, LPCTSTR key_name, LPCTSTR ini_file_path)
{
    std::string str = INILoader::TempObject::GetTypeString(section_name, key_name, ini_file_path);//文字列で最初に取得しておく
    if(str == INILoader::kDefaultStr){//見つからなかったとき
        return kDefaultFloat;
    }
    float ret = ToFloat(str);//float型に変換
    return ret;
}

// string型で取得
std::string	INILoader::TempObject::GetTypeString(LPCTSTR section_name, LPCTSTR key_name, LPCTSTR ini_file_path)
{
    const int kMaxString=256;//最大文字列長
    char buffa[kMaxString];//一時バッファ
    GetPrivateProfileString( section_name, key_name, kDefaultStr, buffa, kMaxString, ini_file_path);
    std::string ret(buffa);
    return ret;
}

bool INILoader::IsFoundFile(const char* file_name)
{
    
    std::ifstream ifs(file_name);
    if (ifs.fail()) {
        return false;//読み込み失敗
    }else {
        return true;//読み込み成功
    }
    
    return true;

}

float INILoader::ToFloat(const std::string str)
{
    std::stringstream ss;
    ss << str;
    float ret;
    ss >> ret;//float型に変換
    return ret;
}

// INIファイルから値を取得する
INILoader::TempObject INILoader::GetValFromIniFile(LPCTSTR section_name, LPCTSTR key_name, LPCTSTR ini_file_path) {
    std::string file_path(ini_file_path);
    if( !IsFoundFile(ini_file_path) ) {
        std::cout << "INIファイル読み込み失敗しました" << std::endl;
    }
    return TempObject(section_name, key_name, ini_file_path);
}