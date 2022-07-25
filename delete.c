#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) 
{
    
    if(strcmp(a,b)<0)
        return 0;
    else if (strcmp(a,b)<0)
        return 1;
    else 
        return 0;
      
      
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    if(strcmp(a,b)>0)
        return 0;
    else if (strcmp(a,b)<0)
        return 1;
    else 
        return 0;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    return 0;
}

int sort_by_length(const char* a, const char* b) {
return 0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b))
{
    for (int i=0; i<len-1; i++) 
    {
        for (int j=i+1; j<len ; j++) {
            if ((*cmp_func)(arr[i],arr[j])==0) 
            {
                char* temp=(char*)malloc(2500*sizeof(char));
                strcpy(temp, arr[j]);
                strcpy(arr[j],arr[i]);
                strcpy(arr[i], temp);
                // printf("#%s#",arr[i]);
            }
        }
    }

}


int main() 
{
    int n;
    printf("n :");
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  printf("\n n str. : ");
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
