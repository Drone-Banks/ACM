/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 200005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

class Complex
{
public:
    double real, imag;
    Complex(double real = 0.0, double imag = 0.0)
    {
        this->real = real, this->imag = imag;
    }
    Complex operator - (const Complex &elem) const
    {
        return Complex(this->real - elem.real, this->imag - elem.imag);
    }
    Complex operator + (const Complex &elem) const
    {
        return Complex(this->real + elem.real, this->imag + elem.imag);
    }
    Complex operator * (const Complex &elem) const
    {
        return Complex(this->real * elem.real - this->imag * elem.imag, this->real * elem.imag + this->imag * elem.real);
    }
    void setValue(double real = 0.0, double imag = 0.0)
    {
        this->real = real, this->imag = imag;
    }
};
Complex A[MaxN], B[MaxN];
int res[MaxN], len, mlen, len1, len2;
char str1[MaxN >> 1], str2[MaxN >> 1];
void Swap(Complex &a, Complex &b)
{
    Complex tmp = a;
    a = b;
    b = tmp;
}
//雷德算法 位逆序置换
void Rader(Complex y[])
{
    for(int i = 1, j = len >> 1, k; i < len - 1; ++ i)
    {
        if(i < j)
            Swap(y[i], y[j]);
        k = len >> 1;
        while(j >= k)
        {
            j -= k;
            k >>= 1;
        }
        if(j < k)
            j += k;
    }
}
//DFT : op == 1
//IDFT : op == -1
void FFT(Complex y[], int op)
{
    //先位逆序置换
    Rader(y);
    // h 为每次要处理的长度， h = 1 时不需处理
    for(int h = 2; h <= len; h <<= 1)
    {
        // Wn = e^(2 * PI / n)，如果是插值，那么 Wn = e^(-2 * PI / n)
        Complex Wn(cos(op * 2 * PI / h), sin(op * 2 * PI / h));
        for(int i = 0; i < len; i += h)
        {
            //旋转因子，初始化为 e^0
            Complex W(1, 0);
            for(int j = i; j < i + h / 2; ++ j)
            {
                Complex u = y[j];
                Complex t = W * y[j + h / 2];
                //蝴蝶操作
                y[j] = u + t;
                y[j + h / 2] = u - t;
                //每次更新旋转因子
                W = W * Wn;
            }
        }
    }
    // 插值的时候要除以 len
    if(op == -1)
        for(int i = 0; i < len; ++ i)
            y[i].real /= len;
}
//DFT 后将 A 和 B 相应点值相乘，将结果放到 res 里面
void Convolution(Complex *A, Complex *B)
{
    //evaluation
    FFT(A, 1), FFT(B, 1);
    for(int i = 0; i < len; ++ i)
        A[i] = A[i] * B[i];
    //interpolation
    FFT(A, -1);
    for(int i = 0; i < len; ++ i)
        res[i] = (int)(A[i].real + 0.5);
}
void Adjustment(int *arr)
{
    //次数界为 len，所以不用担心进位不会进到第 len 位
    for(int i = 0; i < len; ++ i)
    {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
    }
    //去除多余的 0
    while(-- len && res[len] == 0);
}
void Display(int *arr)
{
    for(int i = len; i >= 0; -- i)
        putchar(arr[i] + '0');
    putchar('\n');
}
void Prepare()
{
    len1 = strlen(str1), len2 = strlen(str2);
    mlen = max(len1, len2);
    len = 1;
    // 将 len 扩大到 2 的整数幂
    while(len < (mlen << 1))
        len <<= 1;
    //初始化多项式的系数
    for(int i = 0; i < len1; ++ i)
        A[i].setValue(str1[len1 - i - 1] - '0', 0);
    for(int i = 0; i < len2; ++ i)
        B[i].setValue(str2[len2 - i - 1] - '0', 0);
    // 补 0
    for(int i = len1; i < len; ++ i)
        A[i].setValue();
    for(int i = len2; i < len; ++ i)
        B[i].setValue();
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%s%s", &str1, &str2))
    {
        Prepare();
        Convolution(A,B);
        Adjustment(res);
        Display(res);
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}
