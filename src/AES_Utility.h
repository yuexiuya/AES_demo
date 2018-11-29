#ifndef AES_UTILITY_H
#define AES_UTILITY_H

#include <openssl/aes.h>
#include <stdint.h>

/**
 * @brief The AES_Utility class
 *      工具类，用于 AES 的加密和解密
 */
class AES_Utility {
public:
    AES_Utility();
    ~AES_Utility();
    AES_Utility(const AES_Utility& rhs)=delete;
    AES_Utility& operator=(const AES_Utility& rhs)=delete;

    bool set_encrypt_key(const uint8_t* userKey, const int bits, AES_KEY *key /** out*/);

    bool set_decrypt_key(const uint8_t* userKey, const int bits, AES_KEY *key /** out*/);

    bool encrypt_key(const uint8_t* str, const int str_len,
                     uint8_t* en_str/** out*/, const int en_str_len,
                     const AES_KEY *key);

    bool decrypt_key(const uint8_t* en_str, const int en_str_len,
                     uint8_t* de_str/** out*/, const int de_str_len,
                     const AES_KEY *key);
};

#endif
