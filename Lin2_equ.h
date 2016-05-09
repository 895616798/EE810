//Author : Qingbo Zhang
#ifndef LIN2_EQU_HH_
#define LIN2_EQU_HH_
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double calcoe() {
	vector<double> coe;
	double i;
	char t;
	while(cin.get(t)){
		if (t=='\n')
            break;
        else {
            cin.unget();
            cin >> i;
            coe.push_back(i);
        }
	}
	double sum=0;
	for(vector<double>::const_iterator j=coe.begin();j!=coe.end();j++)
		sum+=*j;
	return sum;
}

void obyoequ() {
	cout<<"please input the coefficents of varibles of left side of equation:"<<'\n';
	double coel=calcoe();
	cout<<"please input the constants of left side of equation:"<<'\n';
	double constl=calcoe();
	cout<<"please input the coefficents of varibles of right side of equation:"<<'\n';
	double coer=calcoe();
	cout<<"please input the constants of right side of equation:"<<'\n';
	double constr=calcoe();
	double sol=(constr-constl)/(coel-coer);
	cout<<"The solution of equation is "<<sol<<'\n';
}

void obytequ() { 
	cout<<"please input the coefficients of 2-order variables of left side of equation:"<<'\n';
	double coel2=calcoe();
	cout<<"please input the coefficients of 1-order variables of left side of equation:"<<'\n';
	double coel1=calcoe();
	cout<<"please input the constants of left side of equation:"<<'\n';
	double constl=calcoe();
	cout<<"please input the coefficients of 2-order variables of right side of equation:"<<'\n';
	double coer2=calcoe();
	cout<<"please input the coefficients of 1-order variables of right side of equation:"<<'\n';
	double coer1=calcoe();
	cout<<"please input the constants of right side of equation:"<<'\n';
	double constr=calcoe();
	double a,b,c,d,real,imag;
	a=coel2-coer2;
	b=coel1-coer1;
	c=constl-constr;
	d=b*b-4*a*c;
	real=-b/(2*a);
	if(d<0) {
		imag=sqrt(-d)/(2*a);
		cout << "The result of the equation are: "<< real << '+' << imag <<'j'<< " and "
											  << real << '-' << imag <<'j'<< '\n';
	}
	else {
		cout << "The result of the equation are: "<< (-b+sqrt(d))/(2*a)<< " and "
											  	  << (-b-sqrt(d))/(2*a) << '\n';
	}
}

void tbyoequ() {
	cout<<"please input the coefficients of X of left side of first equation:"<<'\n';
	double coelx1=calcoe();
	cout<<"please input the coefficients of Y of left side of first equation:"<<'\n';
	double coely1=calcoe();
	cout<<"please input the constants of left side of first equation:"<<'\n';
	double constl1=calcoe();
	cout<<"please input the coefficients of X of right side of first equation:"<<'\n';
	double coerx1=calcoe();
	cout<<"please input the coefficients of Y of right side of first equation:"<<'\n';
	double coery1=calcoe();
	cout<<"please input the constants of right side of first equation:"<<'\n';
	double constr1=calcoe();
	cout<<"please input the coefficients of X of left side of second equation:"<<'\n';
	double coelx2=calcoe();
	cout<<"please input the coefficients of Y of left side of second equation:"<<'\n';
	double coely2=calcoe();
	cout<<"please input the constants of left side of second equation:"<<'\n';
	double constl2=calcoe();
	cout<<"please input the coefficients of X of right side of second equation:"<<'\n';
	double coerx2=calcoe();
	cout<<"please input the coefficients of Y of right side of second equation:"<<'\n';
	double coery2=calcoe();
	cout<<"please input the constants of right side of second equation:"<<'\n';
	double constr2=calcoe();
	double a1,b1,c1,a2,b2,c2,d;
	a1=coelx1-coerx1;
	b1=coely1-coery1;
	c1=constr1-constl1;
	a2=coelx2-coerx2;
	b2=coely2-coery2;
	c2=constr2-constl2;
	double sol1,sol2;
	d=a1*b2-b1*a2;
	if(d==0)
		cout<<"ERROR!"<<'\n';
	else {
		sol1=(c1*b2-b1*c2)/(a1*b2-b1*a2);
		sol2=(c1*a2-a1*c2)/(b1*a2-a1*b2);
		cout<<"The solution of two equations are : "<<"x = "<<sol1<<" y = "<<sol2<<'\n';
	}
}

void funmain() {
	cout<<"welcome to magic equation calculator!"<<'\n';
	cout<<"please choose the type of equation:"<<'\n';
	cout<<"1. Linear equation with one variable"<<'\n'
	    <<"2. Quadratic equation with one variable"<<'\n'
	    <<"3. Linear equation with one variable"<<'\n';
//	    <<"4. two varibles and two order"<<'\n'
//	    <<"5. multiple varibles and one order"<<'\n';
	char mode;
	mode = cin.get();
    cin.ignore(5,'\n');
    switch(mode)
    {
    	case '1':obyoequ();break;
    	case '2':obytequ();break;
    	case '3':tbyoequ();break;
//    	case '4:multiequ();break;
//    	case '5':return 0;
    	default:cout<<"error!";
	}
}

#endif

