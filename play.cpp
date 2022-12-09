#include <iostream>
#include <ctime>
#include <cstring>  
#include <sstream>
#include <stdlib.h>
using namespace std;

bool Surrender = false;
bool Win = false;
int tries=0,score=0;
const int rows = 10;
const int elements = 10;
 
int maxships = 10;
char matrix[rows][elements];
 
//Clear the Matrix
void Clear(){ 
    for(int i=0; i < rows; i++){
        for(int j=0; j < elements; j++){
            matrix[i][j] = '.';
        }
    }
}

//Print the board 
void Show(){
    int counter_x=0;
    int counter_y=0;
    int square_count_x = 0;
    int square_count_y = 0;
        for(int i = 0; i < 11;i++){
            for(int j=0; j<11;j++){
                if((i == 0)&&(j==0))
                    cout<<"   ";
                else if(i == 0){
                    cout<<" "<< counter_x << " ";
                    counter_x++;
                }
                else if(j%11==0){
                    cout<<"\n " << counter_y << ' ';
                    counter_y++; 
                    }
                else if ((Surrender == true)||(Win == true))
                    cout<<" " << matrix[i-1][j-1] << " ";
                else if (matrix[i-1][j-1] == 'D')
                    cout<<" . ";
                else 
                    cout<<" " << matrix[i-1][j-1] << " ";
                    }
                }
    cout << "\n";
}
 
int NumberOfShips(){
    int c = 0;
    for(int i=0; i < rows; i++){
        for(int j=0; j < elements; j++){
            if(matrix[i][j] == 1)
                c++;
        }
    }
 
    return c;
}
 
void SetShips()
{
    srand(time(0));
    int s = 0;
    while(s < maxships)
    {
        int x = rand() % 10;
        int y = rand() % 10;
        if(matrix[x][y] != 'D')
        {
            s++;
            matrix[x][y] = 'D';
        }
    }
}
 
void Attack(int x,int y)
{
    system("clear");
    if(matrix[x][y] == 'D'){
        matrix[x][y] = 'O';
        cout << "Great Job Comander\n";
        tries ++;
        score ++;
    }
    else if (matrix[x][y] == '.'){
        matrix[x][y] = 'X';
        tries ++;
        cout << "We'll get'em next time\n";
    }
    else
        cout<<"Square already attacked \n";
}
 
int play(){
    // Initialize the game
    
    Win = false;
    tries=0,score=0;
    Surrender = false;
    system("clear");
    while ((getchar()) != '\n');

    // Game logic
    char str[10];
    Clear();
    SetShips();
    cout<<"The enemy war ships were dispersed all over our bay \nEnter s anytime to surrender \nComander! It's time to fight:\n";
    while ((Win == false)&&(Surrender == false)){
        Show();    
        cout << "Enter coordenates for an attack comander:";
        cin.getline(str,10);
        if (str[0] == 's'){
            system("clear");
            Surrender = true;
            break;
        }
        char *ptr;
        int coordenates[2];
        int count = 0;
        ptr = strtok(str, " , ");
        while (ptr != NULL){
            stringstream obj;
            obj << ptr;
            obj >> coordenates[count];
            count ++;
            ptr = strtok (NULL, " , ");  
        }
        
        if((coordenates[0]>=0)&&(coordenates[0]<10) && (coordenates[1]>=0)&&(coordenates[1]<10) ){
            Attack(coordenates[0],coordenates[1]);
            if (score == 10){
                Win = true;
                break;
            }else{
                cout<<"Tries: "<<tries<<"\nCurrent Score: " << score << "\n";
            }
        }else{
            cout<<"Coordenates out of range \n";
        }
    }
    cout<<"Game Over \n";
    if (Win ==true){
        cout<<"Congratulations Commander!!! You won. \n";
    }
    cout<<"Battle Sumary: \n" << "Tries: "<<tries<<"\nFinal Score: " << score << "\n"; 
    Show();

    return score;
}

// int main(){
//     play();
//     return 0;
// }