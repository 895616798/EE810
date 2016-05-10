//
//  Differentiate.h
//  Differentiate
//
//  Created by Xiaoqin Chen on 16/5/8.
//  Copyright © 2016年 Xiaoqin Chen. All rights reserved.
//

#ifndef Differentiate_h
#define Differentiate_h
#include<iostream>
#include<string>
#include<cmath>
#include<sstream>
using namespace std;
class Differentiate
{
private:
    string s;
    int degree;
public:
    Differentiate(string s)
    {
        string result;
        stringstream s1;
        int longnum=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='x'&&s[i+1]=='^'){
                if(numerical(s, i+2)==true){
                    s1<<s[i+2];
                    s1>>degree;//change string to int
                    for(int j=i+3;;j++)
                    {
                        if(numerical(s, j)==true)//find the degree,when the degree is larger than 9
                        {
                            degree*=10;
                            stringstream s2;
                            s2<<s[j];
                            s2>>longnum;
                            degree+=longnum;
                        }
                        else
                            break;
                    }
                    result=EquationDifferentiate(&s, i,degree);//do the EquationDifferentiate
                    print(result);
                }
            }
            if(s[i]=='e'&&s[i+1]=='^'&&s[i+2]=='x')
            {
                result="e^x";
                print(result);
            }
            if(numerical(s, i)==true&&s[i+1]=='^'&&s[i+2]=='x')
            {
                result=ExponentialDifferentiate(&s,i);
                print(result);
            }
            if(s[i]=='s')//sinx
            {
                result=TrigonometricDifferentiate(s, i);
                print(result);
                i=i+4;
            }
            if(s[i]=='c')//cosx
            {
                result=TrigonometricDifferentiate(s, i);
                print(result);
                i=i+4;
            }
            if(s[i]=='+')//(u+v)'=u'+v'
            {
                cout<<"+";
                string newstring1="";
                for(int k=i+1;k<=s.size();k++)
                    newstring1+=s[k];
                Differentiate differ1(newstring1);
                break;
            }
            if(s[i]=='-')//(u-v)'=u'-v'
            {
                cout<<"-";
                string newstring1="";
                for(int k=i+1;k<=s.size();k++)
                    newstring1+=s[k];
                Differentiate differ1(newstring1);
                break;
            }
            if(s[i]=='*')//(u*v)'=u'v+v'u
            {
                cout<<"*(";
                string newstring1="",newstring2="";
                for(int k=i+1;k<=s.size();k++)
                    newstring1+=s[k];
                cout<<newstring1<<")+";
                for(int m=0;m<i;m++)
                    newstring2+=s[m];
                cout<<newstring2<<"*(";
                Differentiate differ1(newstring1);
                cout<<")";
                break;
            }
             if(s[i]=='/')//(u/v)‘＝（u'v+v'u）／v^2
            {
                cout<<"*(";
                string newstring1="",newstring2="";
                for(int k=i+1;k<=s.size();k++)
                    newstring1+=s[k];
                cout<<newstring1<<")-";
                for(int m=0;m<i;m++)
                    newstring2+=s[m];
                cout<<newstring2<<"*(";
                Differentiate differ1(newstring1);
                cout<<")/("<<newstring1<<")^2";
                break;
            }

        }
    }
    ~Differentiate(){}
    bool numerical(string s,int i)//is a int or not
    {
        bool num=false;
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
            num=true;
        return num;
        
    }
    int ConstDifferentiate(double n)
    {
        return 0;
    }
    string ExponentialDifferentiate(string *s,int i)
    {
        int a;
        string result;
        stringstream ss1;
        ss1<<s[i];
        ss1>>a;
        for(int j=i-1;j>=0;j--){
            if(numerical(*s, j)==true){
                stringstream ss2;
                ss2<<s[j];
                ss2>>a;
            }
            else{
                break;
            }
        }
        stringstream s1;
        s1<<a;
        result=s1.str()+"ln"+s1.str();
        return result;
    }
    string EquationDifferentiate(string *s,int i,int degree)
    {
        string result;
        int a=0;
        
        if(numerical(*s, i-1)==true)
        {
            stringstream ss1;
            ss1<<s[i-1];
            ss1>>a;
            for(int j=i-2;j>=0;j--){
                if(numerical(*s, j)==true){
                    stringstream ss2;
                    ss2<<s[j];
                    ss2>>a;
                }
                else{
                    break;
                }
            }
            a*=degree;
            stringstream s1,s2;
            s1<<a;
            s2<<degree-1;
            result=s1.str()+"x^"+s2.str();
            
        }
        else{
            stringstream s3,s4;
            s3<<degree;
            s4<<degree-1;
            result=s3.str()+"x^"+s4.str();
        }
        return result;
    }
    string TrigonometricDifferentiate(string s,int i)
    {
        string result;
        if(s[i]=='s')
            result="cosx";
        else
            result="(-sinx)";
        return result;
    }
    void print(string s)const
    {
        cout<<s;
    }
};



#endif /* Differentiate_h */
