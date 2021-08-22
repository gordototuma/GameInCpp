#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

ifstream GameFile("GameFile.txt");

void DrawMap(int HeroPosX, int HeroPosY,char GameMap[5][5] ){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (HeroPosX == j && HeroPosY == i) cout<<'k';
            else cout<<GameMap[i][j];
        }
        cout<<endl;
    }   
}


bool FileValidation(){
    bool ExistGameFile = GameFile.is_open();
    return ExistGameFile;        
}


bool CreateGameFile(int x=1, int y=1){
    ofstream GameFile("GameFile.txt");
    if (GameFile.is_open()){
        GameFile<<x<<endl;
        GameFile<<y<<endl;
        GameFile.close();
        return true;
    }else{
        cout<<"A ocurrido un error al crear archivo de posicionamiento"<<endl;
        GameFile.close();
        return false;
    }
}


int HeroPosXFunction(){
    if (FileValidation()){      
        string PosX = "";
        getline(GameFile, PosX);          
        stringstream PosXStr(PosX);
        int PosXInt = 0;
        PosXStr>>PosXInt;              
        GameFile.close();
        return PosXInt;
    }
    else{
        if (CreateGameFile()) return 1;
    } 
}


int HeroPosYFunction(){   
    ifstream GameFile("GameFile.txt"); 
    string PosY = "";        
    int PosYInt = 0;
    while (getline(GameFile, PosY)){            
        stringstream PosYStr(PosY);            
        PosYStr>>PosYInt;
    }
    GameFile.close();
    return PosYInt;   
}


int main(){
    system("clear");
    int HeroPosX = HeroPosXFunction();
    int HeroPosY = HeroPosYFunction();
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
        system("clear");
        if (input == 'd') HeroPosX++;
        else if(input == 'a') HeroPosX--;
        else if(input == 'w') HeroPosY--;
        else if(input == 's') HeroPosY++;
        else if(input == 'p'){
            CreateGameFile(HeroPosX,HeroPosY);
            isGameOver = true;
        } 

        DrawMap(HeroPosX, HeroPosY, GameMap);
        
    }
    system("clear");
    return 0;
}