vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long temp= 0;
    long long sum =0;
    long long squareSum = 0;
    long C;
    long B;
    for(int i=0;i<A.size();i++){
        temp = A[i];
        sum += temp;
        sum -= (i+1);
        
        squareSum += (temp*temp);
        squareSum -= (long long)((i+1)*(i+1));
    }
    squareSum /= sum ;
    C= (sum + squareSum)/2;
    B= squareSum -C;
    
    vector<int> D;
    D.push_back(C);
    D.push_back(B);
    
    return D;
}
