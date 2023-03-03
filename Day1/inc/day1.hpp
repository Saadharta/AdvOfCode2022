#ifndef DAY1_INC_DAY1_HPP
#define DAY1_INC_DAY1_HPP
/*
    **************************
    Autor: Saadharta
    **************************
    Goal: Training session
    **************************
    Topic: Advent of Code 2022: Day1
    **************************
*/

#include "pch.h"

class Elf {
public:
    Elf(std::initializer_list<int> i_cal_list) {
        for (std::initializer_list<int>::iterator it = i_cal_list.begin(); it != i_cal_list.end(); ++it) {
            calorie_count += (*it);
        }
        std::cout << calorie_count << " calories carried" << std::endl;
    }
    int getCalories(void) {
        return calorie_count;
    }

    /* for comparison between Elves */
    bool operator < (const Elf& other_elf) {
        return (calorie_count < other_elf.calorie_count);
    }

private:
    /* total of calories carried by an Elf*/
    int calorie_count = 0;
};

/* iterates through a vector of Elves and return the one having the maximum amount of calories */
Elf maxCalories(std::vector<Elf> i_velf) {
    Elf max_calories_elf = i_velf[0];
    for (std::vector<Elf>::iterator it = i_velf.begin(); it != i_velf.end(); ++it)
    {
        if (max_calories_elf < *it) {
            max_calories_elf = *it;
        }
    }
    return max_calories_elf;
}


#endif /* DAY1_INC_DAY1_HPP */