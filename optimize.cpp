#include "optimize.h"
using namespace std;

double func(double x){
    return cos(x);
}

int main(){
    // 选定一个区间
    double arr[]={1, 2, 2.2, 4, 5, 6};
    cout << optimize(func, arr, 6, 1e-5) << endl;

    system("pause");
    return 0;
}