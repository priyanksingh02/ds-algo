```cpp
int isDivisible(string s){
  // Create a DFA with 3 states and 2 jumps per state (0/1)
  int state = 0;
  for(int i= 0; i < s.size(); ++i) {
    if(state == 0) {
      if(s[i] == '0') {
        state = 0;
      }
      else {
        state = 1;
      }
    }
    else if(state == 1) {
      if(s[i] == '0') {
        state = 2;
      }
      else {
        state = 0;
      }
    }
    else {
      if(s[i] == '0') {
        state = 1;
      }
      else {
        state = 2;
      }
    }
  }
  return state == 0;
}

```
