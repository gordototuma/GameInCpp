#include<iostream>

using namespace std;


void DrawMap(int HeroPosX, int HeroPosY,char GameMap[5][5] ){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (HeroPosX == j && HeroPosY == i) cout<<'h';
            else cout<<GameMap[i][j];
        }
        cout<<endl;
    }   

}


int main(){

    int HeroPosX = 1;
    int HeroPosY = 1;
    bool isGameOver = false;
    char GameMap[5][5] = {
                            {'1','1','1','1','1'},
                            {'1','1','1','1','1'},
                            {'1','1','1','1','1'},
                            {'1','1','1','1','1'},
                            {'1','1','1','1','1'}
                            };
    char input = ' ';

    DrawMap(HeroPosX, HeroPosY, GameMap);

    while (isGameOver == false)
    {
        cin>>input;
        if (input == 'd') HeroPosX++;
        else if(input == 'a') HeroPosX--;
        else if(input == 'w') HeroPosY--;
        else if(input == 's') HeroPosY++;
        else if(input == 'p') isGameOver = true;

        DrawMap(HeroPosX, HeroPosY, GameMap);
        
    }
    return 0;
}