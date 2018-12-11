/*
p(s,i,table) = "length of longest substring ending with s[i], given table"

p(s,i,table) = 1 + p(s,i-1,new(table)) if table[s[i] - 'a'] = 0
               0 if table[s[i] - 'a'] = 1

s = abcdabcc
p(s,1) = 1
p(s,2) = 2
p(s,3) = 3
p(s,4) = 4
p(s,5) = 4
p(s,6) = 4
p(s,7) = 4
p(s,8) = 1

*/

int p(char* s, int n, int* table){
    if(n < 0)return 0;//invalid case
    if(table[s[n]] == 1)return 0;//this char appeared before
    if(n == 0)return 1;//single char
    
    //int* new = malloc(sizeof(int)*26);//new look up table
    int i;
    //for(i=0;i<26;i++){new[i] = table[i];}//a copy of the old table
    table[s[n]] = 1;//modify 
    return 1 + p(s,n-1,table);//as describled in comment
    //free(new);//free after call
}




int lengthOfLongestSubstring(char* s) {
    
    if(s == NULL)return 0;
    
    int* table = NULL;
    table = malloc(sizeof(int)*128);
    int i = 0;
    int m = strlen(s);
    
    if(m <= 0)return 0;
    
    for(i = 0; i < 128; i++){table[i] = 0;}//ini look up table
    int lengths[m];//m sub-problems
    
    for(i = 0; i < m; i++){
        for(int j = 0; j < 128; j++){table[j] = 0;}
        lengths[i] = p(s,i,table);//compute each sub-prblem
    }
    
    int max = 0;
    
    for(i = 0; i < m; i++ ){
        printf("p(%d) = %d\n",i,lengths[i]);
        if(max < lengths[i])max = lengths[i];
    }
    free(table);
    return max;//return the maximal result
}