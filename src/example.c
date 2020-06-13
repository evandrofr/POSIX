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
    char *p = NULL;
    *p = 'a'; 

    test_assert(513 > 512, "Segmentation test");
    
    return 0;
}

int test8() {
    alarm(2);
    for(int i = 0; i < 100; i++){
        test_printf("Print %d de 100\n", i);
    }
    return 0;
}

int test9() {
    alarm(11);
    test_assert(1 == 1, "Sleep Pass");
    sleep(10);
    test_assert(1 == 0, "Sleep Fail");
    return 0;
}

int test10(){
    test_printf("Quick test pass\n");
    return 0;
}

int test11(){
    test_assert(1 == 0, "Quick Fail");
    return 0;
}

int test12(){
    int soma = 0;
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            for(int k = 0; k < 1000; k++){
                soma++;
            }
        }
    }
    test_assert(1000*1000*1000 == soma, "Hardcore test");
    return 0;
}
test_list = { TEST(test1), TEST(test2), TEST(test3), TEST(test4), TEST(test5), TEST(test6), TEST(test7), TEST(test8), TEST(test9), TEST(test10), TEST(test11), TEST(test12) };

#include "mintest/runner.h"
