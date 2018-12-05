/*
p(i,j) = 1 if s[i] = s[j] and p(i+1,j-1) = 1
       = 0 if s[i] != s[j]
*/

int P(char* s, int i, int j, int** table){
    if(i > j)return 0;
    if(i == j){
        return 1;
    }
    //i < j
    if(table[i][j] != -1)return table[i][j];
    if(s[i] != s[j]){
        return 0;
    }
    //s[i] = s[j]
    if(i+1 == j){
        return 1;
    }
    //printf("(%d,%d)->(%d,%d)\n",i,j,i+1,j-1);
    return P(s,i+1,j-1,table);
}


//DP
char* longestPalindrome(char* s) {
    char* str = NULL;
    int l = strlen(s);
    int** table = NULL;//2-d table, entry(i,j) = 0 iff s[i..j] is not palindrome.
    int i,j;
    table = malloc(sizeof(int*)*l);//table has l rows
    for(i = 0; i < l; i++){
        table[i] = malloc(sizeof(int)*l);//each row has l columns
        for(j = 0; j < l; j++){
            table[i][j] = -1;
        }
    }
    for(i = 0; i < l; i++){
        for(j = 0; j < l; j++){
            table[i][j] = P(s,i,j,table);
        }
    }
    
    //find longest palindrome using table
    if(l > 0){    
        i = 0;
        int left = 0;
        int max = 1;
        while(i <= l/2+1){
            j = l-1;
            while(j > i){
                if(table[i][j] == 1 && j - i + 1 > max){
                    max = j - i + 1;
                    left = i;
                }
                j--;
            }
            i++;
        }
        
        str = malloc(sizeof(char) * max);
        for(i = 0; i < max; i++){
            str[i] = s[left+i];
        }
        
        for(i = 0; i < l; i++){
            free(table[i]);//free before end.
        }
    }
    else{
        str = "";
    }
    printf("%s\n",str);
    return str;
}