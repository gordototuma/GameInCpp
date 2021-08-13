#include <iostream>
#include <stdlib.h>

using namespace std;

void DrawMap(int HeroPosx, int HeroPosy , string GameMap[5][5]){

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(HeroPosx == j && HeroPosy ==i) 
                if (HeroPosx == 0)cout<<"H";
                else cout<<"\tH";
            else cout<<GameMap[i][j];                                        
        }
        cout<<endl;
    }  
}

int main(){

    int HeroPos = 1;
    int HeroPosy = 1;
    
    bool isGameOver = false;    
    
    string GameMap[5][5] = {
                        {"1","\t1","\t1","\t1","\t1"},
                        {"1","\t1","\t1","\t1","\t1"},
                        {"1","\t1","\t1","\t1","\t1"},
                        {"1","\t1","\t1","\t1","\t1"},
                        {"1","\t1","\t1","\t1","\t1"},
                         };    
    char input = ' ';
    system("cls");
    DrawMap(HeroPos, HeroPosy, GameMap);                    
    
    while (isGameOver == false)
    {
        cin>>input;
        if (input == 'd') HeroPos++ ;
        else if (input == 'a') HeroPos--;
        else if (input == 'w') HeroPosy--;
        else if (input == 's') HeroPosy++;
        else if (input == 'p') isGameOver = true;
        system("cls");
        system("clear");
        DrawMap(HeroPos, HeroPosy, GameMap);
    }   

    return 0;
}