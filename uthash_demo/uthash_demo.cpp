#include "include/uthash.h"
#include <iostream>

typedef struct key_value_test{
    int key;
    char value[10] = {0};
    UT_hash_handle hh;
}key_value;


int main(){
    key_value *g_header = nullptr;
    
    for (int i = 0; i < 10; i++){
        key_value *pkv = new key_value();
        pkv->key = i;
        snprintf(pkv->value, 10, "%s%d", "key=", i);
        HASH_ADD_INT(g_header, key, pkv);
    }

    key_value *pkv = nullptr;
    int key = 5;
    HASH_FIND_INT(g_header, &key, pkv);
    if (pkv != nullptr){
        std::cout << pkv->value << std::endl;
    }

    return 0;
}
