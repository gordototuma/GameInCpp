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
            if (HeroPosX == j && HeroPosY == i) cout<<'h';
            else cout<<GameMap[i][j];
        }
        cout<<endl;
    }   
}


bool FileValidation(){

    bool ExistGameFile = GameFile.is_open();
    //GameFile.close();
    return ExistGameFile;    
    
}


bool CreateGameFile(){
    ofstream GameFile("GameFile.txt");
    if (GameFile.is_open()){
        GameFile<<"1"<<endl;
        GameFile<<"1"<<endl;
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

        //ifstream GameFile("GameFile.txt");
        string PosX = "";

        //if (GameFile.is_open()){
            
        getline(GameFile, PosX);  
        //}        
        stringstream PosXStr(PosX);
        int PosXInt = 0;
        PosXStr>>PosXInt;
        GameFile.close();
        
        return PosXInt;
    }
    else{
        if (CreateGameFile()){
            return 1;
        }   
    } 
}


int HeroPosYFunction(){

    if (FileValidation()){

        //ifstream GameFile("GameFile.txt");
        string PosY = "";

        //if (GameFile.is_open()){
        int accountancy = 0;
        int PosYInt = 0;
        while (getline(GameFile, PosY)){
            //cout<<"asdasd"<<PosY<<endl;
            if (accountancy == 1){
                stringstream PosYStr(PosY);
                cout<<"asdasd"<<PosY<<endl;
                
                PosYStr>>PosYInt;
            }
            accountancy++;
        }
        GameFile.close();
        return PosYInt;
        //}      
    }
    else{
        if (CreateGameFile()){
            return 1;
        }
    } 
}


int main(){

    cout<<HeroPosXFunction()<<HeroPosYFunction()<<"\n";
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
        if (input == 'd') HeroPosX++;
        else if(input == 'a') HeroPosX--;
        else if(input == 'w') HeroPosY--;
        else if(input == 's') HeroPosY++;
        else if(input == 'p') isGameOver = true;

        DrawMap(HeroPosX, HeroPosY, GameMap);
        
    }
    return 0;
}