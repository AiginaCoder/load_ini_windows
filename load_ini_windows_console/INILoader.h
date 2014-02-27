#pragma once
#include <windows.h>
#include <string>

// INIファイルローダー
class INILoader
{
private:
    static const LPCTSTR kDefaultStr;   //キー未発見時の文字列の戻り値
    static const UINT kDefaultInt;      //キー未発見時のint型の戻り値
    static const float kDefaultFloat;   //キー未発見時のfloat型の戻り値
    
    explicit struct TempObject//一時保存オブジェクト
    {
        // 引数はメンバとして持つ
        TempObject(LPCTSTR section_name, LPCTSTR key_name, LPCTSTR ini_file_path)
            : section_name_(section_name),
            key_name_(key_name),
            ini_file_path_(ini_file_path){
        }
        // 型キャスト演算子によって戻り値オーバーロードを再現
        operator int()    { return GetTypeInteger(section_name_, key_name_, ini_file_path_); }
        operator float() { return GetTypeFloat(section_name_, key_name_, ini_file_path_); }
        operator std::string() { return GetTypeString(section_name_, key_name_, ini_file_path_); }
    private:
        LPCTSTR section_name_;  // セクション名
        LPCTSTR key_name_;      // キー名
        LPCTSTR ini_file_path_; // INIファイル名
        // 戻り値の違いによるオーバーロード用関数
        static int			GetTypeInteger(LPCTSTR section_name, LPCTSTR key_name, LPCTSTR ini_file_path);
        static float		GetTypeFloat(LPCTSTR section_name, LPCTSTR key_name, LPCTSTR ini_file_path);
        static std::string	GetTypeString(LPCTSTR section_name, LPCTSTR key_name, LPCTSTR ini_file_path);
    };

    // ファイルが存在しているかどうか確認
    // 戻り値 ファイルが存在:true, ファイルがない:false
    static bool IsFoundFile(const char* file_name);

    // 文字列をfloat型に変換
    static float ToFloat(const std::string str);

    // 生成やコピーを禁止する
    INILoader(void){}
    ~INILoader(void){}
    INILoader(const INILoader& rhs);
    INILoader& operator=(const INILoader& rhs);
public:
    // INIファイルから値を取得する
    static TempObject GetValFromIniFile(LPCTSTR section_name, LPCTSTR key_name, LPCTSTR ini_file_path);
};

