#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <openssl/aes.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include "AES_Utility.h"

#define ASE_KEY_LEN 128

int main(void) {

    ///
    AES_Utility aes_utility;
    uint8_t userKey[ASE_KEY_LEN] = {0}; ///密钥
    memset( (void*) userKey, '4', sizeof(userKey)); /// 密钥 4444 4444 4444 4444
    uint8_t src_data[AES_BLOCK_SIZE * 8] = {0};
    uint8_t en_data[AES_BLOCK_SIZE * 8] = {0};
    uint8_t de_data[AES_BLOCK_SIZE * 8] = {0};
    AES_KEY aseKey;
    memset( (void*)src_data, 'd', AES_BLOCK_SIZE);
    printf("src_data = %s\n", src_data);
    /// 加密
    aes_utility.set_encrypt_key(userKey, ASE_KEY_LEN, &aseKey);
    aes_utility.encrypt_key(src_data, sizeof(src_data),
                            en_data, sizeof(en_data),
                            &aseKey);
    printf("en_data = %s\n", en_data);
    /// 解密
    aes_utility.set_decrypt_key(userKey, ASE_KEY_LEN, &aseKey);
    aes_utility.decrypt_key(en_data, sizeof(en_data),
                            de_data, sizeof(de_data),
                            &aseKey);
    printf("de_data = %s\n", de_data);

    /// 测试
//    while(1);
//    AES_KEY aseKey;
//    uint8_t userKey[128] = {0}; ///密钥
//    memset( (void*) userKey, '4', sizeof(userKey));
//    uint8_t src_data[AES_BLOCK_SIZE * 8] = {0};
//    memset( (void*) src_data, 'd', sizeof(src_data)); /// src data = dddd dddd dddd dddd
//    uint8_t en_data[AES_BLOCK_SIZE * 8] = {0};
//    uint8_t de_data[AES_BLOCK_SIZE * 8] = {0};

//    printf("=====> %s\n", src_data);

//    AES_set_encrypt_key(userKey, sizeof(userKey), &aseKey);
//    for(int i=0; i<sizeof(src_data); i=i+AES_BLOCK_SIZE) {
//        AES_encrypt(src_data + i, en_data + i, &aseKey);
//    }
//    printf("=====> %s\n", en_data);

//    AES_set_decrypt_key(userKey, sizeof(userKey), &aseKey);
//    for(int i=0; i<sizeof(src_data); i=i+AES_BLOCK_SIZE) {
//        AES_decrypt(en_data + i, de_data + i, &aseKey);
//    }
//    printf("=====> %s\n", de_data);
    return 0;
}

//#include <memory.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <openssl/aes.h>
////#pragma comment(lib,"libeay32.lib")
//int main(int argc, char **argv)
//{
//    uint8_t buf[512] = {0};
//    unsigned char buf2[512];
//    unsigned char buf3[512];
//    unsigned char aes_keybuf[32];
//    memset((void *)buf,'d',sizeof(buf));
//    memset(buf,0,sizeof(buf2));
//    memset(buf,0,sizeof(buf3));
//    memset(aes_keybuf,0,sizeof(aes_keybuf));

//    printf("===> %d \n", sizeof(buf));
//    printf("buf === %s \n", buf);
////    for(int i = 0; i < 512; i++) {
////        printf("buf === %s \n", buf[i]);
////    }
//    AES_KEY aeskey;
//    AES_set_encrypt_key(aes_keybuf,256,&aeskey);
//    for(int i=0;i<sizeof(buf);i+=16)
//    AES_encrypt(buf+i,buf2+i,&aeskey);

//    printf("buf2 === %s \n", buf2);
//    AES_set_decrypt_key(aes_keybuf,256,&aeskey);
//    for(int i=0;i<sizeof(buf);i+=16)
//    AES_decrypt(buf2+i,buf3+i,&aeskey);

//    printf("buf3 === %s \n", buf3);
//    if(memcmp(buf,buf3,sizeof(buf))==0)
//        printf("test success\r\n");
//    else
//        printf("test fail\r\n");
//}
