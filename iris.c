#include <stdio.h> 
#include <math.h>

int main(void){
    double x1, x2, x3, y1, y2, y3, m12, xc, yc, r;
    double x_coord(
        double x1,
        double y1,
        double x2,
        double y2,
        double x3,
        double y3);
    printf("Enter x and y coordinates for first point: \n"); 
    scanf("%lf %lf",&x1,&y1);
    printf("Enter x and y coordinates for second point: \n"); 
    scanf("%lf %lf",&x2,&y2);
    printf("Enter x and y coordinates for third point: \n");
   scanf("%lf %lf",&x3,&y3);
   xc = x_coord(x1,y1,x2,y2,x3,y3);
   m12 = (y2 - y1)/(x2 - x1);
   yc = -(1/m12)*(xc - (x1 + x2)/2) + (y1 + y2)/2;
   r = sqrt((x1 - xc)*(x1 - xc) + (y1 - yc)*(y1 - yc));
   printf("\nCenter of Circle: (%.1f,%.1f) \n",xc,yc); 
   printf("Radius of Circle: %.1f \n",r);
   return 0;
}

double x_coord(double x1,double y1,double x2,double y2,double x3,double y3){
     double m12, m23, xc_num_all, xc_den, xc, xc_num_p1, xc_num_p2, xc_num_p3;
     m12 = (y2 - y1)/(x2 - x1);
     m23 = (y3 - y2)/(x3 - x2);
    xc_num_p1 = m12*m23*(y1 - y3);
    xc_num_p2 =  m23*(x1 + x2);
    xc_num_p3 = m12*(x2 + x3);
    xc_num_all = xc_num_p1 + xc_num_p2 - xc_num_p3;
    xc_den = 2*(m23 - m12);
    xc = xc_num_all/xc_den;
    return xc;

}
