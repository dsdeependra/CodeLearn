int reverseNum(int A){
    if(A < 10 && A >=0){
        return A;
    }
    
    int rem = A % 10;
    int divi = A / 10; 
    int reverseNum = rem;
   
    
    while(rem <= divi){
        rem = divi % 10;
        reverseNum = reverseNum*10 + rem;
        divi = divi / 10;
        //cout<<rem<<" "<<divi<<" "<<reverseNum<<endl;
    }
    if(divi > 0){
        reverseNum = reverseNum*10 + divi;
    }
    return reverseNum;
}
int Solution::reverse(int A) {
    
    if(sizeof(abs(A)) > sizeof(int)){
        return 0;
    }
   
    if(A<0){
        return reverseNum(abs(A)) * (-1);
    }else{
        return reverseNum(A);
    }
}
