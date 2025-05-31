#include <cstdio>

int main(){
    int gettysburg{};
    int *gettysburg_address = &gettysburg;
    printf("gettysburg: %d\n", gettysburg);
    printf("&gettysburg: %p\n", gettysburg_address);

    *gettysburg_address = 17327;
    printf("gettysburg: %d\n", gettysburg);
    printf("&gettysburg: %p\n", gettysburg_address);


}