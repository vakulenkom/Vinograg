//
//  main.cpp
//  vinograd3
//
//  Created by Mike on 21.12.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <ctime>


void Multiplication(const double* a, const double* b, double* res){
    res[0] = a[0]*b[0];
    res[1] = b[0]*a[1]+b[1]*a[0];
    res[2] = b[0]*a[2]+b[1]*a[1]+a[0]*b[2];
    res[3] = b[0]*a[3]+a[2]*b[1]+a[1]*b[2]+a[0]*b[3];
    res[4] = a[3]*b[1]+a[2]*b[2]+b[3]*a[1];
    res[5] = a[2]*b[3]+a[3]*b[2];
    res[6] = a[3]*b[3];
}

void vinogradSimpleMult(const double* g, const double* d, double* res)
{ 
    double c0=(d[0]+d[1]+d[2]+d[3])*(g[0]+g[1]+g[2]+g[3])/6;
    double c1=g[0]*d[0];
    double c2=(g[0]+g[1])*(d[0]+d[1]);
    double c3=g[1]*d[1];
    double c4=(g[0]+g[1]-g[2]-g[3])*(d[0]+d[1]-d[2]-d[3])*0.5;
    double c5=(g[0]-g[2])*(d[0]-d[2])*0.5;
    double c6=(g[1]-g[3])*(d[1]-d[3])*0.5;
    double c7=(g[1]-g[2])*(d[1]-d[2])/3;
    double c8=(g[0]-g[2]+g[3])*(d[0]-d[2]+d[3])/3;
    double c9=(g[0]+g[1]-2*g[2]+g[3])*(d[0]+d[1]-2*d[2]+d[3])/3;
    
    //current vesion of m(x) is (x-1)*x^2*(x^2+1)*(x^2-x+1)
    // L[i] - вспомогательные переменные дл€ уменьшени€ количества умножений 
    double L0 = 3*c7 + 3*c8;
    double L1 = c2 - c3;
    double L2 = c1 - c2 + c3;
    double L3 = c1 - c4;
    
    //_ASSERT(_CrtCheckMemory());
    
    res[0] = c1;
    res[1] = -c1 + L1;
    res[2] = c0 + L3 + 2*c6 - 3*c8 + c9;
    res[3] = c0 - 2*c1 + L1 - c4 + 2*c5 + L0 - 2*c9;
    res[4] = 2*c0 + L2 - 3*c7 - 3*c8 + 2*c9;
    res[5] = c0 - L3 - 2*c6 + L0 -2*c9;
    res[6] = c0 + L2 + c4 - 2*c5 - 3*c7 + c9;
    
}

int main (int argc, const char * argv[])
{
	int i;
	double c[7];
	double a[4];
	double b[4];
    bool turn; // 1 for vinograd, 0 for standart
    clock_t tStart, tFinish;
    float standartTime,vinogradTime;
    
    //задание многочленов
	for (i=0;i<4;i++){
		a[i]=(double) i+1;
		b[i]=(double) 4+i;
	}
    
    turn=0;
    
    if (turn){
        tStart = clock();
        vinogradSimpleMult(a,b,c);
        tFinish = clock();
        vinogradTime =(float) (tFinish - tStart) / CLOCKS_PER_SEC;
        std::cout << "vinogradTime: " << vinogradTime<<" sec\n";
        for (i=0;i<7;i++)
            std::cout <<"c["<<i<<"]="<<c[i]<<"\n";
        
        std::cout <<"\n";
        
        tStart = clock();
        Multiplication(a,b,c);
        tFinish = clock();
        standartTime = (float)  (tFinish - tStart) / CLOCKS_PER_SEC;
        std::cout << "standartTime: " << standartTime<<" sec\n";
        for (i=0;i<7;i++)
            std::cout <<"c["<<i<<"]="<<c[i]<<"\n";
        
        std::cout << "\ndiff: vin/std= " << vinogradTime/standartTime<<" times\n";

    }
    else{
        tStart = clock();
        Multiplication(a,b,c);
        tFinish = clock();
        standartTime = (float)  (tFinish - tStart) / CLOCKS_PER_SEC;
        std::cout << "standartTime: " << standartTime<<" sec\n";
        for (i=0;i<7;i++)
            std::cout <<"c["<<i<<"]="<<c[i]<<"\n";

        std::cout <<"\n";
        
        tStart = clock();
        vinogradSimpleMult(a,b,c);
        tFinish = clock();
        vinogradTime =(float) (tFinish - tStart) / CLOCKS_PER_SEC;
        std::cout << "vinogradTime: " << vinogradTime<<" sec\n";
        for (i=0;i<7;i++)
            std::cout <<"c["<<i<<"]="<<c[i]<<"\n";
        
        std::cout << "\ndiff: vin/std= " << vinogradTime/standartTime<<" times\n";
    }
    
    
    
    
    
    
    
    
        return 0;
}



