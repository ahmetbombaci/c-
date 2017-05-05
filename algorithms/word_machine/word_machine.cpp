#include <stack>
#include <algorithm>


int do_operation(stack<unsigned int> &my_stack, string &command) {
    
    if(command.size()==0) {
        return -1;
    }
    else if(command.compare("POP") == 0) {
        if(my_stack.empty())
            return -1;
        my_stack.pop();
    }
    else if(command.compare("DUP") == 0) {
        if(my_stack.empty())
            return -1;
        my_stack.push(my_stack.top());
    }
    else if(command.compare("+") == 0) {
        if(my_stack.size()<2)
            return -1;
        unsigned int x1=my_stack.top();
        my_stack.pop();
        unsigned int x2=my_stack.top();
        my_stack.pop();
        unsigned int r=x1+x2;
        if(r<max(x1,x2)) //overflow
            return -1;
        my_stack.push(r);
    }
    else if(command.compare("-") == 0) {
        if(my_stack.size()<2)
            return -1;
        unsigned int x1=my_stack.top();
        my_stack.pop();
        unsigned int x2=my_stack.top();
        my_stack.pop();
        int t=x1-x2;
        if(t<0)
            return -1;
        unsigned int r=t;
        my_stack.push(r);
    }
    else{
        my_stack.push(stol(command));
    }
    return 0;
}

int solution(string &S) {
    stack<unsigned int> my_stack;
    
    
    //cout << S << endl;
    string command="";
    size_t pos=0;
    while((pos = S.find(" ")) != string::npos ) {
        command = S.substr(0, pos);
        //cout << command << endl;
        
        if(do_operation(my_stack, command)==-1)
            return -1;
        
        S.erase(0, pos+1);
        
        
    }
    
    
    //cout << S << endl;
    
    command = S;
    
    if(do_operation(my_stack, command)==-1)
        return -1;
        
    if(my_stack.size()>0)
        return my_stack.top();
     
    return -1;
}