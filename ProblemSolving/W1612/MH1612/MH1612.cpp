#include <iostream>
#include <cstdio>
using namespace std;

#define MAX_KEY 1000
#define MAX_WORD 1000

int numWord=0;
char key[MAX_KEY] = {0, };
char word[MAX_KEY][MAX_WORD];

int charConvertor(char ch)
{
    int ret = 1;
    switch(ch)
    {
        case 'a':
        case 'b':
        case 'c':
            ret = 2;
            break;
        case 'd':
        case 'e':
        case 'f':
            ret = 3;
            break;
        case 'g':
        case 'h':
        case 'i':
            ret = 4;
            break;
        case 'j':
        case 'k':
        case 'l':
            ret = 5;
            break;
        case 'm':
        case 'n':
        case 'o':
            ret = 6;
            break;
        
        case 'p':
        case 'q':
        case 'r':
        case 's':
            ret = 7;
            break;
        case 't':
        case 'u':
        case 'v':
            ret = 8;
            break;
        case 'w':
        case 'x':
        case 'y':
        case 'z':
            ret = 9;
            break;
        default:
            break;
    }
    //cout << ret << endl;
    return ret;
}

bool checkWord(char word[MAX_WORD], int nKeyLen)
{
    bool ret = false;
    int i=0;
    
    //cout << nKeyLen << endl;
    
    for(int i=0;i<nKeyLen;i++)
    {
        //cout << charConvertor(word[i]) <<" "<< key[i] <<endl;
        if(charConvertor(word[i]) != (key[i] - '0')) return false;
    }
    
    return true;
}

int main(void)
{
    int T;
    freopen("sample_input.txt", "r", stdin);
    cin >> T;
    
    for(int tc=1;tc<=T;tc++)
    {
        int nCount = 0;
        int nKeyLen = 0;
        
        
        cin >> key >> numWord;
        
        for(int i=0;i<MAX_KEY;i++)
        {
            if(key[i] == NULL) break;
            nKeyLen++;    
        }
        
        //cout << nKeyLen << " == " << endl;
        
        for(int i=0;i<numWord;i++)
        {
            int nWordLen = 0;
            cin >> word[i];
            for(int j=0;j<MAX_KEY;j++)
            {
                if(word[i][j] == NULL) break;
                nWordLen++;    
            }
            
            if(nKeyLen != nWordLen) continue;
            
            if(checkWord(word[i], nKeyLen) == true) nCount++;
        }
        cout << nCount << endl;
    }
    
    return 0;
}