#pragma once
#include <windows.h>
#include <string>

// INI�t�@�C�����[�_�[
class INILoader
{
private:
    static const LPCTSTR kDefaultStr;   //�L�[���������̕�����̖߂�l
    static const UINT kDefaultInt;      //�L�[����������int�^�̖߂�l
    static const float kDefaultFloat;   //�L�[����������float�^�̖߂�l
    
    explicit struct TempObject//�ꎞ�ۑ��I�u�W�F�N�g
    {
        // �����̓����o�Ƃ��Ď���
        TempObject(LPCTSTR section_name, LPCTSTR key_name, LPCTSTR ini_file_path)
            : section_name_(section_name),
            key_name_(key_name),
            ini_file_path_(ini_file_path){
        }
        // �^�L���X�g���Z�q�ɂ���Ė߂�l�I�[�o�[���[�h���Č�
        operator int()    { return GetTypeInteger(section_name_, key_name_, ini_file_path_); }
        operator float() { return GetTypeFloat(section_name_, key_name_, ini_file_path_); }
        operator std::string() { return GetTypeString(section_name_, key_name_, ini_file_path_); }
    private:
        LPCTSTR section_name_;  // �Z�N�V������
        LPCTSTR key_name_;      // �L�[��
        LPCTSTR ini_file_path_; // INI�t�@�C����
        // �߂�l�̈Ⴂ�ɂ��I�[�o�[���[�h�p�֐�
        static int			GetTypeInteger(LPCTSTR section_name, LPCTSTR key_name, LPCTSTR ini_file_path);
        static float		GetTypeFloat(LPCTSTR section_name, LPCTSTR key_name, LPCTSTR ini_file_path);
        static std::string	GetTypeString(LPCTSTR section_name, LPCTSTR key_name, LPCTSTR ini_file_path);
    };

    // �t�@�C�������݂��Ă��邩�ǂ����m�F
    // �߂�l �t�@�C��������:true, �t�@�C�����Ȃ�:false
    static bool IsFoundFile(const char* file_name);

    // �������float�^�ɕϊ�
    static float ToFloat(const std::string str);

    // ������R�s�[���֎~����
    INILoader(void){}
    ~INILoader(void){}
    INILoader(const INILoader& rhs);
    INILoader& operator=(const INILoader& rhs);
public:
    // INI�t�@�C������l���擾����
    static TempObject GetValFromIniFile(LPCTSTR section_name, LPCTSTR key_name, LPCTSTR ini_file_path);
};

