#include "mintest/macros.h"

int test1() {
    alarm(2);
    while(1){

    }
    return 0;
}

int test2() {
    alarm(2);
    test_assert(1 == 0, "This always fails!");
    printf("This never runs!\n");
    test_assert(1 == 1, "Neither this.");
    return 0;
}

int test3() {
    alarm(2);
    test_printf("<-- Name of the function before the printf!\n");
    test_assert(1 == 1, "This always succeeds");
    return 0;
}

int test4() {
    alarm(2);
    int pow = 1;
    for(int i = 0; i < 10; i++){
        pow *= 2;
    }
    
    test_assert(pow > 512, "For test");
    return 0;
}

int test5() {
    alarm(2);
    double pow = 1;
    pow = 1/0;
    test_assert(pow > 512, "Divisão por zero");
    
    return 0;
}

int test6() {
    alarm(2);
    for(int i = 0; i < 10; i++){
        sleep(1);
    }


    test_assert(513 > 512, "Alarm test");
    
    return 0;
}

int test7() {
    alarm(2);
    int array[5] = {0,1,2,3,4};
    for(int i = 0; i < 10; i++){
        array[i] += 1;
    }


    test_assert(513 > 512, "Segmentation test");
    
    return 0;
}

test_list = { TEST(test1), TEST(test2), TEST(test3), TEST(test4), TEST(test5), TEST(test6), TEST(test7) };

#include "mintest/runner.h"
