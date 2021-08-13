#include<iostream>

using namespace std;


void DrawMap(int HeroPos, char GameMap[5] ){

    for (int i = 0; i < 5; i++)
    {
        if (HeroPos != i) cout<<GameMap[i];
        else cout<<'h';
    }   
    
}

int main(){

    int HeroPos = 1;
    bool isGameOver = false;
    char GameMap[5] = {'1','1','1','1','1'};
    char input = ' ';

    DrawMap(HeroPos, GameMap);

    while (isGameOver == false)
    {
        cin>>input;
        if (input == 'd') HeroPos++;
        else if(input == 'a') HeroPos--;
        else if(input == 'p') isGameOver = true;

        DrawMap(HeroPos, GameMap);
        
    }
    return 0;
}