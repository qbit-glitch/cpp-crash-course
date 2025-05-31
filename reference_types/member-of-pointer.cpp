#include <cstdio>

struct ClockOfTheLongNow{
    int year;

    ClockOfTheLongNow(){
        year = 2019;
    }

    bool set_year(int new_year){
        if (new_year < 2010)
            return false;
        year = new_year;
        return true;
    }

    int get_year(){
        return year;
    }
};

int main(){
    ClockOfTheLongNow clock;
    ClockOfTheLongNow* clock_ptr = &clock;

    clock_ptr -> set_year(2000);

    printf("Adrress of Clock: %p\n",clock_ptr);
    printf("Value of Clock's year: %d", clock_ptr -> get_year());
}