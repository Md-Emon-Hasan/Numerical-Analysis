#include<stdio.h>

//function to calculate factorial

int factorial (int n)
{
    if (n==0 || n==1) //jodi 0! or 1! ==1 hoy to return 1
        return 1;
    else
        return n * factorial(n-1);


}

//function to calculate forward differences table
void forward_diff_table(float y [] , float diff[][10], int n)
{
    for (int i=0; i<n; i++)
    {
        diff[i][0] = y[i]; // Initialize first column with original values y er value input hobe
    }
    //calculate the forward difference
    //difference korar jonno
    for (int j =1; j<n;j++)
    {
        for (int i=0;i<n-j;i++)
        {
            diff[i][j]= diff[i+1][j-1]- diff[i][j-1];
        }
    }
}

// function to calculate backward difference
void backward_diff_table(float y[],float diff[][10], int n)
{
    for (int i =0;i<n; i++)
    {
        diff[i][0] =y[i];  // initial first column with original y values
    }

    // calculate the backward differences
    for (int j =1; j<n;j++)
    {
        for (int i=n-1;i>=j;i--)
        {
            diff[i][j]= diff[i][j-1]- diff[i-1][j-1];
        }
    }
}
// function to calculate u in the interpolation formula u-1,u-2
float u_calculate(float u,int n)
{
    float temp = u;
    for (int i =1; i<n; i++)
    {
        temp=temp *(u-i);
    }
    return temp;
}
float u_calculate_backward(float u,int n)
{
    float temp = u;
    for (int i =1; i<n; i++)
    {
        temp=temp *(u+i);
    }
    return temp;
}

//function forward_interpolation
float forward_interpolate (float x[] ,float y[], float diff[][10], int n, float x_interp)
{
      float u = (x_interp - x[0]) / (x[1] - x[0]); // calculate u=(x-x0)/h
      float result = y[0];  // initial result with y0

      // apply newton's forward interpolation Formula
      for (int i =1 ; i<n; i++)
      {
          result+=(u_calculate(u,i) * diff[0][i]) / factorial(i);
      }
      return result;

}
// function to interpolate missing value using newton's backward interpolation

float backward_interpolate (float x[] ,float y[], float diff[][10], int n, float x_interp)
{
      float u = (x_interp - x[n-1]) / (x[1] - x[0]); // calculate u=(x-xn)/h
      float result = y[n-1];  // initial result with yn

      // apply newton's backward interpolation Formula
      for (int i =1 ; i<n; i++)
      {
          result+=(u_calculate_backward(u,i) * diff[n-1][i]) / factorial(i);
      }
      return result;

}

int main()
{
    int n;
    float x[10], y[10], diff[10][10], x_interp;
    int choice;

    //input the number of data points
    printf("Enter the number of data points (n) : ");
    scanf("%d", &n);

    // input the data points (x and y values)
    printf("Enter the x and y values :\n ");
    for (int i =0; i<n; i++)
    {
        printf("x[%d] = ",i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    //input the value of x for which we want to interpolate
    printf("Enter the value of x to interpolate : ");
    scanf("%f" , &x_interp);

    // Ask te user which method to use (forward or backward)
    printf("Choose the method: \n 1.Newton's Forward Interpolation.\n 2. Newton's Backwark Interpolation\n" );
    scanf("%f", &choice);

    if (choice == 1)
    {
        //create the forward difference table
        forward_diff_table(y,diff,n);

        //Perform forward interpolation
        float y_interp = forward_interpolate(x,y,diff,n,x_interp);
        printf("The interpolated value at x = %.2f using Forward Interpolation is y= %.6f\n", x_interp,y_interp);

    }
    else if (choice == 2)
    {
        // create backward difference table
        backward_diff_table(y, diff,n );
        //perform backward interpolation
        float y_interp = backward_interpolate (x, y, diff, n, x_interp);
        printf("The interpolated value at x = %.2f using Forward Interpolation is y= %.6f\n", x_interp,y_interp);


    }
    else
    {
        printf("Invalid Choice. Please select either 1 or 2 .\n");
    }

    return 0;
}