#include <stdio.h>
//#include <time.h>

char x[1024][1024] = {0, };
int row[1024] = {0, };
int col[1024] = {0, };

int main(void)
{
    int T;
    freopen("sample_input_MH1706.txt", "r", stdin);
    //freopen("input_MH1706.txt", "r", stdin);
    setbuf(stdout, NULL);

    scanf("%d", &T);

    for(int test_case=1;test_case<=T;test_case++)
    {
        int N;
        int res = 0;
        scanf("%d", &N);

        for(int i=0;i<N;i++)
        {
            row[i] = col[i] = 0;
        }

        for(int i=0;i<N;i++)
        {
            scanf("%s", x[i]);
            for(int j=0;j<N;j++)
            {
                if(x[i][j] == 'B')
                {
                    row[i] ^= 1;
                    col[j] ^= 1;
                }
            }
        }

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if((x[i][j] == 'B' && (row[i] ^ col[j] == 0)) ||
                    (x[i][j] == 'W' && (row[i] ^ col[j] == 1)))
                {
                    res++;
                }
            }
        }

        printf("#%d %d\n", test_case, res);
    }

    return 0;
}
