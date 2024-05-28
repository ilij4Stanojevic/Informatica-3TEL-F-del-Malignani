#include <iostream>
#include <ctime>
#include <vector>
#define UNSOLD 0
#define SOLD 1
#define HOME 2
#define HOTEL 3
#define N_PLAYERS 3
using namespace::std;

class Dice{
    public:
        int throW(){
            srand(time(0));
            return rand()%6+1;
        }
};
class Plot{
    public:
        string name;
        string color;
        int buyPrice;
        int homePrice;
        int hotelPrice;
        int baseGain;
        int homeGain;
        int hotelGain;
        int property;

        Plot(string n,string c,int bP,int hmP,int htP,int bG,int hmG,int htG){
            name = n;
            color = c;
            buyPrice = bP;
            homePrice = hmP;
            hotelPrice = htP;
            baseGain = bG;
            homeGain = hmG;
            hotelGain = htG;
            property = UNSOLD;
        }
};
class Player{
    private:
        int _money;
        vector<Plot> _properties;
        bool _isPlaying;

    public:
        string nick;
        char symbol;
        
        Player(string n,char s){
            nick = n;
            symbol = s;
            _money = 500;
            _isPlaying = true;
        }

        void addMoney(int m){
            _money = _money + m;
        }
        void subMoney(int m){
            _money = _money - m;
        }
        void addProperty(Plot &newProperty){
            newProperty.property = SOLD;
            _properties.push_back(newProperty);
        }
        int getMoney(){
            return _money;
        }
};
class City{
    private:
        void _createField(){
            Plot plot0("Go","NULL",0,0,0,0,0,0);

            Plot plot1("Via_Malignani","red",100,200,300,50,100,150);
            Plot plot2("Via_Sello","red",100,200,300,50,100,150);
            Plot plot3("Via_Copernico","red",100,200,300,50,100,150);

            Plot plot4("PRIGIONE","NULL",0,0,0,0,0,0);

            Plot plot5("Via_Marte","blue",100,200,300,50,100,150);
            Plot plot6("Via_Giove","blue",100,200,300,50,100,150);
            Plot plot7("Via_Saturno","blue",100,200,300,50,100,150);

            Plot plot8("IMPREVISTO","NULL",0,0,0,0,0,0);

            Plot plot9("Via_Italia","yellow",100,200,300,50,100,150);
            Plot plot10("Via_Serbia","yellow",100,200,300,50,100,150);
            Plot plot11("Via_Russia","yellow",100,200,300,50,100,150);

            Plot plot12("ALLA_PRIGIONE","NULL",0,0,0,0,0,0);

            Plot plot13("Via_Xiuder","green",100,200,300,50,100,150);
            Plot plot14("IMPREVISTO","NULL",0,0,0,0,0,0);
            Plot plot15("Via_Forno","green",100,200,300,50,100,150);

            field.push_back(plot0);
            field.push_back(plot1);
            field.push_back(plot2);
            field.push_back(plot3);
            field.push_back(plot4);
            field.push_back(plot5);
            field.push_back(plot6);
            field.push_back(plot7);
            field.push_back(plot8);
            field.push_back(plot9);
            field.push_back(plot10);
            field.push_back(plot11);
            field.push_back(plot12);
            field.push_back(plot13);
            field.push_back(plot14);
            field.push_back(plot15);          
        }
    public:
        int playerPositions[N_PLAYERS];
        vector<Plot> field;

        City(){
            for(int i=0;i<N_PLAYERS;i++){
                playerPositions[i] = 0;
            }
            
            _createField();
        }
};

void showPositions(vector<Player> players){
    system("clear");
    cout<<"Posizione dei giocatori:"<<endl;
    for(int i=0;i<N_PLAYERS;i++){
        cout<<" Nome -> "<<players[i].nick<<endl;
    }
}




int main(){
    Player p1("Franklin",'?');
    Player p2("Trevor",'!');
    Player p3("Michael",'^');

    vector<Player> players;
    players.push_back(p1);
    players.push_back(p2);
    players.push_back(p3);

    City LosSantos;

    while(true){
        showPositions(players);
        system("pause");
    }



    return 0;
}