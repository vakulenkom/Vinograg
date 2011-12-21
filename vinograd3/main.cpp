//
//  main.cpp
//  vinograd3
//
//  Created by Mike on 21.12.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>

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
    // tmp[i] - вспомогательные переменные дл€ уменьшени€ количества умножений 
    //    double tmp1 = c2 - c3;
    //    double tmp0 = 3.0 * tmp1 + 4.0 * c6 + c7 - 2.0 * c8 + c9;
    //    double tmp2 = c0 - 2.0 * c6 - c7;
    //    double tmp3 = c1 + c5;
    //    double tmp4 = 2.0 * c4 + c8;
    //    double tmp5 = -2.0 * tmp1 + tmp2;
    
    //_ASSERT(_CrtCheckMemory());
    
    res[0] = c1;
    res[1] = -c1 + c2 - c3;
    res[2] = c0 + c1 - c4 + 2*c6 - 3*c8 + c9;
    res[3] = c0 - 2*c1 + c2 - c3 - c4 + 2*c5 + 3*c7 + 3*c8 - 2*c9;
    res[4] = 2*c0 + c1 - c2 + c3 - 3*c7 - 3*c8 + 2*c9;
    res[5] = c0 - c1 + c4 -2*c6 + 3*c7 + 3*c8 -2*c9;
    res[6] = c0 + c1 - c2 + c3 + c4 - 2*c5 - 3*c7 + c9;
    
}

int main (int argc, const char * argv[])
{
    
	int i;
	double a[4];
	double b[4];
	double c[4];
    
	for (i=0;i<4;i++){
		a[i]=(double) i+1;
		b[i]=(double) i+4;
        //        std::cout <<"a["<<i<<"]="<<a[i]<<"\n";
        //        std::cout <<"b["<<i<<"]="<<b[i]<<"\n";
	}
    vinogradSimpleMult(a,b,c);
    
    for (i=0;i<7;i++)
        std::cout <<"c["<<i<<"]="<<c[i]<<"\n";
    return 0;
}



