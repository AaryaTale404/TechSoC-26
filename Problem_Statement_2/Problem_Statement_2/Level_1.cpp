#include<iostream>
#include<string>
#include<cmath>
using namespace std;

//creating class for moves
class Move {
public :
string move;
int pwrlvl;

Move (string m , int pl){
move = m;
pwrlvl = pl;
}

Move() {
move = "";
pwrlvl = 0;
}

};
 
//creating class for bender
class Bender {
public :
string name;
string element;
int hp;
int maxhp;
int attack;
int defense;
int speed;
Move moves[4];  //array to store moves

//constructer for bender
Bender (string n , string e , int hpvalue , int a , int d , int s , Move m1 , Move m2 , Move m3 , Move m4 ) {
name = n;
element = e;
hp = hpvalue;
attack = a;
defense = d;
speed = s;
moves[0]=m1;
moves[1]=m2;
moves[2]=m3;
moves[3]=m4;
maxhp = hp;

}

//member function to display the stats
void Display_stats () {
cout<<name<<" "<<"("<<element<<") "<<"- HP: "<<hp<<"/"<<maxhp<<", Attack: "<<attack<<", Defense: "<<defense<<", Speed: "<<speed<<endl;
cout<<"Moves: "<<moves[0].move<<" ("<<moves[0].pwrlvl<<"), "<<moves[1].move<<" ("<<moves[1].pwrlvl<<"), "<<moves[2].move<<" ("<<moves[2].pwrlvl<<"), "<<moves[3].move<<" ("<<moves[3].pwrlvl<<")"<<endl;
}



};

int main(){

string name1,name2,element1,element2,m11name,m12name,m13name,m14name,m21name,m22name,m23name,m24name;
int hp1,hp2,attack1,attack2,defense1,defense2,speed1,speed2,
    m11pl,m12pl,m13pl,m14pl,m21pl,m22pl,m23pl,m24pl;
int damage;
int i;

//create and initialise benders using user input-

//bender1-
cin >> name1 >> element1;
cin >> hp1 >> attack1 >> defense1 >> speed1;
cin>>m11name>>m11pl>>m12name>>m12pl>>m13name>>m13pl>>m14name>>m14pl;
Move m11(m11name,m11pl);
Move m12(m12name,m12pl);
Move m13(m13name,m13pl);
Move m14(m14name,m14pl);

Bender bender1(name1,element1,hp1,attack1,defense1,speed1,m11,m12,m13,m14);

//bender2-
cin >> name2 >> element2;
cin >> hp2 >> attack2 >> defense2 >> speed2;
cin>>m21name>>m21pl>>m22name>>m22pl>>m23name>>m23pl>>m24name>>m24pl;
Move m21(m21name,m21pl);
Move m22(m22name,m22pl);
Move m23(m23name,m23pl);
Move m24(m24name,m24pl);

Bender bender2(name2,element2,hp2,attack2,defense2,speed2,m21,m22,m23,m24);

//display the stats before attack-
bender1.Display_stats();
bender2.Display_stats();

//choose attack move (ie input of move index) -
cin>>i;

//implementing battle logic


//Case1:bender1 is attacker
if(speed1>speed2){
damage = round((double)bender1.attack * bender1.moves[i].pwrlvl / bender2.defense);
bender2.hp-=damage;
cout<<bender1.name<<" used "<<bender1.moves[i].move<<"!"<<endl;
cout<<bender2.name<<" took "<<damage<<" damage!"<<endl;
if(bender2.hp<damage){
bender2.hp=0;
}
bender2.Display_stats();
if(bender2.hp==0){
cout<<bender2.name<<" fainted: True"<<endl;
}
else{
cout<<bender2.name<<" fainted: False"<<endl;
}
}

//Case2:bender2 is attacker
else if (speed1<speed2){
damage = round((double)bender2.attack * bender2.moves[i].pwrlvl / bender1.defense);
bender1.hp-=damage;
cout<<bender2.name<<" used "<<bender2.moves[i].move<<"!"<<endl;
cout<<bender1.name<<" took "<<damage<<" damage!"<<endl;
if(bender1.hp<damage){
bender1.hp=0;
}
bender1.Display_stats();
if(bender1.hp==0){
cout<<bender1.name<<" fainted: True"<<endl;
}
else{
cout<<bender1.name<<" fainted: False"<<endl;
}
}

return 0;
}
