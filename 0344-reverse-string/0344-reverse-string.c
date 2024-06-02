

void reverseString(char* s, int sSize){
int a=0;
    for(int i=sSize-1;i>=sSize/2;i--){
    char temp=s[i];
    s[i]=s[a];
    s[a]=temp;
        a++;
}
}