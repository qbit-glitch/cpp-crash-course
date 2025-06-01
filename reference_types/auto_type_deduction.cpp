/*
NOTE: Do not run this code as it contains only code 
fragments and not a proper executable main function
*/



#include <cstdio>

/* Initialization with auto */
int initializationWithAuto(){
    auto the_answer { 42 };      // int
    auto foot { 12L };           // long
    auto rootbeer { 5.0F };      // float
    auto cheeseburger { 10.0 };  // double
    auto politifact_claims { false };  // bool
    auto cheese { "string" };    // char[7]
}


/* auto and Reference Types */
int autoAndReference(){
    auto year { 2019 };             // int
    auto& year_ref = year;          // int&
    const auto& year_cref = year;   // const int&
    auto* year_ptr = &year;         // int*
    const auto* year_cptr = &year;  // const int*
}


/* auto and Code Refactoring */
struct Dwarf{
    // -- snip --
};

Dwarf dwarves[13];

struct Contract {
    const add(const Dwarf&);
};

void from_company(Contract &contract){
    for (const auto &dwarf: dwarves){
        contract.add(dwarf);
    }
}