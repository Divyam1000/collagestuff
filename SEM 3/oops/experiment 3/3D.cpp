#include<iostream>

using namespace std;

class temp{
    int num;
public:
    temp(int n){
        num = n;
        cout<<"Created object "<<num<<endl;
    }
    ~temp(){
        cout<<"Destroying object "<<num<<endl;
    }
};

int main()
{
    cout<<"inside first scope"<<endl;
    temp a(1),b(2),c(3);
    {
        cout<<"inside second scope"<<endl;
        temp d(4),e(5);
    }
    cout<<"outside second scope"<<endl;

    return 0;
}
