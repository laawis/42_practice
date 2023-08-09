#include <unistd.h>

int    main(int argc, char **argv)
{
    int    start;
    int    end;
    int    i;
    int    flag;

    start = 0;
    end = 0;
    i = 0;
    flag = 0;
    
       if (argc == 2)
       {
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        start = i;
        while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
            i++;
        end = i;
        while (argv[1][i] == ' ' && argv[1][i] == '\t')
                i++;
        while(argv[1][i] != '\0')
        {
            while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
            {
                write(1, &argv[1][i], 1);
                flag = 1;
                i++;
            }
            while (argv[1][i] == ' ' || argv[1][i] == '\t')
                i++;
            if (argv[1][i] != '\0' && (argv[1][i - 1] == ' '|| argv[1][i - 1] == '\t'))    
                write(1, " ", 1);
       }
        if (flag == 1)
            write(1, " ", 1);
        while (start < end)
        {
            write(1, &argv[1][start], 1);
            start++;
        }
       }
       write(1, "\n", 1);
       return (0);
     /*
    if (argc > 1 && argv[1][0])
    {
        i = 0;
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        start = i;
        while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
            i++;
        end = i;
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        while(argv[1][i]) 
        {
            while ((argv[1][i] == ' ' && argv[1][i + 1] == ' ') || (argv[1][i] == '\t' && argv[1][i + 1] == '\t'))
                i++; 
            if (argv[1][i] == ' ' || argv[1][i] == '\t')
                flag = 1; 
            write(1, &argv[1][i], 1);
            i++;
        }
        if (flag)
            write(1, " ", 1);
        while (start < end)
        {
            write(1, &argv[1][start], 1);
            start++;
        }
    }
    write(1, "\n", 1);
    return(0);
    */
}
