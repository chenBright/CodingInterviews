// n必须是到编译器就能确定的常数，不能动态输入
template <unsigned int n>
struct Sum {
    enum Value {
        N = Sum<n - 1>::N + n
    };
};

template <>
struct Sum<1> {
    enum Value {
        N = 1
    };
};