void print(void){
    static int x;
    int y=0;
    printf("\n Value of static integer variable x: %d",x);
    printf("\n Value of y: %d",y); x++;y++;
}