#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

template<class ...T>
auto sum(T ...t)
{
    return (0+...+t);//sum()Ҳ��������,return (+...+t)Ҳ�У�����sum()�б�����ֵ����
}

int main()
{
    std::cout<<sum(1,2,3)<<std::endl;
}