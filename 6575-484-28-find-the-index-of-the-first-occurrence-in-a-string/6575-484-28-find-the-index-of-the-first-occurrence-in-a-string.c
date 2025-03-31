int strStr(char* haystack, char* needle) {
    char *res = strstr(haystack,needle);
    if(res == NULL)return -1;
    else return  res - haystack;
}