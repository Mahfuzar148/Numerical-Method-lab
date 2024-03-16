#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 10

class GaussElimination{
private:
    double aug_matrix[MAX_SIZE][MAX_SIZE];
    double solutions[MAX_SIZE];
    double ratio;
    int unknown;
public:
    GaussElimination()
    {
        cout<<"Enter the number of unknowns : ";
        cin>>unknown;
        cout<<"Enter the element of the augmented matrix : "<<endl;

        for(int i=1;i<=unknown;i++)
        {
            for(int j=1;j<=unknown+1;j++)
            {
                cout<<"AugmentedMatrix["<<i<<"]["<<j<<"] = ";
                cin>>aug_matrix[i][j];
            }
        }

    }
   void elimination()
    {
        for(int i=1;i<=unknown-1;i++)
        {
            if(aug_matrix[i][i]==0.0)
            {
                for(int k=i+1;k<=unknown;k++)
                {
                    if(aug_matrix[k][i]!=0.0)
                    {
                        for(int j=1;j<=unknown+1;j++)
                        {
                            swap(aug_matrix[i][j],aug_matrix[k][j]);
                        }
                        break;
                    }
                }
            }

            for(int j = i+1;j<=unknown;j++)
            {
                ratio = aug_matrix[j][i]/aug_matrix[i][i];

                for(int k=1;k<=unknown+1;k++)
                {
                    aug_matrix[j][k] = aug_matrix[j][k]-ratio*aug_matrix[i][k];
                }
            }
        }
    }
    void backSubstitution()
    {
        solutions[unknown] = aug_matrix[unknown][unknown+1]/aug_matrix[unknown][unknown];

        for(int i = unknown-1;i>=1;i--)
        {
            solutions[i] = aug_matrix[i][unknown+1];

            for(int j=i+1;j<=unknown;j++)
            {
                solutions[i] = solutions[i]-aug_matrix[i][j]*solutions[j];
            }
            solutions[i] = solutions[i]/aug_matrix[i][i];


        }
    }
    void displaySolution()
    {
        for(int i=1;i<=unknown;i++)
        {
            cout<<fixed<<setprecision(6)<<solutions[i]<<endl;
        }
    }



};
int main()
{
    GaussElimination gauss ;
    gauss.elimination();
    gauss.backSubstitution();
    gauss.displaySolution();
    return 0;

}
