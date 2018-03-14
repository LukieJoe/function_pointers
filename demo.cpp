#include <stdio.h>
#include <vector>
#include <functional>

template <typename T>
struct obj{
    T method;
};

void caller(void (*func)()){
    func();
    return;
}

int main(){
#if 0
    obj inst;
    inst.method.push_back( []() { printf("hello_world\n"); } );

    inst.method[0]();
#endif

    obj<void(*)()> inst2;
    inst2.method = []() { printf("hello_world\n"); };
    inst2.method();
    inst2.method = []() { printf("good_bye\n"); };
    inst2.method();

#if  0
	auto one = []() { printf("hello\n"); };
	auto two = []() { printf("world\n"); };
	std::vector<void(*)()> func = { one, two };
	func[0]();
	func[1]();
	caller([]() { printf("hello_world\n"); });
#endif

	return 0;
}
