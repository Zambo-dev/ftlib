#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include "ftlib.c"

void print_data(Folder* folder)
{
        long int old = 0;
        while(1)
        {       
                if(old != 0 && strcmp(folder->curr_dir, "C:\\") == 0)
                        break;
                if(old != folder->result_lenght)
                {
                        printf("\n%s", folder->result[old]);
                        old++;
                }
        }
}

int main(int argc, char* argv[])
{
        Folder *f = malloc(sizeof(Folder));
        pthread_t thread1, thread2;
        char* fName;

        if(argc <= 1)
        {
            puts("Missing parameter!");
            return EXIT_FAILURE;
        }
        
        fName = malloc(strlen(argv[1]) + 1);
        strcpy(fName, argv[1]);

        init(f, fName);

        pthread_create(&thread2, NULL, (void*)print_data, (void*)f);

        for(int i=0; i < f->win_disks_lenght; i++)
        {       
                change_root_directory(f, f->win_disks[i]);
                pthread_create(&thread1, NULL, (void*)find_file, (void*)f);
                pthread_join(thread1, NULL);
        }

        pthread_join(thread2, NULL);

        puts("\n");

        resert_directory(f);
        free(f);

        return EXIT_SUCCESS;
}