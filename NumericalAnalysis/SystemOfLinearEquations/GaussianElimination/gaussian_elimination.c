/**
 * @author Rafiul Islam
 * @url https://github.com/rafiulgits
 */

#include<stdio.h>

const int range = 11;

int main()
{
    float mat[range][range];
    float var[range];

    printf("Co-efficient matrix n: ");
    int n; scanf("%d",&n);
    printf("A|B matrix row->col: ");

    int row, col, ite;
    float alpha, sum;

    for(row=1; row<=n; row++)
    {
        for(col=1; col<=n+1; col++)
            scanf("%f",&mat[row][col]);
    }

    for(ite=1; ite<=n-1; ite++)
    {
        for(row=ite+1; row<=n; row++)
        {
            alpha = mat[row][ite]/mat[ite][ite];
            for(col=1; col<=n+1; col++)
                mat[row][col] -= alpha*mat[ite][col];
        }

    }

    puts("\nAfter gaussin elimination: ");
    for(row=1; row<=n; row++)
    {
        for(col=1; col<=n+1; col++)
            printf("%.2f\t",mat[row][col]);
        printf("\n");
    }

    var[n] = mat[n][n+1]/mat[n][n];

    for(row=n-1; row>=1; row--)
    {
        sum = 0;
        for(col=row+1; col<=n; col++)
            sum += mat[row][col]*var[col];
        var[row] = (mat[row][n+1]-sum)/mat[row][row];

    }

    puts("\nSolution: ");
    for(row=1; row<=n; row++)
        printf("x%d: %.2f\n",row,var[row]);

    return 0;
}
