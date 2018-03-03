#include <stdio.h>

typedef struct class{
    void (*method)(struct class*);
    int data;
} class;

int main(){
    class inst2;
    inst2.method = ({ void m(class* c) { printf("Hello World!!\n"); c->data = 10; printf("Data : %d\n", c->data); } m; });
    inst2.method(&inst2);

	return 0;
}
