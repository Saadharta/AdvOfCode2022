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

class Rounds{
    public:
        Rounds(int a, int b): opponent(a), player(b) { 
            std::cout << "opponent " << opponent << " player " << player << std::endl;
        }

    int RoundP1Result(void){
        int status = player;
        if((player %3)  == ((opponent -1) %3)){
            /*
            * loosing case PART 1: 
            * a = Rock(1)      b = Scissor(0) 
            * a = Paper(2)     b = Rock(1)
            * a = Scissor(3)   b = Paper(2)
            */
            status += 0;
        }
        else if(player == opponent){
            /* draw */
            status +=3;
        }
        else{
            /* win */
            status +=6;
        }
        return status;
    }

    int RoundP2Result(void){
        int status = 0;
        /* player is now a loose, a draw or a win */
        /* it's the reverse of the part 1 logic*/
        switch(player){
            case 1: /* loose */
                            /*
                * loosing case PART 2: 
                * a = Rock(1)      b = Scissor(0) 
                * a = Paper(2)     b = Rock(1)
                * a = Scissor(3)   b = Paper(2)
                * However we need to shift b from [0,1,2] to [1,2,3]
                */
                if(0 != (opponent -1) %3){
                    status = opponent -1;
                }else{
                    status = 3;
                }
                break;
            case 2: /* draw */
                status = opponent + 3;
                break;
            case 3: /* win */
                if(0 != (opponent %3)){
                    status = (opponent+1);
                }else{
                    status = 1;
                }
                status += 6; /* points for victory */
                break;
            default: break;
        }
        return status;
    }

    private:
    /* round strategy for opponent and player*/
        int opponent = 0;
        int player = 0;
};