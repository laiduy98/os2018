#include <stdio.h>
#include <unistd.h>

int main(){
    printf("This is parent\n");
    int child1, child2;
    child1 =fork();
    if (child1==0){
        child2=fork();
        if (child2==0){
            char *args[]= { "free", "-h" , NULL};
            execvp("free", args);
        } 
        else{
        char *args[]= { "/bin/ps", "-ef" , NULL};
        execvp("/bin/ps", args);
        }
    } 

}