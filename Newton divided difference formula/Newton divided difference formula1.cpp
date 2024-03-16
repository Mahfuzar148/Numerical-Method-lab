#include<bits/stdc++.h>
using namespace std;

class NewtonsDividedDifferenceInterpolation{
private:
    int n, given_x;
    double x[10], y[10][10];
    double ans = 0.0;
public:
    NewtonsDividedDifferenceInterpolation()
    {
        cout<<"Enter the number of data : ";
        cin>>n;
        cout<<"Enter data : "<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<"x["<<i<<"] = ";
            cin>>x[i];
            cout<<"y["<<i<<"][0] = ";
            cin>>y[i][0];
        }
        cout<<" Enter the value of x for which you want to interpolate : ";
        cin>>given_x;

        /** Divided difference table calculation */

        for(int col = 1; col < n; col++)
        {
            for(int row = 0; row < n - col; row++)
            {
                y[row][col] = (y[row+1][col-1] - y[row][col-1]) / (x[col+row] - x[row]);
            }
        }
    }
    double multiplication(int i)
    {
        double value = 1;
        for(int j = 0; j < i; j++)
        {
            value *= given_x - x[j];
        }
        return value;
    }
    void solve()
    {
        ans = y[0][0];
        for(int i = 1; i < n; i++)
        {
            ans += multiplication(i) * y[0][i];
        }
        cout<<"The value at "<<given_x<<" is "<<ans<<endl;
    }
};

int main()
{
    NewtonsDividedDifferenceInterpolation dividedDifference;
    dividedDifference.solve();
    return 0;
}
