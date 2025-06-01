/*
NOTE: Do not run this code as it contains only code 
fragments and not a proper executable main function
*/


#include <cstdio>

/* const Arguments demo */
void petruchio(const char* shrew){
    printf("Fear not, sweet went, they shall not touch thee, %s.", shrew);
    shrew[0] = 'K';
}

/* const Methods */
struct ClockOfTheLongNow{
    int get_year() const {
        return year;
    }
    private:
    int year;
};

bool is_leap_year(const ClockOfTheLongNow &clock){
    if(clock.get_year() % 4 > 0) return false;
    if(clock.get_year() % 100 > 0) return true;
    if(clock.get_year() % 400 > 0) return false;
    return true;
}

/* const Member Variables */
struct Avout{
    const char* name = "Erasmus";
    ClockOfTheLongNow apert;
};

void does_not_compile(const Avout& avout){
    avout.apert.add_year();  // Compiler error: avout is const

}
