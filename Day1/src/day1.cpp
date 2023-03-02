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
#include "../inc/day1.hpp"
#ifndef TOP_ELF_AMT
    /* How many Elves should be selected for the calories count? */
    #define TOP_ELF_AMT (1)
#endif
/* How to compare Elves? By checking which one carry more calories! */
inline bool compareCalories(Elf e1, Elf e2){
    return(e1 > e2);
}

int main()
{
    /* Elf vector generation */
    std::ifstream infile("./cfg/input.txt");
    std::vector<int> calories;
    std::vector<Elf> v;
    for( std::string line; getline( infile, line ); )
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
    /* return the vector index of the max calories carrier */
    std::cout << "Amount of calories Carried : " << total_calories_count <<std::endl;
    return 0;
}

// some extra fun stuff to fetch the index of the max calories carrier:
// in class Elf

// in main
    // std::vector<Elf>v {e1, e2, e23, e3, e4, e5};
    // /* selection of the highest calories carrier */
    // std::vector<Elf>::iterator itr = std::find(v.begin(), v.end(),max(v));
    // /* return the vector index of the max calories carrier */
    // std::cout << std::distance(v.begin(),itr);