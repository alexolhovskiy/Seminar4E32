#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int findChar(char c,char*str,int start){
    int i=start;
    while(str[i]!='.'){
        if(str[i]==c){
            return i;
        }
        i++;
    }
    return -1;
}


int tillTheEnd(char*str1,char*str2,int pos){
    int i=1;
    while(str2[pos]==str1[i]){
        i++;
        pos++;
    }
    if(str2[pos]=='.'){
        return i;
    }
    return -1;
}


int findPref(char*str1,char*str2){
    int cnt=0,pos=0,i=0;
    int size2=strlen(str2);
    while(i<size2){
        i=findChar(str1[0],str2,i);
        if(i>0){
            i++;
            cnt=tillTheEnd(str1,str2,i);
            if(cnt>0){
                return cnt;
            }
        }else{
            return 0;
        }
    }
    return cnt;
}




//don't_panic
//nick_is_a_mastodon
int main()
{
    char str2[]="don't_panic.";
    char str1[]="nick_is_a_mastodon.";
    //char str2[]="python_has_list_comprehensions.";
    //char str1[]="monty_python.";

    printf("%s\n",str1);
    printf("%s\n",str2);

    int n=findPref(str1,str2);
    if(n==0){
        n=findPref(str2,str1);
        printf("Suffix=%d chars\n",n);
    }else{
        printf("Prefix=%d chars\n",n);
    }

    printf("Hello world!\n");
    return 0;
}
