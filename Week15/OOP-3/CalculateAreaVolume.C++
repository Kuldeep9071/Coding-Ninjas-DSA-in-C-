#include<bits/stdc++.h>
using namespace std;

class Inputs{
    public:
        int length;
        int breadth;
        int height;
        int func(int a){
            length=a;
        }
        int func(int a,int b){
            length=a;
            breadth=b;
        }
        int func(int a,int b,int c){
            length=a;
            breadth=b;
            height=c;
        }
};
class Rectangle: public Inputs{
    public:
        int area(){
            return length*breadth;
        }
};
class Circle: public Inputs{
    public:
        int area(){
            return (22*length*length)/7;
        }
};
class Volume: public Inputs{
    public:
        int area(){
            return length*breadth*height;
        }
};
int choice(){
    int c;
    cin>>c;            
    return c; 
}

int main(){
    int cho = choice();
    if(cho==1){
        Rectangle obj;
        obj.func(10,20);
        int ans = obj.area();
        cout<<ans;
    }
    else if(cho ==2){
        Circle obj;
        obj.func(7);
        int ans = obj.area();
        cout<<ans;
    }
    else if(cho ==3){
        Volume obj;
        obj.func(10,20,30);
        int ans = obj.area();
        cout<<ans;
    }
}
/*
Problem statement
Attempt the problem as per the description.

Create a definition of function "choice" which should take choice as the input and return it.

Create a class "Inputs" which should have three public data members named "length", "breadth", 
"height" and also a function named "func" which should be overloaded with different parametres 
based upon the choice. If choice = 1, two parametres should be there , if choice =2 ,
 one parameter should be there else 3 parameters should be there.

Create following classes which should inherit the "Input" class and should have a public 
function named "area" which returns the area or volume as described:

1.Rectangle 2.Circle 3. Volume
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1
1
Sample Output 1
200
Explanation
Since for 1 , rectangle function will be called where we have passed the length as 10 and 
breadth as 20, so answer = 200.

*/