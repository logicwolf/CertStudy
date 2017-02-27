#include <stdio.h>

int main(void)
{
    int test_case;
    freopen("sample_input_M1706.txt", "r", stdin);
    setbuf(stdout, NULL);

    scanf("%d", &test_case);
lkjsdlfkjsaklj
    for(int T=1;T<=test_case;T++)
    //for(int T=1;T<=1;T++)
    {
        int N;
        double sum=0;

        scanf("%d", &N);
        for(int i=0;i<N;i++)
        {
            int x;
            double p;

            scanf("%lf %d", &p, &x);
            sum += (double) x * p;
        }
        printf("#%d %.6lf\n", T, sum);
    }

    return 0;
}
