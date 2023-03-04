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
#include "../inc/day2.hpp"

#ifndef CFG_PATH
    /* path of the input file */
    #define CFG_PATH ""
#endif

void convertCharToPoints(std::string line, int& a, int& b){
    switch(line.at(0)){
        case 'A': a = 1;break;
        case 'B': a = 2;break;
        case 'C': a = 3;break;
        default: break;
    }
    switch(line.at(2)){
        case 'X': b = 1;break;
        case 'Y': b = 2;break;
        case 'Z': b = 3;break;
        default: break;
    }
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

    if(! line.empty()){
        int a;
        int b;
        convertCharToPoints(line, a, b);
        v_Rounds.push_back(Rounds(a, b));
    }else{
        /* process an empty line */
    }
}

int main()
{
    /* Elf vector generation */
    std::ifstream i_file;
    std::string path = (CFG_PATH);
    std::string filename = "./input.txt";
    i_file.open(path + filename);
    std::vector<Rounds> v;
    if(! i_file.is_open()){
        std::cout << "Warning: unable to find file " << path << "/" << filename <<std::endl;
        return -255;
    }
    for( std::string line; getline( i_file, line ); )
    {
        process_line(line, v);
    }
    int maxP1Points = 0;
    int maxP2Points = 0;
    for (std::vector<Rounds>::iterator itr = v.begin(); itr != v.end(); ++itr){
        maxP1Points +=(*itr).RoundP1Result();
        maxP2Points +=(*itr).RoundP2Result();
    }
    std::cout << "Amount of Points for part1: " << maxP1Points <<std::endl;
    std::cout << "Amount of Points for part2: " << maxP2Points <<std::endl;
    return 0;
}