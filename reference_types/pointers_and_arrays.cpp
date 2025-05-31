#include <cstdio>

struct College{
    char name[256];
};

void print_name(College* college_ptr){
    printf("%s College\n", college_ptr -> name);
}

void print_name(College* colleges, size_t n_colleges){
    for(size_t i=0; i< n_colleges; i++){
        printf("%s College\n", colleges[i].name);
    }
}

int main(){
    College best_colleges[] = {"Magdalem", "Nuffield", "Kellog"};
    // print_name(best_colleges);
    printf("%d | %d\n", sizeof(best_colleges), sizeof(College));
    print_name(best_colleges, sizeof(best_colleges)/sizeof(College));
}