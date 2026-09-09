#include <iostream>
using namespace std;

int area(int side){
    return side*side;
}
int area(int length, int breadth){
    return length*breadth;
}
float area(float base, float height){
    return 0.5f*base*height;
}
int main(){
    int side;
    cout<<"enter side of a sqaure: "<< endl;
    cin>>side;
    cout<<"area of the square is :"<<area(side)<<endl;
    
    int length;
    int breadth;

    cout<<"enter length and breadth of rectangle : "<< endl;
    cin>>length>>breadth;
    cout<<"area of the rectangle is :"<<area(length,breadth)<<endl;

    float base;
    float height;

    cout<<"enter base and height of traingle: "<<endl;
    cin>>base>>height;
    cout<<"area of the triangle :"<<area(base,height)<<endl;



    return 0;

    
}