#include <string.h> 
#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>
#include <unistd.h>



int main(int argc, char *argv[]) {
    int pass_count = 0;
    int ret_filho = 0;
    if(argc == 1){
        pid_t filho, waitpid;

        int size = sizeof(all_tests)/sizeof(test_data);
        printf("Running %d tests:\n", size);
        printf("=====================\n\n");
        
        for (int i = 0; i < size; i++) {
            filho = fork();
            if(filho == 0){
                printf("------------------>Filho: %d Pai: %d Name: %s\n", getpid(), getppid(), all_tests[i].name);
                if (all_tests[i].function() >= 0) {
                    ret_filho = 1;
                    printf("%s: [PASS]\n", all_tests[i].name);
                };
                break;
            }
            
        }

        if (filho == 0) {
            return ret_filho;
        }
        int w;
        // wait(&w);
        while ((waitpid = wait(&w)) > 0){
            printf("Ret_filho = %d\n", WEXITSTATUS(w));
            pass_count += WEXITSTATUS(w);
        }


        // printf("id do primeiro filho a acabar: %d\n", WEXITSTATUS(w));

        printf("\n\n=================================\n");
        printf("%d/%d tests passed\n", pass_count, size);
    } else if(argc == 2) {

        printf("Rodando o teste %s\n", argv[1]);
        int size = sizeof(all_tests)/sizeof(test_data);
        for (int i = 0; i < size; i++) {
            if(strcmp(all_tests[i].name,argv[1]) == 0){
                if(all_tests[i].function() >= 0){
                    printf("%s: [PASS]\n", all_tests[i].name);
                }
            }
        }
    }

    return 0;
}
