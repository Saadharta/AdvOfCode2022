#include "../inc/day1.hpp"
#include "pch.h"



// some extra fun stuff to fetch the index of the max calories carrier:
// in class Elf
    // /* for the final iterator looking for the index of the max calories carrying Elf */
    // bool operator == (const Elf& other_elf){
    //     return (calorie_count == other_elf.calorie_count);
    // }
// in main
    // std::vector<Elf>v {e1, e2, e23, e3, e4, e5};
    // /* selection of the highest calories carrier */
    // std::vector<Elf>::iterator itr = std::find(v.begin(), v.end(),max(v));
    // /* return the vector index of the max calories carrier */
    // std::cout << std::distance(v.begin(),itr);