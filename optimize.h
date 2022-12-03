#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;

int search_index(double *arr, double value, int len){
    // 传入数组指针、被索引的值、数组长度
    for(int i=0; i<len; i++){
        if(value==arr[i]){
            return i;
        };
    }
}

double min(double *arr, int len){
    // 搜索数组最小值
    double temp;
    double copyarr[len];
    for(int i=0; i<len; i++){
        copyarr[i] = arr[i];
    };
    
    // 冒泡排序
    for(int i=0; i<len; i++){
        for(int j=i+1; j<len-i; j++){
            if(copyarr[j] <= copyarr[i]){
                temp = copyarr[j];
                copyarr[j] = copyarr[i];
                copyarr[i] = temp;
            };
        };
    };
    return copyarr[0];
}


double optimize(double func(double), double *arr, int len, double epsilon){
    // 传入被优化函数、数据切分点以及数组长度, 还有误差
    double func_value[len];
    for(int i=0; i<len; i++){
        func_value[i] = func(arr[i]);
    };

    // 找到最小值以及对应的索引(如果刚好在边界, 则直接弹出边界索引)
    double min_value = min(func_value, len);
    int index = search_index(func_value, min_value, len);
    if(index==0 || index==len-1){
        double x=0;
        return index+x;
    }
    double x[3]={arr[index-1], arr[index], arr[index+1]};
    double y[3]={func(x[0]), func(x[1]), func(x[2])};

    while (true)
    {
        // 计算二次函数对称轴
        double k1=x[1]*x[1]-x[0]*x[0];
        double k2=x[1]-x[0];
        double k3=x[2]*x[2]-x[1]*x[1];
        double k4=x[2]-x[1];
        double k5=y[1]-y[0];
        double k6=y[2]-y[1];
        double a=(k5*k4-k6*k2)/(k1*k4-k2*k3);
        double b=(k1*k6-k5*k3)/(k1*k4-k2*k3);
        double C=y[0]-a*x[0]*x[0]-b*x[0];
        double l=-0.5*(k1*k6-k5*k3)/(k5*k4-k2*k6);

        double temp=x[1];  // 用作计算误差

        if(l<x[1]){
            if(func(l)<a*l*l+b*l+C){
                x[2]=x[1];
                x[1]=l;
            }
            else{
                x[0]=l;
            }
        }
        else{
            if(func(l)<a*l*l+b*l+C){
                x[0]=x[1];
                x[1]=l;
            }
            else{
                x[2]=l;
            }
        }
        y[0] = func(x[0]);
        y[1] = func(x[1]);
        y[2] = func(x[2]);

        // 跳出循环
        double abs;
        if(l<temp){
            abs=temp-l;
        }
        else{
            abs=l-temp;
        };

        if(abs<=epsilon){
            return l;
        };


    }
}

