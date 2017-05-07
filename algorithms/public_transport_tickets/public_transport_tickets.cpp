
#include <algorithm>
#include <climits>

#define SINGLE_PASS 2
#define WEEKLY_PASS 7
#define MONTHLY_PASS 25

//find the number of days in the vector during the period
int count_skip_days(vector<int> &A, int period) {
    int c=0;
    int size_A=A.size();
    int exp=A[0]+period;
    
    for(int i=1;i<size_A;++i) {
        if(A[i]<exp) //period pass covers this day
            ++c;
        else
            break;
    }
    
    return c;
}

int find_optimum(vector<int> &A, int depth);

int calculate_cost(vector<int> &A, int period, int cost, int depth) {
    int skip_days=1;
    if(period>1) {
        skip_days+=count_skip_days(A,period);
    }
    vector<int> A_partial(&A[skip_days],&A[A.size()]);
    return cost+find_optimum(A_partial, depth+1);
}


int find_optimum(vector<int> &A, int depth) {
    int size_A=A.size();
    //baseline case
    if(size_A==0)
        return 0;
    else if(size_A==1)
        return SINGLE_PASS;
        
    int total_cost1 = calculate_cost(A,1,SINGLE_PASS,depth);
    int total_cost7 = calculate_cost(A,7,WEEKLY_PASS,depth);
    int total_cost30 = calculate_cost(A,30,MONTHLY_PASS,depth);
    
    return min(total_cost1,min(total_cost7,total_cost30));
}


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    return find_optimum(A, 0);
}