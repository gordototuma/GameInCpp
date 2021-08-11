#include <iostream>

using namespace std;

void DrawMap(int HeroPos, char GameMap[5][5]){

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (HeroPos == 'd' || HeroPos == 'a'){
                if(HeroPos != i) cout<<GameMap[i][j];
                else cout<<'H';            
            }else if (HeroPos == 'w' || HeroPos == 's'){
                if(HeroPos != i) cout<<GameMap[i][j];
                else cout<<'H';                                        
            }
        }
    }  
}

int main(){

    int HeroPos = 1;
    
    bool isGameOver = false;
    char GameMap[5][5] = {
                        {'1','1','1','1','1'},
                        {'1','1','1','1','1'},
                        {'1','1','1','1','1'},
                        {'1','1','1','1','1'},
                        {'1','1','1','1','1'},
                         };
    char input = ' ';

    DrawMap(HeroPos, GameMap);
    while (isGameOver == false)
    {
        cin>>input;
        if (input == 'd') HeroPos++ ;
        else if (input == 'a') HeroPos--;
        else if (input == 'w') HeroPos++;
        else if (input == 's') HeroPos--;
        else if (input == 'p') isGameOver = true;
        DrawMap(HeroPos, GameMap);
    }
    
    

    

    return 0;
}