#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <openssl/sha.h>
#include <assert.h>

uint8_t hex_to_byte(unsigned char h1, unsigned char h2) {
    // Convert a single hex character to its integer value
    if (h1 >= '0' && h1 <= '9') {
        h1 = h1 - '0';
    } else if (h1 >= 'a' && h1 <= 'f') {
        h1 = h1 - 'a' + 10;
    } else if (h1 >= 'A' && h1 <= 'F') {
        h1 = h1 - 'A' + 10;
    }

    if (h2 >= '0' && h2 <= '9') {
        h2 = h2 - '0';
    } else if (h2 >= 'a' && h2 <= 'f') {
        h2  = h2 - 'a' + 10;
    } else if (h2 >= 'A' && h2 <= 'F') {
        h2 = h2 - 'A' + 10;
    }

    return (h1 << 4) | h2;
}

void hexstr_to_hash(unsigned char hexstr[], char hash[32]) {
	for (int i = 0; i < 32; i += 1) {
        hash[i] = hex_to_byte(hexstr[i * 2], hexstr[i * 2 + 1]);
    }
}

void test_hex_to_byte() {
    assert(hex_to_byte('c', '8') == 200);
    assert(hex_to_byte('0', '3') == 3);
    assert(hex_to_byte('0', 'a') == 10);
    assert(hex_to_byte('1', '0') == 16);
}

void test_hexstr_to_hash() {
    const char hexstr[64] = "a2c3b02cb22af83d6d1ead1d4e18d916599be7c2ef2f017169327df1f7c844fd";
    unsigned char hash[32];
    hexstr_to_hash(hexstr, hash);
    for(int i = 0; i < 32; i += 1) {
        //print something about hash
        printf("%02x", hash[i]);
    }
    assert(hash[0] == 0xa2);
    assert(hash[31] == 0xfd);
}

//m2
int8_t check_password(char password[], char given_hash[32]) {
    unsigned char computed_hash[32];
    SHA256((unsigned char*)password, strlen(password), computed_hash);
    return memcmp(computed_hash, given_hash, 32) == 0;
}

const int testing = 1;

int main(int argc, char** argv) {
        unsigned char hash[32];
        hexstr_to_hash(argv[1], hash);
    char hash_as_hexstr[] = "5e884898da28047151d0e56f8dc6292773603d0d6aabbdd62a11ef721d1542d8"; // SHA256 hash for "password"
    char given_hash[32];
    hexstr_to_hash(hash_as_hexstr, given_hash);
    assert(check_password("password", given_hash) == 0);
    assert(check_password("wrongpass", given_hash) == 0);

    return 0;
}

