#include <iostream>

// functor
struct functor
{
    functor(float val1,float val2)
        : val1_(val1)
        , val2_(val2)
    {
    }

    float operator()(float step) const
    {
        return val1_+(val2_-val1_)*step;
    }
private:
    float val1_;
    float val2_;
};

// lambda
auto foo(float val1,float val2)
{
    return [=](float step)
    {
        return val1+(val2-val1)*step;
    };
}

//int main(int argc, char* argv[]){
//    functor func(0.0f,10.0f);
//    std::cout << "Functor value:" << func(0.5f) << std::endl;
//
//    auto x = foo(0.0f,10.0f);
//    std::cout << "Lambda value:" << x(0.5f) << std::endl;
//
//}