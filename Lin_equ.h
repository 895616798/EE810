// Author : Qingbo Zhang
#ifndef LIN_EQU_HH_
#define LIN_EQU_HH_
#include <iostream>
#include <vector>
using namespace std;

class Nod
{
	private:
		char sb;
		double n;
		char x;
	public:
		Nod() {}
		Nod(char s, double num, char x): sb(s), n(num), x(x){}
		friend ostream& operator <<(ostream& s,const Nod& a) {
			return s<<a.sb<<a.n<<a.x;
		}
		
		friend istream& operator >>(istream& s, Nod& a) {
			  s>>a.sb>>a.n;
			  return s;
		}	
		
		void setx(Nod& i) {
			i.x='x';
		}
	
		friend Nod clasi(vector<Nod>& e) {
			vector<Nod> a,b,c,d;
			double suma=0, sumb=0, sumc=0, sumd=0;
			for(auto y:e) {
				if((y.sb=='+') && (y.x=='x'))
					a.push_back(y);
				else if((y.sb=='-') && (y.x=='x'))
					b.push_back(y);
				else if((y.sb=='+') && (y.x!='x'))
					c.push_back(y);
				else if((y.sb=='-') && (y.x!='x'))
					d.push_back(y);
				else
					cout<<"error";
			}
			for(auto m:a)
				suma+=m.n;
			for(auto o:b)
				sumb+=o.n;
			for(auto p:c)
				sumc+=p.n;
			for(auto q:d)
				sumd+=q.n;
				
			Nod newe, newc;
			double D =suma-sumb;
			if(D>0 || D==0)
			{	newe.sb='+'; newe.n=D; newe.x='x'; }
			else if(D<0)
			{	newe.sb='-'; newe.n=-D; newe.x='x'; }
			//cout << newe << end;
			
			double B=sumc-sumd;
			if(B>0 || B==0)
			{	newc.sb='+'; newc.n=B; newc.x=' '; }
			else if(B<0)
			{	newc.sb='-'; newc.n=-B; newc.x=' '; }
		//	cout<<"Your equation equals to :"<<newe<<newc<<'\n';
			e.clear();
			e.push_back(newe);
			e.push_back(newc);
		}
		
		friend double result(vector<Nod> left, vector<Nod> right);
 };	
 
 void set(vector<Nod>& e) {
 	while(1) {
		char t;
		Nod i(0,0,' ');
        cin >> i;
        cin.get(t);
        if (t=='x') {
        	i.setx(i);
        	cin.get(t);
        	if(t=='\n') {
        		e.push_back(i);
        		break;
			}
			cin.unget();
		}
        else if (t=='\n') {
            e.push_back(i);
            break;
		}
		else
			cin.unget();	
		e.push_back(i);
    }	
	
//	for(vector<Nod>::iterator m=e.begin();m!=e.end();m++)
//		cout<<*m;
//	cout<<'\n'; 
 }
 
double result(vector<Nod> left, vector<Nod> right) {
	for(int i=0;i<=1;i++) {
		if(left[i].sb=='-')
			left[i].n*=-1;
		if(right[i].sb=='-')
			right[i].n*=-1;
	}
	double re;
	re=(right[1].n-left[1].n)/(left[0].n-right[0].n);
	return re;
}

void funlinear() {
	cout<<"please input your left side of equation:"; //e.g -3x +17 -12x
	vector<Nod> left;
	set(left);
	clasi(left);
	cout<<"The result after simplification is:";
	for(vector<Nod>::iterator m=left.begin();m!=left.end();m++)
	cout<<*m;
	cout<<'\n'; 
	cout<<"please input your right side of equation:";
	vector<Nod> right;
	set(right);
	clasi(right);
	cout<<"The result after simplification is:";
	for(vector<Nod>::iterator n=right.begin();n!=right.end();n++)
	cout<<*n;
	cout<<'\n'; 
	cout<<"The result is: "<<result(left,right);
}
		  
#endif

 








