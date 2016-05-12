#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include"Differentiate.h"
#include"integral.h"
#include"lin_equ.h"
#include"lin2_equ.h"
#include"que_equ.h"
using namespace std;
int main()
{
    //choose which fuction to use
    bool a=true;
    while(a){
        int c;
        cout<<"please choose the function you want:"<<endl;
        cout<<"1.equation"<<endl;
        cout<<"2.integral"<<endl;
        cout<<"3.defferential"<<endl;
        cout<<"0.quit"<<endl;
        cin>>c;
        if(c==3){//do the differentiate
            cout<<"hint:enter 'quit' to exit"<<endl;
            while(true){
                string s;
                cout<<"\n"<<"please enter an equation(for example:2x^3):"<<endl;
                cin>>s;
                if(s=="quit")
                    break;
                else
                    Differentiate differentiate(s);
            }
        }
        if(c==2){//do the integral
            while (true) {
                int choose;
                cout<<"choose the function(1 is for definite integral, 2 is for indefinite integral) ";
                cin>>choose;
                
                if (choose == 1) {
                    
                    cout<<" Use parameters a, b, c and d to describe the equation like a*x^b+c*x+d: "<<"\n";
                    double a,b,c,d;
                    cin>>a>>b>>c>>d;
                    cout<<"Your integral equation is "<<a<<"*x^"<<b<<"+"<<c<<"x+"<<d<<"\n";
                    cout<<"Input the low bound and up bound of the integral equation:"<<"\n";
                    double low,up;
                    cin>>low>>up;
                    cout<<"Your integral interval is ["<<low<<","<<up<<"]"<<"\n";
                    DefiniteIntegral value(a,b,c,d,low,up);
                    cout <<"Method 1(trapezoidal rule):the value by integration is  "<<value.trapezoidal() << endl;
                    cout <<"Method 2(simpson's rule):the value by integration is  "<<value.simpson() << endl;
                    
                }
                
                else if(choose == 2){
                    
                    //ax^b+c
                    cout<< "Input the parameters to describe the equation(example: ax^b+c)" << "\n";
                    double a,b,c;
                    cin>> a >> b >> c;
                    cout<<"Your equation is   "<<a<<"x^"<<b<<"+"<<c<<"\n";
                    cout<<"The euqation through indefinite integral is"<<"\n";
                    
                    IndefiniteIntegral A(a,b,c);
                    
                    A.print();
                    
                }
                
                else break;
                
            }
            
            return 0;
        }
    
  if(c==1)//do the equation
    {
        int QBchoose;
        cout<<"Please choose one kind of equation:"<<'\n'
        <<"1. Linear equation with one variable"<<'\n'
        <<"2. Linear equation with two variables"<<'\n'
        <<"3. Quadratic equation"<<'\n';
        cin>>QBchoose;
        if(QBchoose==1)
            funlinear();
        else if(QBchoose==2)
            funmain();
        else if(QBchoose==3)
            funquadra();
    }
    if(c==0)//quit the function
    a=false;

    }
}
