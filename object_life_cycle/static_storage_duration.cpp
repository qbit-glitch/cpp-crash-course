#include <cstdio>

static int rat_things_power = 200;  // -> Internal Linkage => A variable is inaccessible to other translation units.

// extern int rat_things_power = 200   // -> External Linkage => makes a variable accessible to other translation unit.


void power_up_rat_thing(int nuclear_isotopes){
    rat_things_power += nuclear_isotopes;
    const auto waste_heat = rat_things_power * 20;
    if(waste_heat > 10000)
        printf("Warning! Hot doggie\n");
}

int main(){
    printf("Rat-things power: %d\n", rat_things_power);
    power_up_rat_thing(100);
    printf("Rat-things power: %d\n", rat_things_power);
    power_up_rat_thing(500);
    printf("Rat-things power: %d\n", rat_things_power);
}

