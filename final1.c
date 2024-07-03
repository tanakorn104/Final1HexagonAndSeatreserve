#include <stdio.h>
#include <string.h>
#include <windows.h>

int reserveseatfinal1()
{
    int nrow,ncol ,userselect,c,i,n;  //i=row n=col
    nrow = 3;
    ncol = 5;
    int userreserveseat[2];  //0=row 1=col
    userreserveseat[0]=0;
    userreserveseat[1]=0;
    while (1){
        printf("Main menu \n");
        printf("1. Reverve seat \n");
        printf("2. Show all seats \n");
        printf("3. Exit \n");
        printf("Input 1 or 2 or 3 : ");
        scanf("%d",&userselect);
        while(c = getchar()!='\n' && c!=EOF){}

        
        
        if(userselect==3){
            printf("Good bye");
            break;
        }else if(userselect == 1){
            while(1){
                int bufrow,bufcol;
                printf("Select row:");
                scanf("%d",&bufrow);
                printf("Select row:");
                scanf("%d",&bufcol);
                if(userreserveseat[0]>nrow || userreserveseat[1]>ncol){
                    printf("Invaid seat! Select again \n");
                    continue;
                }else if(bufrow==userreserveseat[0] && bufcol==userreserveseat[1]){
                    printf("Invaid seat! Select again \n");

                    
                }else{
                    userreserveseat[0] =bufrow;
                    userreserveseat[1] =bufcol;
                    break;
                }
                
            }
            printf("Reverve OK");
            continue;
        }else if (userselect ==2)
        {
            for(i=0;i<nrow;i++){
                for(n=0;n<ncol;n++){
                    if(i+1==userreserveseat[0] && n+1==userreserveseat[1]){
                        printf("*");
                    }else{
                        printf("-");
                    }
                }
                printf("\n");
            }

        }
        

    }
    return 0;
    
}



void hexagonfinal1(){
    int timedelay_ms = 30;
     
    int base;
    char letter;

    printf("Enter Base : ");
    scanf("%d",&base);
    int c;
    while(c=getchar()!='\n' && c!=EOF);
    printf("Enter Letter : ");
    scanf("%c",&letter);
     while(c=getchar()!='\n' && c!=EOF);
     
    //spacestrart array
    if(base<4||base>15){
        printf("Invalid Input!");
        exit(0);
    }
    int nmaxline = 2*(base-2)+1;
    int arrspacceallrow[nmaxline] ;
    int nmaxcenter = base+(base-2)*2;
    int i,n,z;
    int halfall = ((nmaxcenter-1))/2;
    for(i=0;i<halfall-1;i++){
        int ninline = base+(i)*2 ;
        //printf("%d", i);8
        int startspace=(nmaxcenter-ninline)/2;
        arrspacceallrow[i]=startspace;
    }
    int sizearr = sizeof(arrspacceallrow)/sizeof(arrspacceallrow[0]);
    for(i=0;i<(sizearr-1)/2;i++){
        arrspacceallrow[sizearr-(i+1)]=arrspacceallrow[i];
    }
    //เพื่อให้มั่นใจว่าตรงกลางของarrเป็ฯ0เสมอ
    arrspacceallrow[base-2]=0;
    //ตามแถว
    for(i=0;i<nmaxline;i++){
        int halfspace = 30;
        int innerspace;
        if(base%2 == 0){
            innerspace = nmaxcenter/2;
        }else{
            innerspace = ((nmaxcenter-1)/2)+1;
        }
        int delfullspace = halfspace-innerspace;
        for(z=0;z<arrspacceallrow[i]+delfullspace;z++){//printspace
            printf(" ");
        }
        //printletter
        printf("o");
        Sleep(timedelay_ms);
        for(z=0;z<(nmaxcenter-(arrspacceallrow[i]*2))-2;z++){
            if(i==0){
                printf("o");
                Sleep(timedelay_ms);
            }else if(i==sizearr-1){
                printf("o");
                Sleep(timedelay_ms);
            }else{
                printf("%c",letter);
                Sleep(timedelay_ms);
            }
        }
        printf("o");
        Sleep(timedelay_ms);
        printf("\n");
    }
}
