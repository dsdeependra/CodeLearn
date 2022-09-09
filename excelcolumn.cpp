string Solution::convertToTitle(int A) {
    
       string str ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
       string res;
       
    if(A<=26){
        res = str[A-1];
        return res;
    }
   
    while(A / 26 >= 1){
        int r = A % 26;
        A /=26; 
        res += str[r-1];
        //cout<<str<<endl;
    }
    res += str[A-1];
    //str += to_string(1); 
    reverse(res.begin(), res.end());
    return res;
}
