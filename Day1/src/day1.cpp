/*
    **************************
    Autor: Saadharta
    **************************
    Goal: Training session
    **************************
    Topic: Advent of Code 2022: Day1
    **************************
*/
#include <fstream>
#include <iostream>
#include "../inc/day1.hpp"
#ifndef TOP_ELF_AMT
    /* How many Elves should be selected for the calories count? */
    #define TOP_ELF_AMT (1)
#endif

#ifndef CFG_PATH
    /* path of the input file */
    #define CFG_PATH ""
#endif

/* How to compare Elves? By checking which one carry the most calories! */
inline bool compareCalories(Elf e1, Elf e2){
    return(e1 > e2);
}

int main()
{
    /* Elf vector generation */
    std::ifstream i_file;
    std::string path = (CFG_PATH);
    std::string filename = "./input.txt";
    i_file.open(path + filename);
    std::vector<int> calories;
    std::vector<Elf> v;
    if(! i_file.is_open()){
        std::cout << "Warning: unable to find file " << path << "/" << filename <<std::endl;
        return -255;
    }
    for( std::string line; getline( i_file, line ); )
    {
        if(line.empty()){
            /* each empty line creates a new elf with the calories read*/
            v.push_back(Elf(calories));
            /* Empties the calories vector, ready for the next Elf*/
            calories.clear();
        }else{
            /* adds the calorie read at the calory list of the current Elf*/
            calories.push_back(stoi(line));
        }
    }

    /* selection of the highest calories carrier */
    sort(v.begin(), v.end(),compareCalories);
    int total_calories_count = 0;
    for(int i = 0; i < TOP_ELF_AMT; ++i){
        std::cout << "Adding " << v[i].getCalories() << " to the total" << std::endl;
        total_calories_count += v[i].getCalories();
    }
    /* return total of calories carried */
    std::cout << "Amount of calories Carried : " << total_calories_count <<std::endl;
    return 0;
}