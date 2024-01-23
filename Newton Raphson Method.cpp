#include<bits/stdc++.h>
using namespace std;
class NewtonRaphsonMethod{

   private:
    double tolerance= 0.0001;
    double Function(double x)
    {
        return (pow(x,3)-2*x-5);
    }
    double derivative(double x)
    {
        return (3*pow(x,2)-2);
    }
   public:

       void solve()
       {
            cout<<fixed<<setprecision(9)<<endl;
           double x,h;
           while(1)
           {
               srand(time(0));
               x = rand()%1000;
               if(derivative(x)!=0)
               {
                   break;
               }

           }

           h = Function(x)/derivative(x);
           int it = 1;
           while(abs(h)>=tolerance)
           {
               cout<<"iteration : "<<it++<<" x : "<<x<<endl;
                h = Function(x)/derivative(x);
                x = x-h;
           }

           cout<<x<<endl;

       }



};
int main()
{
    NewtonRaphsonMethod n = NewtonRaphsonMethod();
    n.solve();

}
