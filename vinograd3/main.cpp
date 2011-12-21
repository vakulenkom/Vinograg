//
//  main.cpp
//  vinograd3
//
//  Created by Mike on 21.12.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <ctime>

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
	double a[4];
	double b[4];
	double c[4];
    

    //что-нить делаем
    
	for (i=0;i<4;i++){
		a[i]=(double) i+1;
		b[i]=(double) i+4;
        //        std::cout <<"a["<<i<<"]="<<a[i]<<"\n";
        //        std::cout <<"b["<<i<<"]="<<b[i]<<"\n";
	}
    
    clock_t tStart = clock();
    vinogradSimpleMult(a,b,c);
    clock_t tFinish = clock();
    std::cout << "time: " << (double)(tStart - tFinish) / CLOCKS_PER_SEC<<" sec\n";
    
    for (i=0;i<7;i++)
        std::cout <<"c["<<i<<"]="<<c[i]<<"\n";
    return 0;
}



