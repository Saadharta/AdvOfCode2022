/*
    **************************
    Autor: Saadharta
    **************************
    Goal: Training session
    **************************
    Topic: Advent of Code 2022: Day4
    **************************
*/
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>


#include "../inc/day4.hpp"

#ifndef CFG_PATH
    /* path of the input file */
    #define CFG_PATH ""
#endif

void SetElfSectionsBoundaries(std::string& sections, int& min, int& max){
    const std::string section_delimiter = "-";
    size_t section_delimiter_pos = sections.find(section_delimiter);    
    if(section_delimiter_pos != std::string::npos){
        /* min boundary section is captured */
        min = std::stoi(sections.substr(0, section_delimiter_pos));
        /* we erase the alreay captured part of the section boundaries plus delimiter*/
        sections.erase(0, section_delimiter_pos + section_delimiter.length());
        /* leftover is max boundary section */
        max = std::stoi(sections);
        sections.clear();
    }
}

std::vector<int> SetElfSection(std::string elf)
{
    int elf_min;
    int elf_max;
    /* set Elf1 Boundaries */
    SetElfSectionsBoundaries(elf, elf_min, elf_max);
    /* initialize elf section */
    std::vector<int> elf_section(elf_max - elf_min +1);
    std::iota(elf_section.begin(), elf_section.end(),elf_min);
    return elf_section;
}

ElfPair LineToElfPair(std::string line)
{
    /* line structure: min1-max1,min2-max2 */
    const std::string elf_delimiter = ",";
    size_t elf_delimiter_pos = line.find(elf_delimiter);
    std::vector<int> e1;
    std::vector<int> e2;

    if(elf_delimiter_pos != std::string::npos) {
        std::string elf = line.substr(0, elf_delimiter_pos);
        e1 = SetElfSection(elf);
        /* remove processed part of line + delimiter*/
        line.erase(0, elf_delimiter_pos + elf_delimiter.length());
        /* set Elf2 Boundaries */
        e2 = SetElfSection(line);
    }
    ElfPair ep(e1,e2);
    return ep;
}

void process_line(std::string line, std::vector<ElfPair>& v_elf_pair)
{
    if(line.empty()){
        return;
    }
    v_elf_pair.emplace_back(LineToElfPair(line));
}

TEST(myfunctions, add)
{
    GTEST_ASSERT_EQ(add(10, 22), 32);
}

// int main()
// {
//     /* Main class vector generation */
//     std::ifstream i_file;
//     const std::string path(CFG_PATH);
//     const std::string filename("./input.txt");
//     i_file.open(path + filename);
//     if(! i_file.is_open()){
//         std::cout << "Warning: unable to find file " << path << "/" << filename <<std::endl;
//         return -255;
//     }
    
//     std::vector<ElfPair> ep;
//     std::string line; 
//     while( getline(i_file, line) ){
//         process_line(line, ep);
//     }

//     int max_p1_points{0};
//     int max_p2_points{0};
//     bool is_overlapping_pair;
//     bool is_partial_overlapping_pair;
//     for(auto& itr: ep){
//         is_partial_overlapping_pair = itr.isPartialOverlappingSections();

//         std::cout << is_overlapping_pair << " " << is_partial_overlapping_pair << std::endl;
//         /* no partial overlap mean no possibility of full overlap*/
//         if(true == is_partial_overlapping_pair){
//             max_p2_points +=1;
//             is_overlapping_pair = itr.isOverlappingSections();
//             if(true == is_overlapping_pair){
//                 max_p1_points +=1;
//             }
//         }

//     }
    
//     std::cout << "Amount of Points for part1: " << max_p1_points <<std::endl;
//     std::cout << "Amount of Points for part2: " << max_p2_points <<std::endl;
//     return 0;
// }