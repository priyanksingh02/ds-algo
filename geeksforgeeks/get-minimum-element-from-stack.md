```cpp
/*returns min element from stack*/
int _stack :: getMin()
{
   //Your code here
   if(s.empty()) return -1;
   else return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   if(s.empty()) return -1;
   int ans = s.top();
   if(s.top() == minEle) {
       s.pop();
       minEle = s.top();
       s.pop();
   }
   else {
       s.pop();
   }
   return ans;
}

/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   if(s.empty()) {
       minEle = x;
       s.push(x);
       s.push(x);
   }
   else {
       if(x <= minEle) {
            s.push(minEle);
            s.push(x);
            minEle = x;
       }
       else {
           s.push(x);
       }
   }
}


```

