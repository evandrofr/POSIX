#include <string.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

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
                char arq[100];
                sprintf(arq, "%s.txt",all_tests[i].name );
                //char buffer[64];
                int file = open(arq, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
                dup2(file,STDOUT_FILENO);
                if (all_tests[i].function() >= 0) {
                    ret_filho = 1;
                    //write(file, "\033[0;32m", sizeof("\033[0;32m")/sizeof(char)); // verde
                    // sprintf(buffer, "%s: [PASS]\n", all_tests[i].name);
                    // int cont = 0;
                    // while(buffer[cont] != '\0'){
                    //     cont++;
                    // }
                    // write(file, buffer, cont); //
                    // write(file, "\033[0m",sizeof("\033[0m")/sizeof(char));// Normal


                   verde();
                   printf("%s: [PASS]\n", all_tests[i].name);
                   normal();
                };
                close(file);
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
                char arq[100];
                sprintf(arq, "%s.txt",all_tests[id].name );
                char buffer[64];
                int file = open(arq, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
                // dup2(file,STDOUT_FILENO);



                write(file, "\033[1;31m", sizeof("\033[1;31m")/sizeof(char)); // vermelho_bold
                sprintf(buffer, "test%d: [ERROR] %s\n",id,strsignal(WTERMSIG(w))); //strsignal(WTERMSIG(w))
                int cont = 0;
                while(buffer[cont] != '\0'){
                    cont++;
                }
                write(file, buffer, cont); // 
                write(file, "\033[0m",sizeof("\033[0m")/sizeof(char)); //Normal
                close(file);

                // vermelho_bold();
                // printf("test%d: [ERROR] %s\n",id, strsignal(WTERMSIG(w)));
                // normal();

            } 
           
        }


        // printf("id do primeiro filho a acabar: %d\n", WEXITSTATUS(w));
        for (int i = 0; i < size; i++){
            char arq[100];
            sprintf(arq, "%s.txt",all_tests[i].name );
            char buf[1];
            int fileread = open(arq, O_RDONLY);
            int bytes_read = read(fileread, buf, 1);
            printf("%c", buf[0]);
             while(bytes_read != '\0') {
                 bytes_read = read(fileread, buf, 1);
                 printf("%c", buf[0]);
             }
             close(fileread);
        }

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
                    break;
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
