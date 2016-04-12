//
//  main.cpp
//  Algebra solver
//
//  Created by Xiaoqin Chen on 16/4/11.
//  Copyright © 2016年 Xiaoqin Chen. All rights reserved.
//

#include <iostream>
#include"quadratic.h"
using namespace std;
int main(int argc, const char * argv[]) {
    while(true){
    cout<<"please choose:"
    cout<<"1:quadratic";
    cout<<"0:quit;"
    int choose;
    cin>>choose;
    if(choose==1){
    float a,b,c;
    cout<<"ax^2+bx+c=0"<<'\n';
    cout<<"please enter the exactly value of a,b,c:";
    cin>>a;
    cin>>b;
    cin>>c;
    quadratic quad(a,b,c);
    if(quad.findRoot(quad))
        quad.root(quad);
    else
        cout<<"can't find the root suit for this equcation!!!"<<'\n';
    }
    if(choose==0)
    return -1;
}
    
}
