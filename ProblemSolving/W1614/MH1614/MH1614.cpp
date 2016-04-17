#include <iostream>
#include <cstdio>

using namespace std;

char binArr[40] = {0, };
char triArr[40] = {0, };
int binData[40] = {0, };
int triData[40] = {0, };
int binSize = 0;
int triSize = 0;

void charToInt()
{
    while(binArr[binSize] != '\0')
    {
        binData[binSize] = binArr[binSize] - '0';
        binSize++;
    }

    while(triArr[triSize] != '\0')
    {
        triData[triSize] = triArr[triSize] - '0';
        triSize++;
    }
}

void triToBin(int outBin[40], int& nSize, int& DecimalVal)
{
    int dec = 0;
    for(int i=0;i<triSize;i++)
    {
        int temp = 1;

        for(int j = i;j<triSize-1;j++)
            temp = temp * 3;
        dec += temp*triData[i];
    }

    //cout << "dec: " << dec << endl;
    DecimalVal = dec;

    while(dec > 0)
    {
        outBin[nSize++] = dec & 0x1;
        //cout << "dec : " << dec << endl;
        dec = dec >> 1;
    }
}

bool compareBin(int bin[40])
{
    int numMiss = 0;
    for(int i=0;i<binSize;i++)
    {
        if(bin[i] != binData[binSize-i-1]) numMiss++;
        if(numMiss > 1) return false;
    }
    return true;
}

int find()
{
    int res = -1;

    for(int i=0;i<triSize;i++)
    {
        int temp = triData[i];
        for(int j=0;j<3;j++)
        {
            if(temp == j)
            {
                continue;
            }

            triData[i] = j;

            int tempBin[40] = {0, };
            int nSize = 0;
            int DecimalVal;
            triToBin(tempBin, nSize, DecimalVal);

            //cout <<"nSize : " << nSize << endl;

            //if (nSize != binSize) continue;

            if(compareBin(tempBin) == true)
            {
                return DecimalVal;
            }

        }
        triData[i] = temp;
    }

    return res;
}

void Init()
{
    for(int i=0;i<40;i++)
    {
        binArr[i] = 0;
        binData[i] = 0;
        triArr[i] = 0;
        triData[i] = 0;
    }
    triSize = 0;
    binSize = 0;
}

int main(void)
{
    freopen("sample_input.txt", "r", stdin);

    int T;
    cin >> T;

    for(int tc=1;tc<=T;tc++)
    {
         int res = 0;
         Init();
         cin >> binArr >> triArr;
         charToInt();

         res = find();

         cout << res << endl;
    }
    return 0;
}
