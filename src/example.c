#include "mintest/macros.h"

int test1() {
    test_printf("Hello! %d %f\n", 3, 3.14);
    return 0;
}

int test2() {
    test_assert(1 == 0, "This always fails!");
    printf("This never runs!\n");
    test_assert(1 == 1, "Neither this.");
    return 0;
}

int test3() {
    test_printf("<-- Name of the function before the printf!\n");
    test_assert(1 == 1, "This always succeeds");
    return 0;
}

int test4() {
    int pow = 1;
    for(int i = 0; i < 10; i++){
        pow *= 2;
    }
    
    test_assert(pow > 512, "For test");
    return 0;
}

int test5() {
    int pow = 1;
    for(int i = 0; i < 20000; i++){
        for(int j = 0; j < 10000; j++){
            for(int z = 0; z < 100; z++){
                pow += 1;
            }
            
        }
    }
    test_assert(pow > 512, "For test");
    return 0;
}

test_list = { TEST(test1), TEST(test2), TEST(test3), TEST(test4), TEST(test5) };

#include "mintest/runner.h"
