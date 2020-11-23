```cpp
class Solution {
  public:
    string value(char c) {
      switch(c) {
        case '1': return "One ";
        case '2': return "Two ";
        case '3': return "Three ";
        case '4': return "Four ";
        case '5': return "Five ";
        case '6': return "Six ";
        case '7': return "Seven ";
        case '8': return "Eight ";
        case '9': return "Nine ";
        case '0': return "Zero ";
        default : assert(false); return "";
      }
    }

    string ty(char c) {
      switch(c) {
        case '2': return "Twenty ";
        case '3': return "Thirty ";
        case '4': return "Forty ";
        case '5': return "Fifty ";
        case '6': return "Sixty ";
        case '7': return "Seventy ";
        case '8': return "Eighty ";
        case '9': return "Ninety ";
        default : assert(false); return "";
      }
    }

    string teen(const string & s) {
      if(s == "10") return "Ten ";
      else if(s == "11") return "Eleven ";
      else if(s == "12") return "Twelve ";
      else if(s == "13") return "Thirteen ";
      else if(s == "14") return "Fourteen ";
      else if(s == "15") return "Fifteen ";
      else if(s == "16") return "Sixteen ";
      else if(s == "17") return "Seventeen ";
      else if(s == "18") return "Eighteen ";
      else if(s == "19") return "Nineteen ";
      else { assert(false); return ""; }
    }

    string parse(const string & s) {
      if(s.size() == 1)
        return value(s[0]);
      string ans;
      if(s[0] != '0') {
        ans += value(s[0]);
        ans += "Hundred ";
      }
      if(s[1] == '0') {
        if(s[2] != '0')
          ans += value(s[2]);
      }
      else if(s[1] == '1') {
        ans += teen(s.substr(1));
      }
      else {
        ans += ty(s[1]);
        if(s[2] != '0')
          ans += value(s[2]);
      }
      return ans;
    }

    string numberToWords(int num) {
      string s = to_string(num);
      string ans;
      int n = s.size();
      s = string(10-n, '0') + s;
      string part = s.substr(0, 1);
      if(part != "0") {
        ans += parse(part);
        ans += "Billion ";
      }
      part = s.substr(1, 3);
      if(part != "000") {
        ans += parse(part);
        ans += "Million ";
      }
      part = s.substr(4, 3);
      if(part != "000") {
        ans += parse(part);
        ans += "Thousand ";
      }
      part = s.substr(7);
      ans += parse(part);
      if(!ans.empty())
        ans.pop_back(); // remove last space
      else
        return "Zero";
      return ans;
    }
};

```
