#include <cstdio>

struct ClockOfTheLongNow{
    int year;

    ClockOfTheLongNow(){
        year = 2019;
    }

    bool set_year(int new_year){
        if (new_year < 2019)
            return false;
        year = new_year;
        return true;
    }

    int get_year(){
        return year;
    }

};

void add_year(ClockOfTheLongNow &clock ){
    clock.set_year(clock.get_year() + 1);   // No deref operator needed
}

int main(){
    ClockOfTheLongNow clock;
    printf("The year is %d. \n", clock.get_year());

    add_year(clock);   // Clock is implicitly passed by reference
    printf("The year is %d\n", clock.get_year());
}