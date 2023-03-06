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
#include <map>

class Compartment {
    public:
        Compartment(std::vector<char> i_v){
            for(const auto& i: i_v){
                if(items.find(i)==items.end()) {
                    items.insert(std::make_pair(i, 1));
                }
                else {
                    items[i]++;
                }
            }
        }

        friend std::ostream& operator<<(std::ostream& os, Compartment c)
        {
            for (const auto& i: c.items){
                os << i.first << ":" << i.second;
                //for better visuals while testing
                if(i.first != std::prev(c.items.end())->first){
                    os << ' ';
                }
            }
            return os;
        }
        inline std::map<char,int>& GetItems(void){
            return items;
        }
    private:
        std::map<char,int> items;

};

class Rucksack {
    public:
        Rucksack(std::vector<char> compart_1, std::vector<char> compart_2): c1(compart_1), c2(compart_2) {        }

        friend std::ostream& operator<<(std::ostream& os, Rucksack r)
        {
            os << "[" << r.c1 <<"] [" << r.c2 << "]";
            return os;
        }

        char DuplicatedItem(void)
        {
            char duplicate;
            const std::map<char,int>& compartment_1_items = c1.GetItems();
            const std::map<char,int>& compartment_2_items = c2.GetItems();
            for(const auto &i: compartment_1_items){
                for (const auto &j: compartment_2_items){
                    if(i.first == j.first)
                        duplicate = i.first;
                }
            }
            return duplicate;
        }

        const std::vector<char>GetAllItems(void){
            std::vector<char> all_items;
            for(const auto &i: c1.GetItems()){
                all_items.push_back(i.first);
            }
            for(const auto &j: c2.GetItems()){
                all_items.push_back(j.first);
            }
            std::sort(all_items.begin(), all_items.end());
            return all_items;
        }

    private:
        Compartment c1;
        Compartment c2;
};

class ElfGroup{
    public:
        ElfGroup(std::vector<Rucksack> r):_group_rucksacks(r) {}
        
        std::vector<char> DuplicatedItems(void){
            std::vector<char> duplicated_items_in_group;
            for(const auto& i: _group_rucksacks){
                duplicated_items_in_group.push_back(const_cast<Rucksack&>(i).DuplicatedItem());
            }
            return duplicated_items_in_group;
        }

        char FindCommonItem(void){
            const std::vector<char>rucksack_1_items = _group_rucksacks[0].GetAllItems();
            const std::vector<char>rucksack_2_items = _group_rucksacks[1].GetAllItems();
            const std::vector<char>rucksack_3_items = _group_rucksacks[2].GetAllItems();
            std::vector<char> first_intersection;
            std::set_intersection(rucksack_1_items.begin(), rucksack_1_items.end(), rucksack_2_items.begin(), rucksack_2_items.end(),back_inserter(first_intersection));
            std::vector<char> second_intersection;
            std::set_intersection(rucksack_3_items.begin(), rucksack_3_items.end(), first_intersection.begin(), first_intersection.end(), back_inserter(second_intersection));
            return second_intersection[0];
        }

        friend std::ostream& operator<<(std::ostream& os, ElfGroup g)
        {
            for(const auto& i: g._group_rucksacks){
                os << (const_cast<Rucksack&>(i));
            }
            return os;
        }
    private:
        std::vector<Rucksack> _group_rucksacks;
};