/*
    **************************
    Autor: Saadharta
    **************************
    Goal: Training session
    **************************
    Topic: Advent of Code 2022: Day4
    **************************
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>

class Elf {
    public:
        Elf(std::vector<int>& i_v):m_sections(std::move(i_v)) { }

        friend std::ostream& operator<<(std::ostream& os, Elf e)
        {
            os << "[";
            for (const auto& i: e.m_sections){
                //for better visuals while testing
                os << std::setw(3) << i;
            }
            os<<"]";
            return os;
        }
        inline const std::vector<int>& GetAllSections(void){
            return m_sections;
        }
    private:
        std::vector<int> m_sections;

};

class ElfPair {
    public:
        ElfPair(std::vector<int>& elf1, std::vector<int>& elf2): m_elf1(elf1), m_elf2(elf2){ }

        friend std::ostream& operator<<(std::ostream& os, ElfPair ep)
        {
            os << ep.m_elf1 << ep.m_elf2;
            return os;
        }

        bool isOverlappingSections(void){
            // attempt at speeding up; no intersection means no overlap
            if( false == isPartialOverlappingSections())
            {
                return false;
            }
            /* check if one section is overlapped by the other */
            const bool is_overlapped_section_1 = m_overlapping_sections.size() == m_elf1.GetAllSections().size();
            const bool is_overlapped_section_2 = m_overlapping_sections.size() == m_elf2.GetAllSections().size();
            /* return true if one elf has his sections overlapped by the other's sections*/
            return is_overlapped_section_1 || is_overlapped_section_2;
        }

        bool isPartialOverlappingSections(void){
            /* partial overlap means the intersection is not null */
            return (0 != m_overlapping_sections.size());
        }

    private:
        const std::vector<int>GetOverlap(void){
            const std::vector<int>elf_1_sections = m_elf1.GetAllSections();
            const std::vector<int>elf_2_sections = m_elf2.GetAllSections();
            std::vector<int> common_sections;
            std::set_intersection(elf_1_sections.begin(), elf_1_sections.end(), elf_2_sections.begin(), elf_2_sections.end(),back_inserter(common_sections));
            return common_sections;
        }
        /* when orderding this section, placing m_overlapping_sections first causes a std::bad_alloc! */
        Elf m_elf1;
        Elf m_elf2;
        const std::vector<int> m_overlapping_sections = GetOverlap();
};