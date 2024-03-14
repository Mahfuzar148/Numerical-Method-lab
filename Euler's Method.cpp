#include<bits/stdc++.h>
using namespace std;
class EulersMethod{
   private :
       double x0,x,y0,y,h;
   public :
    double f(double x, double y)
    {
        return (x+y+x*y);
    }
    EulersMethod()
    {
        cout<<"Enter initial value of x0 = ";
        cin>>x0;
        cout<<"Enter the value of x = ";
        /// Value of x at which we need approximation
        cin>>x;
        cout<<"Enter the initial value of y0 = ";
        cin>>y0;
        cout<<"Enter the value of h = ";
        cin>>h;     ///step size
    }
    // Function for Euler formula
    void solve()
    {
        y = y0;
        // Iterating till the point at which we need approximation
        while(x0<x)
        {
            y = y + h*f(x0,y);
            x0 = x0 + h;
        }

         // Printing approximation
        cout << "Approximate solution at x = " << x << " is " << y << endl;

    }




};
int main()
{
    EulersMethod euler ;
    euler.solve();
    return 0;

}

/**
   Consider below differential equation
            dy/dx = (x + y + xy)
    with initial condition y(0) = 1
    and step size h = 0.025.
    Find y(0.1).

    Solution:
    f(x, y) = (x + y + xy)
    x0 = 0, y0 = 1, h = 0.025
    Now we can calculate y1 using Euler formula
    y1 = y0 + h * f(x0, y0)
    y1 = 1 + 0.025 *(0 + 1 + 0 * 1)
    y1 = 1.025
    y(0.025) = 1.025.
    Similarly we can calculate y(0.050), y(0.075), ....y(0.1).
    y(0.1) = 1.11167
*/
