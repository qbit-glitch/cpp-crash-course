#include <cstdio>

struct Element
{
    Element* next{};
    char prefix[2];
    short operating_number;

    void insert_after(Element* new_element){
        new_element -> next = this->next;
        this->next = new_element;
    }
};

struct ClockOfTheLongNow {
    bool set_year(int year){
        if (year < 2019)
            return false;
        this->year = year;
        return true;
    }

    private:
    int year;
};
