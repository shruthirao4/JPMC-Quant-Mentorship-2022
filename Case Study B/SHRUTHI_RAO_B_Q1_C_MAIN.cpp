#include<bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

double area_of_D(double n, double r, double theta, double alpha){
    double D = 0.5*r*r*(n-1)*cos(theta+alpha)/n;
    return D;
}

double area_of_C(double n,double r,double theta,double alpha){
    double area_of_sector =  0.5*(M_PI/2-theta-alpha)*r*r;
    double C = area_of_sector - area_of_D(n,r,theta,alpha);
    return C;
}

double area_of_B(double n,double r,double theta,double alpha){
    double area_of_triangle = 0.5*r*r/n;
    double B = area_of_triangle - area_of_C(n,r,theta,alpha);
    return B;
}

double area_of_A(double n,double r,double theta,double alpha){
    double area_of_square = r*r;
    double area_of_quarter = M_PI*r*r/4;
    double A = area_of_square - area_of_quarter - area_of_B(n,r,theta,alpha);
    return A;
}

int main(){
    double n=1;
    double  r, theta, alpha, A, B, C, D, Area_ratio;
    double Percentage;
    cin >> Percentage;
    r = 5;
    //There are no restrictions on r as the required ratio does not depend on it.
    //The area has been computed as a fraction of r^2, i.e., the function returns the coefficient of r^2 in the area expression.
    //As r is only a parameter, we only work with the co-efficients of r.
    //r can have any value, but since it is used in the code and has been defined as double, we need to specify the value of r, which i have taken to be 5,
    //but the answer would be the same for any value of r.
    double q = (n-1)/sqrt(n*n +1);
    double w = 1/sqrt(n*n +1);
    theta = asin(q);
    alpha = asin(w);
    double total_area_of_shaded_region = r*r - M_PI*r*r/4;
    Area_ratio = area_of_A(n,r,theta,alpha)/total_area_of_shaded_region;
    while(Area_ratio*100 < Percentage){
    n++;
    q = (n-1)/sqrt(n*n +1);
    w = 1/sqrt(n*n +1);
    theta = asin(q);
    alpha = asin(w);
    total_area_of_shaded_region = r*r - M_PI*r*r/4;
    Area_ratio = area_of_A(n,r,theta,alpha)/total_area_of_shaded_region;
    }
  cout << n;
}