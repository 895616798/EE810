//
//  quadratic.h
//  Algebra solver
//
//  Created by Xiaoqin Chen on 16/4/11.
//  Copyright © 2016年 Xiaoqin Chen. All rights reserved.
//

#ifndef quadratic_h
#define quadratic_h
#include <iostream>
#include<cmath>
using namespace std;
class quadratic
{
private:
    float a;
    float b;
    float c;
    float theta;
    double x1,x2;
public:
    quadratic(float a,float b,float c):a(a),b(b),c(c)
    {
        theta=b*b-4*a*c;
    }
    ~quadratic(){}
    bool findRoot(quadratic quad)
    {
        bool find=true;
        if(quad.theta<0)
            find=false;
        return find;
        
    }
    void root(quadratic quad)
    {
        if(quad.a!=0){
            quad.x1=(-quad.b+sqrt(quad.theta))/(2*quad.a);
            quad.x2=(-quad.b-sqrt(quad.theta))/(2*quad.a);
            cout<<"x1="<<quad.x1<<'\n';
            cout<<"x2="<<quad.x2<<'\n';
        }
        else
            cout<<"x="<<-c/b<<'\n';
    }
};



#endif /* quadratic_h */
