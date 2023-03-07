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
#include <map>
#include "../inc/day2.hpp"

#ifndef CFG_PATH
    /* path of the input file */
    #define CFG_PATH ""
#endif

void convertCharToPoints(std::string line, int& a, int& b){
    std::map<char,int> map_opponent({{'A',1},{'B',2},{'C',3},{'X',1},{'Y',2},{'Z',3}});
    a = map_opponent.at(line.at(0));
    b = map_opponent.at(line.at(2));
}
/*
 * A X Rock 1pt
 * B Y Paper 2pt
 * C Z Scissor 3pt  
 * lost 0 pt
 * draw 3 pt
 * win 6 pt
 */
void process_line(std::string line, std::vector<Rounds>& v_Rounds)
{
    if(line.empty()){
        return;
    }

    int a{0}, b{0};
    convertCharToPoints(line, a, b);
    v_Rounds.push_back(std::move(Rounds(a, b)));
}

int main()
{
    /* Elf vector generation */
    std::ifstream i_file;
    const std::string path(CFG_PATH);
    const std::string filename("./input.txt");
    i_file.open(path + filename);
    if(! i_file.is_open()){
        std::cout << "Warning: unable to find file " << path << "/" << filename <<std::endl;
        return -255;
    }

    std::vector<Rounds> v;
    std::string line;
    while(getline( i_file, line )){
        process_line(line, v);
    }

    int maxP1Points{0};
    int maxP2Points{0};
    for(auto& itr : v){
        maxP1Points +=itr.RoundP1Result();
        maxP2Points +=itr.RoundP2Result();
    }
    std::cout << "Amount of Points for part1: " << maxP1Points <<std::endl;
    std::cout << "Amount of Points for part2: " << maxP2Points <<std::endl;
    return 0;
}