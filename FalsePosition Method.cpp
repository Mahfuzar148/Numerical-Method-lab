#include<bits/stdc++.h>
using namespace std;
class FalsePositionMethod{
private:
    double a,b;

    double tolerance = 0.0001;
    double Function(double x)
    {
        return (pow(x,3)-2*x-5);
    }
    double intersection (double a,double b)
    {
        double x = ((a*Function(b))-(b*Function(a)))/(Function(b)-Function(a));
        return x;
    }
public:
    void solve()
    {
        while(1)
        {
            srand(time(0));
            a = -99+ rand()%100;
            b = rand()%100;
            if((Function(a)*Function(b)<0))
            {
                break;
            }
        }

        double root ;
        int it = 1;
       while(1)
       {
            root = intersection(a,b);
            printf("Iteration %d : a = %9f b = %9f root = %9f \n",it,a,b,root);

            if(Function(root)==0||abs(Function(root))<tolerance)
            {
                break;
            }

            if(Function(root)*Function(a)<0)
            {
                b = root;
            }
            else
            {
                a = root;
            }
            it++;
       }
        printf("The root is %9f (correct upto 3 decimal places)\n",root);

    }




};
int main()
{
    FalsePositionMethod falsePositionMethod = FalsePositionMethod();
    falsePositionMethod.solve();
    return 0;

}
