#ifndef __MORSECODE_H
#define __MORSECODE_H

#include "Arduino.h"

class MorseCode
{
    public:
        MorseCode(int pin, int delaytime);
        void dot();
        void dash();
        void divid();
        void space();

        char MorseCode[26][4] = {
            {'.','-',' ',' '},      //A
            {'-','.','.','.'},      //B
            {'-','.','-','.'},      //C
            {'-','.','.',' '},      //D
            {'.',' ',' ',' '},      //E
            {'.','.','-','.'},      //F
            {'-','-','.',' '},      //G
            {'.','.','.','.'},      //H
            {'.','.',' ',' '},      //I
            {'.','-','-','-'},      //J
            {'-','.','-',' '},      //K
            {'.','-','.','.'},      //L
            {'-','-',' ',' '},      //M
            {'-','.',' ',' '},      //N
            {'-','-','-',' '},      //O
            {'.','-','-','.'},      //P
            {'-','-','.','-'},      //Q
            {'.','-','.',' '},      //R
            {'.','.','.',' '},      //S
            {'-',' ',' ',' '},      //T
            {'.','.','-',' '},      //U
            {'.','.','.','-'},      //V
            {'.','-','-',' '},      //W
            {'-','.','.','-'},      //X
            {'-','.','-','-'},      //Y
            {'-','-','.','.'}       //Z
        };

    private:
        int _pin;
        int _delaytime;
};


#endif