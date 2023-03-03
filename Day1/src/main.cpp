#include "../inc/day1.hpp"
#include "pch.h"

int main()
{
    /* Elf vector generation */
    Elf e1{ 5000,2500,875 };
    Elf e2{ 10000, 965, 78000 };
    Elf e23{ 10000, 9650, 780000 };
    Elf e3{ 1000, 965, 78000 };
    Elf e4{ 10000, 9650, 7800 };
    Elf e5{ 10000, 9650, 700 };
    std::vector<Elf>v{ e1, e2, e23, e3, e4, e5 };
    /* selection of the highest calories carrier */
    Elf maxCaloriesCarrier = maxCalories(v);
    /* return the vector index of the max calories carrier */
    std::cout << "Max Calories Carried : " << maxCaloriesCarrier.getCalories();
    return 0;
}