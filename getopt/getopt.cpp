#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){

    int result = 0;
    while((result =  getopt(argc, argv, "ab:c::")) != -1){
        switch(result){
            case 'a':
                printf("option=a, optopt=%c, optarg=%s\n", optopt, optarg);
                break;
            case 'b':
                printf("option=b, optopt=%c, optarg=%s\n", optopt, optarg);
                break;
            case 'c':
                printf("option=c, optopt=%c, optarg=%s\n", optopt, optarg);
                break;
            case '?':
                printf("option=?, optopt=%c, optarg=%s\n", optopt, optarg);
                break;
            default:
                printf("default, result=%c\n", result);
                break;
        }
        printf("optind = %d,argv[%d]=%s\n", optind, optind, argv[optind]);
    }

    printf("result=-1, optind=%d\n",optind);

    for(result = optind; result < argc; result++){
        printf("-----argv[%d]=%s\n", result, argv[result]);
    }

    for(result = 1; result < argc; result++){
        printf("-----argv[%d]=%s\n", result, argv[result]);
    }

    return 0;
}