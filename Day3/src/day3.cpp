/*
    **************************
    Autor: Saadharta
    **************************
    Goal: Training session
    **************************
    Topic: Advent of Code 2022: Day3
    **************************
*/
#include <fstream>
#include <iostream>
#include <cmath>
#include "../inc/day3.hpp"

#ifndef CFG_PATH
    /* path of the input file */
    #define CFG_PATH ""
#endif

Rucksack LineToRucksack(std::string line)
{
    std::string first_half = line.substr(0, line.length()/2);
    std::string second_half = line.substr(line.length()/2);
    std::vector<char> v1(first_half.begin(), first_half.end());
    std::vector<char> v2(second_half.begin(), second_half.end());
    Rucksack r(v1,v2);
    return r;
}

void process_line(std::string line, std::vector<Rucksack>& v_Rucksack)
{
    if(! line.empty()){
        v_Rucksack.push_back(std::move(LineToRucksack(line)));
    }else{
        /* process an empty line */
    }
}

int ItemToValue(char item)
{
    if(('a' <= item ) && (item <= 'z')){
           return(((int)item - (int)'a') + 1);
        }
        /* majuscules */
        else{
           return((int)item - 'A' + 27);
        }
}

std::vector<int> ItemVectorToValue(std::vector<char> i_item_vector)
{
    std::vector<int> item_value;
    for(const auto& item : i_item_vector){
        item_value.push_back(ItemToValue(item));
    }
    return item_value;
}

int main()
{
    /* Main class vector generation */
    std::ifstream i_file;
    std::string path(CFG_PATH);
    std::string filename("./input.txt");
    i_file.open(path + filename);
    if(! i_file.is_open()){
        std::cout << "Warning: unable to find file " << path << "/" << filename <<std::endl;
        return -255;
    }
    
    std::vector<ElfGroup> g;
    std::vector<Rucksack> v;
    int line_id = 0;
    for( std::string line; getline( i_file, line ); )
    {
        process_line(line, v);
        if(line_id %3 == 2) {
            /* greate an Elf Group */
            g.push_back(std::move(ElfGroup(v)));
            v.clear();
        }
        line_id ++;
    }
    int max_p1_points = 0;
    int max_p2_points = 0;
    for (std::vector<ElfGroup>::iterator itr = g.begin(); itr != g.end(); ++itr){
        std::vector<char> duplicated_item = (*itr).DuplicatedItems();
        std::vector<int> current_duplicated_item_value = ItemVectorToValue(duplicated_item);
        for (auto& n : current_duplicated_item_value){
            max_p1_points += n;
        }
        for(const auto & i : duplicated_item){
            std::cout << i << " ";
        }
        std::cout << ":" << max_p1_points;
        /* find the common point between all three */
        char common_item = (*itr).FindCommonItem();
       max_p2_points += ItemToValue(common_item);

        std::cout << "|" << common_item << ":" << ItemToValue(common_item) << "=" << max_p2_points << std::endl;
        // maxP2Points +=(*itr).RoundP2Result();
    }
    std::cout << "Amount of Points for part1: " << max_p1_points <<std::endl;
    std::cout << "Amount of Points for part2: " << max_p2_points <<std::endl;
    return 0;
}
