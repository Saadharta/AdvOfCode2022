/*
    **************************
    Autor: Saadharta
    **************************
    Goal: Training session
    **************************
    Topic: Advent of Code 2022: Day1
    **************************
*/
#include <iostream>
#include <vector>
#include <algorithm>

class Elf{
    public:
        Elf(std::vector<int> i_cal_list) {
            for(std::vector<int>::iterator it = i_cal_list.begin(); it != i_cal_list.end(); ++it){
                calorie_count += (*it);
            }
        }

    int getCalories(void){
        return calorie_count;
    }

    /* for comparison between Elves */
    bool operator > (const Elf& other_elf){
        return (calorie_count > other_elf.calorie_count);
    }

    private:
    /* total of calories carried by an Elf*/
        int calorie_count = 0;
};