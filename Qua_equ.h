// Author : Qingbo Zhang
#ifndef QUA_EQU_HH_
#define QUA_EQU_HH_
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cmath>
using namespace std;

double funsplit(string& str, double& suma, double& sumb, double& sumc) {
    vector<string> substr;
    int count = 0;
    int pos = 0;
    int pre_pos = 0;
    for (char& c : str) {
        if (c=='+' || c=='-') {
            if (count == 0) {
                count++;
                continue;
            } else {
                pos = count;
                substr.push_back(str.substr(pre_pos,pos-pre_pos));
                pre_pos = pos;
            }
        }
        count++;
        if (count == str.length()) {
            pos = count;
            substr.push_back(str.substr(pre_pos,pos-pre_pos));
        }
    }
    
//    for(auto Q:substr) 
//    cout<<Q<<' ';
    

    int size;
    vector<string> torder,oorder,zorder;
    for (auto q : substr) {
    	size = q.size();
    	if(q[size-2] == '^')
    		torder.push_back(q);
    	else if(q[size-1] == 'x')
    		oorder.push_back(q);
    	else
    		zorder.push_back(q); 		
	}
	
//	for(auto O:torder)
//	cout<<O<<' ';
//	cout<<endl;
//	for(auto P:oorder)
//	cout<<P<<' ';
//	cout<<endl;
//	for(auto Q:zorder)
//	cout<<Q<<' ';
//	cout<<endl;
	
//	if(torder[0].size()==3)
//		torder[0]="1x^2";
//	for(auto u:torder) {
//		if((u.size()==4)&& (u[0] !='1')) 
//			u=u[0]+"1x^2";
//	}
//	
//	if(oorder[0].size()==1)
//		oorder[0]="1x";
//	for(auto w:oorder) {
//		if((w.size() == 2) && (w[0] != '1'))
//			w=w[0]+"1x";
//	}
	
	string coet[torder.size()];
	int ia=0;
	for(auto ha : torder) {
		coet[ia] = ha.substr(0,ha.size()-3);
		ia++;
	}
	double coeT[torder.size()];
	suma=0;
	for(ia=0; ia<torder.size(); ia++) {
		coeT[ia] = stod(coet[ia]);
		suma+=coeT[ia];
	}
//	cout<<suma<<endl;
//	for(int ia=0;ia<torder.size();ia++)
//	cout<<coeT[ia]<<' ';
//	cout<<endl; 
			
	string coeo[oorder.size()];
	int ib=0;
	for(auto hb : oorder) {
		coeo[ib] = hb.substr(0,hb.size()-1);
		ib++;
	}
	double coeO[oorder.size()];
	sumb=0;
	for(ib=0; ib<oorder.size(); ib++) {
		coeO[ib] = stod(coeo[ib]);
		sumb+=coeO[ib];
	}
//	cout<<sumb<<endl;
//	for(int ib=0;ib<oorder.size();ib++)
//	cout<<coeO[ib]<<' ';
//	cout<<endl; 
	
	string coez[zorder.size()];
	int ic=0;
	for(auto hc : zorder) {
		coez[ic] = hc;
		ic++;
	}
	sumc=0;
	double coeZ[zorder.size()];
	for(ic=0; ic<zorder.size(); ic++) {
		coeZ[ic] = stod(coez[ic]);
		sumc+=coeZ[ic];
	}	
//	cout<<sumc<<endl;
//	for(int ic=0;ic<zorder.size();ic++)
//	cout<<coeZ[ic]<<' ';
//	cout<<endl; 
}

double result(double a, double b, double c, double d, double e, double f) {
	double A=a-d;
	double B=b-e;
	double C=c-f;
//	cout<<A<<' '<<B<< ' '<<C<<endl;
	double D=B*B-4*A*C;
	double real, imag;
	real=-B/(2*A);
	if(D<0) {
		imag=sqrt(-D)/(2*A);
		cout << "The result of the equation are: "<< real << '+' << imag <<'j'<< " and "
											  << real << '-' << imag <<'j'<< '\n';
	}
	else {
	//	imag=sqrt(D)/(2*A);
		cout << "The result of the equation are: "<< (-B+sqrt(D))/(2*A)<< " and "
											  	  << (-B-sqrt(D))/(2*A) << '\n';
	}
}

void funquadra() {
	string s;
	cout<<"please input one equation:";
    cin>>s;
    int len,i,m;
    len=s.size();
//	for(len=0; s[len]!='\0';len++);
	for(i=0; i<len; i++) {
		if(s[i] == '=')
			m=i;
	}
	string left=s.substr(0,m);
	double suma,sumb,sumc,sumd,sume,sumf;
	funsplit(left,suma,sumb,sumc);
	string right=s.substr(m+1,len-m-1);
	funsplit(right,sumd,sume,sumf);
	result(suma, sumb, sumc, sumd, sume, sumf);
}


#endif
