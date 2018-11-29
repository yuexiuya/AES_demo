#include "AES_Utility.h"
#include <stdio.h>

AES_Utility::AES_Utility()
{

}

AES_Utility::~AES_Utility()
{

}

bool AES_Utility::set_encrypt_key(const uint8_t *userKey, const int bits, AES_KEY *key)
{
    printf("set_encrypt_key \n");
    if(userKey == nullptr) {
        printf("[error] userKey is null \n");
        return false;
    }
    int ret = AES_set_encrypt_key(userKey, bits, key);
    if(ret < 0)
        return false;
    return true;
}

bool AES_Utility::set_decrypt_key(const uint8_t *userKey, const int bits, AES_KEY *key)
{
    printf("set_decrypt_key \n");
    if(userKey == nullptr) {
        printf("[error] userKey is null \n");
        return false;
    }
    int ret = AES_set_decrypt_key(userKey, bits, key);
    if(ret < 0)
        return false;
    return true;
}

bool AES_Utility::encrypt_key(const uint8_t *str, const int str_len, uint8_t* en_str, const int en_str_len, const AES_KEY *key)
{
    printf("encrypt_key \n");
    if(key == nullptr || str == nullptr || en_str == nullptr) {
        printf("[error] key|str|en_str is null \n");
        return false;
    }
    if( str_len != en_str_len) {
        printf("[error] en_str_len != str_len , now en_str_len = %d \n", en_str_len);
        return false;
    }

    int _offset = 0;
    while(_offset < str_len) {  /// 一次加密16 bits
        AES_encrypt(str + _offset, en_str + _offset, key);
        _offset += AES_BLOCK_SIZE;
    }
    return true;
}

bool AES_Utility::decrypt_key(const uint8_t *en_str, const int en_str_len, uint8_t* de_str, const int de_str_len, const AES_KEY *key)
{
    printf("decrypt_key \n");
    if(key == nullptr || de_str == nullptr || en_str == nullptr) {
        printf("[error] key|de_str|en_str is null \n");
        return false;
    }
    if( de_str_len != en_str_len) {
        printf("[error] de_str_len != en_str_len , now de_str_len = %d \n", de_str_len);
        return false;
    }

    int _offset = 0;
    while(_offset < en_str_len) {  /// 一次解密16 bits
        AES_decrypt(en_str + _offset, de_str + _offset, key);
        _offset += AES_BLOCK_SIZE;
    }
    return true;
}


