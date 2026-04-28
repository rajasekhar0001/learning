/** To avpid cyclic redundancy, use weak_ptr */

/**
 * weak_ptr is a non-owning observer. It doesn’t increment the strong count, so it can “look at” 
   the object without preventing its destruction.
 * Typical fix: make one side weak_ptr. For example, B should hold a weak_ptr<A>:
 */

 #include <iostream>
#include <memory>
using namespace std;

struct B;
struct A {
    shared_ptr<B> b_ptr;
    ~A() { cout << "A destroyed\n"; }
};
struct B {
    weak_ptr<A> a_ptr;   // <- weak_ptr breaks the cycle
    ~B() { cout << "B destroyed\n"; }
};

int main() {
    auto a = make_shared<A>();
    auto b = make_shared<B>();
    a->b_ptr = b;
    b->a_ptr = a;   // weak_ptr: does NOT increase A's use_count

    cout << "a use_count = " << a.use_count() << '\n'; // likely 1
    cout << "b use_count = " << b.use_count() << '\n'; // likely 2
}

/** Output: Destructors called */