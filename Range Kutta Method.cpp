#include<bits/stdc++.h>
using namespace std;

class RungeKuttaMethod{
    public:
        double x0, y0, x, y, h;

        RungeKuttaMethod(){
            cout<<"Enter x0 = ";
            cin>>x0;
            cout<<"Enter x = ";
            cin>>x;
            cout<<"Enter y0 = ";
            cin>>y0;
            cout<<"Enter h = ";
            cin>>h;
        }

        double f(double x, double y){
            return ((y * y - x * x) / (y * y + x * x));
        }

        void solve(){
            int n = (int)((x - x0) / h);
            for(int i = 1; i <= n; i++){
                double k1 = h * f(x0, y0);
                double k2 = h * f(x0 + 0.5 * h, y0 + 0.5 * k1);
                double k3 = h * f(x0 + 0.5 * h, y0 + 0.5 * k2);
                double k4 = h * f(x0 + h, y0 + k3);

                double k = (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
                y0 = y0 + k;
                x0 = x0 + h;
            }
            cout<<"Value of y is : "<<fixed<<setprecision(4)<<y0<<endl;
        }
};

int main(){
    RungeKuttaMethod kuttaMethod;
    kuttaMethod.solve();
    return 0;
}


/**
y(0) = 1
x = 0.2
x = 0.4
h = 0.2
*/
