/**
 * It’s extremely important when using std::shared_ptr to avoid cyclic ownership and memory leaks.
 */


 /**
  * 🔹 1. Why weak_ptr Exists

When you use std::shared_ptr, ownership of the same object is shared among multiple smart pointers.
Each shared_ptr increases the object’s reference count.
  */

#include <iostream>
#include <memory>
using namespace std;

struct B;
struct A {
    shared_ptr<B> b_ptr;  // A owns B
    ~A() { cout << "A destroyed\n"; }
};
struct B {
    shared_ptr<A> a_ptr;  // B owns A
    ~B() { cout << "B destroyed\n"; }
};

int main() {
    auto a = make_shared<A>();
    auto b = make_shared<B>();
    a->b_ptr = b;
    b->a_ptr = a;
}


/**
 * Output: 
 * ❌ Problem:
    A points to B via shared_ptr
    B points back to A via shared_ptr

        Both objects keep each other alive forever — cyclic reference
        → Destructors never called → memory leak
 */

 /**
  * WHy memory leak ? in detail
  * 
  * End of main() scope: local variables a and b are destroyed.
  * a destructor: decrements a's use_count from 2 → 1 (still owned by b->a_ptr).
  * b destructor: decrements b's use_count from 2 → 1 (still owned by a->b_ptr).
  * Neither use_count reaches 0, so neither object is destroyed.
  * 
  * Result: both objects remain allocated on the heap, each holding a shared_ptr to the other → cyclic reference.
            Their destructors are never invoked → memory leak.
  */