#include <iostream>
#include <sys/wait.h>
#include <cstdlib>
#include <unistd.h>
#include <cstring>

using namespace std;

int main(int argc, char*argv[])
{
pid_t pid;
for (int i = 0; i < argc; i++){
	if (strcmp(argv[i], "static") == 0){
		pid = fork();
		if (pid < 0){
			cout << "Fork error";
			exit(-1);
				}
		else if (pid == 0){
			if (execlp("/bin/wheelchair_configuration", "wheelchair_configuration", NULL) == -1){
				cout << "Error with wheelchair_configuration \n";
													}
				}
		pid = fork();
		if (pid < 0){
        		cout << "Fork error";
        		exit(-1);
			}
		else if (pid == 0){
        		if (execlp("/bin/move_base", "move_base", NULL) == -1){
                	cout << "Error with move_base \n";

									}
				}
}
	else if(strcmp(argv[i], "dynamic") == 0){
		pid = fork();
                if (pid < 0){
                        cout << "Fork error";
                        exit(-1);
                                }
                else if (pid == 0){
                        if (execlp("/bin/wheelchair_configuration_dynamic", "wheelchair_configuration_dynamic", NULL) == -1){
                                cout << "Error with wheelchair_configuration_dynamic \n";
                                                                                                        }
                                }
		pid = fork();
		if (pid < 0){
        		cout << "Fork error";
        		exit(-1);
			}
		else if (pid == 0){
        		if (execlp("/bin/move_base_dynamic", "move_base_dynamic", NULL) == -1){
                		cout << "Error with move_base_dynamic \n";

									}
				}
}
}

pid = fork();
if (pid < 0){
        cout << "Fork error";
        exit(-1);
}
else if (pid == 0){
        if (execlp("/bin/controlwheel", "controlwheel", NULL) == -1){
                cout << "Error with controlwheel \n";
}
}
wait(NULL);
wait(NULL);
wait(NULL);
return 0;
}
