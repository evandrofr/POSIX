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
        printf("=========================================\n\n");
        
        for (int i = 0; i < size; i++) {
            filho = fork();
            if(filho == 0){
                //printf("------------------>Filho: %d Pai: %d Name: %s\n", getpid(), getppid(), all_tests[i].name);
                if (all_tests[i].function() >= 0) {
                    ret_filho = 1;
                    verde();
                    printf("%s: [PASS]\n", all_tests[i].name);
                    normal();
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
            int id = waitpid - getpid();
            if (WIFEXITED(w)) pass_count += WEXITSTATUS(w);
            if (WIFSIGNALED(w)){
                vermelho_bold();
                printf("test%d: [ERROR] %s\n",id, strsignal(WTERMSIG(w)));
                normal();
            } 
           
        }


        // printf("id do primeiro filho a acabar: %d\n", WEXITSTATUS(w));

        printf("\n\n=================================\n");
        printf("%d/%d tests passed\n", pass_count, size);
    } else if(argc == 2) {
        pid_t f;
        printf("Rodando o teste %s\n", argv[1]);
        int size = sizeof(all_tests)/sizeof(test_data);
        for (int i = 0; i < size; i++) {
            if(strcmp(all_tests[i].name,argv[1]) == 0){
                f = fork();
                if(f == 0){
                    if(all_tests[i].function() >= 0){
                        verde();
                        printf("%s: [PASS]\n", all_tests[i].name);
                        normal();
                    }
                }
              
            }
        }
        if(f == 0){
            return 0;
        }
        int st;
        wait(&st);
        if (WIFSIGNALED(st)){
            vermelho_bold();
            printf("%s: [ERROR] %s\n",argv[1], strsignal(WTERMSIG(st)));
            normal();
        }
        
 
    }

    return 0;
}
