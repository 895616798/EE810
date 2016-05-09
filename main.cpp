// Author: Qingbo Zhang
#include <iostream>
#include "Lin_equ.h"
#include "Lin2_equ.h"
#include "Qua_equ.h"

using namespace std;

int main() {
	int choose;
	cout<<"Please choose one kind of equation:"<<'\n'
		<<"1. Linear equation with one variable"<<'\n'
		<<"2. Linear equation with two variables"<<'\n'
		<<"3. Quadratic equation"<<'\n';
	cin>>choose;
	if(choose==1)
		funlinear();
	else if(choose==2)
		funmain();
	else if(choose==3)
		funquadra();
}
